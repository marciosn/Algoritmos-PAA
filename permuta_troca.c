#include <stdio.h>
#include <time.h>
#include <string.h>

#define N 100000

void troca(char *x, char *y){
	char temp; temp = *x; *x = *y; *y = temp;
}

void permuta(char *s, int ini, int fim){
int i = 0;
	if(ini == fim) return; 

		else
		
		for(i = ini; i <= fim; i++){
			troca(&s[ini], &s[i]);
			permuta(s, ini + 1, fim);
			troca(&s[ini], &s[i]);
		}
	
}

int main(){
	
	int i = 0;	
	clock_t ini = clock();
	char s[] = "1234567";
	permuta(s, 0, strlen(s) - 1);
	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;
	printf("\n%f segundos\n", tempo_exec * 1000000);
	
	
	return 0;
}


