#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int key;
    node* up=NULL, *left=NULL, *right=NULL;
};

struct BstTree
{
    node* root=NULL;
    void insert(int w)
    {
        node* pom=new node;
        pom->key=w;
        if(root==NULL)
        {
            root=pom;
        }
        else
        {
            node* pom2=root;
            while(!((pom2->key<=w && pom2->right==NULL)||(pom2->key>w && pom2->left==NULL)))
            {
                if(pom2->key<=w) pom2=pom2->right;
                else pom2=pom2->left;
            }
            if(pom2->key<=w)
            {
                pom2->right=pom;
                pom->up=pom2;
            }
            else
            {
                pom2->left=pom;
                pom->up=pom2;
            }
        }
    }
    bool find_sum(node* pom, vector<int>& liczby, int suma)
    {
        if(pom==NULL) return false;
        else if(find_sum(pom->left, liczby, suma)) return true;
        else if(find(liczby.begin(), liczby.end(), suma-pom->key)!=liczby.end())
        {
            if(suma-pom->key<pom->key)
            {
                cout<<suma-pom->key<<" "<<pom->key;
            }
            else cout<<pom->key<<" "<<suma-pom->key;
            return true;
        }
        else
        {
            liczby.push_back(pom->key);
            if(find_sum(pom->right, liczby, suma)) return true;
            else return false;
        }
    }
    void trim(int minimum, int maximum)
    {

       node* pom=root;
       while((pom->key>=minimum && pom->left!=NULL) || (pom->key<minimum && pom->right!=NULL))
       {
            while(pom->key>=minimum && pom->left!=NULL)
            {
                pom=pom->left;
            }
            while(pom->key<minimum && pom->right!=NULL)
            {
                pom=pom->right;
            }
       }
       if(pom->key<minimum) pom=pom->up;
       pom->left=NULL;
       node* pom2=root;
       while((pom2->key<=maximum && pom2->right!=NULL) || (pom2->key>maximum && pom2->left!=NULL))
       {
            while(pom2->key<=maximum && pom2->right!=NULL)
            {
                pom2=pom2->right;
            }
            while(pom2->key>maximum && pom2->left!=NULL)
            {
                pom2=pom2->left;
            }
       }
       if(pom2->key>maximum) pom2=pom2->up;
       pom2->right=NULL;
       if(pom2->key>maximum || pom2->key<minimum) root=NULL;
    }
};
