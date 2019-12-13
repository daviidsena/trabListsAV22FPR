#include <stdio.h>
#include <stdlib.h>

//declaração de constantes
#define TRUE 1
#define FALSE 0
#define TAM 10

//declaração de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//declaração de protótipos
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
TLista pesquisar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
int main ()
{
	//declaração de variáveis
	TLista L[TAM];
  TLista pVelho[TAM];
  TLista pNovo[TAM];
	int i;
	for(i=0; i<TAM; i++){
		L[i] = NULL;
		}

	int opcao, num1, num2, alt, desejado, desejado1;
  int rest, rest2, resto, resto2;
	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();
		
		switch (opcao)
		{
			//inserção
			case 1: printf ("Entre com o número a ser inserido: ");
			        scanf ("%d", &num1);
			        rest = num1%10;
			        if (inserir (&L[rest], num1) == TRUE) //ou apenas inserir (&L, num1)
			        {
			        	printf ("Elemento inserido!\n");
					}
					else
					{
						printf ("ERRO: Elemento não inserido!\n");
					}
					break;
				
			//remoção
			case 2: printf ("Entre com o número a ser removido: ");
			        scanf ("%d", &num1);
			        rest = num1%10;
			        if (remover (&L[rest], num1) == TRUE)
			        {
			        	printf ("Elemento removido!\n");
					}
					else
					{
						printf ("ERRO: Elemento não removido!\n");
					}
					break;
				
			//alterar
			case 3: 
					
					printf ("Entre com o número a ser alterado: ");
			        scanf ("%d", &num1);
			        rest = num1%10;
			        pVelho[rest] = pesquisar (L[rest], num1);
			        if(pVelho[rest] == NULL){
						printf ("O numero velho nao existe na lista! ");
					}
			        
			        printf ("Entre com o novo elemento: ");
			        scanf ("%d", &num2);
			        rest2 = num2%10;					
					pNovo[rest2] = pesquisar (L[rest2], num2);		
					
					if(pNovo[rest2] != NULL){
						printf ("O numero novo ja existe na lista! ");
					}
			        
			        
			        if (pVelho[rest] != NULL && pNovo[rest2] == NULL)
			        {
                remover (&L[rest], num1);
                inserir (&L[rest2], num2);
			        	printf ("Elemento alterado!\n");
					}
					else
					{
						printf ("ERRO: Elemento não alterado!\n");
					}
					break;
				
			//pesquisar
			case 4: printf ("Entre com o número a ser buscado: ");
			        scanf ("%d", &num1);
			        rest = num1%10;
			        if (pesquisar (L[rest], num1))  
			        {
			        	printf ("Elemento encontrado!\n");
					}
					else
					{
						printf ("Elemento não encontrado!\n");
					}
					break;
				
					//exibir
			case 5: 
				printf ("1 - Exibir a lista completa, 2 - determinada lista: ");
				scanf ("%d", &desejado);
				if(desejado == 1){
					for(i=0; i<TAM; i++){
						exibir (L[i]);
						}
					
					}else if(desejado == 2){
						printf ("Digite qual lista especifica deseja exibir: ");
						scanf ("%d", &desejado1);
						exibir (L[desejado1]);
					}
					else {
						printf ("Digite um numero valido: ");
						}

				break;

			//saída
			case 6: printf ("Fim do programa!");
			        break;
			        
			//opção inválida
			default: printf ("Opção inválida! Tente novamente.");
		}
		
		system ("pause");
	}
	while (opcao != 6);
}

//implementação das funções
int inserir (TLista *L, int numero)
{
	TLista aux;
	
	if (pesquisar (*L, numero) == NULL)  //verificando se o elemento não existe na lista
	{	
		aux = (TLista) malloc (sizeof(TNo));
		
		if (!aux)  //não há memória disponível
		{
			return FALSE;
		}
		else
		{
			aux->valor = numero;
			aux->prox = *L;
			*L = aux;
			
			return TRUE;
		}	
	}
	else
	{
		return FALSE;
	}
}

int remover (TLista *L, int numero)
{
	TLista aux1, aux2;
	
	if (*L)  //verificando se existe elementos na lista
	{
		if ((*L)->valor == numero)
		{
			aux1 = *L;
			*L = (*L)->prox;
			free (aux1);
			return TRUE;
		}
		else
		{
			aux2 = *L;
			aux1 = aux2->prox;
			
			while (aux1)   //while (aux1 != NULL)
			{
				if (aux1->valor == numero)
				{
					aux2->prox = aux1->prox;
					free (aux1);
					return TRUE;					
				}
				else
				{
					aux2 = aux1;
					aux1 = aux1->prox;
				}
			}
		}
	}
	 return FALSE;
}

TLista pesquisar (TLista L, int numero)
{
	TLista aux = L;
	
	while (aux)   // while (aux != NULL)
	{
 		if (aux->valor == numero)
		{
		 	return aux;
		}		
		aux = aux->prox;
	}
	
	return NULL;
}

void exibir (TLista L)
{
	TLista aux = L;
	
	if (!L)   // if (L == NULL)
	{
		printf ("Lista vazia!\n");
	}
	else
	{	
	    printf ("Lista: ");
		while (aux)    //  while (aux != NULL)
		{
			printf ("%d ", aux->valor);
			aux = aux->prox;
		}
		printf ("\n");
	}
}

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opções:\n\n");
	printf ("(1) Inserir\n(2) Remover\n(3) Alterar\n");
	printf ("(4) Buscar\n(5) Exibir\n(6) Sair\n\n");
	printf ("Entre com a sua opção: ");
	scanf ("%d", &op);
	
	return op;
}

