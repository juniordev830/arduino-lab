# Button debounce

Este experimento lê um botão no pino digital D2 usando o resistor interno INPUT_PULLUP e acende o LED integrado enquanto o botão está pressionado.

## Montagem

- Conecte um terminal do botão ao pino D2.
- Conecte o outro terminal ao GND.
- Não use alimentação externa para este circuito.
- Compile para o modelo exato da placa antes de carregar.

O sketch considera o botão pressionado quando a leitura é LOW. A leitura só muda após 35 ms estáveis, evitando múltiplos eventos causados pelo ruído mecânico do botão.
