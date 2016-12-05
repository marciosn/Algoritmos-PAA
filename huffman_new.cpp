#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <climits>

#include <queue>
#include <vector>
using namespace std;

#define N 5

typedef struct Node {
   const Node *esq;
   const Node *dir;
   int f;  // frequência
   char c; // caractere armazenado (se folha)
} Node;


class NodeComp {
public:
   int operator() (const Node* p1, const Node* p2) {
      return p1->f > p2->f;
   }
};

priority_queue < Node*, vector<Node*>, NodeComp> Q;

Node* EXTRACT_MIN(){
	Node* node = Q.top(); Q.pop();
	return node;
};

char C[N] = {'a', 'b', 'c', 'd', 'f'};
int freq[N] = {45, 12, 13, 5, 16};
int n = 0;

Node* HUFFMAN(){
	cout<<"entrou HUFFMAN AGAINNNNN!!!!!";
	for (int j = 0; j < N; j++) {
		Node* aux = new Node();
		aux->c = C[j];
		cout<< aux->c << " ";
		aux->f = freq[j];
		Q.push(aux);
	}

	for(int i = 0; i < N; i++){
		Node* z;
		z->esq = EXTRACT_MIN();
		z->dir = EXTRACT_MIN();
		z->f = z->esq->f + z->dir->f;

		Q.push(z); 
	}
	return EXTRACT_MIN();
}

void print_tree(const Node *u, int nivel)
{
   if (u == NULL) return;
   for (int i = 0; i < nivel; i++)
      cout << '\t';
   cout << ((u->esq == NULL) ? u->c : ' ') << u->f << endl;
   print_tree(u->esq, nivel+1);
   print_tree(u->dir, nivel+1);
}

int main(int argc, char const *argv[]){
	Node* n = HUFFMAN();
	print_tree(n, 0);
	return 0;
}