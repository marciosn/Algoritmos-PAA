#include <bits/stdc++.h>
#include <string>
using namespace std;

int minimo(int x, int y, int z){
   return min(min(x, y), z);
}

int DE_RECURSIVA(string text1, string text2, int i, int j){

	if (i == 0) return j;
	if (j == 0) return i;
	if (text1[ i - 1] == text2[ j - 1 ]) return DE_RECURSIVA(text1, text2, i - 1, j - 1);
	return 1 + minimo(
						DE_RECURSIVA(text1, text2, i, j - 1),
						DE_RECURSIVA(text1, text2, i - 1, j),
						DE_RECURSIVA(text1, text2, i - 1, j - 1)
					);
}

int DE_DINAMICA(string text1, string text2, int i, int j){
	int subp[i+1][j+1];

	for (int m = 0; m <= i; m++) {
		for (int n = 0; n <= j; n++) {

			if (m == 0) {
				subp[m][n] = n;
			} else if (n == 0) {
				subp[m][n] = m;
			} else if (text1[m - 1] == text2[n - 1]) {
				subp[m][n] = subp[m - 1][n - 1];
			} else {
				subp[m][n] = 1 + minimo(
									subp[m][n - 1],
									subp[m - 1][n],
									subp[m - 1][n - 1]
								);
			}
		}
	}
	return subp[i][j];
}

int main(){

	string str1 = "snowy";
    string str2 = "sunny";
    
    cout << DE_RECURSIVA( str1 , str2 , str1.length(), str2.length()) << '\n';
    cout << DE_DINAMICA( str1 , str2 , str1.length(), str2.length()) << '\n';
    return 0;
}