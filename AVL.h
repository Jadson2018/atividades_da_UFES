#ifndef __AVL_H__
#define __AVL_H__
#include<stdio.h>
#include<stdlib.h>
//Grupo:Jadson Costa de Amorim e Jo�o Pedro Souza Andrade
//estrutura da arvore AVL
typedef struct no{
	void* info;
	int bal;
	struct no *esquerdo, *direito;
}No;

//FUN��ES IMPLEMENTADAS//

//Inicio do n�
//recebe uma chave que ser� adicionada ao novo n� criado
//o retorno � a nova chave
No *inicioNo(void *chave);

//fun��o que trata a rota��o � direita
// recebe o ponteiro para a �rvore e um ponteiro para inteiro que � tratado como booleano
//o retorno � a �rvore rotacionada � direita
No *caso1(No *v, int *h);

//fun��o que trata a rota��o � esquerda
// recebe o ponteiro para a �rvore e um ponteiro para inteiro que � tratado como booleano
//o retorno � a �rvore rotacionada � esquerda
No *caso2(No *v, int *h);

//fun��o que isere de forma balanceada os n�s da �rvore
// recebe o ponteiro para a �rvore, o ponteiro para inteiro, a chave do n� que ser� feita a inser��o e as fun��es de compara��o de igualdade e maior ou menor para o tipo 
//de dado da chave
//o retorno � a �rvore balanceada com o novo n�
No *insereAVL(No *v, int *h, void *x, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//fun��o para imprimir a �rvore
// recebe o ponteiro para a �rvore o n�vel que dever� ser o valor 1 e uma fun��o para imprimir o tipo de dado da chave
//� um procedimento e apenas imprime
void imprimeArvore(No *T, int nivel, void (*imprimir)(void*));

//fun��o que busca um n� na �rvore com uma determinada chave passada como par�metro
//recebe um ponteiro para a �rvore, um ponteiro que apontar� para o pai do n� encontrado
//a chave a ser procurada, a fun��o de compara��o de chaves para o tipo de dado da chave e a que verifica se � maior ou menor
//retorna o n� buscado
No *busca(No *T, No **pai, void *ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//verifica qual o sucessor de um n� da �rvore
//recebe o ponteiro para a �rvore e um ponteiro que aponta para o pai desse n�
//retorna o n� sucessor
No *sucessor(No *P, No **paiP);

//fun��o que remove um n� da �rvore de acordo com uma chave
//recebe, o ponteiro para a �rvore, a chave e as fun��es que s�o passadas como par�metro da fun��o busca
//retorna a �rvore com um n� removido
No *removeChave(No *T, void *ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//fun��o que busca um n� da �rvore de acordo com uma chave, basicamente o que faz a fun��o busca por�m n�o � usada na fun��o de remo��o
//foi implementada como alternativa a busca por n�o precisar de um ponteiro para o pai e por isso ser melhor para ser usada externamente
//recebe um ponteiro para o n�, a chave a ser buscada e as fun��es que verificam se duas chaves s�o iguais maiores ou menores implementadas para o tipo de dado da chave
//retorna o n� buscado
No *buscaChave(No *T, void *ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*));

//fun��o que verifica se a �rvore � vazia
//recebe o ponteiro para a �rvore
//retorna 
int arvoreVazia(No *A);

//fun��o que esvazia a �rvore
//recebe o ponteiro para a �rvore
//retorna a �rvore vazia
No *liberarArvore(No *A);

//FUN��ES QUE PRECISAM SER IMPLEMENTADAS//
//imprime de acordo com o tipo de dado definido pela chave
//recebe a chave do n�
//imprime o tipo de dado definido
void imprimir(void* info);

//compara se uma chave � igual a outra de acordo com o tipo definido
//recebe duas chaves
//retorna 1 para verdadeiro e 0 para falso
int comparaChave(void* info, void* ch);

//compara se a primeira chave � maior que a segunda
//recebe uma chave do n� analisado e uma chave a ser comparada
//retorna 1 caso seja maior e 0 caso menor
int e_maior(void* info, void* ch);

#endif
