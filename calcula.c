#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

int main()
{
    int num = 0; // variavel para um numero base 10 que sera informado pelo usuario
    int binario[MAX]; //vetor para guardar o numero em binario
    int i = 0; //j; //variaveis para controle do for
    int num_aux = 0; //variavel auxiliar
    int opcao=0;
    int num_bin=0, total = 0, resto=0;
    int potencia = 0;

    do {
    printf("\n|---------------------------|");
    printf("\n|---CALCULADORA DE BASES----|");
    printf("\n| 1 - Decimal para binario--|");
    printf("\n| 2 - Binario para decimal--|");
    printf("\n| 3 - Sair------------------|");
    printf("\n|---------------------------|");
    printf("\n");
    printf("Selecione a sua opcao: ");
    scanf("%i", &opcao);

    switch(opcao){
		case 1:
		    printf("Entre com um numero decimal: ");
            scanf("%d", &num);

            num_aux = num;
            i = 0;
            while(num > 0)
            {
                /* para a convers‹o de decimal para binario, s‹o feitas sucessivas divisoes por 2 e o resultado eh armazenado no vetor chamado binario, cujo o
                indice eh i*/
                binario[i] = num % 2;
                i ++;
                num = num / 2;
            }
            printf("%d em binario: ", num_aux); //exibe o resultado com o numero inicialmente digitado pelo usuario

            for(i= i-1; i>=0; i--) //para percorrer o vetor montado e mostar o numero em binario
                printf("%d", binario[i]); //exibe o resultado como o valor convertido para o usuario.

            //for(j = i-1; j>=0; j--) //para percorrer o vetor montado e mostar o numero em binario
            //    printf("%d", binario[j]); //exibe o resultado como o valor convertido para o usuario.


            printf("\n");

        //return 0;
        break;

		case 2:
		    num_bin = 0;
		    total = 0;
		    potencia = 0;
			printf("Entre com um numero binario: ");
            scanf("%d", &num_bin);

            num_aux = num_bin;
            //total = 0;

            while(num_bin >0)
            {
                /* para a convers‹o de binario para decimal, utiliza-se o metodo polinomial, em que s‹o feitas sucessivas adicoes, multiplicando-se
                (da direita para a esquerda) o valor binario por 2, elevando-se a potencia que representa a sua posicao no numero binario*/

                total = total + (num_bin % 10) * pow(2, potencia);
                num_bin = num_bin / 10; // para buscar o proximo numero da direita para a esquerda.
                potencia = potencia + 1; // incrementa a potencia, pois estamos buscanodo o proximo numero na linha de comando acima.

            }
            printf("%d", num_aux); //exibe o resultado com o numero inicialmente digitado pelo usuario
            printf(" equivale a %d em decimal \n", total); //exibe o resultado como o valor convertido para o usuario


        //return 0;
        break;

		//default:
			//printf("Opcao invalida!\n");

    }
    } while (opcao != 3);
    printf("\n FIM!!! \n");
}
