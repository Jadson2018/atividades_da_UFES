#ifndef __AVL_H__
#define __AVL_H__
#include<stdio.h>
#include<stdlib.h>
//Grupo:Jadson Costa de Amorim e João Pedro Souza Andrade
//estrutura da arvore AVL
typedef struct no{
	void* info;
	int bal;
	struct no *esquerdo, *direito;
}No;

//FUNÇÕES IMPLEMENTADAS//

//Inicio do nó
//recebe uma chave que será adicionada ao novo nó criado
//o retorno é a nova chave
No *inicioNo(void *chave);

//função que trata a rotação à direita
// recebe o ponteiro para a árvore e um ponteiro para inteiro que é tratado como booleano
//o retorno é a árvore rotacionada à direita
No *caso1(No *v, int *h);

//função que trata a rotação à esquerda
// recebe o ponteiro para a árvore e um ponteiro para inteiro que é tratado como booleano
//o retorno é a árvore rotacionada à esquerda
No *caso2(No *v, int *h);

//função que isere de forma balanceada os nós da árvore
// recebe o ponteiro para a árvore, o ponteiro para inteiro, a chave do nó que será feita a inserção e as funções de comparação de igualdade e maior ou menor para o tipo 
//de dado da chave
//o retorno é a árvore balanceada com o novo nó
No *insereAVL(No *v, int *h, void *x, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//função para imprimir a árvore
// recebe o ponteiro para a árvore o nível que deverá ser o valor 1 e uma função para imprimir o tipo de dado da chave
//é um procedimento e apenas imprime
void imprimeArvore(No *T, int nivel, void (*imprimir)(void*));

//função que busca um nó na árvore com uma determinada chave passada como parâmetro
//recebe um ponteiro para a árvore, um ponteiro que apontará para o pai do nó encontrado
//a chave a ser procurada, a função de comparação de chaves para o tipo de dado da chave e a que verifica se é maior ou menor
//retorna o nó buscado
No *busca(No *T, No **pai, void *ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//verifica qual o sucessor de um nó da árvore
//recebe o ponteiro para a árvore e um ponteiro que aponta para o pai desse nó
//retorna o nó sucessor
No *sucessor(No *P, No **paiP);

//função que remove um nó da árvore de acordo com uma chave
//recebe, o ponteiro para a árvore, a chave e as funções que são passadas como parâmetro da função busca
//retorna a árvore com um nó removido
No *removeChave(No *T, void *ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//função que busca um nó da árvore de acordo com uma chave, basicamente o que faz a função busca porém não é usada na função de remoção
//foi implementada como alternativa a busca por não precisar de um ponteiro para o pai e por isso ser melhor para ser usada externamente
//recebe um ponteiro para o nó, a chave a ser buscada e as funções que verificam se duas chaves são iguais maiores ou menores implementadas para o tipo de dado da chave
//retorna o nó buscado
No *buscaChave(No *T, void *ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//função que verifica se a árvore é vazia
//recebe o ponteiro para a árvore
//retorna 
int arvoreVazia(No *A);

//função que esvazia a árvore
//recebe o ponteiro para a árvore
//retorna a árvore vazia
No *liberarArvore(No *A);

//FUNÇÕES QUE PRECISAM SER IMPLEMENTADAS//
//imprime de acordo com o tipo de dado definido pela chave
//recebe a chave do nó
//imprime o tipo de dado definido
void imprimir(void* info);

//compara se uma chave é igual a outra de acordo com o tipo definido
//recebe duas chaves
//retorna 1 para verdadeiro e 0 para falso
int comparaChave(void* info, void* ch);

//compara se a primeira chave é maior que a segunda
//recebe uma chave do nó analisado e uma chave a ser comparada
//retorna 1 caso seja maior e 0 caso menor
int e_maior(void* info, void* ch);

#endif
