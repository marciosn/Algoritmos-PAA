#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <climits>

using namespace std;

#define N 9
list<int> Adj[N];
list<int> Q;


enum Cores {branco, preto, cinza};

int grau_entrada[N] = {0};
int grau_saida[N] = {0};
int cor[N] = {0};
int pi[N] = {0};
int d[N] = {0};
int f[N] = {0};
int tempo = 0;

const char* vert[N] = {"s", "t", "u", "v", "x", "y", "w", "z", "a"};

enum Vertices {s,t,u,v,x,y,w,z, a};
			 //0,1,2,3,4,5,6,7
void inicializa_grafo(){
   Adj[a].push_back(s);
   Adj[s].push_back(z); 
   Adj[s].push_back(w);
   Adj[z].push_back(y);
   Adj[z].push_back(w);
   Adj[y].push_back(x);
   Adj[x].push_back(z);
   Adj[w].push_back(x);
   Adj[t].push_back(v);
   Adj[t].push_back(u);
   Adj[v].push_back(w);
   Adj[v].push_back(s);
   Adj[u].push_back(v);
   Adj[u].push_back(t);
}

void DFS_VISIT(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	tempo = tempo + 1;
	d[u] = tempo;
	grau_saida[u] = Adj[u].size();
	//grau_saida[u] = grau_saida[u] + 1;

	//printf("cor[%s] =  cinza \t d[%s] = %d\n", vert[u], vert[u], tempo);

	for (it=Adj[u].begin(); it != Adj[u].end(); it++){
	    grau_entrada[*it] = grau_entrada[*it] + 1;
		if (cor[*it] == branco) {
			pi[*it] = u;

			//printf("cor[%s] == branca \t pi[%s] = %s\n", vert[*it], vert[*it], vert[u]);
			//printf("chamando recursivamente DFS_VISIT para o vertice %s\n", vert[*it]);
			//printf("%s\n", "===================================================");
			DFS_VISIT(*it);

		}
	}
	cor[u] = preto;
	tempo = tempo + 1;
	f[u] = tempo;
	//printf("cor[%s] =  preto \t f[%s] = %d\n", vert[u], vert[u], tempo);
}

void DFS(list<int> G[]){
	list<int>::iterator it;
	for (int i = 0;i < N; i ++) {
		cor[i] = branco;
		pi[i] = -1;
		grau_entrada[i] = 0;
		grau_saida[i] = 0;
		//printf("cor[%s] = branco \t pi[%s] = -1\n", vert[i], vert[i]);
	}
	//printf("%s\n", "===================================================");
	
	tempo = 0;
	for(int j = 0; j < N; j++) {
		if (cor[j] == branco) {
			DFS_VISIT(j);
		}
	}

}

void imprime(){
    for(int j = 0; j < N; j++) {
		printf("grau_entrada[%s] = %d\n", vert[j], grau_entrada[j]);
	}
	
	for(int j = 0; j < N; j++) {
		printf("grau_saida[%s] = %d\n", vert[j], grau_saida[j]);
	}
}

int main() {
	inicializa_grafo();
	DFS(Adj);
	imprime();
   return 0;
}
