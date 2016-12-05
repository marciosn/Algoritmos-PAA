#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <climits>

using namespace std;

#define N 8

std::list<int> GOrdenadoByF (0,N);

list<int> Adj[N];
list<int> GT[N];
list<int> Q;

enum Cores {branco, preto, cinza};

int cor[N] = {0};
int pi[N] = {0};
int d[N] = {0};
int f[N] = {0};
int tempo = 0;

const char* vert[N] = {"s", "t", "u", "v", "x", "y", "w", "z"};

enum Vertices {s,t,u,v,x,y,w,z};
			 //0,1,2,3,4,5,6,7

void inicializa_grafo(){
   Adj[s].push_back(t);
   Adj[t].push_back(u);
   Adj[t].push_back(x);
   Adj[t].push_back(y);
   Adj[u].push_back(v);
   Adj[u].push_back(w);
   Adj[v].push_back(u);
   Adj[v].push_back(z);
   Adj[x].push_back(s);
   Adj[x].push_back(y);
   Adj[y].push_back(w);
   Adj[w].push_back(y);
   Adj[w].push_back(z);
   Adj[z].push_back(z);
}


void DFS_VISIT(int u){
	list<int>::iterator it;

	cor[u] = cinza;
	tempo = tempo + 1;
	d[u] = tempo;

	for (it=Adj[u].begin(); it != Adj[u].end(); it++){

		if (cor[*it] == branco) {
			pi[*it] = u;
			DFS_VISIT(*it);
		}
	}

	cor[u] = preto;
	tempo = tempo + 1;
	f[u] = tempo;

	GOrdenadoByF.push_front (u);

	printf("f[%s] com o tempo =  %d\n", vert[u], tempo);
}

void DFS(list<int> G[]){
	list<int>::iterator it;
	for (int i = 0;i < N; i ++) {
		cor[i] = branco;
		pi[i] = -1;
	}
	
	tempo = 0;
	for(int j = 0; j < N; j++) {
		if (cor[j] == branco) {
			DFS_VISIT(j);
		}
	}
}

void geraGrafoT(list<int> G[]){
	printf("%s\n", "<<<<<<<<<<<< begin grafo transposto >>>>>>>>>>>>>>");
	list<int>::iterator it;
	for (int i = 0; i < N; i++){
		for (it=Adj[i].begin(); it != Adj[i].end(); it++){
			GT[*it].push_back(i);
			printf("[ %s - %s ] ", vert[*it], vert[i]);
		}
		printf("%s\n", "");
	}
	printf("%s\n", "<<<<<<<<<<<<  end grafo transposto >>>>>>>>>>>>>>");
}

void imprimeAdj(){
	printf("%s\n", "<<<<<<<<<<<<  imprimindo Adj >>>>>>>>>>>>>>");
	list<int>::iterator it;
	for (int i = 0; i < N; i++){
		for (it=Adj[i].begin(); it != Adj[i].end(); it++){
			printf("%s -> %s  ", vert[i], vert[*it]);
		}
		printf("%s\n", "");
	}

	printf("%s\n", "");

	for(int j = 0; j < N; j++){
		printf("d[%s] = %d \t f[%s] = %d\n", vert[j], d[j], vert[j], f[j]);
	}
}

void imprimiGRAFO_ORDENADO(){
	printf("%s\n", "<<<<<<<<<<<<  grafo ordenado por f >>>>>>>>>>>>>>");
	list<int>::iterator it;
	for (std::list<int>::iterator it=GOrdenadoByF.begin(); it!=GOrdenadoByF.end(); ++it){
		printf("vertice = %s indice = %d\n", vert[*it], *it);	
		
	}
}

void getGT(){
	list<int>::iterator it;
	int i = 0;
	for (std::list<int>::iterator it=GOrdenadoByF.begin(); it!=GOrdenadoByF.end(); ++it){
		printf("indice %d vertice %s\n", i, vert[*it]);
		GT[i].push_back(*it);
		i++;
	}
}

int main() {
	inicializa_grafo(); // inicializando grafo
	DFS(Adj);			// executando DFS para obter o f de cada vertice
	geraGrafoT(Adj);	// gerando grafo transposto GT
	DFS(GT);			// aplicando a DFS no grafo transposto GT

   return 0;
}