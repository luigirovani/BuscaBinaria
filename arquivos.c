#include <stdlib.h>
#include <stdio.h>

FILE *arq;

int main(){

	/* Modos de abertura de arquivo
	wb	Escrita a partir do início.
		Se não existir cria.
		Se existir sobrescreve.
	rb	Leitura. O arquivo precisa existir.
	ab	Append. Adiciona dados ao arquivo a partir do FINAL.
		Se não existir cria;
	w+b	Leitura e Escrita no início do arquivo.
		Se existir apaga.
		Se não existir cria um novo.
	r+b	Leitura e escrita no início do arquivo.
		O arquivo deve existir.
	a+b	Leitura no início & Escrita no final.
		Se não existir cria um novo.
	*/	

	
	//TESTE DE ABERTURA DE ARQUIVO
	arq = fopen("saida.dat","rb"); 
	if (arq == NULL){
		printf("Erro na abertura de arquivo.\n");
	}

	
	//ESCREVER EM UM ARQUIVO
	int i = 1988;
	int v[3]={100,200,300};
	
	arq = fopen("saida.dat","wb");
	if(arq == NULL)
		printf("Erro na abertura de arquivo.\n");
	else{
		fwrite(&i,sizeof(int),1,arq);
		fwrite(v,sizeof(int),3,arq);
	}
	fclose(arq);
	
	//LER DE UM ARQUIVO BINÁRIO
	arq = fopen("saida.dat","rb");
	fread(&i,sizeof(int),1,arq);
	printf("i=%d\n",i);

	int w[4];
	fread(w,sizeof(int),4,arq);
	printf("[%d][%d][%d][%d]\n",w[0],w[1],w[2],w[3]);
	
	//FSEEK
	printf("\nFSEEK\n");
	fseek(arq,0,SEEK_SET);
	fread(&i,sizeof(int),1,arq);
	printf("i=%d\n",i);
	fread(&i,sizeof(int),1,arq);
	printf("i=%d\n",i);
	
	printf("\nFSEEK_END\n");
	fseek(arq,2,SEEK_END);
	fread(&i,sizeof(int),1,arq);
	printf("i=%d\n",i);



	//FECHA ARQUIVO
	fclose(arq);

}
