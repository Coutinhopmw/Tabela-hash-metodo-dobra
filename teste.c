#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 1000

int main() {
    
    FILE *arquivo = fopen("chaves.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numero;
    int colisoes = 0;         // Inicializando o contador de colisões
    int numAlocados[MAX_NUMEROS] = {0}; // Inicializa o array com zeros
    int i;

    // Lendo números do arquivo
    while (fscanf(arquivo, "%d", &numero) != EOF) {
        // Exemplo de tratamento para colisões (aqui você pode personalizar conforme necessário)
        // Vamos usar um método simples de verificação de colisões
        int index = numero % MAX_NUMEROS; // Usando módulo para determinar o índice

        // Verificando se já existe um número alocado nesse índice
        if (numAlocados[index] != 0) {
            colisoes++; // Incrementa o contador de colisões
        }
        
        // Alocando o número no array
        numAlocados[index] = numero; // Aloca o número no índice correspondente
        printf("%d\n", numero);
    }

    // Fechando o arquivo
    fclose(arquivo);

    // Imprimindo o número de colisões
    printf("Colosoes: %d\n", colisoes);

    return 0;
}
