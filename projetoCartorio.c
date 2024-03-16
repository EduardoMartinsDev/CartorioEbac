#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definição da linguagem e uso de acentuação
	
	char arquivo[40]; //Inicio da criação de variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Final da criação das variáveis/string
	
			printf("Digite o CPF a ser cadastrado: "); // Responsável por copiar os valores das strings
			scanf("%s", cpf); // %s é um placeholder para a string
		
			strcpy(arquivo, cpf);// Responsável por copiar os valores das strings
		
			FILE *file; //Cria o arquivo
			file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa criar nova e escrever
			fprintf(file, cpf); //salva o valor da variável
			fclose(file); //fecha o arquivo
			
			file = fopen(arquivo, "a"); // "a" atualiza o arquivo
			fprintf(file, ","); // separa os dados com vírgula
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
				printf("Não foi possível abrir o arquivo. Não localizado! \n");
			}
			
				while(fgets(conteudo, 200, file) != NULL)
				{
					printf("\nEssas são as informações do usuário: ");
					printf("%s", conteudo);
					printf("\n\n");
				}
	
					system("pause");
		
}

int deletar()
{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
	
			printf("Digite o CPF do usuário a ser deletado: ");
			scanf("%s",cpf);		
				
			FILE *file;
			file = fopen(cpf, "r");
			fclose(file);
						
				if(file == NULL)
				{
					printf("O usuário não foi encontrado no sistema!.\n\n");
					system("pause");
				}
					else
					{
						remove(cpf);
						printf("O usuário foi deletado do sistema com sucesso!.\n\n");
						system("pause");
					}	
															
}

int main()
{
	int opcao=0;
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
		printf("### Cartório da EBAC ###\n\n");
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
			
				printf("### Cartório da EBAC ###\n\n");	// início do menu
				printf("Escolha a opção desejada do menu\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n"); //fim do menu
				printf("\t4 - Sair do sistema\n\n");
				printf("Digite a opção:  ");	
				scanf("%d", &opcao);			
					
				system("cls"); //este comando faz a limpeza de todos os dados após o usuário fazer o imput
			
					switch(opcao)
					{
						case 1:
							registro(); // chamada de funções
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
							printf("Error - Essa opção não está disponível!\n"); 
							system("pause");
						break;						
					} // fim da seleção
			}
		}
						else
						{
							printf("\nSenha incorreta!");
						}
		
}
