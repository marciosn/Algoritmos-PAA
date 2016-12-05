#include <stdio.h>
#include <time.h>
#include <string.h>

#define N 5


void imprime_bits(int b[], int n){
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d", b[i]);
	printf("\n");
}

void seq_bits(){
	int b[N] = {0}, i;
	while (i){
	//imprime_bits(b, N);
	for (i = N-1; (i >= 0) && (b[i] == 1); i--)
		b[i] = 0;
	if(i < 0) break;
		b[i] = 1;
	}
}

int main(){
	
	int i = 0;
	clock_t ini = clock();
	seq_bits();
	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;
	printf("\n%f segundos\n", tempo_exec * 1000000);
	return 0;
}


