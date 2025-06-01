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

// Função para exibir o menu de atributos
int exibirMenu(int atributoEscolhido) {
    printf("\nEscolha um atributo para comparação:\n");
    if (atributoEscolhido != 1) printf("1 - População\n");
    if (atributoEscolhido != 2) printf("2 - Área\n");
    if (atributoEscolhido != 3) printf("3 - PIB\n");
    if (atributoEscolhido != 4) printf("4 - Pontos Turísticos\n");
    if (atributoEscolhido != 5) printf("5 - Densidade Populacional\n");
    printf("Digite sua escolha: ");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

// Função para comparar dois atributos
float compararAtributo(Carta carta1, Carta carta2, int atributo) {
    switch (atributo) {
        case 1: // População
            printf("População - Carta 1: %d, Carta 2: %d\n", carta1.populacao, carta2.populacao);
            return carta1.populacao - carta2.populacao;
        case 2: // Área
            printf("Área - Carta 1: %.2f, Carta 2: %.2f\n", carta1.area, carta2.area);
            return carta1.area - carta2.area;
        case 3: // PIB
            printf("PIB - Carta 1: %.2f, Carta 2: %.2f\n", carta1.pib, carta2.pib);
            return carta1.pib - carta2.pib;
        case 4: // Pontos Turísticos
            printf("Pontos Turísticos - Carta 1: %d, Carta 2: %d\n", carta1.pontos_turisticos, carta2.pontos_turisticos);
            return carta1.pontos_turisticos - carta2.pontos_turisticos;
        case 5: // Densidade Populacional
            printf("Densidade Populacional - Carta 1: %.2f, Carta 2: %.2f\n", carta1.densidade_populacional, carta2.densidade_populacional);
            return carta2.densidade_populacional - carta1.densidade_populacional; // Menor valor vence
        default:
            printf("Atributo inválido!\n");
            return 0;
    }
}

int main() {
    // Definindo duas cartas para comparação
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 699000000000, 10};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6000000, 1182.30, 362000000000, 8};

    // Calculando atributos das cartas
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Escolha dos atributos
    int atributo1 = exibirMenu(0);
    int atributo2 = exibirMenu(atributo1);

    // Comparação dos atributos
    printf("\nComparando os atributos escolhidos:\n");
    float resultado1 = compararAtributo(carta1, carta2, atributo1);
    float resultado2 = compararAtributo(carta1, carta2, atributo2);

    // Soma dos valores dos atributos
    float somaCarta1 = (atributo1 == 1 ? carta1.populacao : atributo1 == 2 ? carta1.area : atributo1 == 3 ? carta1.pib : atributo1 == 4 ? carta1.pontos_turisticos : carta1.densidade_populacional) +
                       (atributo2 == 1 ? carta1.populacao : atributo2 == 2 ? carta1.area : atributo2 == 3 ? carta1.pib : atributo2 == 4 ? carta1.pontos_turisticos : carta1.densidade_populacional);
    float somaCarta2 = (atributo1 == 1 ? carta2.populacao : atributo1 == 2 ? carta2.area : atributo1 == 3 ? carta2.pib : atributo1 == 4 ? carta2.pontos_turisticos : carta2.densidade_populacional) +
                       (atributo2 == 1 ? carta2.populacao : atributo2 == 2 ? carta2.area : atributo2 == 3 ? carta2.pib : atributo2 == 4 ? carta2.pontos_turisticos : carta2.densidade_populacional);

    // Determinação do vencedor
    printf("\nSoma dos atributos:\n");
    printf("Carta 1 (%s): %.2f\n", carta1.nome, somaCarta1);
    printf("Carta 2 (%s): %.2f\n", carta2.nome, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (somaCarta1 < somaCarta2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}