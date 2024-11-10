#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 10000
#define MAX_LINHA 256
#define TABLE_SIZE 1000

// Função hash usando o método da dobra
int hash_dobra(int chave) {
    int parte1 = chave / 1000;      // Pega os 3 primeiros dígitos
    int parte2 = chave % 1000;      // Pega os 3 últimos dígitos
    int hash = (parte1 + parte2) % TABLE_SIZE; // Soma as partes e aplica módulo
    return hash;
}

int main() {
    FILE *arquivo = fopen("chaves.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[MAX_LINHA];
    int numero;
    int colisoes[TABLE_SIZE] = {0};
    int total_colisoes = 0;

    // Lê cada linha do arquivo e calcula o hash
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numero = atoi(linha); // Converte a linha em um número inteiro

        int hash_index = hash_dobra(numero); // Aplica a função hash
        if (colisoes[hash_index] > 0) {
            total_colisoes++; // Conta colisão se o índice já está ocupado
        }
        colisoes[hash_index]++; // Incrementa o contador de colisões
    }

    printf("Total de colisoes: %d\n", total_colisoes);

    fclose(arquivo);
    return 0;
}

