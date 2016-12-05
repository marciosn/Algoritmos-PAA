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
int descoberto[N] = {0};
int final[N] = {0};
int ordTop[N] = {0};
int tempo = 0;

char conj[N];

const char* vert[N] = {"s", "t", "u", "v", "x", "y", "w", "z"};

enum Vertices {s,t,u,v,x,y,w,z};
			 //0,1,2,3,4,5,6,7


/*					 // a    b    c    d    e    f    g    h
const char* vert[N] = {"a", "b", "c", "d", "e", "f", "g", "h"};

enum Vertices {a,b,c,d,e,f,g,h};
             //0 1 2 3 4 5 6 7*/

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

/*void inicializa_grafo()
{
   
   Adj[a].push_back(b);
   Adj[b].push_back(c);
   Adj[b].push_back(e);
   Adj[b].push_back(f);
   Adj[c].push_back(d);
   Adj[c].push_back(g);
   Adj[d].push_back(c);
   Adj[d].push_back(h);
   Adj[e].push_back(a);
   Adj[e].push_back(f);
   Adj[f].push_back(g);
   Adj[g].push_back(f);
   Adj[g].push_back(h);
   Adj[h].push_back(h);
}*/

bool DFS_VISIT_BIPARTIDO(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	tempo = tempo + 1;
	descoberto[u] = tempo;

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
	printf("o tempo no momento em que é f[%s] é finalizado é %d\n", vert[u], tempo);
	tempo = tempo + 1;
	final[u] = tempo;
	ordTop[u] = final[u];
	//printf("salvando f[%s] \n", vert[u]);
	//printf("cor[%s] =  preto \t f[%s] = %d\n", vert[u], vert[u], tempo);
	//printf("f[%s] = %d\n", vert[u], tempo);
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
	DFS_BIPARTIDO(Adj);

	/*if(DFS_BIPARTIDO(Adj) == false) {
		printf("%s\n", "falso");
	} else {
		printf("%s\n", "Verdade");
	}*/


	for(int j = 0; j < N; j++){
		//printf("%d\n", ordTop[j]);
		printf("d[%s] = %d \t f[%s] = %d\n", vert[j], descoberto[j], vert[j], final[j]);
	}

   return 0;
}