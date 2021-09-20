// Trabalho de Programação ( Agenda 2.0 )
// Saul Basso Junior

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define N 1000

typedef struct{
	int cond;
    char nome[200], telefone[200], celular[200], dia[200], mes[200], ano[200], pesq[3];
} Registro ;
Registro VetorRegistro[N], aux1, aux2[N];

int opc2, opc3, i, j, quant, auxq=0,cond;

void Cadastro(Registro VetorRegistro[N]);
void ordenaNome( int quant, Registro VetorRegistro[N], Registro aux1);
void ordenaData(int quant, Registro VetorRegistro[N], Registro aux1);
void AlterarCont(Registro VetorRegistro[N]);
void ConverteMin(char aux2[]);
void Pesquisa(Registro VetorRegistro[N]);
void MovLixeira(Registro VetorRegistro[N]);
void Lixeira(Registro VetorRegistro[N]);
int CarregaArquivo();
void SalvaArquivo(int t);


int main(){
	setlocale(LC_ALL, "Portuguese");
	int opc, menu=1;
    quant=CarregaArquivo();
    auxq=quant;
    do{
	    system("cls");
		printf("\tBem Vindo a sua Agenda!!!!\n\n");
		printf("\t---------------MENU---------------\n\n");
		printf("\t0 - Sair da Agenda.\n");
		printf("\t1 - Cadastrar. \n");
		printf("\t2 - Listagem Ordem Alfabetica.\n");
		printf("\t3 - Listagem Ordem De nascimento.\n");
		printf("\t4 - Alterar Contatos.\n");
		printf("\t5 - Pesquisar\n");
		printf("\t6 - Excluir Contatos.\n");
		printf("\t7 - Lixeira.\n");
		printf("\t----------------------------------\n\n");
		printf("\tQUAL OPÇÃO DESEJA ACESSAR?:  ");
        scanf("%d", &opc);
		switch(opc){
			case 0:
				menu=0;
				system("cls");
				printf("\tAgenda Salva!!\n");
				printf("\tPrograma encerrado!!\n\n");
                system("pause");
                SalvaArquivo(quant);
            break;
			case 1:
				Cadastro(VetorRegistro);		
			break;
			case 2:
				system("cls");
				ordenaNome(quant, VetorRegistro, aux1);
				for(i=0; i<quant; i++) {	
					if (VetorRegistro[i].cond==0){
				    	fflush(stdin);
                        printf(" \n\t Nome: %s ", &VetorRegistro[i].nome);
                        printf(" \n\t Celular: %s", &VetorRegistro[i].celular);
                        printf(" \n\t Telefone: %s", &VetorRegistro[i].telefone);
                        printf(" \n\t Data de Nascimento: %s/%s/%s\n\n", &VetorRegistro[i].dia, &VetorRegistro[i].mes, &VetorRegistro[i].ano);
					}
                }
                system ("pause");	
			break;
			case 3:
				system("cls");
				ordenaData (quant,VetorRegistro, aux1);
				for(i=0; i<quant; i++) {
                    if (VetorRegistro[i].cond==0){
				        fflush(stdin);
                        printf(" \n\t Nome: %s ", &VetorRegistro[i].nome);
                        printf(" \n\t Celular: %s", &VetorRegistro[i].celular);
                        printf(" \n\t Telefone: %s", &VetorRegistro[i].telefone);
                        printf(" \n\t Data de Nascimento: %s/%s/%s \n\n", &VetorRegistro[i].dia, &VetorRegistro[i].mes, &VetorRegistro[i].ano);
                    }
                }
                system ("pause");
            break;
            case 4:
            	AlterarCont(VetorRegistro);
            break;
            case 5:
            	Pesquisa(VetorRegistro);
            break;
            case 6:
            	ordenaNome(quant, VetorRegistro, aux1);
            	MovLixeira(VetorRegistro);
            break;
            case 7:
            	Lixeira(VetorRegistro);
            break;
            	
		}	
	}while(menu!=0);
}

void Cadastro(Registro VetorRegistro[N]){
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf("\n\tQuantos Contatos deseja cadastrar? \n\t:: ");
	scanf("%d", &quant);
	quant=quant+auxq;
	for(i=auxq;i<=quant;i++){
		system("cls");
		for(i=auxq; i<quant; i++){
			fflush(stdin);
		    printf(" \n\t Nome: ");
			gets(VetorRegistro[i].nome);
            printf(" \n\t Telefone: ");
            gets(VetorRegistro[i].telefone);
            printf(" \n\t Celular: ");
            gets(VetorRegistro[i].celular);
            printf(" \n\t Data de Nascimento: ");
            printf(" \n\t Dia: ");
            gets(VetorRegistro[i].dia);
            printf(" \n\t Mês: ");
            gets(VetorRegistro[i].mes);
            printf(" \n\t Ano: ");
            gets(VetorRegistro[i].ano);
            VetorRegistro[i].cond=0;
		}
		auxq=quant;
		system("cls");
	}
}

void ordenaNome (int quant, Registro VetorRegistro[N], Registro aux1){
	int i,j;
	for(i=0;i!=quant; i++){   
        for(j=i+1; j!=quant; j++){
            if (strcmpi(VetorRegistro[i].nome, VetorRegistro[j].nome)>0) {
                aux1= VetorRegistro[i];                      
                VetorRegistro[i]= VetorRegistro[j];                      
                VetorRegistro[j]= aux1;                      
            }
        }
    }	
}

void ordenaData (int quant, Registro VetorRegistro[N], Registro aux1){
	int i,j, x=0;
	while(x<=quant){
	    for(i=0;i<quant; i++){   
            for(j=i+1; j<quant; j++){
            	if (strcmpi(VetorRegistro[i].ano, VetorRegistro[j].ano)==0){
            		if (strcmpi(VetorRegistro[i].mes, VetorRegistro[j].mes)==0)
					if (strcmpi(VetorRegistro[i].dia, VetorRegistro[j].dia)>0) {
                    aux1= VetorRegistro[i];                      
                    VetorRegistro[i]= VetorRegistro[j];                      
                    VetorRegistro[j]= aux1;
				    }
					if (strcmpi(VetorRegistro[i].mes, VetorRegistro[j].mes)>0){
						aux1= VetorRegistro[i];                      
                        VetorRegistro[i]= VetorRegistro[j];                      
                        VetorRegistro[j]= aux1;
					}	
				}
                if (strcmpi(VetorRegistro[i].ano, VetorRegistro[j].ano)>0) {
                    aux1= VetorRegistro[i];                      
                    VetorRegistro[i]= VetorRegistro[j];                      
                    VetorRegistro[j]= aux1;                     
                }
            }
        }	
        x++;
    }
}

void AlterarCont(Registro VetorRegistro[N]){
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	for(i=0;i<=quant;i++){
		ordenaNome(quant, VetorRegistro, aux1);
		printf("\tAlterar Contato Cadastrado\n");
		printf("\t0 - Para sair\n");
		printf("\t1 - Nome do Contato\n");
		printf("\t2 - Telefone Fixo\n");
		printf("\t3 - Telefone Celular\n");
		printf("\t4 - Data de Nascimento");
		printf("\n\t::: ");
		scanf("%d", &opc2);
		switch(opc2){
			case 0:
            i=quant+1;	
            break;
            case 1:
            	for(j=0;j<=quant;j++){
            		system("cls");
            		for(i=0; i!=quant; i++){
            			if(VetorRegistro[i].cond==0)
            			printf(" \n\t %d Nome: %s ",i, &VetorRegistro[i].nome);
					}
					printf("\n\tAlterar Nome do Contato: ");
					scanf("%d", &i);
					if (i>=0 && i<=N){
						fflush(stdin);
						printf("\n\tNovo Nome do Contato: ");
						gets(VetorRegistro[i].nome);
						j=quant+1;
					}
					system("pause");
				}
			break;
			case 2:
				for(j=0;j<=quant;j++){
					system("cls");
					for(i=0; i!=quant; i++){
						if(VetorRegistro[i].cond==0)
						printf(" \n\t %d Nome: %s ",i, &VetorRegistro[i].nome);
					}
					printf("\n\tAlterar Telefone do Contato: ");
					scanf("%d", &i);
					if (i>=0 && i<=N){
						fflush(stdin);
						printf("Novo Telefone Fixo:\n");
						gets(VetorRegistro[i].telefone);
						j=quant+1;
					}
					system("pause");
				}
			break;
			case 3:
				for(j=0;j<=quant;j++){
					system("cls");
					for(i=0; i!=quant; i++){
						if(VetorRegistro[i].cond==0)
						printf(" \n\t %d Nome: %s ",i, &VetorRegistro[i].nome);
					}
					printf("\n\tAlterar Numero de Celular do Contato: ");
					scanf("%d", &i);
					if (i>=0 && i<=N){
						fflush(stdin);
						printf("Novo Numero de Celular:\n");
						gets(VetorRegistro[i].celular);
						j=quant+1;
					}
					system("pause");
				}
			break;
			case 4:
				for(j=0;j<=quant;j++){
					system("cls");
					for(i=0; i!=quant; i++){
						if(VetorRegistro[i].cond==0)
						printf(" \n\t %d Nome: %s ",i, &VetorRegistro[i].nome);
					}
					printf("\tAlterar Data de Nascimento do Contato: ");
					scanf("%d", &i);
					if (i>=0 && i<=N){
						fflush(stdin);
						printf("\tNova Data de Nascimento:");
						printf("\n\t Dia: ");
						gets(VetorRegistro[i].dia);
						printf("\n\t Mês: ");
						gets(VetorRegistro[i].mes);
						printf("\n\t Ano: ");
						gets(VetorRegistro[i].ano);
						j=quant+1;
					}
					system("pause");
				}
			break;
			system("pause");
		}
	}	
}

void ConverteMin(char aux2[]) {
    int i=0;
    while (aux2[i]!='\0') {
        aux2[i]=tolower(aux2[i]);
        i++;     
    }
}

void Pesquisa(Registro VetorRegistro[N]){
	char nome[N], aux2[N];
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf("\n\t Pesquisar por? \n\t 1=Data de Nascimento. \n\t 2=Nome.\n\t :: ");
	scanf("%d", &cond);
	if(cond==1){
		system("cls");
	    fflush(stdin);
	    printf(" \n\t Dia: ");
	    gets(VetorRegistro[0].pesq);
	    printf(" \n\t Mês: ");
	    gets(VetorRegistro[1].pesq);
	    printf(" \n\t Ano: ");
	    gets(VetorRegistro[2].pesq);
	    for(i=0; i<quant; i++){
	    	if((strcmpi(VetorRegistro[0].pesq,VetorRegistro[i].dia)==0) && (strcmp(VetorRegistro[1].pesq,VetorRegistro[i].mes)==0) && (strcmp(VetorRegistro[2].pesq,VetorRegistro[i].ano)==0)){
	    		if (VetorRegistro[i].cond==0){
	    			fflush(stdin);
	    			printf(" \n\t Nome: %s ", &VetorRegistro[i].nome);
	    			printf(" \n\t Celular: %s", &VetorRegistro[i].celular);
	    			printf(" \n\t Telefone: %s", &VetorRegistro[i].telefone);
	    			printf(" \n\t Data de Nascimento: %s/%s/%s \n\n", &VetorRegistro[i].dia, &VetorRegistro[i].mes, &VetorRegistro[i].ano);
				}
				else printf("\n\t Contato Excluido!\n");
			}	
		}
	}
	if(cond==2){
		system("cls");
		fflush(stdin);
		printf(" \n\t Pesquisa: ");
		gets(nome);
		system("cls");
		for(i=0; i<quant; i++){
			strcpy(aux2, VetorRegistro[i].nome);
			ConverteMin(nome);
            ConverteMin(aux2);
			if(strstr(aux2,nome)!=NULL){
				if (VetorRegistro[i].cond==0){
					fflush(stdin);
					printf(" \n\t Nome: %s ", &VetorRegistro[i].nome);
					printf(" \n\t Celular: %s", &VetorRegistro[i].celular);
					printf(" \n\t Telefone: %s", &VetorRegistro[i].telefone);
					printf(" \n\t Data de Nascimento: %s/%s/%s \n\n", &VetorRegistro[i].dia, &VetorRegistro[i].mes, &VetorRegistro[i].ano);
				}
				else printf("\n\t Contato Excluido!\n");
			}
		}
	}
	system ("pause");
}

void MovLixeira(Registro VetorRegistro[N]){
	system("cls");
	printf("Excluir Cadastro de Contato.\n");
	for(i=0; i!=quant; i++){
		if(VetorRegistro[i].cond==0)
		printf(" \n\t %d Nome: %s ",i, &VetorRegistro[i].nome);
	}
	printf("\n\t Qual Contato deseja Excluir? ");
	scanf("%d", &i);
	if (i>=0 && i<=N){
		system("cls");
		fflush(stdin);
		printf("\n\t Deseja Excluir o Contato??");
		printf ("\n\t 1 = Sim. \n\t 0 = Não. \n\t ::");
		scanf("%d",&VetorRegistro[i].cond);
	}
	if(VetorRegistro[i].cond==1){
		printf("\n\tTodos os Dados do Contato Foram Para a Lixeira!!\n\n");
	}
	system("pause");
}
void Lixeira(Registro VetorRegistro[N]){
	system("cls");
	printf("\n\t1-Recuperar Contato\n");
	printf("\t2-Excluir Permanentemente\n");
	scanf("%d", &opc2);
	switch(opc2){
		case 1:
			printf("\tRecuperar Contato.\n");
			for(i=0; i!=quant; i++){
				if (VetorRegistro[i].cond==1)
				printf(" \n\t %d Nome: %s ",i, &VetorRegistro[i].nome);
			}
			printf("\n\t Qual Contato deseja Recuperar? ");
			scanf(" %d", &i);
			if (i>=0 && i<=N){
				system("cls");
				fflush(stdin);
				printf("\n\t Deseja Recuperar o Contato??");
				printf ("\n\t 0 = Sim. \n\t 1 = Não. \n\t ::");
				scanf("%d",&VetorRegistro[i].cond);
			}
			printf("\n\tTodos os Dados do Contato Foram Recuperados!!\n");
		break;
		case 2:
			printf("\tExcluir Contato.\n");
			for(i=0; i!=quant; i++){
				if (VetorRegistro[i].cond==1)
				printf(" \n\t %d Nome: %s ",i, &VetorRegistro[i].nome);
			}
			printf("\n\t Qual Contato deseja Excluir? ");
			scanf(" %d", &opc3);
			if (opc3>=0 && opc3<=N){
				system("cls");
				fflush(stdin);
				printf("\n\t Deseja Excluir o Contato??");
				printf ("\n\t 0 = Sim. \n\t 1 = Não. \n\t ::");
				scanf("%d", &opc2);
				if(opc2==0){
					for(i=opc3;i<quant; i++){
						j=i+1;
						if(j<=quant)
						VetorRegistro[i]= VetorRegistro[j];
					}
					memset(&VetorRegistro[i].nome,0,sizeof(VetorRegistro[i].nome));
                    memset(&VetorRegistro[i].telefone,0,sizeof(VetorRegistro[i].telefone));
                    memset(&VetorRegistro[i].celular,0,sizeof(VetorRegistro[i].celular));
                    memset(&VetorRegistro[i].dia,0,sizeof(VetorRegistro[i].dia));
                    memset(&VetorRegistro[i].mes,0,sizeof(VetorRegistro[i].mes));
                    memset(&VetorRegistro[i].ano,0,sizeof(VetorRegistro[i].ano));
                    quant=quant-1;
				}
			}
			printf("\n\tTodos os Dados do Contato Foram Excluidos!!\n");
			system("pause");
		break;
	}
}

int CarregaArquivo() {
  int veri;   
  FILE *fp;
  fp=fopen("agenda.dad", "rb");
  if (fp==NULL) {
     printf("Arquivo ainda nao existe\n");
     system("pause");
     return 0;
  }
  veri=0;
  fread(&VetorRegistro[veri], sizeof(Registro), 1, fp);
  while (!feof(fp)) {
     veri++;
     fread(&VetorRegistro[veri], sizeof(Registro), 1, fp);
  }
  fclose(fp);
  return veri;
}

void SalvaArquivo(int t) {
  FILE *fp;
  fp=fopen("agenda.dad", "wb");
  if (fp==NULL) {
     printf("Erro ao salvar arquivo.\n");
     system("pause");
     exit(-1);              
  }
  fwrite(VetorRegistro, sizeof(Registro), t , fp);
  fclose(fp);        
}
