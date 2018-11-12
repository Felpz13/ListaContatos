#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"

int main()
{
    system("color 17");

    Lista *li;
    li = criaLista();

    carregarLista(li);

    menu(li);

    return 0;
}
