#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h>// biblioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string



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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	fclose(file);
    getchar();
}

int deletar ()
{
    char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n\n");
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
			printf("Usuário deletado com sucesso!.\n\n");
            getchar();
		}
	}
	fclose(file);
}

int main()
{
    int opcao=0; // definindo variável
    int laco=1;

    for (laco = 1; laco = 1;)

    {
        setlocale(LC_ALL,"Portuguese"); // definindo a linguagem

        // início do menu
        printf("\n   Cartório da EBAC   \n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 -Registrar nomes \n\n");
        printf("\t2 -Consultar nomes \n\n");
        printf("\t3 -Deletar nomes \n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção:");
        // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usuário

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
            printf("Essa opção não etá disponível\n\n");
            getchar();
            break;
        }


    }
}
