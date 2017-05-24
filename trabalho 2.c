#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereInicio (node *LISTA);
void exibe (node *LISTA);
void libera (node *LISTA);
void insere (node *LISTA);
void altera (node *LISTA);
void procura(node *LISTA);

int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
	}
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	tam=0;
}

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar agenda\n");
	printf("2. Exibir agenda\n");
	printf("3. Adicionar contato\n");
	printf("4. Alterar contato\n");
    printf("5. Procura contato\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *LISTA, int op)
{
	node *tmp;
	switch(op){
		case 0:
			libera(LISTA);
			break;

		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;

		case 2:
			exibe(LISTA);
			break;

		case 3:
			insereInicio(LISTA);
			break;

		case 4:
		    altera(LISTA);
			break;

		case 5:
		    procura(LISTA);
			break;
/*
		case 6:
			break;

		case 7:
			break;

		case 8:
			break;
*/
		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}

void insereInicio(node *LISTA)
{
	node *novo=aloca();
	node *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;

	tam++;
}

void exibe(node *LISTA)
{
	system("cls");
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tam ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tam ; count++)
		printf("%5d", count+1);


	printf("\n\n");
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}
void altera(node *LISTA)
{
int y;
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
printf("Qual contato deseja alterar:\n");
scanf("%d",&y);
      while (LISTA!= NULL && LISTA->num != y)
          LISTA = LISTA->prox;
      if (LISTA->num == y){
    printf("O contato a ser alterado e: %d\n",LISTA->num);
    /*printf("Novo email:\n");
    scanf("%s",LISTA->email);
    printf("Novo telefone:\n");
    scanf("%s",LISTA->telefone);*/
    printf("contato alterado com sucesso!");
      }
      else
    printf("contato nao encontrado!\n");
}

void procura(node *LISTA)
{
int y;
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
printf("Qual contato deseja procurar:\n");
scanf("%d",&y);
      while (LISTA!= NULL && LISTA->num != y)
          LISTA = LISTA->prox;
      if (LISTA->num == y)
    printf("O contato: %d\n",LISTA->num);
    /*printf("Email: %s",LISTA->email);
    printf("Telefone: %s",LISTA->telefone);*/
      else
    printf("contato nao encontrado!\n");
}
