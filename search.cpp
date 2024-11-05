//Luigi Augusto Rovani
//Maria Julia Leandro Leal da Rocha
//Pedro Augusto De Lima Oliveira
//Vithoria Cabreira

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <locale>
#include <limits>




const int min_value = 0;
const int sample = 100;
const int min_length = 10;
const auto max_length = 100000000; // 1 bilhão

using std::vector;
using std::cout;
using std::endl;

class Busca {
protected:
    long int count;

public:
    Busca() : count(0) {}

    virtual void buscar(const vector<int>& vetor, int elemento) = 0;

    void testar(const vector<int>& vetor, int tentativas) {
        count = 0;
        std::random_device rd;
        std::mt19937 gerador(rd());
        std::uniform_int_distribution<int> distribuicao(0, vetor.size() - 1);

        for (int i = 0; i < tentativas; i++) {
            int elemento = vetor[distribuicao(gerador)];
            buscar(vetor, elemento);
        }
        int media = count / tentativas;
        cout << " " << media << endl;
    }

};

class BuscaSequencial : public Busca {
public:
    void buscar(const vector<int>& vetor, int elemento) override {
        for (size_t i = 0; i < vetor.size(); ++i) {
            count++;
            if (vetor[i] == elemento) {
                break;
            }
        }
    }
};

class BuscaBinaria : public Busca {
public:
    void buscar(const vector<int>& vetor, int elemento) override {
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
};

static vector<int> gen_vector(int len_vector) {
    vector<int> vetor(len_vector);

    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<int> distribuicao(min_value, len_vector * 10);

    for (int& valor : vetor) {
        valor = distribuicao(gerador);
    }

    std::sort(vetor.begin(), vetor.end());
    return vetor;
}

static void test(int len_vector) {
    vector<int> vetor = gen_vector(len_vector);
    cout << "Testando com vetor de tamanho: " << len_vector << endl;

    BuscaSequencial buscaSeq;
    cout << "Média Busca Sequencial: ";
    buscaSeq.testar(vetor, sample);

    BuscaBinaria buscaBin;
    cout << "Média Busca Binária: ";
    buscaBin.testar(vetor, sample);

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");
    for (int i = min_length; i <= max_length; i *= 10) {
        test(i);
    }

}


