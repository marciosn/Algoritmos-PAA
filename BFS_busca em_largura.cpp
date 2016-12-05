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

const char* vert[N] = {"s", "w", "r", "t", "x", "v", "u", "y"};
enum Cores {branco, preto, cinza};
enum Vertices {s,w,r,t,x,v,u,y};
			 //0 1 2 3 4 5 6 7

int cor[N] = {0};
int pi[N] = {0};
int d[N] = {0};

void inicializa_grafo()
{
   Adj[s].push_back(w);
   Adj[s].push_back(r);
   Adj[r].push_back(s);
   Adj[r].push_back(v);
   Adj[v].push_back(r);
   Adj[w].push_back(s);
   Adj[w].push_back(t);
   Adj[w].push_back(x);
   Adj[t].push_back(w);
   Adj[t].push_back(x);
   Adj[t].push_back(u);
   Adj[x].push_back(w);
   Adj[x].push_back(t);
   Adj[x].push_back(u);
   Adj[x].push_back(y);
   Adj[u].push_back(t);
   Adj[u].push_back(x);
   Adj[u].push_back(y);
   Adj[y].push_back(x);
   Adj[y].push_back(u);
}


void BFS(list<int> G[], int s){
	printf("percorrendo os vertices de G (excluindo o %s)\n", vert[s]);
	 list<int>::iterator it;
	for (int i = 1;i < N; i++) {
		cor[i] = branco;
		d[i] = INT_MAX;
		pi[i] = -1;
		printf("cor[%s] = branco \t d[%s] = oo \t pi[%s] = -1\n", vert[i], vert[i], vert[i]);
	}

	printf("%s\n", "===================================================");

	cor[s] = cinza;
	d[s] = 0;
	pi[s] = -1;

	printf("cor[%s] = cinza \t d[%s] = %d\n", vert[s], vert[s], d[s]);
	printf("%s\n", "===================================================");

	Q.push_back(s);
	printf("enfileira %s\n", vert[s]);

	while(!Q.empty()){
			int u = Q.front();
			printf("remove %s da fila\n", vert[u]);
			Q.pop_front();
			for (it=Adj[u].begin(); it != Adj[u].end(); it++){

				if (cor[*it] == branco) {
					cor[*it] = cinza;

					d[*it] = d[u] + 1;
					pi[*it] = u;
					Q.push_back(*it);
					printf("cor[%s] == branco \t cor[%s] = cinza \t d[%s] = %d \t pi[%s] = %s \n", vert[*it], vert[*it], vert[*it], d[u] + 1, vert[*it], vert[u]);
					printf("enfileira %s\n", vert[*it]);

				}
			}
			cor[u] = preto;
			printf("cor[%s] = preto\n", vert[u]);

			printf("%s\n", "=============================================================================");
		}
}

int main() {
	inicializa_grafo();
	BFS(Adj, s);

   return 0;
}