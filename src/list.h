#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* primeiro_no;
} ListaEncadeada;

ListaEncadeada* criar_lista();
int esta_vazia(ListaEncadeada* lista);
int tamanho(ListaEncadeada* lista);
int obter(ListaEncadeada* lista, int posicao);
int modificar(ListaEncadeada* lista, int posicao, int valor);
int inserir(ListaEncadeada* lista, int posicao, int valor);
int retirar(ListaEncadeada* lista, int posicao);
void imprimir(ListaEncadeada* lista);

#endif /* LISTA_ENCADEADA_H */


