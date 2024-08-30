#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por cadastras usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf);    //Respons�vel por copiar os valores das strings
    
    FILE *file;   //cria o arquivo cujo nome � arquivo
    file = fopen(arquivo, "w"); // cria o arquivo que precisa ser aberto como novo o "W" refere-se a palavra Write = escrever
    fprintf(file,cpf);  //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); 
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf ("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
      
    file = fopen(arquivo, "a");
    fprintf (file,","); // Virgula usada para dar espa�o entre os dados coletados de cada usu�rio
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf ("%s",sobrenome);
    
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf (file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf ("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" Refere-se a palavra ler = Read 
	
	if(file == NULL) 
	{
		printf("N�o foi poss�vel encontrar o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto as informa��es do usu�rio estiverem dentro do conteudo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
	


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado ou n�o registrado no sistema!.\n");
		system("pause");
	}
	
}


int main()
{
	
	int opcao=0;    //Definindo Vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
	system("cls");    //Limpa a tela 
	
	setlocale(LC_ALL, "Portuguese");   //Definindo a Idioma
	
	
	printf("xxx Cart�rio da EBAC xxx\n\n");   //Inicio do menu
	printf("\t\tEscolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");   
	printf("Opc�o:");       //Fim do menu
	
	
	scanf("%d" , &opcao);  //Armazenando a escolha do usu�rio
	
	system("cls");   //Limpa a tela ap�s escolha das op��es
	
     	    switch(opcao)   //inicio da sele��o
    	 {
    	 	//chamada de fun��es 
	    	case 1:
	        registro();
	    	break;
		
	    	case 2:
	     	consulta();
	    	break;
		
	     	case 3:
		    deletar();
	    	break;
		
		    default:
		    printf("Esta op��o n�o est� disponivel!\n");
		    system("pause"); 
		    break;       // fim de sele��o
	     }
    }

}

