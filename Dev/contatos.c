#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"

cto novoContato()
{
    cto novo;

    printf("Insira o Codigo do contato: ");
    scanf("%d", &novo.cod);

    printf("Insira o nome do contato: ");
    fflush(stdin);
    gets(novo.nome);

    printf("Insira a Empresa que o contato ""%s"" trabalha: ", novo.nome);
    fflush(stdin);
    gets(novo.empresa);

    printf("Insira o Departamento da empresa ""%s"" que o contato ""%s"" trabalha: ", novo.empresa, novo.nome);
    fflush(stdin);
    gets(novo.departamento);

    printf("Insira o Telefone fixo do contato ""%s"": ", novo.nome);
    scanf("%d", &novo.telefone);

    printf("Insira o Telefone celular do contato ""%s"": ", novo.nome);
    scanf("%d", &novo.celular);

    printf("Insira o E-mail do contato ""%s"": ", novo.nome);
    fflush(stdin);
    gets(novo.email);

    printContato(novo);

    return novo;
}

void printContato(cto cto)
{
    printf("\n---------------------------------------------------------------\n");
    printf("COD: %d\t\t\t\t\tNOME: %s\n", cto.cod, cto.nome);
    printf("EMP: %s\t\t\t\tDEP: %s\n", cto.empresa, cto.departamento);
    printf("TEL: %d\t\t\t\tCEL: %d\n", cto.telefone, cto.celular);
    printf("EMAIL: %s", cto.email);
    printf("\n---------------------------------------------------------------\n");
}
