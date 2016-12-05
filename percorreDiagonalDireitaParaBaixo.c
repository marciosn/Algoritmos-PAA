#include <stdlib.h>
#include <stdio.h>

void percorreDiagonalDireitaParaBaixo( int x, int y, int linha, int coluna, int v[][4] ){
    while( x < linha && y < coluna ){
        printf( "%d\n" , v[x++][y++] );
    }
}

int main( int argc, char **argv ){
    
    int v[][4] = { { 1 , 2 , 3 , 10 },
                   { 4 , 5 , 6 , 11 },
                   { 7 , 8 , 9 , 12 } };

    percorreDiagonalDireitaParaBaixo( 0, 1, 3, 4, v );
}