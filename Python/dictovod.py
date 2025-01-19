import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QScrollArea, QTextBrowser
from PyQt6.QtCore import QMetaObject, Qt, pyqtSignal, QObject
import speech_recognition as sr
from threading import Thread

class Communicator(QObject):
    update_text_signal = pyqtSignal(str)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Dictovod")
        self.setFixedSize(250, 200)  # Увеличиваем размер окна

        # Create a central widget
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        # Set up layout
        layout = QVBoxLayout()
        central_widget.setLayout(layout)

        # Add a scrollable area for displaying recognized text
        self.scroll_area = QScrollArea()
        self.scroll_area.setWidgetResizable(True)

        # Create a text browser for compact text display
        self.text_browser = QTextBrowser()
        self.text_browser.setReadOnly(True)
        self.scroll_area.setWidget(self.text_browser)
        layout.addWidget(self.scroll_area)

        # Communicator for thread-safe updates
        self.communicator = Communicator()
        self.communicator.update_text_signal.connect(self.add_text)

        # Start speech recognition in a separate thread
        self.recognition_thread = Thread(target=self.start_continuous_recognition, daemon=True)
        self.recognition_thread.start()

    def add_text(self, text):
        self.text_browser.append(text)  # Добавляем текст в QTextBrowser

    def start_continuous_recognition(self):
        recognizer = sr.Recognizer()
        while True:
            try:
                with sr.Microphone() as source:
                    audio = recognizer.listen(source, timeout=5)
                    recognized_text = recognizer.recognize_google(audio, language="ru-RU")
                    self.communicator.update_text_signal.emit(recognized_text)
            except Exception:
                pass

if __name__ == "__main__":
    app = QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec())
