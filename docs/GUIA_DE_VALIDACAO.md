# Verificação e evolução — Arduino Lab

## Escopo confirmado

Laboratório de hardware com exemplos Blink e button debounce.

## Localização do código

`experiments/blink/README.md`, `experiments/button-debounce/README.md` e respectivos sketches.

## Verificar localmente

Seguir os dois READMEs de experimentos, selecionar a placa correta na Arduino IDE e compilar antes de gravar.

Use dados fictícios e registre no PR o comando, ambiente e resultado observado. Para projetos sem runtime instalado, marque a verificação como pendente em vez de afirmar que passou.

## Casos de regressão a cobrir

Conferir uso do LED_BUILTIN e INPUT_PULLUP, comportamento do botão com debounce e esquema de montagem sem alimentação de rede.

## Limitações e próximo incremento

Não prometer execução sem placa. Documentar modelo exato, tensão, pinos e comportamento esperado de cada novo experimento.

## Critérios de revisão

- [ ] O comportamento alterado está descrito com exemplo reproduzível.
- [ ] Há teste ou procedimento de validação compatível com o código real.
- [ ] Nenhuma chave, dado pessoal ou arquivo gerado foi incluído sem necessidade.
- [ ] A documentação distingue o implementado do planejado.
