const { app, BrowserWindow } = require('electron');

let mainWindow;

app.on('ready', () => {
  mainWindow = new BrowserWindow({
    width: 420, // Ширина с учетом границ
    height: 500, // Высота с запасом для содержимого
    resizable: false, // Отключаем изменение размера окна
    webPreferences: {
      nodeIntegration: false,
      contextIsolation: true, // Для повышения безопасности
    },
  });

  // Загрузите страницу с плагином
  mainWindow.loadURL('https://dictovod.ru/hello/');

  // Закройте приложение при закрытии окна
  mainWindow.on('closed', () => {
    mainWindow = null;
  });
});

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});
