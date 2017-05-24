#include <stdio.h>
#include <stdlib.h>

struct Node{
	int nome;
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
	printf("Opcao: ");
	scanf("%d", &opt);

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
		printf("Novo elemento: "); scanf("%d", &novo->nome);
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
/*void ordenar(lista **l) {

    if(*l == NULL || (*l)->prox == NULL) return; //se for nulo(vazio), ou apenas 1 elemento
    lista *aux = *l, *t;
    char s[100]; //precisa de espacao suficiente para armazenar o nome

    while(aux != NULL) {
      t = aux->prox;
      while(t != NULL) {
        if(strcmp(aux->nome, t->nome) > 0) { //se vir depois
            strcpy(s, aux->nome);
            strcpy(aux->nome, t->nome);
            strcpy(t->nome, s);
        }
        t = t->prox;
      }
      aux = aux->prox;
    }
}*/
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->nome);
		tmp = tmp->prox;
	}
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
system("cls");
int y;
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
    printf("Qual contato deseja alterar:");
    scanf("%d",&y);
        while (LISTA!= NULL && LISTA->nome != y)
        LISTA = LISTA->prox;
            if (LISTA->nome == y){
            printf("O contato a ser alterado e: %d\n",LISTA->nome);
            /*printf("Novo email:\n");
            scanf("%s",LISTA->email);
            printf("Novo telefone:\n");
            scanf("%s",LISTA->telefone);*/
            printf("contato alterado com sucesso!");
            }
            else printf("contato nao encontrado!\n");
}

void procura(node *LISTA)
{
system("cls");
int y;
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
printf("Qual contato deseja procurar:\n");
scanf("%d",&y);
      while (LISTA!= NULL && LISTA->nome != y)
          LISTA = LISTA->prox;
      if (LISTA->nome == y)
    printf("O contato: %d\n",LISTA->nome);
    /*printf("Email: %s",LISTA->email);
    printf("Telefone: %s",LISTA->telefone);*/
      else
    printf("contato nao encontrado!\n");
    return ;
}
