#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // defini��o da linguagem e uso de acentua��o
	
	char arquivo[40]; //Inicio da cria��o de vari�veis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Final da cria��o das vari�veis/string
	
			printf("Digite o CPF a ser cadastrado: "); // Respons�vel por copiar os valores das strings
			scanf("%s", cpf); // %s � um placeholder para a string
		
			strcpy(arquivo, cpf);// Respons�vel por copiar os valores das strings
		
			FILE *file; //Cria o arquivo
			file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa criar nova e escrever
			fprintf(file, cpf); //salva o valor da vari�vel
			fclose(file); //fecha o arquivo
			
			file = fopen(arquivo, "a"); // "a" atualiza o arquivo
			fprintf(file, ","); // separa os dados com v�rgula
			fclose(file);
				
			printf("Digite o nome a ser cadastrado: ");
			scanf("%s", nome);
					
			file = fopen(arquivo, "a");
			fprintf(file,nome);
			fclose(file);
				
			file = fopen(arquivo, "a");
			fprintf(file, ",");
			fclose(file);
						
			printf("Digite o sobrenome a ser cadastrado: ");
			scanf("%s", sobrenome);
					
			file = fopen(arquivo, "a");
			fprintf(file,sobrenome);
			fclose(file);
				
			file = fopen(arquivo, "a");
			fprintf(file, ",");
			fclose(file);
					
			printf("Digite o cargo a ser cadastrado: ");
			scanf("%s", cargo);
					
			file = fopen(arquivo, "a");
			fprintf(file,cargo);
			fclose(file);
				
				system("pause");			
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
			
			if(file == NULL)
			{
				printf("N�o foi poss�vel abrir o arquivo. N�o localizado! \n");
			}
			
				while(fgets(conteudo, 200, file) != NULL)
				{
					printf("\nEssas s�o as informa��es do usu�rio: ");
					printf("%s", conteudo);
					printf("\n\n");
				}
	
					system("pause");
		
}

int deletar()
{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
	
			printf("Digite o CPF do usu�rio a ser deletado: ");
			scanf("%s",cpf);		
				
			FILE *file;
			file = fopen(cpf, "r");
			fclose(file);
						
				if(file == NULL)
				{
					printf("O usu�rio n�o foi encontrado no sistema!.\n\n");
					system("pause");
				}
					else
					{
						remove(cpf);
						printf("O usu�rio foi deletado do sistema com sucesso!.\n\n");
						system("pause");
					}	
															
}

int main()
{
	int opcao=0;
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");
		
		if(comparacao == 0)
		{
			system("cls");
			
			for(laco=1;laco=1;)
			{
				system("cls");			
				setlocale(LC_ALL, "Portuguese");
			
				printf("### Cart�rio da EBAC ###\n\n");	// in�cio do menu
				printf("Escolha a op��o desejada do menu\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n"); //fim do menu
				printf("\t4 - Sair do sistema\n\n");
				printf("Digite a op��o:  ");	
				scanf("%d", &opcao);			
					
				system("cls"); //este comando faz a limpeza de todos os dados ap�s o usu�rio fazer o imput
			
					switch(opcao)
					{
						case 1:
							registro(); // chamada de fun��es
						break;	
						
						case 2:
							consulta();
						break;
						
						case 3:	
							deletar();
						break;
						
						case 4:
							printf("Obrigado por utilizar o sistema\n");
						return 0;
						break;
						
						default:
							printf("Error - Essa op��o n�o est� dispon�vel!\n"); 
							system("pause");
						break;						
					} // fim da sele��o
			}
		}
						else
						{
							printf("\nSenha incorreta!");
						}
		
}
