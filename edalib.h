#ifndef edalib_h
#define edalib_h

    #include <bits/stdc++.h>

    using namespace std;

    void print_test();
    void print_outro();

    string replace(string values_string);

    struct No;

    void insere_node(int value, No *&root);

    struct No *liberaNo(struct No *root, int Chave);

    void inorder(struct No *root);

    void printa(No *root);

    int getAltura(No *No);

    void calculaFatBal(No *root);


#endif