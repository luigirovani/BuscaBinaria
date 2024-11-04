#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::srand;


static void buscaSequencial(const vector<int>& vetor, int& count, int elemento) {
    for (size_t i = 0; i < vetor.size(); ++i) {
        count++;
        if (vetor[i] == elemento) {
            break;
        }
    }
}

static void buscaBinaria(const vector<int>& vetor, int& count, int elemento) {
    int inicio = 0;
    int fim = vetor.size() - 1;

    while (inicio <= fim) {
        count++;
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == elemento)
            break;

        if (vetor[meio] < elemento)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

}

static void binaria(const vector<int>& vetor, int tentativas) {
	int count = 0;

    for (int i = 0; i < tentativas; i++) {
        int elemento = vetor[std::rand() % vetor.size()];
        buscaBinaria(vetor, count, elemento);
    }
    int media = count / tentativas;
    cout << "Media da busca binaria: " << media << endl;
}

static void sequencial(const vector<int>& vetor, int tentativas) {
    int count = 0;

    for (int i = 0; i < tentativas; i++) {
        int elemento = vetor[std::rand() % vetor.size()];
        buscaSequencial(vetor, count, elemento);
    }
    int media = count / tentativas;
    cout << "Media da busca sequencial: " << media << endl;
}


int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    int amostras = 1000;
    int minimo = 0;
    int tentativas = 1000;
    vector<int> vetor;
    
	for (int i = 0; i < amostras; i++) {
		int num = minimo + (rand() % (amostras - minimo + 1));
		cout << num << " ";
		vetor.push_back(num);
    }

	sequencial(vetor, tentativas);
	binaria(vetor, tentativas);
    return 0;
}

