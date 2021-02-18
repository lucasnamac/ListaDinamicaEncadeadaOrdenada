
typedef struct no * Lista;

void menu();

Lista cria_lista();

int lista_vazia(Lista lst);

int insere_ord (Lista *lst, int elem);

int remove_ord (Lista *lst, int elem);

int imprimir(Lista lst);

int removerImpares(Lista *lst);

int menor(Lista lst);

int tamanho(Lista lst);

int Iguais(Lista lst1, Lista lst2);

Lista intercala(Lista lst1, Lista lst2);
