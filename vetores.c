#include <stdio.h>

#define MAX_SIZE 50

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == valor)
            return meio;
        if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1; 
}

int removerElemento(int vetor[], int tamanho, int valor) {
    int posicao = buscaBinaria(vetor, tamanho, valor);
    if (posicao == -1) {
        printf("Elemento nao encontrado!\n");
        return tamanho;
    }

    for (int i = posicao; i < tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    printf("Elemento removido.\n");
    return tamanho - 1;
}

int inserirElemento(int vetor[], int tamanho, int valor) {
    if (tamanho >= MAX_SIZE) {
        printf("Capacidade maxima do vetor atingida.\n");
        return tamanho;
    }

    int i;
    for (i = tamanho - 1; (i >= 0 && vetor[i] > valor); i--) {
        vetor[i + 1] = vetor[i];
    }
    vetor[i + 1] = valor;
    printf("Elemento inserido.\n");
    return tamanho + 1;
}

int main() {
    int tamanho = 0, opcao;
    int vetor[MAX_SIZE];

    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > MAX_SIZE);

    printf("Insira os elementos do vetor (um por um):\n");
    for (int i = 0; i < tamanho; i++) {
        int valor;
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &valor);

        tamanho = inserirElemento(vetor, i, valor);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Imprimir vetor\n");
        printf("2. Consultar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Inserir elemento\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;
            case 2: {
                int valor;
                printf("Digite o elemento a ser consultado: ");
                scanf("%d", &valor);
                int posicao = buscaBinaria(vetor, tamanho, valor);
                if (posicao != -1)
                    printf("Elemento encontrado na posicao %d.\n", posicao);
                else
                    printf("Elemento nao encontrado.\n");
                break;
            }
            case 3: {
                int valor;
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &valor);
                tamanho = removerElemento(vetor, tamanho, valor);
                break;
            }
            case 4: {
                int valor;
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &valor);
                tamanho = inserirElemento(vetor, tamanho, valor);
                break;
            }
            case 5:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}