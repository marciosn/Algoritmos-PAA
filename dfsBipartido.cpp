#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <climits>

using namespace std;

#define N 8
list<int> Adj[N];
list<int> Q;

enum Cores {branco, preto, cinza};

int cor[N] = {0};
int pi[N] = {0};
int d[N] = {0};
int f[N] = {0};
int ordTop[N] = {0};
int tempo = 0;

char conj[N];

const char* vert[N] = {"s", "t", "u", "v", "x", "y", "w", "z"};

enum Vertices {s,t,u,v,x,y,w,z};
			 //0,1,2,3,4,5,6,7

void inicializa_grafo()
{
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

/*const char* vert[N] = {"s", "t", "u", "v"};
enum Vertices {s,t,u, v};

void inicializa_grafo()
{
   Adj[s].push_back(t);
   Adj[t].push_back(s);
   Adj[t].push_back(u);
   Adj[u].push_back(t);
   Adj[u].push_back(v);
   Adj[v].push_back(u);
   Adj[v].push_back(s);
   Adj[s].push_back(v);
}*/


/*const char* vert[N] = {"s", "t", "u"};
enum Vertices {s,t,u};

void inicializa_grafo()
{
   Adj[s].push_back(t);
   Adj[t].push_back(s);
   Adj[t].push_back(u);
   Adj[u].push_back(t);
   Adj[u].push_back(s);
   Adj[s].push_back(u);
}*/

bool DFS_VISIT_BIPARTIDO(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	tempo = tempo + 1;
	d[u] = tempo;

	//printf("cor[%s] =  cinza \t d[%s] = %d\n", vert[u], vert[u], tempo);

	for (it=Adj[u].begin(); it != Adj[u].end(); it++){
		if (cor[*it] == branco) {
			pi[*it] = u;
			conj[*it] = (conj[u]=='A') ? 'B':'A';

			//printf("%s pertence ao conjunto %c\n", vert[*it], conj[*it]);
			//printf("cor[%s] == branca \t pi[%s] = %s\n", vert[*it], vert[*it], vert[u]);
			//printf("chamando recursivamente DFS_VISIT para o vertice %s\n", vert[*it]);
			DFS_VISIT_BIPARTIDO(*it);
		} else if (conj[*it] == conj[u]) {
			return false;
		}
	}
	cor[u] = preto;
	tempo = tempo + 1;
	f[u] = tempo;
	ordTop[u] = f[u];
	printf("salvando f[%s] \n", vert[u]);
	//printf("cor[%s] =  preto \t f[%s] = %d\n", vert[u], vert[u], tempo);
	return true;
}

bool DFS_BIPARTIDO(list<int> G[]){
	list<int>::iterator it;
	for (int i = 0;i < N; i ++) {
		cor[i] = branco;
		pi[i] = -1;

		//printf("cor[%s] = branco \t pi[%s] = -1\n", vert[i], vert[i]);
	}

	tempo = 0;

	for(int j = 0; j < N; j++) {
		if (cor[j] == branco) {
			conj[j] = 'A';
			if(DFS_VISIT_BIPARTIDO(j) == false){
				return false;
			}
		}
	}
	return true;
}

int main() {
	inicializa_grafo();
	if(DFS_BIPARTIDO(Adj) == false) {
		printf("%s\n", "falso");
	} else {
		printf("%s\n", "Verdade");
	}


	for(int j = 0; j < N; j++){
		printf("%d\n", ordTop[j]);
	}

   return 0;
}