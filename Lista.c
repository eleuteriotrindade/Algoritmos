#include <stdio.h>
#include <stdlib.h>

typedef struct bloco
{
	int item;
	struct bloco *proximo;
}B;

void inicia(B *lista);
int menu(void);
void opcao(B *lista, int op);
B *criaNo();
void insereFim(B *lista);
void insereInicio(B *lista);
void exibe(B *lista);
void libera(B *lista);

int main(){

	B *lista;
	lista = (B*)malloc(sizeof(B));


	return 0;
}

void inicia(B *lista)
{
	lista->proximo = NULL;
}

int menu()
{
	int opt;

	printf_s("Escolha a opcao\n");
	printf_s("0. Sair\n");
	printf_s("1. Exibir lista\n");
	printf_s("2. Adicionar node no inicio\n");
	printf_s("3. Adicionar node no final\n");
	printf_s("4. Zerar lista\n");
	printf_s("Opcao: ");
	scanf_s("%d", &opt);

	return opt;
}

void opcao(B *lista, int op)
{
	switch (op){
	case 0:
		libera(lista);
		break;

	case 1:
		exibe(lista);
		break;

	case 2:
		insereInicio(lista);
		break;

	case 3:
		insereFim(lista);
		break;

	case 4:
		inicia(lista);
		break;

	default:
		printf_s("Comando invalido\n\n");
	}
}

int vazia(B *lista)
{
	if (lista->proximo == NULL)
		return 1;
	else
		return 0;
}


void insereFim(B *lista)
{
	B *novo = (B *)malloc(sizeof(B));
	if (!novo){
		printf_s("Sem memoria disponivel!\n");
		exit(1);
	}
	printf_s("Novo elemento: "); scanf_s("%d", &novo->item);
	novo->proximo = NULL;

	if (vazia(lista))
		lista->proximo = novo;
	else{
		B *tmp = lista->proximo;

		while (tmp->proximo != NULL)
			tmp = tmp->proximo;

		tmp->proximo = novo;
	}
}

void insereInicio(B *lista)
{
	B *novo = (B *)malloc(sizeof(B));
	if (!novo){
		printf_s("Sem memoria disponivel!\n");
		exit(1);
	}
	printf_s("Novo elemento: "); scanf_s("%d", &novo->item);

	B *antigofn = lista->proximo;

	lista->proximo = novo;
	novo->proximo = antigofn;
}

void exibe(B *lista)
{
	if (vazia(lista)){
		printf_s("Lista vazia!\n\n");
		return;
	}

	B *tmp;
	tmp = lista->proximo;

	while (tmp != NULL){
		printf("%5d", tmp->item);
		tmp = tmp->proximo;
	}
	printf_s("\n\n");
}

void libera(B *lista)
{
	if (!vazia(lista)){
		B *proxNode,
			*atual;

		atual = lista->proximo;
		while (atual != NULL){
			proxNode = atual->proximo;
			free(atual);
			atual = proxNode;
		}
	}
}