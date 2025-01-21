#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Cidade;

// Função para calcular densidade populacional
float calcular_densidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return pib / populacao;
}

// Função para exibir os dados de uma cidade
void exibir_cidade(Cidade cidade) {
    printf("\nEstado: %c\n", cidade.estado);
    printf("Código da Carta: %s\n", cidade.codigo);
    printf("Nome da Cidade: %s\n", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões de reais\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidade_populacional);
    printf("PIB per Capita: %.2f mil reais\n", cidade.pib_per_capita);
}

int main() {
    Cidade cidades[NUM_ESTADOS * CIDADES_POR_ESTADO];
    int total_cidades = 0;

    printf("Cadastro de Cidades\n\n");

    // Loop para cadastrar as cidades
    for (char estado = 'A'; estado < 'A' + NUM_ESTADOS; estado++) {
        for (int i = 1; i <= CIDADES_POR_ESTADO; i++) {
            Cidade cidade;
            cidade.estado = estado;
            sprintf(cidade.codigo, "%c%02d", estado, i); // Gera o código da carta automaticamente

            printf("Cadastro da cidade %s:\n", cidade.codigo);

            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]", cidade.nome);

            printf("Digite a população: ");
            scanf("%d", &cidade.populacao);

            printf("Digite a área em km²: ");
            scanf("%f", &cidade.area);

            printf("Digite o PIB em bilhões de reais: ");
            scanf("%f", &cidade.pib);

            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &cidade.pontos_turisticos);

            // Calcula propriedades derivadas
            cidade.densidade_populacional = calcular_densidade(cidade.populacao, cidade.area);
            cidade.pib_per_capita = calcular_pib_per_capita(cidade.pib, cidade.populacao);

            // Armazena a cidade no array
            cidades[total_cidades++] = cidade;

            // Exibe os dados cadastrados
            printf("\nDados cadastrados:\n");
            exibir_cidade(cidade);
            printf("\n");
        }
    }

    printf("\nCadastro finalizado. Total de cidades cadastradas: %d\n", total_cidades);

    return 0;
}
