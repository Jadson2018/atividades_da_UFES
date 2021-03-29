#include "AVL.h"
//Autor:Jadson Costa de Amorim
//função que cria um novo nó
No *inicioNo(void *chave){ 
	No *novo;
	novo = (No*)malloc(sizeof(No));
	if(novo==NULL){
        printf("Erro problemas com a alocacao de memoria.\n");
		exit(1);
	}
	novo->esquerdo = NULL;
	novo->direito = NULL;
	novo->info = chave;
    novo->bal = 0;
	return  novo;
}
//função que trata a rotação a direita
No *caso1(No *v, int *h){
	No *u,*z;
	u = v->esquerdo;
	//rotação simples a direita
	if(u->bal==1){
		v->esquerdo = u->direito;
		u->direito = v;
		v->bal = 0;
		v = u;
	}
	//rotação dupla a direita
	else{
		z = u->direito;
		u->direito = z->esquerdo;
		z->esquerdo = u;
		v->esquerdo = z->direito;
		z->direito = v;
		if(z->bal==1){
			v->bal = -1;
		}else{
			v->bal = 0;
		}
		if(z->bal == -1){
			u->bal = 1;
		}
		else{
			u->bal = 0;
		}
		v = z;
	}
	v->bal = 0;  //após a árvore ser baleanceada o campo fator de balanceamento recebe 0
	*h = 0;      
	return v;
}
//função que trata a rotação a esquerda
No *caso2(No *v, int *h){
	No *u,*z;
    u = v->direito;
    
    //rotação simples a esquerda
    if(u->bal == -1){
    	v->direito = u->esquerdo;
    	u->esquerdo = v;
    	v->bal = 0;
    	v = u;
	}else{ //rotação dupla a esquerda
		z = u->esquerdo;
		u->esquerdo = z->direito;
		z->direito = u;
		v->direito = z->esquerdo;
		z->esquerdo = v;
		if(z->bal == 1){
			v->bal = 0;
		}else{
			v->bal = 1;
		}
		if(z->bal == -1){
			u->bal = 0;
		}else{
			v->bal = -1;
		}
		v = z;
	}
	v->bal = 0;
	*h = 0;
	return v;
}
No *insereAVL(No *v, int *h, void* x, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*)){
	if(v==NULL){		
		  v = inicioNo(x);
		  *h = 1;
		  return v;
	}else{
		   if(comparaChave(v->info,x)==1){
		   	  printf("já existe um elemento com essa chave\n");
		   	  return v;
	       }
		   if(e_maior(v->info,x)==1){
			  v->esquerdo = insereAVL(v->esquerdo,h,x,comparaChave,e_maior);
			  if(*h==1){
				switch(v->bal){
					case -1:
						v->bal = 0;
						*h = 0;
						break;
					case 0:
						v->bal = 1;
						break;
					case 1:
						v = caso1(v,h);
						break;		
			    }
			  }
		  }else{
				v->direito = insereAVL(v->direito,h,x,comparaChave,e_maior);
				if(*h==1){
					switch(v->bal){
						case 1:
							v->bal = 0;
							*h = 0;
							break;
						case 0:
							v->bal = -1;
							break;
						case -1:
							v = caso2(v,h);
						    break;	
					}
				}
			}
	}
	return v;
}
void imprimeArvore(No *T, int nivel, void (*imprimir)(void*)){
	int i;
	if(T!=NULL){
		imprimeArvore(T->direito,nivel+1,imprimir);
		for(i=0;i<nivel;i++){
			printf("\t");
		}
		imprimir(T->info);
		imprimeArvore(T->esquerdo,nivel+1,imprimir);
	}
}
No *busca(No *T, No **pai, void* ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*)){
	if(!T){
		return NULL;
	}
	if(comparaChave(T->info,ch)==1){
		return T;
		(*pai) = T;
	}
	if(e_maior(T->info,ch)==1){
		return busca(T->esquerdo,pai,ch,comparaChave,e_maior);
	}else{
		return busca(T->direito,pai,ch,comparaChave,e_maior);
	}
}
No *sucessor(No *P, No **paiP){
       if(P != NULL){
       	  (*paiP) = P;
           P = P->direito;
           if(P!=NULL){
              while(P->esquerdo != NULL){
              	(*paiP) = P;
              	P = P->esquerdo;
			  }
		   }
	   }
	   return P;	
}
No *removeChave(No *T, void* ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*)){
	No *paiProc = NULL;
	No *proc = busca(T, &paiProc, ch, comparaChave, e_maior);
	if(proc!=NULL){
		No *paiSuc = NULL;
	    No *suc = sucessor(proc,&paiSuc);
	    if(suc!=NULL){
	    	proc->info = suc->info;
	    	if(suc==paiSuc->esquerdo)paiSuc->esquerdo = suc->direito;
	    	else paiSuc->direito = suc->direito;
	    	free(suc);
		}else{
			if(paiProc!=NULL){
			   if(proc == paiProc->esquerdo)paiProc->esquerdo = proc->esquerdo;
			   else paiProc->direito = proc->esquerdo;
			}else{
				T= proc->esquerdo;
			 free(proc);
			}
		}
	}
	return T;
}
No *buscaChave(No *T, void* ch, int (*comparaChave)(void*,void*), int (*e_maior)(void*,void*)){
	if(!T){
		return NULL;
	}
	if(comparaChave(T->info,ch)==1){
		return T;
	}
	if(e_maior(T->info,ch)==1){
		return buscaChave(T->esquerdo,ch,comparaChave,e_maior);
	}else{
		return buscaChave(T->direito,ch,comparaChave,e_maior);
	}
}
int arvoreVazia(No *A){
	return A==NULL;
}
No *liberarArvore(No *A){
	if(!arvoreVazia(A)!=0){
		liberarArvore(A->esquerdo);
		liberarArvore(A->direito);
		free(A);
	}else{
		return NULL;
	}
}
