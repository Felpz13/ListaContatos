#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"

int main()
{
    system("color 17");
    system("mode con:cols=64lines=30");

    Lista *li;
    li = criaLista();

    menu(li);

    return 0;
}
