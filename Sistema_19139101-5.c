#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct Cadastro
{
    int tipo;
    char titulo[100];
    char codigo[30];
    char autor[30];
    char editora[30];
    char ano[5];
    char caixa[10];
    char edicao[5];
    char isbn[30];
    char quantiExemplares[5];
} Obra;

void cadastrarObras(Obra produto[]);
int contarRegistro(Obra produto[]);
void ListarProdutosCategoria(int buscaCategoria, Obra produto[]); 
void ListarProdutosCaixa(Obra produto[]);

int main()
{
    setlocale(LC_ALL, "");
    Obra produto[60];

    int num;
    char resp;
    num = 0;

    printf(">>>> Cicero Jose da Silva Junior <<<<\n");
    printf(">>>> RA: 19139101-5 <<<< \n");
    printf(">>>> Engenharia de Software <<<<\n");

    while (num != 5)
    {
        printf("\n1- Cadastrar as obras\n");
        printf("\n2- Listar Todos os Livros\n");
        printf("\n3- Listar Todas as Revistas\n");
        printf("\n4- Listar Obras por Caixa\n");
        printf("\n5- Sair\n");
        printf("\nDigite a Opção: ");
        scanf("%d", &num);
        printf("*************");
        switch (num)
        {
        case 1:
            system("cls");
            resp = 's';
            while ((resp == 'S') || (resp == 's'))
            {

                cadastrarObras(produto);
                printf("\nDeseja cadastrar uma nova obra? [s] [n]: ");
                scanf("%c", &resp);
            }
            break;
        case 2:
            system("cls");
            ListarProdutosCategoria(1, produto);

            break;

        case 3:
            system("cls");
            ListarProdutosCategoria(2, produto);

            break;

        case 4:
            ListarProdutosCaixa(produto);
            break;

        case 5:
            printf("O Programa está sendo finalizado...");
            return 0;
            break;

        default:
            printf("Digite um número válido");
            break;
        }
    }
}
void cadastrarObras(Obra produto[])
{
    FILE *arq;
    arq = fopen("arquivo.txt", "a+");
    if (arq != NULL)
    {
        int i = 0;
        printf("*********************");
        printf("\nInforme [1] Livro [2] Revista:\n");
        fflush(stdin);
        scanf("%d", &produto[i].tipo);
        printf("\nInforme o Título: ");
        fflush(stdin);
        gets(produto[i].titulo);

        printf("\nInforme o Código: ");
        fflush(stdin);
        gets(produto[i].codigo);

        printf("\nInforme o Autor: ");
        fflush(stdin);
        gets(produto[i].autor);

        printf("\nInforme a Editora: ");
        fflush(stdin);
        gets(produto[i].editora);

        printf("\nInforme o Ano: ");
        fflush(stdin);
        gets(produto[i].ano);

        printf("\nInforme a Edição: ");
        fflush(stdin);
        gets(produto[i].edicao);

        printf("\nInforme o ISBN: ");
        fflush(stdin);
        gets(produto[i].isbn);

        printf("\nInforme a Quantidade de Exemplares: ");
        fflush(stdin);
        gets(produto[i].quantiExemplares);

        printf("\nInforme a Caixa Que Deseja Armazenar: ");
        fflush(stdin);
        gets(produto[i].caixa);

        fwrite(&produto[i], sizeof(Obra), 1, arq);
        i++;
        fclose(arq);
    }
    else
    {
        printf("************");
        printf("\nNão foi possivel abrir o arquivo");
        exit(1);
    }
}

int contarRegistro(Obra produto[])
{
    FILE *arq = fopen("arquivo.txt", "r");
    if (arq != NULL)
    {
        int contador = 0;
        while (1)
        {
            Obra p;

            int registro = fread(&p, sizeof(Obra), 1, arq);

            if (registro < 1)
            {
                break;
            }
            else
            {
                produto[contador] = p;
                contador++;
            }
           
        }
        fclose(arq);
        return contador;
    }
    else
    {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1); 
    }
}


void ListarProdutosCategoria(int buscaCategoria, Obra produto[])
{

    int quantidadeproduto = contarRegistro(produto);
    int i;

    printf("\n>>>> Deseja listar os produtos por categoria <<<< \n");
    
    if (buscaCategoria == 1)
    {
        printf("Categoria pesquisada: Livros \n");
    }
    
    else if (buscaCategoria == 2)
    {
        printf("Categoria pesquisada: Revistas \n");
    }
    else
    {
        printf("Digite um número válido \n");
    }

    for (i = 0; i < quantidadeproduto; i++)
    {
        if (produto[i].tipo == buscaCategoria)
        {
            printf("\nTitulo: %s\n", produto[i].titulo);
            printf("Codigo: %s\n", produto[i].codigo);
            printf("Edicao: %s\n", produto[i].edicao);
            printf("Autor: %s\n", produto[i].autor);
            printf("Editora: %s\n", produto[i].editora);
            printf("ISBN: %s\n", produto[i].isbn);
            printf("Quantidade de exemplares: %s\n", produto[i].quantiExemplares);
            printf("Ano: %s\n", produto[i].ano);
            printf("Caixa: %s\n", produto[i].caixa);
            
            if (produto[i].tipo == 1)
            {
                printf("Tipo: Livro\n\n");
            }
            else
            {
                printf("Tipo: Revista\n\n");
            }
            printf("===================================================\n\n");
        }
    }
}



void ListarProdutosCaixa(Obra produto[])
{
    char buscacaixa[50]; 

   
    system("cls");
    printf("\nQual caixa você deseja pesquisar? ");
    fflush(stdin);
    gets(buscacaixa);

    int quantidadeproduto = contarRegistro(produto);
    int i;
    int vc;
    vc = 0;

    printf("\n>>>> Lista de obras por caixa <<<< \n");
    
    
    printf("Caixa Pesquisada: %s \n", buscacaixa);

    for (i = 0; i < quantidadeproduto; i++)
    {
      
        if (strcmp(produto[i].caixa, buscacaixa) == 0)
        {
            printf("\nTitulo: %s\n", produto[i].titulo);
            printf("Edicao: %s\n", produto[i].edicao);
            printf("Autor: %s\n", produto[i].autor);
            printf("Editora: %s\n", produto[i].editora);
            printf("ISBN: %s\n", produto[i].isbn);
            printf("Quantidade de exemplares: %s\n", produto[i].quantiExemplares);
            printf("Ano: %s\n", produto[i].ano);
            printf("Caixa: %s\n", produto[i].caixa);
            if (produto[i].tipo == 1)
            {
                printf("Tipo: Livro\n\n");
            }
            else
            {
                printf("Tipo: Revista\n\n");
            }
            printf("===================================================\n\n");
           vc++;
        }
    }if (vc == 0){
        printf("\nNão foi possível encontrar a caixa");
    }
}
