#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


void titulo(char selecao[15])
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                  Lista de Contatos - ACME                   +\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("\n%s\n", selecao);
}

void menu(Lista li)
{
    int aux;
    char opc, busca[30];
    cto contatoAtual;

    do
    {
        system("cls");

        titulo("");

        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+\t\t1. Novo Contato                               +\n");
        printf("+\t\t2. Lista de Contatos                          +\n");
        printf("+\t\t3. Buscar Nome                                +\n");
        printf("+\t\t4. Buscar Codigo                              +\n");
        printf("+\t\t5. Alterar Contato                            +\n");
        printf("+\t\t6. Remover Contato                            +\n");
        printf("+\t\t7. Sair                                       +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        opc = getch();

        switch (opc)
        {
            case '1':

                system("cls");
                titulo("NOVO CONTATO:\n");
                contatoAtual = novoContato();
                aux = insereCod(li,contatoAtual);
                if(aux) printf("\nInserido com sucesso!\n");
                else printf("\nNao foi possivel inserir o contato!\n");
                system("pause");

                break;

            case '2':

                system("cls");
                titulo("LISTA DE CONTATOS:\n");
                listarContatos(li);
                system("pause");

                break;

            case '3':

                system("cls");
                titulo("BUSCAR - NOME:\n");
                printf("Insira o nome a ser procurado: ");
                fflush(stdin);
                gets(busca);
                aux = consultaListaNome(li,busca);
                if(aux != 1) printf("Contato nao encontrado!!!\n");


                system("pause");

                break;

            case '4':

                system("cls");
                titulo("BUSCAR - COD:\n");
                printf("Insira o codigo a ser procurado: ");
                scanf("%d", &aux);
                aux = consultaListaCod(li,aux,&contatoAtual);
                if(aux) printContato(contatoAtual);
                else printf("Contato nao encontrado!!!\n");
                system("pause");

                break;

            case '5':

                system("cls");
                titulo("ALTERAR CONTATO:\n");
                printf("Insira o codigo a ser procurado: ");
                scanf("%d", &aux);
                aux = modificaContato(li,aux,&contatoAtual);
                if(aux) printf("Contato alterado com sucesso!\n");
                else printf("não foi possivel alterar o contato!!");
                system("pause");

                break;

            case '6':

                system("cls");
                titulo("REMOVER CONTATO:\n");
                printf("Insira o codigo a ser procurado: ");
                scanf("%d", &aux);
                aux = consultaListaCod(li,aux,&contatoAtual);
                if(aux)
                {
                    printContato(contatoAtual);
                    printf("Tem certeza que deseja excluir o contato acima? (s/n): ");
                    fflush(stdin);
                    opc = getchar();

                    if((opc == 's') || (opc == 'S'))
                    {

                        aux = removeLista(li,contatoAtual.cod);
                        if(aux) printf("contato removido com sucesso!!!\n");
                        else printf("Nao foi possivel remover o contato!!!\n");
                    }
                }

                else printf("\nContato nao encontrado!!!\n\n");

                system("pause");

                break;

            case '7':

                salvaLista(li);
                apagaLista(li);
                exit(0);

                break;

            case 'T':

                aux = listaVazia(li);
                if (aux == 1) printf("Lista Vazia!!!\n");
                else printf("Lista com elementos!!!\n");
                system("pause");

                break;
        }

    }while(opc);
}
