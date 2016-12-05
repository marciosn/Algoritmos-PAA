#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <algorithm>
using namespace std;

#define N 20
#define W 10
int P[] = {0};
double V[] = {0};
double M[W+1][N+1] = {0};

double MOCHILA_RECURSIVA(int w, int i){
	if (i == 0) return 0;

	if (P[i] <= w) {
		return std::max( V[i] + MOCHILA_RECURSIVA( w - P[i], i - 1 ), MOCHILA_RECURSIVA( w, i-1 ) );
	}
	return MOCHILA_RECURSIVA(w, i-1);

}

double MOCHILA_MEMORIZACAO(int w, int i){

	for (int j = 0; j < W; j++) {
		M[j][0] = -1;
	}

	for (int k = 0; k < N; k++) {
		M[0][k] = -1;
	}

	double result = 0;

	if (i == 0) return 0;

	if (M[w][i] != -1) {
		return M[w][i];	
	} else {
		if (P[i] <= w) {
			result = std::max( V[i] + MOCHILA_MEMORIZACAO( w - P[i], i - 1 ), MOCHILA_MEMORIZACAO( w, i-1 ) );
			M[w][i] = result;
			return result;
		}
		M[w][i] = MOCHILA_MEMORIZACAO(w, i-1);
		return M[w][i];
	}
}

double MOCHILA_DINAMICA(){
	for (int i = 0; i <= N; i ++) {
		for (int w = 0; w <= W; w++) {
			if (P[i] <= w) {
				M[w][i] = std::max( V[i] + M[w-P[i]][i -1], M[w][i-1] );
			} else {
				M[w][i] = M[w][i-1];
			}
		}
	}
	return M[W][N];
}

void performMochilaRecursiva(){
	clock_t ini = clock();

	double s = MOCHILA_RECURSIVA(W, N);
	std::cout << "solucao recursiva = " << s << '\t';

	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;
	printf("\t| executou em %f segundos\n", tempo_exec * 1000000);

}

void performMochilaMemorizacao(){
	clock_t ini = clock();	

	double s2 = MOCHILA_MEMORIZACAO(W, N);
	std::cout << "solucao memorizacao = " << s2 << '\t';

	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;
	printf("| executou em %f segundos\n", tempo_exec * 1000000);
}

void performMochilaDinamica(){

	for (int j = 0; j < W; j++) {
		M[j][0] = 0;
	}

	for (int k = 0; k < N; k++) {
		M[0][k] = 0;
	}

	clock_t ini = clock();

	double s3 = MOCHILA_DINAMICA();
	std::cout << "solucao dinamica = " << s3 << '\t';

	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;
	printf("\t| executou em %f segundos\n", tempo_exec * 1000000);
}


int main(){

for (int i = 0; i < N; i++) {
   	P[i] = W * (double) rand() / RAND_MAX;
   	V[i] = (double) rand() / RAND_MAX;
}

	performMochilaRecursiva();
	performMochilaMemorizacao();
	performMochilaDinamica();
}