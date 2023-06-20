#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char proprietario[30];
    char combustivel[10];
    char modelo[100];
    char cor[20];
    char placa[20];
    char chassi[20];
    int ano;
} Veiculo;

Veiculo veiculo[5000];
int j;

int perguntas();
void imprimir();
void listarCarro();
void listarPlaca();
void listarModelo();
void trocarProprietario();
int verificarPlaca(char *placa);

int main()
{
    perguntas();
    imprimir();
    listarCarro();
    listarPlaca();
    listarModelo();
    trocarProprietario();
    imprimir();
    return 0;
}

int perguntas()
{
    printf("QUANTOS CARROS QUER CADASTRAR ?:\n");
    scanf("%i", &j);
    getchar();

    if (j <= 5000)
    {
        for (int i = 0; i < j; i++)
        {
            printf("QUAL O NOME DO PROPRIETARIO ? :\n");
            scanf("%s", veiculo[i].proprietario);
            getchar();

            printf("QUAL O COMBUSTIVEL ? :\n");
            scanf("%s", veiculo[i].combustivel);
            getchar();

            printf("QUAL O MODELO DO CARRO ? :\n");
            scanf("%s", veiculo[i].modelo);
            getchar();

            printf("QUAL A COR ? :\n");
            scanf("%s", veiculo[i].cor);
            getchar();

            printf("QUAL A PLACA ? :\n");
            scanf("%s", veiculo[i].placa);
            getchar();

            printf("QUAL O CHASSI ? :\n");
            scanf("%s", veiculo[i].chassi);
            getchar();

            printf("QUAL O ANO ? :\n");
            scanf("%d", &veiculo[i].ano);
            getchar();
        }
    }
    else
    {
        printf("MAIOR QUE 5000 \n");
        printf("VOLTANDO AO MENU \n");
        main();
    }
    return 0;
}

void imprimir()
{
    printf("=================:\n");
    printf("DONOS E PLACAS:\n");
    for (int i = 0; i < j; i++)
    {
        printf("DONO: %s\n PLACA: %s\n", veiculo[i].proprietario, veiculo[i].placa);
    }
    printf("\n");
}

void listarCarro()
{
    printf("DONOS DE CARRO A DIESEL A PARTIR DE 1980:\n");
    for (int i = 0; i < j; i++)
    {
        if (veiculo[i].ano >= 1980 && strcmp(veiculo[i].combustivel, "diesel") == 0)
        {
            printf("%s\n", veiculo[i].proprietario);
        }
    }
    printf("\n");
}

void listarPlaca()
{
    printf("PLACAS COM A FINAL 0, 2, 4 ou 7:\n");
    for (int i = 0; i < j; i++)
    {
        int len = strlen(veiculo[i].placa);
        char lastChar = veiculo[i].placa[len - 1];
        if (lastChar == '0' || lastChar == '2' || lastChar == '4' || lastChar == '7')
        {
            printf("PLACA: %s\n DONO: %s\n", veiculo[i].placa, veiculo[i].proprietario);
        }
    }
    printf("\n");
}

void listarModelo()
{
    printf("COR COM PLACA IMPAR E SOMA DOS NUMEROS PAR:\n");
    for (int i = 0; i < j; i++)
    {
        if (verificarPlaca(veiculo[i].placa))
        {
            printf("Modelo: %s\nCor: %s\n", veiculo[i].modelo, veiculo[i].cor);
            printf("=================:\n");
        }
    }
    printf("\n");
}

int verificarPlaca(char *placa)
{
    int len = strlen(placa);
    int sum = 0;

    if (len < 2)
    {
        return 0;
    }

    if (isdigit(placa[1]))
    {
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (isdigit(placa[i]))
        {
            sum += placa[i] - '0';
        }
    }

    if (sum % 2 == 0)
    {
        return 1;
    }

    return 0;
}

void trocarProprietario()
{
    char chassi[20];
    int encontrado = 0;
    int trocar;

    printf("================\n");
    printf("DESEJA TROCAR O DONO?:\n");
    printf("1 = SIM\n");
    printf("2 = NAO\n");
    printf("================\n");
    scanf("%i", &trocar);
    getchar();

    if (trocar == 1)
    {
        printf("DIGITE O CHASSI:\n");
        scanf("%s", chassi);
        getchar();

        for (int i = 0; i < j; i++)
        {
            if (strcmp(veiculo[i].chassi, chassi) == 0)
            {
                int possuiZero = 0;
                for (int k = 0; k < strlen(veiculo[i].placa); k++)
                {
                    if (veiculo[i].placa[k] == '0')
                    {
                        possuiZero = 1;
                        break;
                    }
                }

                if (!possuiZero)
                {
                    printf("NOVO DONO DA PLACA %s:\n", veiculo[i].placa);
                    printf("QUAL O NOME DO NOVO DONO ?:\n");
                    scanf("%s", veiculo[i].proprietario);
                    getchar();
                    encontrado = 1;
                    break;
                }
                else
                {
                    printf("NAO PODE SER TROCADO\n");
                    break;
                }
            }
        }

        if (!encontrado)
        {
            printf("CHASSI %s NAO ENCONTRADO.\n", chassi);
        }
        printf("=============\n");
        printf("=============\n");
    }
}
