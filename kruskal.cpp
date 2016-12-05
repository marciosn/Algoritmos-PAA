#include iostream
#include ctime
#include list
#include vector
#include algorithm

struct Node {
   struct Node *pai;
   int rank;
   char c;  identificador
};

struct Aresta {
   int u;
   int v;
   int peso;
};	
#define N 9
listAresta Adj[N];
vectorAresta arestas;

void inicializa_arestas(){
   for (int u = 0; u < N; u++)
      for (listArestaiterator e = Adj[u].begin(); e != Adj[u].end(); e++)
         if (u  e-v) arestas.push_back(e);
}

void inicializa_grafo()
{
   enum Vertices {a,b,c,d,e,f,g,h,i};
                0 1 2 3 4 5 6 7 8
   Adj[a].push_back((Aresta){a,b,4});
   Adj[a].push_back((Aresta){a,h,8});
   Adj[b].push_back((Aresta){b,a,4});
   Adj[b].push_back((Aresta){b,c,8});
   Adj[b].push_back((Aresta){b,h,11});
   Adj[c].push_back((Aresta){c,b,8});
   Adj[c].push_back((Aresta){c,d,7});
   Adj[c].push_back((Aresta){c,f,4});
   Adj[c].push_back((Aresta){c,i,2});
   Adj[d].push_back((Aresta){d,c,7});
   Adj[d].push_back((Aresta){d,e,9});
   Adj[d].push_back((Aresta){d,f,14});
   Adj[e].push_back((Aresta){e,d,9});
   Adj[e].push_back((Aresta){e,f,10});
   Adj[f].push_back((Aresta){f,c,4});
   Adj[f].push_back((Aresta){f,d,14});
   Adj[f].push_back((Aresta){f,e,10});
   Adj[f].push_back((Aresta){f,g,2});
   Adj[g].push_back((Aresta){g,f,2});
   Adj[g].push_back((Aresta){g,h,1});
   Adj[g].push_back((Aresta){g,i,6});
   Adj[h].push_back((Aresta){h,a,8});
   Adj[h].push_back((Aresta){h,b,11});
   Adj[h].push_back((Aresta){h,g,1});
   Adj[h].push_back((Aresta){h,i,7});
   Adj[i].push_back((Aresta){i,c,2});
   Adj[i].push_back((Aresta){i,g,6});
   Adj[i].push_back((Aresta){i,h,7});
   inicializa_arestas();
}

bool comp_aresta(Aresta i, Aresta j){
   return i.peso  j.peso;
}

void MAKE_SET(int x) {
   pai[x] = x;
   rank[x] = 0;
}

void UNION(int x, int y){
   LINK(FIND_SET(x), FIND_SET(y));
}

void LINK(int x, int y){
   if (rank[x] > rank[y]) {
      pai[y] = x;
   } else {
      pai[x] = rank[y];
   }

   if (rank[x] == rank[y] ) {
      rank[y] = rank[y] + 1;
   }
}

void FIND_SET(int x){
   if (pai[x] != x) {
         pai[x] = FIND_SET(pai[x]);
      }
   return pai[x];
}

void AGM_KRUSKAL(listAresta Adj, int n){
   for (int u = 0; u < N; u++){
      for (listArestaiterator e = Adj[u].begin(); e != Adj[u].end(); e++){
         MAKE_SET(e);
      }
   }

   sort(arestas.begin(), arestas.end(), comp_aresta);

   for (int k = 0; k < N; k++){
      for (listArestaiterator i = Adj[k].begin(); i != Adj[k].end(); e++){
         if (FIND_SET(i) != FIND_SET(arestas[i])) {
            //imprime
            UNION(i, arestas[i]);
         }
      }
   }
   
}