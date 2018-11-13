#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customLib.h"

typedef struct elemento
{
    cto dados;
    struct elemento *prox;

}ELEM;

Lista *criaLista()
{
    Lista *li;

    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL) *li = NULL;

    return li;
}

void carregarLista(Lista li)
{
    FILE *txt;
    cto ctoLocal;

    txt = fopen("contatos.bin", "rb");

    if (txt == NULL)
    {
        printf("BEM VINDO NOVO USUARIO!\n");
        system("pause");
    }

    else
    {
        while (fread(&ctoLocal, sizeof(cto), 1, txt))
        {
            insereCod(li,ctoLocal);
        }

        fclose(txt);
    }
}

void listarContatos(Lista *li)
{
    if(li == NULL) printf("Não existe nenhum contato salvo!!");

    ELEM *no = *li;
    int i = 0;

    while(no != NULL)
    {
        printContato(no->dados);
        no = no->prox;
        i++;
    }
}

int listaVazia(Lista *li)
{
    if (li == NULL) return 1;

    if (*li == NULL) return 1;

    return 0;
}

int insereCod(Lista *li, cto cto)
{
    if (li == NULL) return 0;

    ELEM *no = (ELEM*) malloc(sizeof(ELEM));

    if (no == NULL) return 0;

    no->dados = cto;

    if(listaVazia(li))
    {
        no->prox = (*li);
        *li = no;
        return 1;
    }

    else
    {
        ELEM *ant, *atual = *li;

        while(atual != NULL && atual->dados.cod < cto.cod)
        {
            ant = atual;
            atual = atual->prox;
        }

        if(atual == *li)
        {
            no->prox = (*li);
            *li = no;
        }

        else
        {
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1;
    }
}

int consultaListaNome(Lista *li, char nome[30])
{
    if(li == NULL) return 0;

    ELEM *no = *li;
    char nomeBusca[30], nomeCadastro[30];
    int aux = 0;
    strcpy(nomeBusca,nome);
    strupr(nomeBusca);

    while(no != NULL)
    {
        strcpy(nomeCadastro, no -> dados.nome);
        strupr(nomeCadastro);

        if(strcmp(nomeBusca, nomeCadastro) == 0)
        {
            printContato(no->dados);
            aux = 1;
        }

        no = no->prox;
    }

    return aux;
}

int consultaListaCod(Lista *li, int cod, cto *cto)
{
    if(li == NULL) return 0;

    ELEM *no = *li;

    while(no != NULL && no->dados.cod != cod) no = no->prox;

    if(no == NULL) return 0;

    else
    {
        *cto = no->dados;
        return 1;
    }
}

int modificaContato(Lista *li, int cod, cto *ctoAtual)
{

    if(li == NULL) return 0;

    cto local;
    char opc;

    consultaListaCod(li,cod,&local);

    printContato(local);

    printf("Deseja alterar o contato acima? (s/n)\n");

    fflush(stdin);
    opc = getchar();

    if ((opc == 's') || (opc == 'S'))
    {
        removeLista(li,local.cod);
        local = novoContato();
        insereCod(li,local);

        *ctoAtual = local;

        return 1;
    }

    return 0;
}

int removeLista(Lista *li, int cod)
{
    if(li == NULL) return 0;

    ELEM *ant, *no = *li;

    while(no != NULL && no->dados.cod != cod)
    {
        ant = no;
        no = no->prox;
    }

    if(no == NULL) return 0;

    if(no == *li) *li = no->prox;

    else ant->prox = no->prox;

    free(no);

    return 1;

}

void salvaLista (Lista *li)
{
    FILE *txt;
    ELEM *no = *li;

    txt = fopen("contatos.bin", "wb");

    if (txt == NULL)
    {
        printf("\nErro ao salvar as alterações!\n");
        system("pause");
    }

    else
    {
        while(no != NULL)
        {
            fwrite(&no->dados, sizeof(cto), 1, txt);
            no = no->prox;
        }

        fclose(txt);
    }

    free(no);
}

void apagaLista (Lista *li)
{
    if (li != NULL)
    {
        ELEM *no;
        while((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
