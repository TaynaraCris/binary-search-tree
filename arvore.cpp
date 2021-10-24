#include <bits/stdc++.h>

using namespace std;

string replace(string values_string){
 
     for(int i =  0; i < values_string.length(); i++){
         if(values_string[i] == ','){
            values_string[i] = ' ';
         }
     }
     return values_string;
 }

struct No {
    int Chave;
    struct No *pEsq{}, *pDir{};
    int FatBal;
};

void insere_node(int value, No *&root){
    if (root == nullptr) { /*inserir x como raiz da árvore*/
    	root = (No*)malloc(sizeof(No));
    	root->Chave = value;
    	root->pEsq = nullptr;
    	root->pDir = nullptr;
    } else {
    	if (value < root->Chave) {
    		insere_node(value, root->pEsq);
    	}
    	if (value > root->Chave) {
    		insere_node(value, root->pDir);
    	}
	}
};


void printa(No * root){
    if (root != nullptr) { /*inserir x como raiz da árvore*/
		cout << root->Chave << endl;
		printa(root->pEsq);
		printa(root->pDir);
    }
};


int main(){

    fstream file;
    file.open("arquivo.csv", ios::in);

    string values_string;

    int values[10000];
    int ind = 0;
    string number = "";

	while(file.good()){
		getline(file, values_string);
		values_string = replace(values_string);

		for(int i = 0; i < values_string.size(); ++i){
			if(values_string[i] >= '0' && values_string[i] <= '9'){
				number += values_string[i];
			}
			else if((values_string[i] == ' ' && number != "") || values_string[i] == '\0'){
				values[ind] = stoi(number);
				ind++;
				number = "";
			}
		}

		values[ind] = stoi(number);
	}

    No * root = nullptr;

	// Gera a arvore
    for(int i = 0; i <= ind;++i) {
		insere_node(values[i], root);
    }

	cout << "Printar:" << endl;
	// Printando os nos
	printa(root);	

    return 0;
}
