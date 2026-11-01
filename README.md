# Arduino Lab

Laboratório de experimentos de eletrônica, programação embarcada e automação com Arduino usando C/C++.

## Experimento disponível

### [Blink — LED integrado](experiments/blink/README.md)

O primeiro experimento usa apenas o LED integrado da placa (LED_BUILTIN), sem componentes ou ligações externas. Consulte as instruções antes de compilar e carregar o sketch.

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

Experimentos futuros devem ser adicionados em pastas independentes para manter instruções e circuitos isolados.
