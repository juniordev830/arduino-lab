# Debounce em Ada

Implementacao de referencia para supressao de ruido digital: estado so muda apos N amostras consecutivas iguais e opostas ao estado corrente.

Teste: gnatmake -gnat2022 labs/ada/debouncer.adb && ./debouncer

O exemplo Ada executa no host e nao possui interface fisica com o Arduino. Os firmwares existentes nao foram modificados.
