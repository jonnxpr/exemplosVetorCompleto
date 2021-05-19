/*
	Função: Trabalhar com strings
	Autor: Jonathan Douglas Diego Tavares
	Data: 21/10/2016
*/

//Importações
#include<stdio.h>
#include<stdlib.h>

/****************************
OPERAÇÕES BÁSICAS DE HUD
****************************/

void imprimirErro(char* origem, char* erro){
    printf("ERRO(%s): %s.\n", origem, erro);
}

//limpa tela
void limparTela(){
    system("CLEAR");
}

void separar(){
     printf("-------------------------\n");
}

void pausar(){
    printf("Pressione qualquer tecla para continuar.\n");
    getchar();
}

//printa a string na tela
void printar(char* string){

    if (testaNulo(string) == 1){
        imprimirErro("printar", "A string fornecida é nula");
    } else {
        printf("string = %s\n",string);
    }
}

/*****************************************
            OPERAÇÕES BÁSICAS
*****************************************/

//testa se vetor nulo
int testaNulo(char* string){
    if (string == NULL){
        return 1;
    } else {
        return 0;
    }
}

int strlen(char* string){
    int tamanho = 0;
    char *p = NULL;
    if (testaNulo(string) == 1){
        imprimirErro("strlen","A string fornecida é nula");
    } else {
        for (p = string; *p != '\0'; p++){
            tamanho = tamanho + 1;
        }
    }
    return tamanho;
}

void *strcpy2(char *p,char const *q, int n)
{

    while( n-- >= 1  && (*p++=*q++)){
    }//enter code here

   //return saved;
}

void *strcpy1(char *p,char const *q)
{

    while((*p++=*q++));//enter code here

   //return saved;
}

void strcat(char *destino, char *origem){

    while(*destino){
        destino++;
    }

    while((*destino++ = *origem++));
}

char* substring(int inicio, char* string){
    char* buffer = &string;

    while(inicio-- >= 1){
        buffer++;
    }

    return buffer;
}

//Início do main()
int main(int argc, char *argv[]){
    char teste[] = {"maria"};
    char *teste2 = substring(1, teste2);

    printar(teste);

	return 0;
}//Fim main()
