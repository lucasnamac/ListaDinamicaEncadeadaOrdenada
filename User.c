#include<stdio.h>
#include<stdlib.h>
#include"DinamicaOrdenada.h"
#include<locale.h>


int main(){
    int opcao, elem, remover,qtd=0;
    Lista l1, l2, l3;
    l1=cria_lista();
    l2=cria_lista();
    l3=cria_lista();
    setlocale(LC_ALL, "Portuguese");
    menu();
    scanf("%d", &opcao);

    while(opcao!=11){
        switch(opcao){
            case(1):
                printf("Digite o n�mero que deseja inserir\n");
                scanf("%d", &elem);
                insere_ord(&l1, elem);
                break;
            case(2):
                printf("Digite o n�mero que quer remover\n");
                scanf("%d", &remover);
                remove_ord(&l1, remover);
                break;
            case(3):
                imprimir(l1);
                break;

            case(4):
                //Remover impares
                removerImpares(&l1);
                break;

            case(5):
                printf("Menor elemento �: %d\n", menor(l1));
                break;

            case(6):
                printf("O tamanho da lista �: %d\n", tamanho(l1));
                break;

            case(7):
                printf("Verifica se as listas s�o iguais\n");
                printf("Digite a quantidade de elmentos da lista 2\n");
                scanf("%d", &qtd);
                while(qtd--){
                    scanf("%d", &elem);
                    insere_ord(&l2, elem);
                }
                imprimir(l2);
                Iguais(l1, l2);
                break;

            case(8):
                printf("Digite a quantidade de elementos que deseja inserir na l2\n");
                scanf("%d", &qtd);
                while(qtd--){
                    scanf("%d", &elem);
                    insere_ord(&l2, elem);
                }
                l3=intercala(l1, l2);
                imprimir(l3);

                break;

        };
        menu();
        scanf("%d", &opcao);
    }

    return 0;
}
