//Importações
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**************************************************
    TESTE DE VETOR
    @DATE 11/10/2016
    @AUTHOR JONATHAN DOUGLAS DIEGO TAVARES
    @FUNCAO: TESTAR FUNCÕES PARA ATUAR COM VETORES
**************************************************/
/****************************************************
IMPORTANTE:
A PRIMEIRA POSICÃO É PARA GUARDAR O TAMANHO DO VETOR
****************************************************/


/****************************
OPERAÇÕES BÁSICAS DE HUD
****************************/
//limpa tela
void limparTela(){
    system("CLEAR");
}

//printa o vetor na tela
void printar(int *vetor){
    int i = 0;

    if (testaNulo(vetor) == 1){
        printf("ERRO(printar): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            printf("Posicao %d: %d\n", i, vetor[i]);
        }
    }
}

void pausar(){
    printf("Pressione qualquer tecla para continuar.\n");
    getchar();
}

void separar(){
     printf("-------------------------\n");
}



/*****************************************
            OPERAÇÕES BÁSICAS
*****************************************/
//testa se vetor nulo
int testaNulo(int *vetor){
    if (vetor == NULL){
        return 1;
    } else {
        return 0;
    }
}

//zera o vetor
void zeraVetor(int *vetor){
    int i;
    if (testaNulo(vetor) == 1){
        printf("ERRO(zeraVetor): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            vetor[i] = 0;
        }
    }
}

//aloca vetor inteiro dinamicamente
int* alocaVetor(int quantidade){
    int *vetor;

    if (quantidade <= 0){
        printf("ERRO(alocaVetor): Quantidade inválida para criação do vetor.\n");
        return NULL;
    } else {
        vetor = (int *)malloc(sizeof(int) * (quantidade + 1));

        if (testaNulo(vetor) == 1){
            printf("ERRO(alocaVetor): Não foi possível alocar a quantidade de memória desejada.\n");
        } else {
            vetor[0] = quantidade;
            zeraVetor(vetor);
        }
    }

    return vetor;
}

//devolve o tamanho do vetor (atualmente bugado por algum motivo que eu ainda não sei)
int tamanho(int *vetor){
    int tamanho = 0;
    int i = 0;

    if (testaNulo(vetor) == 1){
        printf("ERRO(tamanho): O vetor fornecido é nulo.\n");
    } else {
        tamanho = sizeof(vetor)/sizeof(vetor[0]);
    }
    return tamanho;
}

//clona vetor
int* clone(int *vetor){
    int tamanho, i;
    int *vetorClone;

    if (testaNulo(vetor) == 1){
        printf("ERRO(clone): O vetor fornecido é nulo.\n");
    } else {
        tamanho = vetor[0];
        vetorClone = alocaVetor(tamanho);

        if (testaNulo(vetorClone) == 1){
            printf("ERRO(clone): Não foi possível alocar a quantidade de memória desejada.\n");
        } else {
            for (i = 1; i <= tamanho; i++){
                vetorClone[i] = vetor[i];
            }
        }
    }

    return vetorClone;
}

/**************************************
        LEITURA DE DADOS
*************************************/
//preencher o vetor
void preencher(int *vetor){
    int i;

    if (testaNulo(vetor) == 1){
        printf("ERRO(preencher): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            printf("Posicao %d: ");
            scanf("%d", &vetor[i]);
            printf("\n");
        }
    }
}

//preenche com valores randomicos
void preencherRand(int *vetor, int limite){
    int i;

    if (testaNulo(vetor) == 1){
        printf("ERRO(preencher): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            vetor[i] = rand() % limite;
        }
    }
}

/***********************
OPERAÇÕES MATEMÁTICAS
***********************/

//Operações com vetores

//soma escalar ao vetor
void somaEscalar(int escalar, int *vetor){
    int i;
    if (testaNulo(vetor) == 1){
        printf("ERRO(somaEscalar): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            vetor[i] = vetor[i] + escalar;
        }
    }
}

//subtrai escalar do vetor
void subtraiEscalar(int escalar, int *vetor){
    int i;
    if (testaNulo(vetor) == 1){
        printf("ERRO(subtraiEscalar): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            vetor[i] = vetor[i] - escalar;
        }
    }
}

//multiplica escalar pelo vetor
void multEscalar(int escalar, int *vetor){
    int i;
    if (testaNulo(vetor) == 1){
        printf("ERRO(multEscalar): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            vetor[i] = vetor[i] * escalar;
        }
    }
}

//divide escalar pelo vetor

void divideEscalar(int escalar, int *vetor){
    int i;
    if (testaNulo(vetor) == 1){
        printf("ERRO(divideEscalar): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            vetor[i] = vetor[i] / escalar;
        }
    }
}

//soma todos elementos de a com b e armazena em a ( se tamanho(a) == tamanho(b) )

void somaVet(int *vet1, int *vet2){
    int i;

    if (testaNulo(vet1) == 1 || testaNulo(vet2) == 1){
        printf("ERRO(somaVet): O vetor fornecido é nulo.\n");
    } else if (tamanho(vet1) != tamanho(vet2)){
        printf("ERRO(somaVet): O tamanho do vetor 1 é diferente do vetor 2.\n");
    } else {
        for(i = 1; i <= vet1[0]; i = i + 1){
            vet1[i] = vet1[i] + vet2[i];
        }
    }
}

//subtrai elementos b de a e armazena em a ( se tamanho(a) == tamanho(b) )
void subtraiVet(int *vet1, int *vet2){
    int i;

    if (testaNulo(vet1) == 1 || testaNulo(vet2) == 1){
        printf("ERRO(subtraiVet): O vetor fornecido é nulo.\n");
    } else if (tamanho(vet1) != tamanho(vet2)){
        printf("ERRO(subtraiVet): O tamanho do vetor 1 é diferente do vetor 2.\n");
    } else {
        for(i = 1; i <= vet1[0]; i = i + 1){
            vet1[i] = vet1[i] - vet2[i];
        }
    }
}

/*********************************
            ORDENAÇÃO
*********************************/
//ordena vetor crescente (método de bolha)
void bubblesortCresc(int *vetor){
    int i;
    int j;
    int temp;

    if(vetor == NULL){
        printf("ERRO(bubblesortCresc): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            for (j = 1; j <= vetor[0]; j = j + 1){
                if (vetor[i] > vetor[j]){
                    temp = vetor[j];
                    vetor[j] = vetor[i];
                    vetor[i] = temp;
                }
            }
        }
    }
}

//orderna vetor decrescente (método de bolha)
void bubblesortDec(int *vetor){
    int i;
    int j;
    int temp;

    if(vetor == NULL){
        printf("ERRO(bubblesortDec): O vetor fornecido é nulo.\n");
    } else {
        for (i = 1; i <= vetor[0]; i = i + 1){
            for (j = 1; j <= vetor[0]; j = j + 1){
                if (vetor[i] < vetor[j]){
                    temp = vetor[j];
                    vetor[j] = vetor[i];
                    vetor[i] = temp;
                }
            }
        }
    }
}

//calcula a média do vetor (total/quantidade)
int calcMedia(int *vetor){
    int i = 0;
    int soma = 0;
    if (testaNulo(vetor) == 1){
        printf("ERRO(calcMedia): O vetor fornecido é nulo.\n");
    } else {
        for(i = 1; i <= vetor[0]; i = i + 1){
            soma = soma + vetor[i];
        }
    }

    return soma/vetor[0];
}

/***********************
      UTILITÁRIOS
***********************/
void atualizarSeed(){
    //seed
    srand(time(0));
}

//protótipo de teste
void testeSimples();

void teste2();

/***************************
            MAIN
***************************/
int main(){
    atualizarSeed();
    //selecione o teste desejado
    //teste1();
    //teste2();
    //teste3();

    //vazio
    return 0;
}//fim main



/*********************************
               Testes
*********************************/

void teste3(){
    int *vetor = alocaVetor(5);
    preencherRand(vetor, 100);
    printar(vetor);
    int *vetor2 = clone(vetor);
    printf("----------------\n");
    printar(vetor2);
}

void teste2(){
    int *vetor = alocaVetor(5);
    int media;

    zeraVetor(vetor);
    preencherRand(vetor, 5);
    printar(vetor);

    printf("--------------------------\n");

    media = calcMedia(vetor);

    printf("A média do vetor é: %d",media);

}
void testeSimples(){
    int *vet1 = alocaVetor(5);
    int *vet2 = alocaVetor(5);


    //TESTES SIMPLES
    printf("tamanho (vet1) = %d\n",vet1[0]);
    printf("tamanho (vet2) = %d\n",vet2[0]);
    separar();

    printf("Mostra os vetores inicializados: \n\n");

    printar(vet1);
    separar();

    printar(vet2);
    separar();

    printf("Faz valores randômicos: \n\n");

    preencherRand(vet1,10);
    printar(vet1);
    separar();

    preencherRand(vet2,10);
    printar(vet2);
    separar();

    //TESTES DE OPERAÇÕES MATEMÁTICAS

    printf("Operações matemáticas(soma,sub,mult,div) usando escalar = 2 e vet1: \n\n");

    somaEscalar(2,vet1);
    printar(vet1);
    separar();

    subtraiEscalar(2,vet1);
    printar(vet1);
    separar();

    multEscalar(2,vet1);
    printar(vet1);
    separar();

    divideEscalar(2,vet1);
    printar(vet1);
    separar();

    //TESTES ENTRE VETORES
    printf("Soma e subtrai vet1 e vet2 (resposta em vet1): \n\n");

    somaVet(vet1,vet2);
    printar(vet1);
    separar();

    subtraiVet(vet1,vet2);
    printar(vet2);
    separar();

    //TESTA ORDENAÇÃO

    printf("Ordena vet1: \n\n");

    bubblesortCresc(vet1);
    printar(vet1);
    separar();

    bubblesortDec(vet1);
    printar(vet1);
    separar();

    //libera memória
    free(vet1);
    free(vet2);
}
