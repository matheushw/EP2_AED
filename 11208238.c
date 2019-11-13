#include "filapreferencial.h"

PFILA criarFila(){
    PFILA res = (PFILA) malloc(sizeof(FILAPREFERENCIAL));
    res->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    res->inicioNaoPref = res->cabeca;
    res->cabeca->id = -1;
    res->cabeca->idade = -1;
    res->cabeca->ant = res->cabeca;
    res->cabeca->prox = res->cabeca;
    return res;
}

int tamanho(PFILA f){
	PONT atual = f->cabeca->prox;
	int tam = 0;
	while (atual != f->cabeca) {
		atual = atual->prox;
		tam++;
	}
	return tam;
}

PONT buscarID(PFILA f, int id){
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		if (atual->id == id) return atual;
		atual = atual->prox;
	}
	return NULL;
}

void exibirLog(PFILA f){
	int numElementos = tamanho(f);
	printf("\nLog fila [elementos: %i]\t- Inicio:", numElementos);
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		printf(" [%i;%i]", atual->id, atual->idade);
		atual = atual->prox;
	}
	printf("\n                       \t-    Fim:");
	atual = f->cabeca->ant;
	while (atual != f->cabeca) {
		printf(" [%i;%i]", atual->id, atual->idade);
		atual = atual->ant;
	}
	printf("\n\n");
}


int consultarIdade(PFILA f, int id){
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		if (atual->id == id) return atual->idade;
		atual = atual->prox;
	}
	return -1;
}



bool inserirPessoaNaFila(PFILA f, int id, int idade){




	return false;
}

bool atenderPrimeiraDaFila(PFILA f, int* id){
	PONT aux;
	if (tamanho(f) == 0) {
		return false;
	} else if (f->cabeca->ant == f->cabeca->prox) {
		id = f->cabeca->prox->id;  
		f->inicioNaoPref = f->cabeca;
		f->cabeca->id = -1;
		f->cabeca->idade = -1;    
		f->cabeca->ant = f->cabeca;    
		f->cabeca->prox = f->cabeca; 
	} else {
		if (f->inicioNaoPref == f->cabeca->prox) f->inicioNaoPref = f->cabeca->prox->prox; 
		aux = f->cabeca->prox;
		f->cabeca->prox = f->cabeca->prox->prox;
		f->cabeca->prox->ant = aux->ant;
		free(aux);
	} 
	return true;
}


bool desistirDaFila(PFILA f, int id){



	return false;
}
