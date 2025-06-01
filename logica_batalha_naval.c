#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularAtributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta carta1, Carta carta2, int opcao) {
    printf("\nComparação de cartas:\n");

    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nome, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d\n", carta2.nome, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            } else if (carta1.area < carta2.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            } else if (carta1.pib < carta2.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nome, carta1.estado, carta1.pontos_turisticos);
            printf("Carta 2 - %s (%s): %d\n", carta2.nome, carta2.estado, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade populacional
            printf("Atributo: Densidade Populacional\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.densidade_populacional);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    // Definindo duas cartas para comparação
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 699000000000, 10};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6000000, 1182.30, 362000000000, 8};

    // Calculando atributos das cartas
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Menu interativo
    int opcao;
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    // Comparar as cartas com base na escolha do usuário
    compararCartas(carta1, carta2, opcao);

    return 0;
}