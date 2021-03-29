#include "AVL.c"
//Grupo:Jadson Costa de Amorim e Jo�o Pedro Souza Andrade
//estrutura aluno
typedef struct aluno{
	int matricula;
	char nome[50];
	char curso[50];
	char turma[50];
	int anodeingresso;
	char campos[50];
	char universidade[50];
	float CR;
}Aluno;
//fun��o que imprime os dados do aluno passado como par�metro um tipo gen�rico
void imprimir(void* info){
	Aluno *A = (Aluno*)info;
	printf("nome:%s\n",A->nome);
	printf("matricula:%d\n",A->matricula);
	printf("curso:%s\n",A->curso);
	printf("turma:%s\n",A->turma);
	printf("ano de ingresso:%d\n",A->anodeingresso);
	printf("campos:%s\n",A->campos);
	printf("universidade:%s\n",A->universidade);
	printf("CR:%f\n",A->CR);
}
//impress�o comum de um aluno
void impressaoNativa(Aluno *A){
	printf("nome:%s\n",A->nome);
	printf("matricula:%d\n",A->matricula);
	printf("curso:%s\n",A->curso);
	printf("turma:%s\n",A->turma);
	printf("ano de ingresso:%d\n",A->anodeingresso);
	printf("campos:%s\n",A->campos);
	printf("universidade:%s\n",A->universidade);
	printf("CR:%f\n",A->CR);
	
}
//fun��o que imprime a matricula do aluno
void imprimeChave(void* info){
	Aluno *A = (Aluno*)info;
	printf("matricula:%d\n",A->matricula);
}
//impress�o da �rvore inteira
void imprimirAlunos(No *Arvore){
	imprimeArvore(Arvore,1,imprimir);
}
//fun��o que compara duas chaves, recendo dois nos como par�metro
int comparaChave(void* info, void* ch){
	Aluno *A = (Aluno*)info;
	Aluno *chave = (Aluno*)ch;
	if(A->matricula==chave->matricula){
		return 1;
	}else{
		return 0;
	} 
}
//fun��o que compara duas chaves recebendo um no e um valor
int comparaChave2(void* info, void* ch){
	Aluno *A = (Aluno*)info;
	int *valor = (int*)ch;
	if(A->matricula==(*valor)){
		return 1;
	}else{
		return 0;
	} 
}
//fun��o que verifica se uma chave � maior que a outra
int e_maior(void* info, void* ch){
	Aluno *A = (Aluno*)info;
	Aluno *chave = (Aluno*)ch;
	if(A->matricula>chave->matricula){
		return 1;
	}else{
		return 0;
    } 
}
//fun��o que imprime o menu
void menu(){
	printf("\n=====CADASTRO DE ALUNOS=====\n");
	printf("1-Cadastrar aluno\n");
	printf("2-remover aluno\n");
	printf("3-procurar aluno\n");
	printf("4-imprimir alunos\n");
	printf("5-sair\n");
	printf("\n============================\n");
}
int main(){
	No *tree = NULL; //ponteiro que aponta para o primeiro n� da �rvore
	No *p;   //ponteiro utilizado para apontar n�s da �rvore
	int n=1; //vari�vel que conta a quantidade de alunos na �rvore
	Aluno *A = (Aluno*)malloc(sizeof(Aluno)); //vetor que guarda os alunos, o ponteiro info da �rvore aponta para uma posi��o de A
	int h = 0; //vari�vel que funciona como uma vari�vel booleana
	int op = 0; //vari�vel de op��o
	int M; //vari�vel que guardar� uma chave no caso uma matricula
	while(1){
    	menu();
    	printf(">>>");
    	scanf("%d",&op);
    	switch(op){
    		case 1:
    			//o novo aluno ser� introduzida na quantidade de alunos menos 1
    			printf("nome:\n");
    			scanf("%s",A[n-1].nome);
    			printf("curso:\n");
    		    scanf("%s",A[n-1].curso);
	            printf("matricula:\n");
	            scanf("%d",&A[n-1].matricula);
                printf("turma:\n");
                scanf("%s",A[n-1].turma);
                printf("ano de ingresso:\n");
                scanf("%d",&A[n-1].anodeingresso);
                printf("campos:\n");
                scanf("%s",A[n-1].campos);
                printf("universidade:\n");
                scanf("%s",A[n-1].universidade);
                printf("CR:\n");
                scanf("%f",&A[n-1].CR);
                tree = insereAVL(tree,&h,(A+(n-1)),&comparaChave,&e_maior);//o espa�o de mem�ria onde o novo aluno foi inserido � passado como par�metro para ser apontado pela chave
                n++; //vari�vel n � incrementada
                A =(Aluno *) realloc( A, n*sizeof(Aluno)); // o vetor � realocado
    			break;
    		case 2:
    			printf("informe a matricula do aluno que deseja excluir:");
    			scanf("%d",&M);
    			tree = removeChave(tree,&M,&comparaChave2,&e_maior);
    			break;
    		case 3:
    			printf("informe a matricula do aluno a ser buscado:");
    			scanf("%d",&M);
    			p = buscaChave(tree,&M,&comparaChave2,&e_maior);
    			imprimir(p->info);
    			break;
    		case 4:
    			imprimeArvore(tree,1,&imprimeChave);
    			break;
    		case 5:
    			printf("programa encerrado...");
    			free(A);
    			exit(1);
    			break;
		}
    	
    }
    return 0;
	
}

