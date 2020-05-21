#include "multiset.h"

template<typename type>
multiset<type>::multiset()//in constructor initializam radacina cu NULL astfel fiind siguri ca pornim cu un multiset gol
{
    head = NULL;
}

template<typename type>
multiset<type>::~multiset()//destructorul parcurge tot multisetul cu un while si sterge fiecare nod in parte
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
    if(head==NULL)//Verific daca multisetul este gol iar daca este atunci adaug nodul in radacina
    {
        head=new Node<type>;
        head->data=value;
        head->next=NULL;
    }
    else if(head->data>=value)//Verific daca nodul nou este mai mic decat radacina, in acest caz devenind chiar el noua radacina
    {
        Node<type> *nod = new Node<type>;
        nod->data=value;
        nod->next=head;
        head=nod;
    }
    else//daca if-urile de mai sus au fost negative atunci incep si parcurg tot multisetul pentru a vedea unde adaug noul nod
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
    if(head->data==value)//verific daca nodul pe care vreau sa il il elimin nu este cumva chiar radacina
    {
        n=head->next;
        delete head;
        head=n;
    }
    else//altfel caut nodul pe care vreau sa il elimin si il sterg
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
int multiset<type>::nr_aparitii(type value)//parcurg tot multisetul si inumar in nr cate aparitii ale lui value exista in multiset
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
bool multiset<type>::exista(type value)//parcurg tot multisetul si verific daca value exista in multiset
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
void multiset<type>::elimin(type value)//elimin toate aparitiile lui value din multiset
{
    Node<type> *n= head;
    Node<type> *n_back;
    if(head->data==value)//verific daca nodurile pe care vreau sa le elimin nu sunt chiar la inceput
    {
        while(head->data==value)
        {
            n=head->next;
            delete head;
            head=n;
        }
    }
    else//altfel parcurg multisetul pana le gasesc si dupa le elimin pe toate cu un while
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
int multiset<type>::nr_elem_distincte()// parcurg tot multisetul si inumar cate elemente distincte exista in el
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
multiset<type>::multiset(const multiset& cpy)//constructorul de copiere se apeleaza atunci cand declaram un nou multiset si primeste ca argument un alt multiset
{
    //atunci multisetul pe care il primeste ca argument va fi copiat in multisetul nou declarat
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
multiset<type>& multiset<type>::operator=(const multiset& cpy)//supraincarcarea operatorului =
{
    // pentru a=b copiem multisetul b in multisetul a
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

