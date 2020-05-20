#include "multiset.h"

template<typename type>
multiset<type>::multiset()
{
    head = NULL;
}

template<typename type>
multiset<type>::~multiset()
{
    while(head != NULL)
    {
        Node<type> *n = head->next;
        delete head;
        head = n;
    }
}

template<typename type>
void multiset<type>::insert(type value)
{
    if(head==NULL)
    {
        head=new Node<type>;
        head->data=value;
        head->next=NULL;
    }
    else if(head->data>=value)
    {
        Node<type> *nod = new Node<type>;
        nod->data=value;
        nod->next=head;
        head=nod;
    }
    else
    {
        Node<type> *n= head;
        while(n!=NULL)
        {
            if(n->next==NULL)
            {
                Node<type> *nod = new Node<type>;
                nod->data = value;
                nod->next=n->next;
                n->next=nod;
                break;
            }
            else if(n->data<=value && n->next->data>value)
            {
                Node<type> *nod = new Node<type>;
                nod->data = value;
                nod->next=n->next;
                n->next=nod;
                break;
            }
            n=n->next;
        }
    }
}

template<typename type>
void multiset<type>::pop(type value)
{
    Node<type> *n= head;
    Node<type> *n_back;
    if(head->data==value)
    {
        n=head->next;
        delete head;
        head=n;
    }
    else
        while(n!=NULL)
        {
            if(n->data==value)
            {
                n_back->next=n->next;
                delete n;
                break;
            }
            n_back=n;
            n=n->next;
        }
}

template<typename type>
int multiset<type>::nraparitii(type value)
{
    int nr=0;
    Node<type> *n= head;
    while(n!=NULL)
    {
        if(n->data==value)nr++;
        n=n->next;
    }
    return nr;
}

template<typename type>
bool multiset<type>::exista(type value)
{
    Node<type> *n= head;
    while(n!=NULL)
    {
        if(n->data==value)return 1;
        n=n->next;
    }
    return 0;
}

template<typename type>
void multiset<type>::elimin(type value)
{
    Node<type> *n= head;
    Node<type> *n_back;
    if(head->data==value)
    {
        while(head->data==value)
        {
            n=head->next;
            delete head;
            head=n;
        }
    }
    else
        while(n!=NULL)
        {
            if(n->data==value)
            {
                while(n->data==value)
                {
                    n_back->next=n->next;
                    delete n;
                    n=n_back->next;
                }
                break;
            }
            n_back=n;
            n=n->next;
        }
}

template<typename type>
int multiset<type>::nr_elem_distincte()
{
    int nr=1;
    Node<type> *n= head;
    while(n->next!=NULL)
    {
        if(n->data!=n->next->data)nr++;
        n=n->next;
    }
    return nr;
}

template<typename type>
multiset<type>::multiset(const multiset& cpy)
{
    head=new Node<type>;
    Node<type> *n= cpy.head;
    Node<type> *aux= head;
    while(n!=NULL)
    {
        Node<type> *nod = new Node<type>;
        nod->data = n->data;
        nod->next=NULL;
        head->next = nod;
        head=nod;
        n=n->next;
    }
    head=aux->next;
}


template<typename type>
multiset<type>& multiset<type>::operator=(const multiset& cpy)
{
    if (this == &cpy) return *this;
    head=new Node<type>;
    Node<type> *n= cpy.head;
    Node<type> *aux= head;
    while(n!=NULL)
    {
        Node<type> *nod = new Node<type>;
        nod->data = n->data;
        nod->next=NULL;
        head->next = nod;
        head=nod;
        n=n->next;
    }
    head=aux->next;
    return *this;
}

