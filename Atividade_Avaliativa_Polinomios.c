#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
//Jadson Costa de Amorim
struct no {
	int coeficiente;
	int expoente;
	struct no *prox;
};
struct no *criaNo(int coeficiente,int expoente){
       struct no *novo;
	   novo = (struct no *)malloc(sizeof(struct no));
	   if(novo==NULL){
           printf("Erro problemas com a alocacao de memoria.\n");
		   exit(1);
	   }
	   novo->coeficiente=coeficiente;
	   novo->expoente=expoente;
	   novo->prox=NULL;
	   return novo;
}
/*struct no *insereInicio(struct no *L, int coeficiente, int expoente){
	   struct no *novo = criaNo(coeficiente, expoente);
	   novo -> prox = L;
	   L = novo;
	   return L;
}
struct no *insereFinal(struct no *L, int coeficiente, int expoente){
	struct no *novo = criaNo(coeficiente,expoente);
	struct no *aux = L;
	if(L==NULL) L = novo;
	else{
		while(aux->prox != NULL)aux = aux->prox;
		aux->prox = novo;
	}
	return L;
}*/
struct no *insereListaOrdenado(struct no *L, int coeficiente, int expoente){
       struct no *novo = criaNo(coeficiente, expoente);
       struct no *aux = L, *pred = NULL;
       if(L==NULL) L = novo;
       else{
          while(aux != NULL && expoente<aux->expoente){
          	pred = aux;
          	aux = aux->prox;
		  }
		  if(pred == NULL){
		  	novo->prox = aux;
		  	L = novo;
		  }
		  else{
		  	novo->prox = aux;
		  	pred->prox = novo;
		  }
    	}
		  
    return L;
}
int buscaExpoente(struct no *L, int exp){
	   struct no *aux = L;
	   int valor=0;
	   if(L==NULL){
	   	return 0;
	   }
	   else{
	   	    while(aux!=NULL){
	   		    if(exp<=aux->expoente)break;
	   	    	aux=aux->prox;
		   }
		   if(aux->expoente==exp){
		   	  valor=1;
		   }
		   return valor;
	   }
}
struct no *somaPolinomios(struct no *P1, struct no *P2){
	       struct no *aux1 = P1;
		   struct no *aux2 = P2;
		   struct no *P3 = NULL;
		   int soma=0;
		   int expoente;
		   if(P1==NULL || P2==NULL)P3=NULL;
		   else{
		      while(aux1!=NULL){
		      	while(aux2!=NULL && aux2->expoente>aux1->expoente){
		      		  P3=insereListaOrdenado(P3,aux2->coeficiente,aux2->expoente);
					  aux2=aux2->prox;
				}
				if(aux1->expoente==aux2->expoente){
					soma=aux1->coeficiente+aux2->coeficiente;
					expoente=aux1->expoente;
					P3=insereListaOrdenado(P3,soma,expoente);
				}
				else{
					P3=insereListaOrdenado(P3,aux1->coeficiente,aux1->expoente);
					if(buscaExpoente(P3,aux2->expoente)==1){
					   P3=insereListaOrdenado(P3,aux2->coeficiente,aux2->expoente);
					}
				}
			    aux1=aux1->prox;
			    aux2=P2;
			  }
		   }
		   return P3;
}
struct no *subtraiPolinomios(struct no *P1, struct no *P2){
           struct no *aux1 = P1;
           struct no *aux2 = P2;
           struct no *P3 = NULL;
           int subtracao;
           int expoente;
           if(P1==NULL || P2==NULL)P3=NULL;
		   else{
		      while(aux1->prox!=NULL){
		      	while(aux2->prox!=NULL && aux2->expoente>aux1->expoente){
		      		aux2=aux2->prox;
				}
				if(aux1->expoente==aux2->expoente){
				    subtracao=aux1->coeficiente-aux2->coeficiente;
					expoente=aux1->expoente;
					P3=insereListaOrdenado(P3,subtracao,expoente);
				}
			    aux1=aux1->prox;
			    aux2=P2;
			  }
		   }
		   return P3;
}
struct no *multiplicaPolinomios(struct no *P1, struct no *P2){
	       struct no *aux1 = P1;
		   struct no *aux2 = P2;
		   struct no *P3 = NULL;
		   int multiplicacao;
		   int expoente;
		   if(P1==NULL || P2==NULL)P3=NULL;
		   else{
		      while(aux1->prox!=NULL){
		      	while(aux2->prox!=NULL){
		      		multiplicacao=aux1->coeficiente*aux2->coeficiente;
		      		expoente=aux1->expoente+aux2->expoente;
		      		P3=insereListaOrdenado(P3,multiplicacao,expoente);
		      		aux2=aux2->prox;
		      		
				}
			    aux1=aux1->prox;
			    aux2=P2;
			  }
		   }
		   return P3;
}
struct no *excluiInicio(struct no *L){
	struct no *aux=L;
	if(L==NULL){
	    return NULL;	
	}
	else{
		L=L->prox;
		free(aux);
		return L;
	}
}
struct no *excluiLista(struct no *L){
	struct no *aux=L;
	if(L==NULL){
		return NULL;
	}
	else{
	  while(aux->prox!=NULL){
		L=excluiInicio(L);
      }
      return L;
    }
}
void imprimePolinomio(struct no *L){
	struct no *aux = L;
	int cont=0;
	while(aux!=NULL){
		if(aux->coeficiente>0 && cont>0){
			printf("+%dX^(%d)",aux->coeficiente,aux->expoente);
		}
		else{
		printf("%dX^(%d)",aux->coeficiente,aux->expoente);
	   }
	   cont++;
	   aux = aux->prox;
    }
	printf("\n");
}
int main(){
	struct no *Polinomio1 = NULL;
	struct no *Polinomio2 = NULL;
	struct no *Operacao = NULL;
	int coeficiente;
	int expoente;
	int escolha, esclist;
	setlocale(LC_ALL, "Portuguese");
	
	while(1){
     	printf("1-somar polinômios\n2-subtrair polinômios\n3-multiplicar polinomios\n0-sair");
     	scanf("%d",&escolha);
     	switch(escolha){
     		case 1:
     			while(esclist!=3){
     				printf("1-inserir monomio no primeiro polinômio\n2-inserir monomio no segundo polinômio \n3-parar insercao\n");
     				scanf("%d",&esclist);
     				if(esclist==1){
     					printf("informe o coeficiente:\n");
     					scanf("%d",&coeficiente);
     					printf("informe o expoente:\n");
     					scanf("%d",&expoente);
     					Polinomio1=insereListaOrdenado(Polinomio1,coeficiente,expoente);
					 }
					 if(esclist==2){
					 	printf("informe o coeficiente:\n");
     					scanf("%d",&coeficiente);
     					printf("informe o expoente:\n");
     					scanf("%d",&expoente);
     					Polinomio2=insereListaOrdenado(Polinomio2,coeficiente,expoente);
					 }
				 }
				 	 Operacao=somaPolinomios(Polinomio1,Polinomio2);
					 imprimePolinomio(Polinomio1);
					 printf("+");
					 imprimePolinomio(Polinomio2);
					 printf("=");
					 imprimePolinomio(Operacao);
					 Polinomio1=excluiLista(Polinomio1);
					 Polinomio2=excluiLista(Polinomio2);
					 Operacao=excluiLista(Operacao);
     			break;
     	     case 2:
     	     	while(esclist!=3){
     	     			printf("1-inserir monomio no primeiro polinômio\n2-inserir monomio no segundo polinômio \n3-parar insercao\n");
     			     	scanf("%d",&esclist);
     			     	if(esclist==1){
     			     		printf("informe o coeficiente:\n");
     					    scanf("%d",&coeficiente);
     					    printf("informe o expoente:\n");
     					    scanf("%d",&expoente);
     					    Polinomio1=insereListaOrdenado(Polinomio1,coeficiente,expoente);
						}
						if(esclist==2){
					       	printf("informe o coeficiente:\n");
     				    	scanf("%d",&coeficiente);
     				    	printf("informe o expoente:\n");
     				    	scanf("%d",&expoente);
     				    	Polinomio2=insereListaOrdenado(Polinomio2,coeficiente,expoente);
					    }
				  }
				        Operacao=subtraiPolinomios(Polinomio1,Polinomio2);
					    imprimePolinomio(Polinomio1);
					    printf("-");
					    imprimePolinomio(Polinomio2);
					    printf("=");
					    imprimePolinomio(Operacao);
					    Polinomio1=excluiLista(Polinomio1);
					    Polinomio2=excluiLista(Polinomio2);
			            Operacao=excluiLista(Operacao);
				  break;
			    case 3:
			    	while(esclist!=3){
			    		printf("1-inserir monomio no primeiro polinômio\n2-inserir monomio no segundo polinômio \n3-parar insercao\n");
     			     	scanf("%d",&esclist);
     			     	if(esclist==1){
     			     		printf("informe o coeficiente:\n");
     					    scanf("%d",&coeficiente);
     					    printf("informe o expoente:\n");
     					    scanf("%d",&expoente);
     					    Polinomio1=insereListaOrdenado(Polinomio1,coeficiente,expoente);
						}
						if(esclist==2){
					       	printf("informe o coeficiente:\n");
     				    	scanf("%d",&coeficiente);
     				    	printf("informe o expoente:\n");
     				    	scanf("%d",&expoente);
     				    	Polinomio2=insereListaOrdenado(Polinomio2,coeficiente,expoente);
					    }
					}
					    Operacao=multiplicaPolinomios(Polinomio1,Polinomio2);
					    imprimePolinomio(Polinomio1);
					    printf("*");
					    imprimePolinomio(Polinomio2);
					    printf("=");
					    imprimePolinomio(Operacao);
				        Polinomio1=excluiLista(Polinomio1);
					    Polinomio2=excluiLista(Polinomio2);
			            Operacao=excluiLista(Operacao);
     				break;
		 }
    }
    return 0;
}
