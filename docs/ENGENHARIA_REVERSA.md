# Engenharia reversa e estudo — Arduino Lab

## Objetivo e fluxo

Exercícios de temporização, botão e serial no Arduino. Compare os pares setup/loop em experiments com debounce.c e timing.h. O simulador em tools exercita regras que não dependem da placa.

**Tecnologias identificadas** · Arduino/C++, C, C/C++.

**Revisão de referência** · `043d3344e43a`.

## Mapa do código

| Caminho | Papel de leitura | Símbolos selecionados |
| --- | --- | --- |
| [experiments/blink/blink.ino](../experiments/blink/blink.ino) | Implementação | `setup`, `loop` |
| [experiments/button-debounce/button-debounce.ino](../experiments/button-debounce/button-debounce.ino) | Implementação | `setup`, `loop` |
| [experiments/button-debounce/debounce.c](../experiments/button-debounce/debounce.c) | Implementação | `debounce_init` |
| [experiments/button-debounce/debounce.h](../experiments/button-debounce/debounce.h) | Implementação | `debounce_init` |
| [experiments/serial-blink/serial-blink.ino](../experiments/serial-blink/serial-blink.ino) | Implementação | `setup`, `loop` |
| [experiments/serial-blink/timing.h](../experiments/serial-blink/timing.h) | Implementação | `blink_is_due` |
| [tools/debounce_sim.c](../tools/debounce_sim.c) | Implementação | `read_u32` |

## Configuração e referências

Referências existentes: [docs/GUIA_DE_VALIDACAO.md](GUIA_DE_VALIDACAO.md), [experiments/blink/README.md](../experiments/blink/README.md), [experiments/button-debounce/README.md](../experiments/button-debounce/README.md), [experiments/serial-blink/README.md](../experiments/serial-blink/README.md).

## Roteiro de estudo e desenvolvimento

1. Comece pelo fluxo descrito acima e localize seus pontos de entrada no mapa. Acompanhe uma entrada válida até a transformação ou a resposta.
2. Abra um teste relacionado ao fluxo e descreva qual regra ele protege. Compare o tratamento esperado para entradas válidas, inválidas e nos limites.
3. Ao adicionar uma regra, determine qual módulo controla o dado e cubra o caso nesse nível. Em seguida, confira o efeito no comando, na API ou na interface de entrada.

**Pergunta de entrevista**

Por que uma transição de botão precisa de estabilidade e como testá-la sem hardware?

## Testes versionados

Arquivos para começar a leitura dos cenários de teste: [tests/debounce_test.c](../tests/debounce_test.c), [tests/serial_blink_test.cpp](../tests/serial_blink_test.cpp).

Os comandos e versões de runtime usados no CI ficam em [.github/workflows/ci.yml](../.github/workflows/ci.yml), [.github/workflows/portfolio-checks.yml](../.github/workflows/portfolio-checks.yml).

[Voltar ao README](../README.md).
