#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "list.h"

#define randint(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

int main() {
    ListaEncadeada* lista = criar_lista();

    printf("A lista esta vazia?: %s\n", esta_vazia(lista) ? "Sim" : "Nao");

    for (int i = 1; i <= randint(0, 100); i++) {
        inserir(lista, i, randint(0, 100));
    }

    printf("Tamanho: %d\n", tamanho(lista));

    printf("%d\n", obter(lista, 2));
    modificar(lista, randint(0, 100), 7);
    imprimir(lista);
    printf("%d\n", obter(lista, 2));

    printf("%d\n", retirar(lista, 2));
    printf("Tamanho: %d\n", tamanho(lista));

    imprimir(lista);

    return 0;
}