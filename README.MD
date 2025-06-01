# Super Trunfo - Comparação de Cartas

Este projeto implementa a lógica de comparação de cartas do jogo Super Trunfo, com base em atributos numéricos como população, área, PIB, densidade populacional e PIB per capita.

## Funcionalidades

- Cadastro de cartas com os seguintes atributos:
  - Estado
  - Código da carta
  - Nome da cidade
  - População
  - Área
  - PIB
  - Número de pontos turísticos
- Cálculo automático de:
  - Densidade populacional (População / Área)
  - PIB per capita (PIB / População)
- Comparação de duas cartas com base em um atributo pré-definido no código.
- Determinação da carta vencedora com base nas regras:
  - Para todos os atributos, exceto densidade populacional, vence a carta com o maior valor.
  - Para densidade populacional, vence a carta com o menor valor.

## Como executar

1. Clone o repositório:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DO_REPOSITORIO>