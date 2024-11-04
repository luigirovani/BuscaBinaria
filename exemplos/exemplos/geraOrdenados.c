//-----------------------------------------------------------------------------------
// Gera uma sequencia de numeros positivos aleatorios
// em ordem crescente.
//
// Usa um inteiro longo longo sem sinal valor máximo 18.446.744.073.709.551.615
// Assim podemos testar limites com grande quantidade de dados não repetidos.
//-----------------------------------------------------------------------------------

 
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <math.h>

typedef unsigned long long BIGNUMBER;

/*----------------------------------
 * Função para mostrar os limites de 
 * inteiros na versão do compilador.
 *----------------------------------*/
 void imprimeLimites(){
	//Varia se o compilador for de 32 ou de 64 bits.
	printf("Máximo de long=\t%ld\n",LONG_MAX);//
	printf("Mínimo de long=\t%ld\n",LONG_MIN);	
	printf("Máximo de unsigned long=\t%lu\n",ULONG_MAX);

	printf("Mínimo de long long=%lld\n",LLONG_MIN);
	printf("Máximo de long long=%lld\n",LLONG_MAX);
	
	printf("Máximo unsigned long long=%llu\n",ULLONG_MAX);
}

int main(int argc, char **argv){
	if(argc < 2){
		printf("Uso:\n");
		printf("\t./geraOrdenados <nome do arquivo de saída> <quantidade de inteiros>\n\n");
		exit(1);
	}
	FILE *arq;
	arq = fopen(argv[1],"wb"); //abre o arquivo	
	BIGNUMBER quantidade = atoi(argv[2]);	

	BIGNUMBER num = 1+rand()%100; //gera o primeiro numero aleatório
	for(BIGNUMBER i=0; i<quantidade; i++){
		printf("%lld\tBN=%lld\n",i,num); 
		fwrite(&num,sizeof(BIGNUMBER),1,arq);
		num = num + 1 + rand()%100; //proximo número = anterior + um valor aleatório (==ordenado crescente)
	}

	fclose(arq);	

}
