#include <iostream>

struct element
    {
        element* next;
        element* prev;
        int key;
        std::string word;
    };

//Bidirectional list
class List
{
    public:
    element* head;
    element* tail;

    List() {
        head=new element;
        tail=new element;
        head->prev=NULL;
        tail->next=NULL;
        head->next=tail;
        tail->prev=head;
        }
     ~List()
    {
        element* tmp;
        while(head!=NULL)
        {
            tmp=head;
            head=head->next;
            if(head=head->next) head->next=tail;
            delete tmp;
        }
    }
    //checking if list is empty
    bool empty()
    {
        if(head->next==tail) return true;
        else return false;
    }
    //add new element after e element
    void insert(element* e, int key, std::string word)
   {
       element* new_element=new element;
       new_element->prev=e->prev;
       e->prev->next=new_element;
       e->prev=new_element;
       new_element->next=e;
       new_element->key=key;
       new_element->word=word;
       if(e==tail)
       {
           new_element->next=head->next;
           head->next->prev=new_element;
       }
       else if(e==head->next)
       {
           head->next=new_element;
           new_element->prev=tail->prev;
           tail->prev->next=new_element;
       }
   }
   //delete e element
    void delete(element* e)
    {
       e->prev->next=e->next;
       e->next->prev=e->prev;
       if(e==tail->prev) tail->prev=e->prev;
       if(e==head->next) head->next=e->next;
       if(e==e->next)
       {
           head->next=tail;
           tail->prev=head;
       }
       delete e;
    }
    //returns key of element e
    int get_key(element* e)
    {
        return e->key;
    }
    //returns word of element e
    std::string get_word(element* e)
    {
        return e->word;
    }
};

