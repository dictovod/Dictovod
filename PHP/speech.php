<?php
/*
Plugin Name: Speech Recognition Shortcode
Description: Добавляет интерфейс с распознаванием речи. Выводит слово "привет" при его произнесении.
Version: 1.1
Author: lp85d
*/

// Регистрируем шорткод
function speech_recognition_shortcode() {
    ob_start();
    ?>
    <style>
        #speech-recognition {
            position: fixed;
            top: 0;
            left: 0;
            width: 100vw;
            height: 100vh;
            display: flex;
            flex-direction: column;
            justify-content: flex-start;
            align-items: center;
            padding-top: 10vh;
            background: rgba(0, 0, 0, 0.05);
        }
        #start-button {
            width: 35%;
            height: auto;
            max-height: calc(35% / 3 * 1);
            font-size: 1.8vw;
            font-weight: bold;
            cursor: pointer;
            border: none;
            background: #007BFF;
            color: white;
            border-radius: 10px;
            padding: 1vw 2vw;
            transition: background 0.3s;
            text-align: center;
            white-space: nowrap;
        }
        #start-button:hover {
            background: #0056b3;
        }
        #output {
            font-size: 2vw;
            color: green;
            margin-top: 20px;
            text-align: center;
        }
    </style>
    
    <div id="speech-recognition">
        <button id="start-button">Разрешить микрофон и начать</button>
        <p id="output"></p>
    </div>

    <script>
        document.getElementById('start-button').addEventListener('click', () => {
            const output = document.getElementById('output');

            // Проверяем поддержку API
            if (!('webkitSpeechRecognition' in window || 'SpeechRecognition' in window)) {
                output.textContent = 'Ваш браузер не поддерживает распознавание речи.';
                return;
            }

            // Инициализируем API
            const SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
            const recognition = new SpeechRecognition();

            recognition.lang = 'ru-RU'; // Устанавливаем язык на русский
            recognition.interimResults = false; // Только окончательные результаты

            recognition.onstart = () => {
                output.textContent = 'Слушаю... Говорите "привет".';
            };

            recognition.onspeechend = () => {
                output.textContent = 'Обработка речи...';
            };

            recognition.onerror = (event) => {
                output.textContent = 'Произошла ошибка: ' + event.error;
            };

            recognition.onresult = (event) => {
                const transcript = event.results[0][0].transcript.trim();

                if (transcript.toLowerCase() === 'привет') {
                    output.textContent = 'Вы сказали: "привет"';
                } else {
                    output.textContent = 'Вы сказали: ' + transcript;
                }
            };

            recognition.start();
        });
    </script>
    <?php
    return ob_get_clean();
}

add_shortcode('speech_recognition', 'speech_recognition_shortcode');
