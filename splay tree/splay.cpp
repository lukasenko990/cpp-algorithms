#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct node
{
    string key;
    vector<string> reffers;
    node* up=NULL, *left=NULL, *right=NULL;
};

struct Splay
{
    node* root=NULL;
    void rotate_left(node* e)
    {
        if(e==root) root=e->right;
        else if(e==e->up->left) e->up->left=e->right;
        else e->up->right=e->right;
        e->right->up=e->up;
        e->up=e->right;
        e->right=e->up->left;
        if(e->up->left!=NULL) e->up->left->up=e;
        e->up->left=e;
    }
    void rotate_right(node* e)
    {
        if(e==root) root=e->left;
        else if(e==e->up->left) e->up->left=e->left;
        else e->up->right=e->left;
        e->left->up=e->up;
        e->up=e->left;
        if(e->up->right!=NULL) e->up->right->up=e;
        e->left=e->up->right;
        e->up->right=e;
    }
    void zig(node* e)
    {
        if(e==e->up->left) rotate_right(e->up);
        else rotate_left(e->up);
    }
    void zig_zig(node* e)
    {
            if(e==e->up->left)
            {
                rotate_right(e->up->up);
                rotate_right(e->up);
            }
            else
            {
                rotate_left(e->up->up);
                rotate_left(e->up);
            }
    }
    void zig_zag(node* e)
    {
        if(e==e->up->left)
        {
            rotate_right(e->up);
            rotate_left(e->up);
        }
        else
        {
            rotate_left(e->up);
            rotate_right(e->up);
        }
    }
    void splay(node* e)
    {
        while(e!=root)
        {
            if(e->up==root) zig(e);
            else if((e==e->up->left && e->up==e->up->up->left)||
                    (e==e->up->right && e->up==e->up->up->right))
                        zig_zig(e);
            else zig_zag(e);
        }
    }
    bool find(string k)
    {
        node* pom=root;
        node* pom2;
        while(pom!=NULL && pom->key!=k)
        {
            pom2=pom;
            if(pom->key>k) pom=pom->left;
            else pom=pom->right;
        }
        if(pom!=NULL)
        {
            splay(pom);
            return true;
        }
        else
        {
            splay(pom2);
            return false;
        }
    }
    void insert(string k1, string k2)
    {
        if(root==NULL)
        {
            root=new node;
            root->key=k1;
            root->reffers.push_back(k2);
        }
        else
        {
            if(!find(k1))
            {
                node* new_node=new node;
                new_node->key=k1;
                new_node->reffers.push_back(k2);
                if(root->key<k1)
                {
                    new_node->left=root;
                    root->up=new_node;
                    new_node->right=root->right;
                    if(root->right!=NULL)
                    {
                        root->right->up=new_node;
                    }
                    root->right=NULL;
                }
                else
                {
                    new_node->right=root;
                    root->up=new_node;
                    new_node->left=root->left;
                    if(root->left!=NULL)
                    {
                        root->left->up=new_node;
                    }
                    root->left=NULL;
                }
                root=nowy;
            }
            else
            {
                root->reffers.push_back(k2);
            }
        }
    }
    void write(string k)
    {
        if(find(k))
        {
            for(int i=0;i<root->reffers.size();i++)
            {
                cout<<root->reffers[i]<<endl;
            }
        }
    }
};
