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

const char* vert[N] = {"s", "t", "u", "v", "x", "y", "w", "z", "a"};
enum Vertices {s,t,u,v,x,y,w,z, a};

int cor[N] = {0};
int pi[N] = {0};
int d[N] = {0};
char conj[N];

void inicializa_grafo_bp_test(){
	Adj[s].push_back(w);
	Adj[t].push_back(w);
	Adj[t].push_back(y);
	Adj[u].push_back(z);
	Adj[u].push_back(a);
	Adj[v].push_back(w);
	Adj[x].push_back(w);
	Adj[x].push_back(a);
	Adj[w].push_back(s);
	Adj[w].push_back(t);
	Adj[w].push_back(x);
	Adj[y].push_back(t);
	Adj[y].push_back(v);
	Adj[z].push_back(u);
	Adj[a].push_back(u);
	Adj[a].push_back(x);
}

// grafo não bipartido....
void inicializa_grafo_nao_bipartido()
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

// grafo bipartido....
void inicializa_grafo_bipartido()
{
   Adj[s].push_back(t);
   Adj[t].push_back(s);
   Adj[t].push_back(u);
   Adj[u].push_back(t);
   Adj[u].push_back(v);
   Adj[v].push_back(u);
   Adj[v].push_back(s);
   Adj[s].push_back(v);
}

bool BFS(list<int> G[], int s){
	 conj[0] = 'A';
	 list<int>::iterator it;
	for (int i = 1;i < N; i++) {
		cor[i] = branco;
		d[i] = INT_MAX;
		pi[i] = -1;
	}

	cor[s] = cinza;
	d[s] = 0;
	pi[s] = -1;

	Q.push_back(s);

	while(!Q.empty()){
			int u = Q.front();
			Q.pop_front();
			for (it=Adj[u].begin(); it != Adj[u].end(); it++){

				if (cor[*it] == branco) {
					conj[*it] = (conj[u]=='A') ? 'B':'A';
					printf("%s pertence ao conjunto %c\n", vert[*it], conj[*it]);
					cor[*it] = cinza;

					d[*it] = d[u] + 1;
					pi[*it] = u;
					Q.push_back(*it);
				} else if(conj[*it] == conj[u]) {
					return false;
				}
			}
			cor[u] = preto;
		}
		return true;
}

int main() {
	inicializa_grafo_bp_test();
	//inicializa_grafo_nao_bipartido();
	//inicializa_grafo_bipartido();
	if(BFS(Adj, s) == false) {
		printf("%s\n", "Não é bipartido...");
	} else {
		printf("%s\n", "É bipartido...");
	}
   return 0;
}
