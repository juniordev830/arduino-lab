# Arduino Lab

Laboratório de experimentos de eletrônica, programação embarcada e automação com Arduino usando **C e C++**.

## Experimento disponível

### [Blink — LED integrado](experiments/blink/README.md)

O primeiro experimento usa apenas o LED integrado da placa (LED_BUILTIN), sem componentes ou ligações externas. Consulte as instruções antes de compilar e carregar o sketch.

### [Button debounce — botão com pull-up](experiments/button-debounce/README.md)

O segundo experimento lê um botão em D2 com INPUT_PULLUP. A lógica de debounce de 35 ms usa um módulo em **C11**, integrado ao sketch Arduino e testável em computador sem placa.


### [Serial Blink — LED sem bloqueio](experiments/serial-blink/README.md)

Terceiro experimento: temporização do LED integrado com `millis()`, comandos simples no monitor serial e teste portável de estouro do contador. O CI compila para Arduino Uno e executa o teste C++ nativo.

## Boas práticas de segurança

- Selecione o modelo exato da placa e verifique seus limites elétricos antes de ligar qualquer circuito.
- Não conecte componentes diretamente a uma alimentação sem conferir tensão, corrente e polaridade.
- Nunca conecte a rede elétrica residencial a uma placa Arduino.
- Documente placa, tensão, componentes, pinos e esquema em cada novo experimento.
- Teste o sketch em bancada e mantenha fios e circuitos desligados durante alterações de montagem.

## Estrutura

```text
experiments/
└── blink/
    ├── blink.ino
    └── README.md
```

## Testes nativos em C

Sem placa conectada, rode:

```bash
gcc -std=c11 -Wall -Wextra -Werror -pedantic tests/debounce_test.c experiments/button-debounce/debounce.c -o debounce_test
./debounce_test
```

O teste verifica ruídos do botão, acionamento, soltura e o retorno de `millis()` ao zero. O GitHub Actions compila o módulo em C e o sketch para Arduino Uno.

### Simulador de botão em C

Você também pode simular o circuito sem uma placa física. Cada linha representa `milissegundos nivel`, onde `0` indica botão pressionado e `1` indica botão solto (`INPUT_PULLUP`):

```bash
gcc -std=c11 -Wall -Wextra -Werror -pedantic tools/debounce_sim.c experiments/button-debounce/debounce.c -o debounce_sim
./debounce_sim < tests/debounce_samples.txt
./debounce_sim --threshold-ms 50 < tests/debounce_slow_samples.txt
```

Com o padrão de **35 ms**, a saída esperada é `50 PRESSED` e `90 RELEASED`. Com **50 ms**, o segundo conjunto produz `65 PRESSED` e `120 RELEASED`. O simulador verifica os dados de entrada, rejeita tempos fora de ordem e permite ajustar o intervalo de debounce de **1 a 10.000 ms**. Os testes automáticos comparam a saída aos eventos esperados.

Experimentos futuros devem ser adicionados em pastas independentes para manter instruções e circuitos isolados.

## Verificação antes de contribuir

O [guia de validação](docs/GUIA_DE_VALIDACAO.md) descreve o estado do código, as verificações reproduzíveis e os riscos a observar ao revisar novas alterações.
