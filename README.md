# ESP32 Cyber Distance Scanner

Um projeto utilizando ESP32, display OLED SPI e sensor VL53L0X para criar um scanner de distância com interface inspirada em sistemas futuristas e cyberpunk.

## Funcionalidades

- Medição de distância em tempo real
- Exibição da distância em milímetros
- Barra de proximidade dinâmica
- Indicador visual de alvo detectado ("TARGET LOCK")
- Interface gráfica em OLED

## Hardware Utilizado

- ESP32 DevKit V1
- Display OLED SPI 128x64
- Sensor VL53L0X
- Protoboard
- Jumpers macho-macho

## Ligações

### OLED SPI

| OLED | ESP32 |
|--------|--------|
| GND | GND |
| VCC | 3V3 |
| D0 | GPIO 18 |
| D1 | GPIO 23 |
| RES | GPIO 4 |
| DC | GPIO 2 |
| CS | GPIO 5 |

### VL53L0X

| Sensor | ESP32 |
|---------|---------|
| VIN | 3V3 |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## Dependências

Adicione ao arquivo `platformio.ini`:

```ini
lib_deps =
    adafruit/Adafruit GFX Library
    adafruit/Adafruit SSD1306
    pololu/VL53L0X
```

## Como Funciona

O sensor VL53L0X realiza leituras contínuas da distância até o objeto mais próximo.

As informações são exibidas na tela OLED através de:

- Distância em milímetros
- Barra visual de proximidade
- Mensagem de detecção quando um alvo é identificado

Quando um objeto se aproxima do sensor, a barra cresce proporcionalmente e o sistema entra em modo **TARGET LOCK**.

## Exemplo

```text
CYBER SCAN

128 mm

███████████░

TARGET LOCK
```

## Estrutura do Projeto

```text
.
├── src/
│   └── main.cpp
├── include/
├── lib/
├── platformio.ini
└── README.md
```

## Próximos Passos

- Adicionar LED indicador de proximidade
- Implementar animação de radar
- Criar modo Detector de Mão Jedi
- Criar Scanner Corporal Sci-Fi
- Desenvolver sistema de alarme
- Adicionar múltiplas telas e menus

## Autor

Leonardo Barros

## Licença

Este projeto é livre para estudo, modificação e experimentação.
