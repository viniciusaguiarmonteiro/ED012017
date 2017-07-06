#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int num;
	struct No *prox;
} pilha;

void push(pilha **p, int elemento);

int main()
{

	int x=1, e;

	pilha **p = NULL;
	while (x == 1)
	{
		printf("Insira o numero: ");
	    scanf("%d", &e);
	    push(&p, e);
	    printf("Deseja inseir um novo numero, digite 1\n");
	    scanf("%d", &x);
	}

	pilha *aux;

	aux = p;

	while(aux != NULL)
    {
	   printf("\nValor da pilha : %d\n", aux->num);
	   aux = aux->prox;
    }
}

void push(pilha **p, int elemento)
{

    pilha *novo = (pilha*) malloc(sizeof(pilha));
    if(novo == NULL)
    {
        printf("ERRO DE ALOCACAO");
        exit(1);
    }
    novo->num = elemento;

    if(*p == NULL)
    {
        novo->prox = NULL;
        *p= novo;
    }

    else
    {
        novo->prox = *p; 
        *p = novo;
    }
}
