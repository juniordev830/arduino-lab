# Serial Blink — LED integrado sem delay()

Experimento independente para Arduino Uno (AVR). O LED da placa pisca sem bloquear o loop com \`delay()\`; os comandos ASCII **f** e **s** recebidos no monitor serial (9600 baud) alternam os intervalos entre 150 ms e 500 ms.

Não conecte equipamentos externos nem a rede elétrica à placa. O código usa exclusivamente o LED integrado.

## Teste

\`\`\`sh
g++ -std=c++17 -Wall -Wextra -Werror -pedantic tests/serial_blink_test.cpp -o /tmp/serial_blink_test
/tmp/serial_blink_test
arduino-cli compile --fqbn arduino:avr:uno experiments/serial-blink
\`\`\`

A comparação com \`uint32_t\` testa o estouro de \`millis()\` para evitar uma pausa prolongada quando o contador reinicia. É um experimento pedagógico, não um componente de segurança crítica.
