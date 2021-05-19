/*
	Função:
	Autor: Jonathan Douglas Diego Tavares
	Data: xx/xx/xxxx
*/

//Importações
#include<stdio.h>
#include<stdlib.h>

/****************************
OPERAÇÕES BÁSICAS DE HUD
****************************/

//limpar a tela
void limparTela(){
    system("CLEAR");
}

//separador de hud
void separar(){
     printf("-------------------------\n");
}

//solicita input para continuar
void pausar(){
    printf("Pressione qualquer tecla para continuar.\n");
    getchar();
}

/*****************************************
            OPERAÇÕES BÁSICAS
*****************************************/
//imprime um erro na tela
void imprimirErro(char* origem, char* erro){
    printf("ERRO(%s): %s.\n", origem, erro);
}

typedef struct{
    char *nome;
    double preco;
    int quantidade;
} Produto;

Produto* aloca(int quantidade){
    Produto *prod = (Produto*)calloc(sizeof(Produto),quantidade);
    (*prod).nome = (char*)calloc(sizeof(char), 50);
    return prod;
}

void setProd(Produto *prod, const char *nome, double preco, int quantidade){
    (*prod).nome = nome;
    (*prod).preco = preco;
    (*prod).quantidade = quantidade;
}

void preenche(Produto *prods, int quantidade){
    while(quantidade-- >= 1){
        (*prods).nome = "teste";
        (*prods).preco = 3.0;
        (*prods).quantidade = quantidade;
    }
}

void mostra(Produto *prods, int quantidade){
    while(quantidade-- >= 1 && prods != NULL){
        printf("Nome: %s\n", (*prods).nome);
        printf("Preço: %f\n", (*prods).preco);
        printf("Quantidade: %d\n", (*prods).quantidade);
        prods++;
    }
}

//Início do main()
int main(int argc, char *argv[]){
    Produto *produtos = aloca(10);
    //setProd(produtos, "Toddynho", 2.0, 1);
    preenche(produtos, 1);
    mostra(produtos,2);
	return 0;
}//Fim main()
