#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista {
	ListaNo* prim;
};

struct listano {
char name[100];
char email[100];
char phone[15];
ListaNo* prox;
};

Lista* lst_cria (void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

void lst_insere (Lista* l,ListaNo listano){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    printf("nome:  \n");
    scanf("%s",listano.name);
    printf("email:  \n");
    scanf("%s",listano.email);
    printf("telefone:  \n");
    scanf("%s",listano.phone);
    novo->name;
    novo->email;
    novo->phone;
    l->prim = novo;
}
int main (void){
Lista* l = lst_cria();
lst_insere(l, listano);
return 0;
}
