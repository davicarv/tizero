#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string



int registro ()
{
    setlocale(LC_ALL, "Portuguese");

    char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

    getchar();
}

int consultar ()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	fclose(file);
    getchar();
}

int deletar ()
{
    char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usu�rio deletado com sucesso!.\n\n");
            getchar();
		}
	}
	fclose(file);
}

int main()
{
    int opcao=0; // definindo vari�vel
    int laco=1;

    for (laco = 1; laco = 1;)

    {
        setlocale(LC_ALL,"Portuguese"); // definindo a linguagem

        // in�cio do menu
        printf("\n   Cart�rio da EBAC   \n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 -Registrar nomes \n\n");
        printf("\t2 -Consultar nomes \n\n");
        printf("\t3 -Deletar nomes \n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o:");
        // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usu�rio

        system("clear"); // limpar a tela


        switch (opcao)
        {
            case 1:
            registro();
            getchar();
            break;

            case 2:
            consultar ();
            getchar();
            break;

            case 3:
            deletar ();
            getchar();
            break;

            case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;

            default:
            printf("Essa op��o n�o et� dispon�vel\n\n");
            getchar();
            break;
        }


    }
}
