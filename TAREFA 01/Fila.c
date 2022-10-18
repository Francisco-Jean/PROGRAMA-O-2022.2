#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

struct fila {
  int tamanho;
  int capacidade_maxima;
  Aluno *fila_alunos;
};

/* Aloca espaço em memória e retorna uma fila */
Fila *fila_cria() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->fila_alunos = (Aluno *)malloc(CAPACIDADE_INICIAL * sizeof(Aluno *));
  fila->capacidade_maxima = CAPACIDADE_INICIAL;
  fila->tamanho = 0;
  return fila;
}

/* Libera a memória de uma fila previamente criada e atribui NULL ao ponteiro
 * fila */
int fila_libera(Fila **fila) {
  if (fila != NULL) {
    if ((*fila)->tamanho > 0) {
      free((*fila)->fila_alunos);
      (*fila)->fila_alunos = NULL;
    }
    free(*fila);
    *fila = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na fila. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a fila ou aluno sejam NULL
 */
int fila_insere(Fila *fila, Aluno *aluno) {
  if (fila == NULL || aluno == NULL) {
      return -1;
    }
  int matricula;
  char nome[50];
  char curso[30];
  
  int matricula2;
  char nome2[50];
  char curso2[30];
  alu_acessa(aluno,&matricula,nome,curso);
  
  for (int a = 0; a < fila->tamanho; a++) {
    alu_acessa((&(fila->fila_alunos))[a],&matricula2,nome2,curso2);
    if(matricula2 == matricula){
      return 0;
    }
  }
  (&(fila->fila_alunos))[fila->tamanho] = aluno;
  fila->tamanho++;
  return 1;
}

/* Remove um aluno na fila. Retorna o aluno ou NULL caso a fila esteja vazia ou
 * seja NULL */
Aluno *fila_retira(Fila *fila) {
  if (fila == NULL || fila->tamanho == 0){
    return NULL;
  }
  Aluno *aln = fila->fila_alunos;
  for(int x = 1; x < fila->tamanho; x++){
    (&(fila->fila_alunos))[x-1] = (&(fila->fila_alunos))[x];
  }
  fila->tamanho--;
  (&(fila->fila_alunos))[fila->tamanho] = NULL;
    return aln;
  }

/* Recupera o primeiro aluno da fila. Retorna o aluno ou NULL caso a fila esteja
 * vazia ou seja NULL */
Aluno *fila_primeiro(Fila *fila) {
  if (fila == NULL || fila->tamanho == 0) {
    return NULL;
  }
  return (&(fila->fila_alunos))[0];
}


/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) fila vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a fila seja NULL */
Aluno *fila_busca(Fila *fila, int matricula) {
  int matricula1;
  char nome[50];
  char curso[30];
  if (fila != NULL) {
    for (int x = 0; x < fila->tamanho; x++) {
      alu_acessa((&(fila->fila_alunos))[x], &matricula1, nome, curso);
      if (matricula1 == matricula) {
        return (&(fila->fila_alunos))[x];
      }
    }
  }
  return NULL;
}

/* Verifica se a fila está vazia. Retorna 1 se a fila estiver vazia, 0 caso não
 * esteja vazia e -1 se a fila for NULL
 */
int fila_vazia(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }
  if (fila->tamanho == 0) {
    return 1;
  }
  return 0;
}

/* Computa a quantidade de alunos alunos na fila. Retorna a quantidade de alunos
 * ou -1, caso a fila for NULL.
 */
int fila_quantidade(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }
  return fila->tamanho;
}