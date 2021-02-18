#include<stdio.h>
#include<stdlib.h>
#include"DinamicaOrdenada.h"

void menu(){
    printf("1- Inserir\n");
    printf("2- Remover\n");
    printf("3- Imprimir\n");
    printf("4- Remover pares\n");
    printf("5- Menor\n");
    printf("6- Tamanho\n");
    printf("7- Iguais\n");
    printf("8- Intercala\n");
}

struct no{
    int info;
    struct no * prox;
};

Lista cria_lista() {
    return NULL;
}


int lista_vazia(Lista lst) {
    if (lst == NULL) return 1;

    else return 0;
}

int insere_ord (Lista *lst, int elem) {

    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) { return 0; }
    N->info = elem;
    if (lista_vazia(*lst) || elem <= (*lst)->info) {
        N->prox = *lst;
        *lst = N;
        return 1;
    }

    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info < elem)aux = aux->prox;

    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ord (Lista *lst, int elem) {
    if (lista_vazia(*lst) == 1 || elem < (*lst)->info) return 0;

    Lista aux = *lst;

    if (elem == (*lst)->info) {
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info < elem) aux = aux->prox;
    if (aux->prox == NULL || aux->prox->info > elem) return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}


int imprimir(Lista lst){

    Lista Aux;
    Aux=lst;
    if(lista_vazia(lst)==1) return 0;

    while(Aux!=NULL){
        printf("%d ", Aux->info);
        Aux=Aux->prox;
    }
    printf("\n");

    return 1;
}

int removerImpares(Lista *lst){

    Lista Aux=*lst;
    Lista Aux2;
    if(lista_vazia(*lst)==1) return 0;

    while((*lst)->info%2!=0){
        Aux2=(*lst);
        (*lst)=Aux2->prox;
        free(Aux2);
    }

    while(Aux!=NULL){
        if(Aux->prox->info%2!=0){
            Aux2=Aux->prox;
            Aux->prox=Aux2->prox;
            free(Aux2);
        }
        Aux=Aux->prox;
    }
    return 1;
}

int menor(Lista lst){
    if(lista_vazia(lst)==1) return 0;

    int num;
    num=lst->info;

    return num;
}


int tamanho(Lista lst){

    int cont=0;
    Lista Aux=lst;

    if(lista_vazia(lst)==1) return 0;

    while(Aux!=NULL){
        cont++;
        Aux=Aux->prox;
    }
    return cont;

}

int Iguais(Lista lst1, Lista lst2){
    Lista Aux1=lst1;
    Lista Aux2=lst2;
    int cont=0;

    if(lista_vazia(lst1)==1 || lista_vazia(lst2)==1){
        printf("S�o iguais\n");
        return 1;
    }

    if(tamanho(lst1)!= tamanho(lst2)){
        printf("N�o s�o iguais\n");
        return 0;
    }
    while(Aux1!=NULL && Aux2!= NULL){
        if(Aux1->info==Aux2->info){
            cont++;
        }
        Aux1=Aux1->prox;
        Aux2=Aux2->prox;
    }
    if(cont==tamanho(lst1)) printf("S�o iguais\n");
    else printf("N�o s�o iguais\n");

    return 1;
}

Lista intercala(Lista lst1, Lista lst2){
    Lista lst3=cria_lista();
    Lista Aux1=lst1;
    Lista Aux2=lst2;
    Lista Aux3=lst3;
    Lista N;
    while(Aux1!=NULL || Aux2!=NULL){
        N= (Lista) malloc (sizeof(struct no));
        if(N!=NULL) N->prox=NULL;
        else return NULL;

        if((Aux2==NULL) || ((Aux1!=NULL) && (Aux1->info <= Aux2->info))){
            N->info=Aux1->info;
            Aux1=Aux1->prox;
        }else{
            N->info=Aux2->info;
            Aux2=Aux2->prox;
        }

        if(lista_vazia(lst3)==1){
            lst3=N;
            Aux3=N;
        }else{
            Aux3->prox=N;
            Aux3=Aux3->prox;
        }
    }
    return lst3;
}



