/*
	Fun��o:
	Autor: Jonathan Douglas Diego Tavares
	Data: xx/xx/xxxx
*/

//Importa��es
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/****************************
OPERA��ES B�SICAS DE HUD
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
            OPERA��ES B�SICAS
*****************************************/
//imprime um erro na tela
void imprimirErro(char* origem, char* erro){
    printf("ERRO(%s): %s.\n", origem, erro);
}

char* strchar(char *string, char *ch){
    char* res = NULL;
    do{
        if (*string == ch){
            res = string;
            return &(*res);
        }
    }while(*string++ != '\0');

    return &(*res);
}

int strlen(const char* string){
    int tamanho = 0;

    while(*string && *string != '\0'){
        tamanho++;
        string++;
    }
    return tamanho;
}

char* strstr2(const char *str, const char *target) {
    if (!*target){
            return (char*)str;
    }

    char *p1 = (char*)str;
    while (*p1) {
        char *p1Begin = p1, *p2 =(char*) target;
        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (!*p2){
            return p1Begin;
        }
        p1 = p1Begin + 1;
    }
    return NULL;
}


void preenche(int *v){
    int i = 1;
    while(i <= v[0]){
        v[i] = rand()%100;
        i = i + 1;
    }
}

int* aloca(int quantidade){
    int* vetor = (int*)calloc(sizeof(int),quantidade+1);
    vetor[0] = quantidade;
    preenche(vetor);

    return vetor;
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void printa(int *v){
    int i = 1;
    while(i <= v[0]){
        printf(" %d ", v[i]);
        i = i + 1;
    }
    printf(" \n ");
}

void calc(int *v, int num, int *xmin, int *xmax){
    *xmin = v[1];
    *xmax = v[1];

    int i = 1;

    while(num >= 1){

        if (*xmin > v[i]){
            int *temp = *xmin;
            *xmin = v[i];
            v[i] = temp;
        }

        if(*xmax < v[i]){
            int *temp = *xmax;
            *xmax = v[i];
            v[i] = temp;
        }

        i = i + 1;
        num = num - 1;
    }
}

//In�cio do main()
int main(int argc, char *argv[]){
	srand(time(NULL));
	int *vetor = aloca(10);
	printa(vetor);

	int *menor = aloca(1);
	int *maior = aloca(1);
	int num = 10;

	calc(vetor, num, menor, maior);
	printf("maior: %d , menor: %d\n", *maior, *menor);

	system("pause");
	return 0;
}//Fim main()
