#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QThread>
#include <QAudioInput>
#include <QIODevice>
#include <vosk_api.h> // Vosk API заголовок

class SpeechRecognitionWorker : public QObject {
    Q_OBJECT
public:
    explicit SpeechRecognitionWorker(QObject *parent = nullptr) : QObject(parent) {
        model = vosk_model_new("model");
        if (!model) {
            qFatal("Failed to load model. Make sure the 'model' directory exists and is accessible.");
        }
        recognizer = vosk_recognizer_new(model, 16000.0);
        if (!recognizer) {
            qFatal("Failed to create recognizer.");
        }
    }

    ~SpeechRecognitionWorker() override {
        vosk_recognizer_free(recognizer);
        vosk_model_free(model);
    }

signals:
    void newTextRecognized(const QString &text);

public slots:
    void startRecognition() {
        QAudioInput *audioInput = new QAudioInput();
        QIODevice *audioDevice = audioInput->start();

        if (!audioDevice) {
            qWarning("Failed to start audio input.");
            return;
        }

        while (!QThread::currentThread()->isInterruptionRequested()) {
            QByteArray buffer = audioDevice->readAll();
            if (buffer.isEmpty()) {
                continue;
            }

            if (vosk_recognizer_accept_waveform(recognizer, buffer.data(), buffer.size())) {
                const char *result = vosk_recognizer_result(recognizer);
                emit newTextRecognized(QString::fromUtf8(result));
            }
        }

        audioInput->stop();
        delete audioInput;
    }

private:
    VoskModel *model;
    VoskRecognizer *recognizer;
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Dictovod");
        setFixedSize(250, 200);

        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setReadOnly(true);
        layout->addWidget(textBrowser);

        setCentralWidget(centralWidget);

        SpeechRecognitionWorker *worker = new SpeechRecognitionWorker();
        QThread *thread = new QThread(this);
        worker->moveToThread(thread);

        connect(thread, &QThread::started, worker, &SpeechRecognitionWorker::startRecognition);
        connect(worker, &SpeechRecognitionWorker::newTextRecognized, this, &MainWindow::appendText);

        // Безопасное завершение потока
        connect(this, &MainWindow::destroyed, thread, [thread, worker]() {
            thread->requestInterruption();
            thread->quit();
            thread->wait();
            delete worker;
        });

        thread->start();
    }

public slots:
    void appendText(const QString &text) {
        textBrowser->append(text);
    }

private:
    QTextBrowser *textBrowser;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

#include "main.moc"
