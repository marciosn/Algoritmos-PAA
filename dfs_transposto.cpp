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

	//printf("f[%s] \t tempo =  %d\n", vert[u], tempo);
}

void DFS(list<int> G[]){
	//printf("%s\n", "===== begin DFS =====");
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
	//printf("%s\n", "===== end DFS =====");
}

void DFS_VISIT_GT(int u){
	list<int>::iterator it;

	cor[u] = cinza;
	tempo = tempo + 1;
	d[u] = tempo;

	printf("verificando adjacentes de %s\n", vert[u]);
	for (it=GT[u].begin(); it != GT[u].end(); it++){
		if (cor[*it] == branco) {
			pi[*it] = u;
			DFS_VISIT_GT(*it);
		}
	}

	cor[u] = preto;
	tempo = tempo + 1;
	f[u] = tempo;
	printf("f[%s] = %d\n", vert[u], tempo);
}

void DFS_GT(list<int> G[]){
	//printf("%s\n", "inicializando vertices com cor branca");
	list<int>::iterator it;
	for (std::list<int>::iterator it=GOrdenadoByF.begin(); it!=GOrdenadoByF.end(); ++it){
		cor[*it] = branco;
		pi[*it] = -1;
		//printf("cor[%s] = branco \t pi[%s] = -1\n", vert[*it], vert[*it]);
	}
	//printf("%s\n", "finalizando inicialização");
	
	tempo = 0;
	printf("%s\n","<<<<<<<<<<<< DFS_GT >>>>>>>>>>>>>>");
	for (std::list<int>::iterator it=GOrdenadoByF.begin(); it!=GOrdenadoByF.end(); ++it){
		if (cor[*it] == branco) {
			DFS_VISIT_GT(*it);
		}
		
	}
	printf("%s\n","<<<<<<<<<<<< DFS_GT >>>>>>>>>>>>>>");
}

void geraGrafoT(list<int> G[]){
	//printf("%s\n", "<<<<<<<<<<<< begin grafo transposto >>>>>>>>>>>>>>");
	list<int>::iterator it;
	for (int i = 0; i < N; i++){
		for (it=Adj[i].begin(); it != Adj[i].end(); it++){
			GT[*it].push_back(i);
			//printf("[ %s - %s ] ", vert[*it], vert[i]);
		}
		//printf("%s\n", "");
	}
	//printf("%s\n\n", "<<<<<<<<<<<<  end grafo transposto >>>>>>>>>>>>>>");
}


int main() {
	inicializa_grafo();
	DFS(Adj);
	geraGrafoT(Adj);
	DFS_GT(GT);
   return 0;
}