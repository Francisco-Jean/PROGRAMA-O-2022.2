#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

struct node {
  Aluno *aluno;
  struct node *proximo;
};

typedef struct node No;

struct pilha {
  No *primeiro;
};

/* Aloca espaço em memória e retorna uma pilha. */
Pilha *pilha_cria() {
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->primeiro = NULL;
  return pilha;
}

/* Libera a memória de uma pilha previamente criada e atribui NULL ao ponteiro
 * pilha. Retorna 1 caso seja possível fazer a liberação e 0 caso a pilha
 * informada seja NULL. */
int pilha_libera(Pilha **pilha) {
  if (pilha != NULL) {
    if ((*pilha)->primeiro != NULL) {
      No *aux = (*pilha)->primeiro;
      do {
        alu_libera(&aux->aluno);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*pilha);
    *pilha = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na Pilha. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a pilha ou aluno sejam NULL.
 */
int pilha_push(Pilha *pilha, Aluno *aluno) {
  if(pilha == NULL || aluno == NULL){
    return -1;
  }
  int matricula_aluno;
  int matricula_compara;
  char nome[50];
  char curso[30];
  alu_acessa(aluno, &matricula_aluno, nome, curso);
  
  No *no_aux = pilha->primeiro;
  No *anterior = no_aux;
  if(pilha->primeiro == NULL){
    No * novo_no = (No*)malloc(sizeof(No));
    novo_no->aluno = aluno;
    novo_no->proximo = NULL;
    No ** aux = &(pilha->primeiro);
    *aux = novo_no;
    return 1;
  }
  while(no_aux != NULL){
      alu_acessa(no_aux->aluno,&matricula_compara, nome, curso);
    if(matricula_aluno == matricula_compara){
      return 0;
    }
    anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  No * novo_no = (No*)malloc(sizeof(No));
  novo_no->aluno = aluno;
  novo_no->proximo = NULL;

  No ** aux = &(anterior->proximo);
  *aux = novo_no;
  return 1;
}

/* Remove um aluno na pilha. Retorna o aluno ou NULL caso a pilha esteja vazia
 * ou seja NULL. */
Aluno *pilha_pop(Pilha *pilha) {
  if(pilha == NULL || pilha->primeiro == NULL){
    return NULL;
  }
  No *no_aux = pilha->primeiro;
  No *anterior = no_aux;
  No *anterior2 = no_aux;
  while(no_aux != NULL){
    anterior2 = anterior;
    anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  anterior2->proximo = NULL;
  return anterior->aluno;
}

/* Recupera o primeiro aluno da pilha. Retorna o aluno ou NULL caso a pilha
 * esteja vazia ou seja NULL. */
Aluno *pilha_top(Pilha *pilha){
    if(pilha == NULL || pilha->primeiro == NULL){
    return NULL;
  }
  No *no_aux = pilha->primeiro;
  No *anterior = no_aux;
  while(no_aux != NULL){
    anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  return anterior->aluno;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) pilha vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a pilha seja NULL */
Aluno *pilha_busca(Pilha *pilha, int matricula) {
  if(pilha == NULL || pilha->primeiro == NULL){
    return NULL;
  }

  int matricula_aux;
  char nome[50];
  char curso[30];
  No * no_aux = pilha->primeiro;
  while(no_aux != NULL){

    alu_acessa(no_aux->aluno, &matricula_aux, nome,curso);
    if(matricula == matricula_aux){
      return no_aux->aluno;
    }
    no_aux = no_aux->proximo;
  }
  return NULL;
}

/* Verifica se a pilha está vazia. Retorna 1 se a pilha estiver vazia, 0 caso
 * não esteja vazia e -1 se p Pilha for NULL
 */
int pilha_vazia(Pilha *pilha) {
  if (pilha == NULL) {
    return -1;
  }
  if (pilha->primeiro == NULL) {
    return 1;
  }
  return 0;
}

/* Computa a quantidade de alunos na pilha. Retorna a quantidade de alunos
 * ou -1, caso a Pilha for NULL.
 */
int pilha_quantidade(Pilha *pilha) {
  if(pilha == NULL){
    return -1;
  }
  No * aux = pilha->primeiro;
  int total = 0;
  while(aux != NULL){
    total ++;
  }
  return total;
}