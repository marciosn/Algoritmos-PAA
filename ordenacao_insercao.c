#include <stdio.h>
#include <time.h>
#include <string.h>

#define N 100000


void insercao(int A[], int n){
	int chave, i, j;
	for (j = 1; j < n; j++ ){
		chave = A[j];
			for(i = j -1; (i >= 0) && (A[i] > chave); i --)
				A[i + 1] = A[i];
			A[i + 1] = chave;
	}
}

int main(){
	
	int i = 0;
	int A[N], n = N;
	int V[5] = {1, 3, 5, 7, 8};
	
	//for(i = 0; i < N; i++) A[i] = i + 1;
	for(i = 0; i < N; i++) A[i] = N - 1;
	
	clock_t ini = clock();
	insercao(A, n);

	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;
	printf("\n%f segundos\n", tempo_exec * 1000000);
	
	
	return 0;
}


