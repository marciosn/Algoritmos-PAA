#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <algorithm>
using namespace std;


#define NUM_PALAVRAS 40
#define TAM_IDEAL    80

int L[NUM_PALAVRAS + 1];
int prox[NUM_PALAVRAS + 1] = {0};
int tam_restante[NUM_PALAVRAS + 1] = {0};
int M[300] = {0};

int TEXTO_NITIDO_RECURSIVO(int i){

	if (tam_restante[i] <= TAM_IDEAL) return 0;

	int menor = -1;
	int j = i;
	int tam = -1;
	while(tam + 1 + L[j] <= TAM_IDEAL) {
		tam = tam + 1 + L[j];
		int v = TEXTO_NITIDO_RECURSIVO(j + 1) + (TAM_IDEAL - tam) * (TAM_IDEAL - tam);
		if (v < menor) {
			menor = v;
		}
		j = j + 1;
	}
	return menor;
}

int TEXTO_NITIDO_DINAMICO(){
	for (int i = NUM_PALAVRAS; i >= 1; i--) {
		if (tam_restante[i] <= TAM_IDEAL) {
			M[i] = 0;
		} else {
			M[i] = -1;
			int j = i;
			int tam = -1;

			while(tam + 1 + L[j] <= TAM_IDEAL) {
				tam = tam + 1 + L[i];
				int v = M[j + 1] + (TAM_IDEAL - tam) * (TAM_IDEAL - tam);
				if (v < M[i]) {
					M[i] = v;
				}
				j = j - 1;
			}
		}
		return M[1];
	}

}

int main(){

	for (int i = 1; i <= NUM_PALAVRAS; i++) {
		L[i] = std::min( (double) TAM_IDEAL , 1-6 * (double) rand() / RAND_MAX );
	}

	for (int i = NUM_PALAVRAS - 1; i >= 1; i--) {
		tam_restante[i] = tam_restante[i + 1] + 1 + L[i];
	}


	int r = TEXTO_NITIDO_RECURSIVO(NUM_PALAVRAS);
	int r2 = TEXTO_NITIDO_DINAMICO();
	std::cout << "solucao recursiva = " << r << '\n';
	std::cout << "solucao dinamica = " << r2 << '\n';
}