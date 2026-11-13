# Button debounce

Este experimento lê um botão no pino digital D2 usando o resistor interno INPUT_PULLUP e acende o LED integrado enquanto o botão está pressionado.

## Montagem

- Conecte um terminal do botão ao pino D2.
- Conecte o outro terminal ao GND.
- Não use alimentação externa para este circuito.
- Compile para o modelo exato da placa antes de carregar.

O sketch considera o botão pressionado quando a leitura é LOW. A leitura só muda após 35 ms estáveis, evitando múltiplos eventos causados pelo ruído mecânico do botão.

## Implementação em C

O sketch `button-debounce.ino` chama `debounce_init` e `debounce_update`, declaradas em `debounce.h` e implementadas em `debounce.c` (**C11**). A leitura continua ativa em nível LOW; um toque só é considerado estável depois de 35 ms sem mudar. A diferença de tempos usa aritmética sem sinal para lidar com o rollover de `millis()`.

Execute o teste sem Arduino:

```bash
gcc -std=c11 -Wall -Wextra -Werror -pedantic tests/debounce_test.c experiments/button-debounce/debounce.c -o debounce_test
./debounce_test
```

Execute os comandos a partir da raiz do repositório. O teste de C não substitui a compilação real do sketch no Arduino CLI.
