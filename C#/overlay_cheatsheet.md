# 📺 Шпаргалка по настройке оверлея

## Быстрые настройки позиций

### Наверху по центру (по умолчанию)
```json
"OverlayPosition": "top",
"OverlayOffsetX": 0,
"OverlayOffsetY": 5
```

### Внизу по центру (субтитры)
```json
"OverlayPosition": "bottom",
"OverlayOffsetX": 0,
"OverlayOffsetY": 50
```

### По центру экрана (караоке)
```json
"OverlayPosition": "center",
"OverlayOffsetX": 0,
"OverlayOffsetY": 0
```

### Наверху слева
```json
"OverlayPosition": "top",
"OverlayOffsetX": -600,
"OverlayOffsetY": 10
```

### Наверху справа
```json
"OverlayPosition": "top",
"OverlayOffsetX": 600,
"OverlayOffsetY": 10
```

### Внизу слева
```json
"OverlayPosition": "bottom",
"OverlayOffsetX": -600,
"OverlayOffsetY": 50
```

### Внизу справа
```json
"OverlayPosition": "bottom",
"OverlayOffsetX": 600,
"OverlayOffsetY": 50
```

## Цвета фона (ARGB)

### Прозрачность
- `#00......` - полностью прозрачный
- `#80......` - 50% прозрачности
- `#c0......` - 75% прозрачности
- `#ff......` - непрозрачный

### Популярные цвета
```json
"#c8000000"  // Полупрозрачный черный (рекомендуется)
"#e0000000"  // Почти черный
"#80ffffff"  // Полупрозрачный белый
"#c01e3a8a"  // Полупрозрачный синий
"#c02e7d32"  // Полупрозрачный зеленый
"#c0ffa500"  // Полупрозрачный оранжевый
```

## Размеры

### Для FullHD (1920x1080)
```json
"OverlayWidth": 1000,   // Средний
"OverlayWidth": 1400,   // Широкий
"OverlayWidth": 600     // Узкий
```

### Для 4K (3840x2160)
```json
"OverlayWidth": 2000,   // Средний
"OverlayWidth": 2800,   // Широкий
"OverlayWidth": 1200    // Узкий
```

## Шрифты

### Для читаемости
```json
"OverlayFontFamily": "Segoe UI",
"OverlayFontSize": 18.0
```

### Для караоке/презентаций
```json
"OverlayFontFamily": "Impact",
"OverlayFontSize": 32.0
```

### Для субтитров
```json
"OverlayFontFamily": "Arial",
"OverlayFontSize": 14.0
```

### Для стриминга
```json
"OverlayFontFamily": "Roboto",
"OverlayFontSize": 20.0
```

## Длительность показа

```json
"OverlayDuration": 2000   // 2 секунды (быстро)
"OverlayDuration": 4000   // 4 секунды (по умолчанию)
"OverlayDuration": 6000   // 6 секунд (долго)
"OverlayDuration": 10000  // 10 секунд (очень долго)
```

## Готовые конфигурации

### Стиль YouTube субтитров
```json
{
  "OverlayWidth": 800,
  "OverlayHeight": 70,
  "OverlayPosition": "bottom",
  "OverlayOffsetX": 0,
  "OverlayOffsetY": 100,
  "OverlayTextColor": "#ffffff",
  "OverlayBackgroundColor": "#e0000000",
  "OverlayFontFamily": "Roboto",
  "OverlayFontSize": 18.0,
  "OverlayDuration": 4000
}
```

### Стиль новостной ленты
```json
{
  "OverlayWidth": 1400,
  "OverlayHeight": 60,
  "OverlayPosition": "top",
  "OverlayOffsetX": 0,
  "OverlayOffsetY": 0,
  "OverlayTextColor": "#ffffff",
  "OverlayBackgroundColor": "#ff0047ab",
  "OverlayFontFamily": "Arial",
  "OverlayFontSize": 16.0,
  "OverlayDuration": 5000
}
```

### Стиль телепромптера
```json
{
  "OverlayWidth": 1000,
  "OverlayHeight": 200,
  "OverlayPosition": "center",
  "OverlayOffsetX": 0,
  "OverlayOffsetY": -200,
  "OverlayTextColor": "#000000",
  "OverlayBackgroundColor": "#f0ffffff",
  "OverlayFontFamily": "Times New Roman",
  "OverlayFontSize": 24.0,
  "OverlayDuration": 8000
}
```

### Стиль стриминга (правый нижний угол)
```json
{
  "OverlayWidth": 500,
  "OverlayHeight": 80,
  "OverlayPosition": "bottom",
  "OverlayOffsetX": 500,
  "OverlayOffsetY": 30,
  "OverlayTextColor": "#00ff00",
  "OverlayBackgroundColor": "#c0000000",
  "OverlayFontFamily": "Consolas",
  "OverlayFontSize": 16.0,
  "OverlayDuration": 3000
}
```

---

**Совет**: Начните с готовой конфигурации и постепенно подстраивайте под себя!