#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include <string.h>

#define SIZE 20


typedef struct data DATA;
struct data{
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
};
typedef struct paciente PACIENTE;
	struct paciente{
	int id;
	char nome[20];
	char email[25];
	int cpf;
	char endereco[40];
	int telefone;		
};

typedef struct medico MEDICO;
struct medico{
	int idM;
    char nomeM[20];
    char especializacao[20];
    int crm;
};

typedef struct agenda AGENDA;
struct agenda{
 	char nome[20];
 	DATA hmarcada;
	char procedimento[15];
	int medico_id;
	int paciente_id;	
};


void cabecalho();
void CadastroP();
void Listar();
void CadastroM();
void ListarM();
void Agenda();
void LConsulta();

main(){
	setlocale(LC_ALL, "portuguese");
	int opcao;

	char login[15] = "admin2020";
    char login1[15];
    char senha[15] = "12345";
    char senha1[15];  
	
	printf("\n\n#---------TELA DE LOGIN---------#\n\n");

    printf("\nDigite o Login: ");
    scanf("%s", login1);

    printf("\nDigite a Senha: ");
    scanf("%s", senha1);

    if (strcmp(login, login1 ) == 0 && strcmp(senha, senha1) == 0 ) 

        printf("\n\nLOGADO COM SUCESSO !\n\n");
		

    else
		{

        printf("\n\nDADOS INVALIDOS!\n\n"); 
		return 0;
		}
		system("pause");
		
	
	
	do{
		system("cls");
		
		cabecalho();
		printf("\n                                        ");	
		printf("\n                                        ");	
		printf("\n 	  MENU PRINCIPAL                      ");
		printf("\n                                        ");
		printf("\n  1-Cadastrar novo paciente             ");
		printf("\n  2-Listar pacientes                    ");
		printf("\n  3-Cadastrar novo médico               ");
		printf("\n  4-Listar médicos                      ");
		printf("\n  5-Agendar consulta                    ");
		printf("\n  6-Consultas agendadas                 ");
		printf("\n                                        ");	
		
		printf("\n  7-Sair                               ");
		printf("\n                                        ");
		
	
		printf("\n\n > Escolha uma opção, e pressione ENTER: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				CadastroP();
			break;
			
			case 2:
				Listar();
			break;
			
			
			case 3:
				CadastroM();
			break;
			
			case 4:
				ListarM();
			break;
			
			case 5:
				Agenda();
				
			break;
			
			case 6:
				LConsulta();
			break;
			
			case 7:
				printf("Saindo do programa Efficient Healt\n");
				getch();
			break;
			
			default:
				printf("Opção Inválida !\n");
				getch();
			break;
		}
	}while(opcao!=7);
	
}

void cabecalho(){
	system("cls");
	printf("\n#------------------------------------#");
	printf("\n¦          EFFICIENT HEALT           ¦"); 
	printf("\n#------------------------------------#");
}

void CadastroP(){
	FILE* arquivo;
	PACIENTE cad;
	
	
	arquivo = fopen("Pacientescad.txt", "ab");
	
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!");
	}
	
	
	else{
		do{
			cabecalho();
			printf("\n\n");
			fflush(stdin);
			printf("\nDigite o ID: ");
			scanf("%i",&cad.id);
			
			fflush(stdin);
			printf("\nDigite o nome:");
			gets(cad.nome);
			
			fflush(stdin);
			printf("\nDigite o e-mail:");
			gets(cad.email);
			
			printf("\nDigite o CPF:");
			scanf("%d", &cad.cpf);
			
			fflush(stdin);
			printf("\nDigite o endereço:");
			gets(cad.endereco);
			
			fflush(stdin);
			printf("\nDigite o telefone:");
			scanf("%d", &cad.telefone);
			
			printf("\n");
		
			
			fwrite(&cad, sizeof(PACIENTE),1,arquivo);
			
			printf("\nDeseja continuar(s/n)?");
		}while(getche () == 's');
		fclose(arquivo);
		system("pause");
	}
	
}
void Listar(){
	FILE* arquivo;
	PACIENTE cad;
	
	arquivo = fopen("Pacientescad.txt", "rb");
	
	cabecalho();
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!");
	}
	else{
		while(fread(&cad, sizeof(PACIENTE),1,arquivo)==1){
			printf("\n");
			printf("ID: %d\n", cad.id);
			printf("Nome: %s\n", cad.nome);
			printf("E-mail: %s\n", cad.email);
			printf("CPF: %d\n", cad.cpf);
			printf("Endereço: %s\n", cad.endereco);
			printf("Telefone: %d\n", cad.telefone);
		
			}
	fclose(arquivo);
	getch();
	
	system("pause");
		}
}
void CadastroM(){
		FILE* arquivo;
	MEDICO med;
	
	arquivo = fopen("Médicoscad.txt", "ab");
	
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!");
	}
	else{
		do{
			cabecalho();
			printf("\n");
			fflush(stdin);
			printf("\nDigite o ID: ");
			scanf("%d",&med.idM);
			
			fflush(stdin);
			printf("\nDigite o nome:");
			gets(med.nomeM);
			
			fflush(stdin);
			printf("\nDigite a especialização do médico:");
			gets(med.especializacao);
			
			fflush(stdin);
			printf("\nDigite o CRM:");
			scanf("%d", &med.crm);
			
			
			fwrite(&med, sizeof(MEDICO),1,arquivo);
			
			printf("\nDeseja continuar(s/n)?");
		}while(getche () == 's');
		fclose(arquivo);
		system("pause");
	}
}
void ListarM(){
	FILE* arquivo;
	MEDICO med;
	
	arquivo = fopen("Médicoscad.txt", "rb");
	
	cabecalho();
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!");
	}
	else{
	
		while(fread(&med, sizeof(MEDICO),1,arquivo)==1){
			printf("\n");
			printf("ID: %d\n", med.idM);
			printf("Nome: %s\n", med.nomeM);
			printf("Especialização: %s\n", med.especializacao);
			printf("CRM: %d\n", med.crm);
			printf("\n\n");
			}
	fclose(arquivo);
	getch();
	
	system("pause");
		}
}

void Agenda(){
	FILE *arquivo;
	AGENDA ag;
	
	arquivo = fopen("ConsultasAgendadas.txt", "ab");
	cabecalho();
	if(arquivo == NULL){
		printf("Problemas ao abrir o arquivo!");
	}
	else{
		do{
			cabecalho();
			printf("\nAGENDAR CONSULTA\n\n");
			
			fflush(stdin);
			printf("\nDigite o nome do paciente: ");
			gets(ag.nome);
			
			fflush(stdin);
			printf("\nDigite a data (Dia, Mês, Ano, Hora, Minuto):");
			scanf("%d %d %d %d %d", &ag.hmarcada.dia, &ag.hmarcada.mes, &ag.hmarcada.ano, &ag.hmarcada.hora, &ag.hmarcada.minuto);
			
			fflush(stdin);
			printf("\nEntre com procedimento desejado:");
        	gets(ag.procedimento);
        	
        	fflush(stdin);
        	printf("\nDigite ID do paciente:");
        	scanf("%d", &ag.paciente_id);
        	
        	fflush(stdin);
        	printf("\nDigite o ID do médico:");
        	scanf("%d", &ag.medico_id);
        	
        	fwrite(&ag, sizeof(AGENDA),1,arquivo);
        	
        	printf("\nDeseja continuar (s/n)?");
        
		}while(getche () =='s' );
		fclose(arquivo);
		system("pause");
	
		}
	}
void LConsulta(){
	FILE *arquivo;
	AGENDA ag;
	
	arquivo = fopen("ConsultasAgendadas.txt", "rb");
	cabecalho();
	if(arquivo == NULL){
		printf("Problemas ao abrir o arquivo!");
	}
	else{
		while(fread(&ag, sizeof(AGENDA),1,arquivo) ==1){
			printf("\n");
			printf("Nome: %s\n", ag.nome);
			printf("Data: %d/%d/%d %d:%d\n", ag.hmarcada.dia, ag.hmarcada.mes,ag.hmarcada.ano,ag.hmarcada.hora,ag.hmarcada.minuto);
			printf("Procendimento: %s\n", ag.procedimento);
			printf("ID do paciente: %d\n", ag.paciente_id);
			printf("ID do médico: %d\n", ag.medico_id);
			printf("\n-----------------------------------------\n\n");
		}
	fclose(arquivo);
	getch();
	system("pause");
	}
}





