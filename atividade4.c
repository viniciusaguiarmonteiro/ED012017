#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int fila[10];
int i;
int aux;
int x;
int frente=0;
int end=0;

int filafull();
int filaemp();
void in(int x);
int out();

int main()
{
	do
	{
	   printf("\nInsira um valor: ");
	   scanf("%d", &x);
	   in(x);
	}while(end<MAX);

	x=end;

	for(i=0;i<x;i++)
	{
		printf("\n%d valor desenfileirado: %d",i+1,out());
	}

	return 0;
}

int filafull()
{
	return (end==MAX);
}

int filaemp()
{
	return(frente==end);
}

void in(int x)
{
	if(! filafull())
	{
		fila[end++]=x;
	}

	else
	{
		printf("\nFILA CHEIA");
	}
}

int out()
{
	if(! filaemp())
	{
		aux=fila[frente];
		frente++;
		return aux;
	}

	else
	{
		printf("\nFILA VAZIA");
	}

}
