#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct node
{
    string key;
    vector<string> reffers;
    node* up=NULL;
    vector<node*> sons;
};

struct drzewoTrie
{
    node* root=NULL;
    void insert(string k1, string k2)
    {
        if(root==NULL)
        {
            root=new node;
            node* pom=new node;
            pom->key=k1;
            pom->reffers.push_back(k2);
            root->sons.push_back(pom);
            pom->up=root;
        }
        else
        {
           int found=-1;
           for(int i=0;i<root->sons.size();i++)
           {
               if(root->sons[i]->key[0]==k1[0])
               {
                   found=i;
                   break;
               }
           }
           if(found==-1)
           {
               node* pom=new node;
               pom->key=k1;
               pom->reffers.push_back(k2);
               pom->up=root;
               root->sons.push_back(pom);
           }
           else
           {
               bool exist=false;
               node* pom=root->sons[found];
               int pos_k1=0,pos=0;
               while(pom->key[pos]==k1[pos])
               {
                   if(pom->key==k1)
                   {
                       exist=true;
                       pom->reffers.push_back(k2);
                       break;
                   }
                   else if(pos==pom->key.length()-1)
                   {
                       k1=k1.substr(pos+1,k1.length()-pos-1);
                       found=-1;
                       for(int i=0;i<pom->sons.size();i++)
                       {
                           if(k1[0]==pom->sons[i]->key[0])
                           {
                               found=i;
                               break;
                           }
                       }
                       if(found==-1)
                       {
                           node* pom2=new node;
                           pom2->key=k1;
                           pom2->up=pom;
                           pom2->reffers.push_back(k2);
                           pom->sons.push_back(pom2);
                           exist=true;
                           break;
                       }
                       else
                       {
                           pom=pom->sons[found];
                           pos=-1;
                       }
                   }
                   else if(pos==k1.length()-1)
                   {
                       node* pom2=new node;
                       pom->key=pom->key.substr(pos+1,pom->key.length()-pos-1);
                       pom2->up=pom->up;
                       pom->up=pom2;
                       pom2->sons.push_back(pom);
                       pom2->key=k1;
                       pom2->reffers.push_back(k2);
                       pom2->up->sons.erase(pom2->up->sons.begin()+found);
                       pom2->up->sons.push_back(pom2);
                       exist=true;
                       break;
                   }
                   pos++;
               }
               if(exist==false)
               {
                    node* pom2=new node;
                    node* pom3=new node;
                    pom2->key=pom->key.substr(0,pos);
                    pom->key=pom->key.substr(pos,pom->key.length()-pos);
                    pom3->key=k1.substr(pos,k1.length()-pos);
                    pom2->up=pom->up;
                    pom3->reffers.push_back(k2);
                    pom2->sons.push_back(pom);
                    pom2->sons.push_back(pom3);
                    pom->up->sons.erase(pom->up->sons.begin()+found);
                    pom->up->sons.push_back(pom2);
                    pom->up=pom3->up=pom2;
               }
           }
        }
    }
    void write(string k)
    {
        if(root!=NULL)
        {
            int found=-1;
            for(int i=0;i<root->sons.size();i++)
            {
                if(root->sons[i]->key[0]==k[0])
                {
                    found=i;
                    break;
                }
            }
            if(found!=-1)
            {
                bool wrong=false;
                node* pom=root->sons[found];
                while(pom->key!=k && k.length()>=pom->key.length())
                {
                    found=-1;
                    k=k.substr(pom->key.length(),k.length()-pom->key.length());
                    wrong=true;
                    for(int i=0;i<pom->sons.size();i++)
                    {
                        if(pom->sons[i]->key[0]==k[0])
                        {
                            found=i;
                            break;
                        }
                    }
                    if(found!=-1)
                    {
                        pom=pom->sons[found];
                        wrong=false;
                    }
                    else break;
                }
                if(pom->key==k && wrong==false)
                {
                    for(int i=0;i<pom->reffers.size();i++)
                    {
                        cout<<pom->reffers[i]<<endl;
                    }
                }
            }
        }
    }
};
