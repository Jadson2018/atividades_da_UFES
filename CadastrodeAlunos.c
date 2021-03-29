#include "AVL.c"
//Grupo:Jadson Costa de Amorim e João Pedro Souza Andrade
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
//função que imprime os dados do aluno passado como parâmetro um tipo genérico
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
//impressão comum de um aluno
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
//função que imprime a matricula do aluno
void imprimeChave(void* info){
	Aluno *A = (Aluno*)info;
	printf("matricula:%d\n",A->matricula);
}
//impressão da árvore inteira
void imprimirAlunos(No *Arvore){
	imprimeArvore(Arvore,1,imprimir);
}
//função que compara duas chaves, recendo dois nos como parâmetro
int comparaChave(void* info, void* ch){
	Aluno *A = (Aluno*)info;
	Aluno *chave = (Aluno*)ch;
	if(A->matricula==chave->matricula){
		return 1;
	}else{
		return 0;
	} 
}
//função que compara duas chaves recebendo um no e um valor
int comparaChave2(void* info, void* ch){
	Aluno *A = (Aluno*)info;
	int *valor = (int*)ch;
	if(A->matricula==(*valor)){
		return 1;
	}else{
		return 0;
	} 
}
//função que verifica se uma chave é maior que a outra
int e_maior(void* info, void* ch){
	Aluno *A = (Aluno*)info;
	Aluno *chave = (Aluno*)ch;
	if(A->matricula>chave->matricula){
		return 1;
	}else{
		return 0;
    } 
}
//função que imprime o menu
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
	No *tree = NULL; //ponteiro que aponta para o primeiro nó da árvore
	No *p;   //ponteiro utilizado para apontar nós da árvore
	int n=1; //variável que conta a quantidade de alunos na árvore
	Aluno *A = (Aluno*)malloc(sizeof(Aluno)); //vetor que guarda os alunos, o ponteiro info da árvore aponta para uma posição de A
	int h = 0; //variável que funciona como uma variável booleana
	int op = 0; //variável de opção
	int M; //variável que guardará uma chave no caso uma matricula
	while(1){
    	menu();
    	printf(">>>");
    	scanf("%d",&op);
    	switch(op){
    		case 1:
    			//o novo aluno será introduzida na quantidade de alunos menos 1
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
                tree = insereAVL(tree,&h,(A+(n-1)),&comparaChave,&e_maior);//o espaço de memória onde o novo aluno foi inserido é passado como parâmetro para ser apontado pela chave
                n++; //variável n é incrementada
                A =(Aluno *) realloc( A, n*sizeof(Aluno)); // o vetor é realocado
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

