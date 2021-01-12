#include <iostream>
#include <vector>
using namespace std;

int n;

void imprimir(vector<char>& w) {
	for(int i = 0; i < n; ++i) {
		cout << w[i];
	}
	cout << endl;	
}

void anagrama(vector<char>& word, vector<bool>& used, int x, vector<char>& res) {
	if(x == n) imprimir(res);
	else {
		for(int i = 0; i < n; ++i) {
			if(not used[i]) {
				res[x] = word[i];
				used[i] = true;
				anagrama(word, used, x+1, res);
				used[i] = false;
			}
		}
	}
}

int main() {
	cout << "Insertar num. de letras:" << endl;
	cin >> n;
	
	cout << "Insertar palabra:" << endl;
	vector<char> palabra(n);
	char c;
	for(int i = 0; i < n; ++i) {
		cin >> c;
		palabra[i] = c;
	}
	cout << endl;

	vector<char> resultado(n);
	vector<bool> usado(n, false);

	anagrama(palabra, usado, 0, resultado);
	cout << endl;
}