#include <iostream>
#include <vector>

using namespace std;
struct element
{
    string key;
    vector<string> reffers;
};

struct HashTab
{
    vector<element*> tab[1000];
    void insert(string k1, string k2)
    {
       int pom=((k1.length()+k1[0]+k1[k1.length()-1])*k1[0])%1000;
       int found=-1;
       for(int i=0;i<tab[pom].size();i++)
       {
           if(tab[pom][i]->key==k1)
           {
               found=i;
               break;
           }
       }
       if(found==-1)
       {
           element* p=new element;
           p->key=k1;
           p->reffers.push_back(k2);
           tab[pom].push_back(p);
       }
       else
       {
           tab[pom][found]->reffers.push_back(k2);
       }
    }
    void write(string k)
    {
        int pom=((k.length()+k[0]+k[k.length()-1])*k[0])%1000;
        int found=-1;
        for(int i=0;i<tab[pom].size();i++)
        {
            if(tab[pom][i]->key==k)
            {
                found=i;
                break;
            }
        }
        if(found!=-1)
        {
            for(int i=0;i<tab[pom][found]->reffers.size();i++)
            {
                cout<<tab[pom][found]->reffers[i]<<endl;
            }
        }
    }
};
