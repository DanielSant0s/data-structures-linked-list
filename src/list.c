#include <stdio.h>
#include <stdlib.h>

#include "list.h"

No* criar_no(int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

ListaEncadeada* criar_lista() {
    ListaEncadeada* lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    lista->primeiro_no = NULL;
    return lista;
}

int esta_vazia(ListaEncadeada* lista) {
    return lista->primeiro_no == NULL;
}

int tamanho(ListaEncadeada* lista) {
    int contador = 0;
    No* no_atual = lista->primeiro_no;
    while (no_atual != NULL) {
        contador++;
        no_atual = no_atual->proximo;
    }
    return contador;
}

int obter(ListaEncadeada* lista, int posicao) {
    if (posicao < 1 || posicao > tamanho(lista)) {
        return -1; // Indicate invalid position or empty list
    }
    int contador = 1;
    No* no_atual = lista->primeiro_no;
    while (contador < posicao) {
        no_atual = no_atual->proximo;
        contador++;
    }
    return no_atual->valor;
}

int modificar(ListaEncadeada* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho(lista)) {
        return 0; // Indicate failure
    }
    int contador = 1;
    No* no_atual = lista->primeiro_no;
    while (contador < posicao) {
        no_atual = no_atual->proximo;
        contador++;
    }
    no_atual->valor = valor;
    return 1; // Indicate success
}

int inserir(ListaEncadeada* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho(lista) + 1) {
        return 0; // Indicate failure
    }
    No* novo_no = criar_no(valor);
    if (posicao == 1) {
        novo_no->proximo = lista->primeiro_no;
        lista->primeiro_no = novo_no;
    } else {
        int contador = 1;
        No* no_atual = lista->primeiro_no;
        while (contador < posicao - 1) {
            no_atual = no_atual->proximo;
            contador++;
        }
        novo_no->proximo = no_atual->proximo;
        no_atual->proximo = novo_no;
    }
    return 1; // Indicate success
}

int retirar(ListaEncadeada* lista, int posicao) {
    if (posicao < 1 || posicao > tamanho(lista)) {
        return -1; // Indicate invalid position or empty list
    }
    int valor;
    if (posicao == 1) {
        No* no_removido = lista->primeiro_no;
        valor = no_removido->valor;
        lista->primeiro_no = no_removido->proximo;
        free(no_removido);
    } else {
        int contador = 1;
        No* no_atual = lista->primeiro_no;
        while (contador < posicao - 1) {
            no_atual = no_atual->proximo;
            contador++;
        }
        No* no_removido = no_atual->proximo;
        valor = no_removido->valor;
        no_atual->proximo = no_removido->proximo;
        free(no_removido);
    }
    return valor;
}

void imprimir(ListaEncadeada* lista) {
    No* no_atual = lista->primeiro_no;
    while (no_atual != NULL) {
        printf("%d ", no_atual->valor);
        no_atual = no_atual->proximo;
    }
}