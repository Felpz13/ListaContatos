#ifndef CUSTOMLIB_H_INCLUDED
#define CUSTOMLIB_H_INCLUDED

typedef struct contato
{
    int cod, telefone, celular;
    char nome[30], empresa[30], departamento[30], email[20];

}cto;

cto novoContato();

void printContato(cto cto);

void titulo(char selecao[15]);

void menu();

typedef struct elemento* Lista;

Lista *criaLista();

void listarContatos(Lista *li);

int consultaListaNome(Lista *li, char nome[30]);

int consultaListaCod(Lista *li, int cod, cto *cto);

int insereCod(Lista *li, cto cto);

int modificaContato(Lista *li, int cod, cto *cto);

int removeLista(Lista *li, int cod);

void salvaLista (Lista *li);

void apagaLista (Lista *li);

int listaVazia(Lista *li);

#endif // CUSTOMLIB_H_INCLUDED
