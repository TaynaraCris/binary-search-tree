
#include <bits/stdc++.h>
// #include "edalib.h"

using namespace std;

string replace(string values_string)
{

    for (int i = 0; i < values_string.length(); i++)
    {
        if (values_string[i] == ',')
        {
            values_string[i] = ' ';
        }
    }
    return values_string;
}

struct No
{
    int Chave;
    struct No *pEsq{}, *pDir{};
    int FatBal;
};

void insere_node(int value, No *&root)
{
    if (root == nullptr)
    { /*inserir x como raiz da árvore*/
        root = (No *)malloc(sizeof(No));
        root->Chave = value;
        root->pEsq = nullptr;
        root->pDir = nullptr;
    }
    else
    {
        if (value < root->Chave)
        {
            insere_node(value, root->pEsq);
        }
        if (value > root->Chave)
        {
            insere_node(value, root->pDir);
        }
    }
};

struct No *liberaNo(struct No *root, int Chave)
{
    if (root == NULL)
        return root;
    if (Chave < root->Chave)
        root->pEsq = liberaNo(root->pEsq, Chave);
    else if (Chave > root->Chave)
        root->pDir = liberaNo(root->pDir, Chave);
    else
    {
        if (root->pEsq == NULL and root->pDir == NULL)
            return NULL;
        else if (root->pEsq == NULL)
        {
            struct No *temp = root->pDir;
            free(root);
            return temp;
        }
        else if (root->pDir == NULL)
        {
            struct No *temp = root->pEsq;
            free(root);
            return temp;
        }
        return root;
    }
}

void inorder(struct No *root)
{
    if (root != NULL)
    {
        inorder(root->pEsq);
        printf("%d  %d\n", root->Chave, root->FatBal);
        inorder(root->pDir);
    }
}

void printa(No *root)
{
    if (root != nullptr)
    { /*inserir x como raiz da árvore*/
        cout << root->Chave << endl;
        printa(root->pEsq);
        printa(root->pDir);
    }
};

int getAltura(No *No)
{
    if (No == nullptr)
        return 0;
    else
    {
        /* computa a altura de cada subArvore */
        int lHeight = getAltura(No->pEsq);
        int rHeight = getAltura(No->pDir);

        /* usa a maior altura */
        if (lHeight > rHeight)
        {
            return (lHeight + 1);
        }
        else
        {
            return (rHeight + 1);
        }
    }
}

void calculaFatBal(No *root)
{
    if (root != nullptr)
    {
        calculaFatBal(root->pEsq);
        calculaFatBal(root->pDir);

        root->FatBal = (getAltura(root->pEsq) - getAltura(root->pDir));
    }
}
