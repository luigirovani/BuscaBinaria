#include <stdio.h>
#include <stdlib.h>


typedef unsigned long long BIGNUMBER;
FILE *arq;

//Faz a busca sequencial no arquivo
// x: o valor a ser buscado
// n: o número de registros no arquivo
// arq: o arquivo contendo os dados
// contador: uma variável auxiliar para contar a quantidade de comparações até encontrar x.
int buscaSequencial(BIGNUMBER x, BIGNUMBER n, FILE *arq, BIGNUMBER *contador){
	BIGNUMBER i;
	BIGNUMBER fim = n-1;
	BIGNUMBER valor;
	*contador = 0;
	for(i=0; i<n; i++){
		*contador = *contador + 1;
		
		fseek(arq,i*sizeof(BIGNUMBER),SEEK_SET); 	//posiciona cursor no arquivo binario na posiçã i.
		fread(&valor,sizeof(BIGNUMBER),1,arq);		//le valor na posicao
		if(valor == x) return i; //se encontrou devolve a posição i.
	}
	return n; //se não encontrou devolve n (o tamanho do arquivo em número de registros).
}




int main(int argc, char **argv){
	arq = fopen(argv[1],"rb");	
	BIGNUMBER n = atoi(argv[2]);
	BIGNUMBER x = atoi(argv[3]);
	BIGNUMBER contador = 0;
	BIGNUMBER p;
	
	BIGNUMBER k = 0;
	
	//p = buscaBinaria(x,n,arq,&contador);
	//printf("P=%lld\tContador binaria:    %lld\n",p,contador);
	// IMPLEMENTAR A BUSCA BINÁRIA

	//Faz 100 buscas no arquivo.
	for(BIGNUMBER i = 0; i< 100; i++){
		BIGNUMBER x = rand();
		p = buscaSequencial(x,n,arq,&contador);	
		k = k + contador;
		//printf("P=%lld\tContador sequencial: %lld\n",p,contador);
	}
	printf("Média das buscas = %llu\n",(k/100));
	fclose(arq);

}
