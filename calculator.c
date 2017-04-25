#include<stdio.h>
int bin_poli[9] = {1, 0, 0, 0, 1, 1, 0, 1, 1};
int bin[8] = {0};
int bin_result[9] = {1};
 poli_result;

void converteb(int);
void leitura();
void imprimeb();
void menu();
void identificador(int);
void somasubtracao();
void multiplicacao();
void divisao();
void transforma();

void leitura(){

    int num;

    printf("Digite um numero entre 0 e 255\n");
    scanf("%d", &num);

    if(num >= 0 && num<=255){
        converteb(num);
    }else{
        num = -1;
        printf("Número invalido!\n");
        leitura();
    }
}
void converteb(int num){

    int i = 7, aux = num;

    while(num > 0){
		// Obtém o resto da divisão de num por 2
		bin[i] = num % 2;
		i--;
		num = num / 2;
	}

	printf("%d em binario: ", aux);

	// percorre o vetor para mostrar o número em binário
	for(i = 0; i < 8; i++){
		printf("%d", bin[i]);
	}
	printf("\n\n");

	menu();
}
void imprimeb(){

    int i;

    printf("Resultado da operacao em binario\n");
    for(i = 0; i < 9; i++){
		printf("%d", bin_result[i]);
	}
	printf("\n\n");
}
void menu(){

    int opcao;

    printf("Selecione a operacao que deseja fazer:\n");
    printf("\t1 - Soma.\n\t2 - Subtracao.\n\t3 - Multiplicacao.\n\t4 - Divisao.\n\n");
    scanf("%d", &opcao);
    printf("\n");
    identificador(opcao);
}
void identificador(int opcao){
    if(opcao == 1){
        somasubtracao();
    }else if(opcao == 2){
        somasubtracao();
    }else if(opcao == 3){
        multiplicacao();
    }else if(opcao == 4){
        divisao();
    }else{
        printf("Opcao invalida.\n");
        menu();
    }
}
void somasubtracao(){

    int i = 0;

    while(i < 9){
        if(bin[i] == bin_poli[i + 1]){
            bin_result[i + 1] = 0;
        }else{
            bin_result[i + 1] = 1;
        }
        i++;
    }
    imprimeb();
    transforma();
}
void multiplicacao(){


    int i = 0;

    while(i < 9){
        if(bin[i] == bin_poli[i + 1]){
            bin_result[i + 1] = 0;
        }else{
            bin_result[i + 1] = 1;
        }
        i++;
    }
}
void divisao(){

    int i = 0;

    while(i < 9){
        if(bin[i] == bin_poli[i + 1]){
            bin_result[i + 1] = 0;
        }else{
            bin_result[i + 1] = 1;
        }
        i++;
    }
}

void transforma(){

    int i = 0, cont = 8;
    printf("Polinomio resultante: ");
    for(i = 0; i < 9; i++){
        if(bin_result[i] != 0){
            if(i == 8){
                printf(" + 1");
            }else if(i == 7){
                printf("x");
            }else{
                printf("x^%d + ", cont);
            }
        }
        cont--;
    }
    printf("\n\n");

}
int main(){

    printf("\t\t\t\t\tCalculadora Polinomial Binaria\n\n");
    printf("Objetivo: fazer operacoes basicas com o polinomio proposto.\nPolinomio: x^8 + x^4 + x^3 + x + 1\n\n");
    leitura();
}
