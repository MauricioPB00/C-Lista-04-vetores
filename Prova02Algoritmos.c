#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 30

typedef struct
{
    float maximo;
    float minimo;
    float abertura;
    float fechamento;
} Candle;

void pergunta(Candle[], int);
void carrega(Candle[]);
void media_mes(Candle[], int, float[]);
void menor_preco(Candle[], int);
void fechamento(Candle[], int);
void dia(Candle[], int, float[]);

int main()
{
    int j = 0;
    Candle candle[N];
    float vet[j];

    pergunta(candle, j);
    carrega(candle);
    media_mes(candle, j, vet);
    menor_preco(candle, j);
    fechamento(candle, j);
    dia(candle, j, vet);
}

void pergunta(Candle candle[], int j)
{
    printf(" Quantos dias quer cadastrar ? Maximo de 30 dias");
    scanf("%s", &j);
    if (j < N)
    {
        for (int i = 0; i < j; i++)
        {
            printf("Qual a abertura ?");
            scanf("%s", candle[i].abertura);

            printf("Qual o maximo ?");
            scanf("%s", candle[i].maximo);

            printf("Qual a minimo ?");
            scanf("%s", candle[i].minimo);

            printf("Qual a fechamento ?");
            scanf("%s", candle[i].fechamento);
        }
    }
    else
    {
        printf(" Maior que 30");
        return;
    }
    return j;
}

void carrega(Candle candle[])
{
    int d;
    printf("Deseja carregar quantos dias ?");
    scanf("%i", &d);

    for (int i = 0; i < d; i++)
    {
        printf(" Dia %i ", i);
        printf("Abertura : %f ", candle[i].abertura);
        printf("Fechamento : %f ", candle[i].fechamento);
        printf("Maximo : %f ", candle[i].maximo);
        printf("Minimo : %f ", candle[i].minimo);
    }
}

void media_mes(Candle candle[], int j, float vet[])
{
    
    for (int i = 0; i < j; i++)
    {
        vet[i] = (candle[i].maximo + candle[i].minimo) / 2;
         printf("A media do dia %f", vet[i]);
    }   
}

void menor_preco(Candle candle[], int j)
{
    int menor = 5000;

    for (int i = 0; i < j; i++)
    {
        if (candle[i].abertura < menor)
        {
            menor = 0;
            menor = candle[i].abertura;
        }
    }
    printf("%f", menor);
}

void fechamento(Candle candle[], int j)
{
    int maior = 0;

    for (int i = 0; i < j; i++)
    {
        if (candle[i].fechamento > maior)
        {
            maior = 0;
            maior = candle[i].fechamento;
        }
    }
}

void dia(Candle candle[], int j, float vet[]){
    
    int abertura = 0;
    int dia[j];

    abertura = candle[0].abertura;

    for (int i = 0; i < j; i++)
    {
        if(vet[i] > abertura){
            dia[i]=i;
        }
        abertura = candle[i].abertura;
    }
    
}
