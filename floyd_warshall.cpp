#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <limits>
using namespace std;

#define N 15                      // número de vértices
double w[N+1][N+1] = {0.0};      // pesos das arestas
double D[N+1][N+1][N+1] = {0.0}; // tabela da prog. dinâmica


void inicializa_grafo_aleatorio(){
   double DENSIDADE = 0.8;
   for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) 
         if (((double) rand() / RAND_MAX) < DENSIDADE)
            w[i][j] = N * ((double) rand()) / RAND_MAX;
         else 
            w[i][j] = numeric_limits<double>::infinity();
}

void inicializa_grafo(){
   if (N != 6) {
      inicializa_grafo_aleatorio();
      return;
   }

   for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
         w[i][j] = numeric_limits<double>::infinity();

   enum Vertices {vazio,r,s,t,u,v,W,};
                //      1 2 3 4 5 6
   w[s][r] = 10;
   w[s][u] = 5;
   w[r][W] = 1;
   w[r][u] = 2;
   w[W][t] = 2;
   w[W][v] = 4;
   w[v][s] = 7;
   w[v][W] = 6;
   w[v][t] = 5;
   w[u][r] = 3;
   w[u][W] = 9;
   w[u][v] = 2;
}

void inicializa_matriz(){
	for (int i = 1; i <= N; i++){
      for (int j = 1; j <= N; j++){
      	D[i][j][0] = w[i][j];
      }
	}
}

double floyd_warshall_recursivo(int i, int j, int k){
	if (k == 0) return w[i][j];
	return (double) std::min( floyd_warshall_recursivo(i,j,k-1) , (floyd_warshall_recursivo(i,k,k-1) + floyd_warshall_recursivo(k,j,k-1)));
}

double floyd_warshall_dinamico(){
	inicializa_matriz();

	for(int k = 1; k <= N ; k++){
		for (int i = 1; i <= N ; i++){
	      for (int j = 1; j <= N ; j++){
	      	D[i][j][k] = (double) std::min( D[i][j][k-1], D[i][k][k-1] + D[k][j][k-1] );
	      }
		}
	}
	
}

void perform_recursivo(){
	clock_t ini = clock();
	for (int i = 1; i <= N; i++){
      for (int j = 1; j <= N; j++){
      	double s = floyd_warshall_recursivo(i, j, N);
      	std::cout <<  s << ' ';
      }
       std::cout << '\n';
	}

	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;
	printf(" --> recursivo executou em %f segundos\n", tempo_exec * 1000000);
}

void perform_dinamico(){
	clock_t ini = clock();
	floyd_warshall_dinamico();
	clock_t fim = clock();
	double tempo_exec = (double)(fim - ini) / CLOCKS_PER_SEC;

	//imprime
	for (int i = 1; i <= N; i++){
	      for (int j = 1; j <= N; j++){
	      		double s = D[i][j][N];
	      		std::cout <<  s << ' ';
	      }
	       std::cout << '\n';
	}

	printf(" --> dinamico executou em %f segundos\n", tempo_exec * 1000000);
}

int main(){
	inicializa_grafo();
	perform_recursivo();
	perform_dinamico();
}
