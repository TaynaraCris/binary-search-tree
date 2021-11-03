#include <bits/stdc++.h>

// Use essa biblioteca para executar o codigo em ambiente LINUX
// Para executar use (g++ arvore.cpp -o prog edalib.a) e depois (./prog)
#include "edalib.h"
#include <stdlib.h>

// Use essa biblioteca para executar o codigo em ambiente WINDOWS
#include "edalibWindows.h"

using namespace std;

int main()
{
	fstream file;
	file.open("arquivo.csv", ios::in);

	string values_string;

	int values[10000];
	int ind = 0;
	string number = "";
	int opcao = 1;
	No *root = nullptr;

	while(opcao != 0)
	{	
		printf("\n#### MENU ####\n");
		printf("1 - Gera ABP\n");
		printf("2 - Calcula fator de balanceamento\n");
		printf("3 - Imprime ABP\n");
		printf("0 - Sair\n");
		printf("Escolha : ");

		scanf("%d",&opcao);

		if(opcao == 1)
		{
			while (file.good())
			{
				getline(file, values_string);
				values_string = replace(values_string);

				for (int i = 0; i < values_string.size(); ++i)
				{
					if (values_string[i] >= '0' && values_string[i] <= '9')
					{
						number += values_string[i];
					}
					else if ((values_string[i] == ' ' && number != "") || values_string[i] == '\0')
					{
						values[ind] = stoi(number);
						ind++;
						number = "";
					}
				}

				values[ind] = stoi(number);
			}
			// Gera a arvore
			for (int i = 0; i <= ind; ++i)
			{
				insere_node(values[i], root);
			}
			printf("Árvore gerada com sucesso\n");
		}
		
		else if(opcao == 2)
		{
			calculaFatBal(root);
			printf("Fatores calculados com sucesso\n");
		}

		else if(opcao == 3)
		{
			cout << "Printando em ordem crescente:" << endl;
			// Printando os nos
			//printa(root);
			inorder(root);
		}
		else{
			//Inserir a chave abaixo e descomentar para liberar os nós
			root = liberaNo(root, root->Chave);
		}
	}
	return 0;
}