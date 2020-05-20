#ifndef MULTISET_H
#define MULTISET_H
#include<iostream>
using namespace std;

template<typename type>
struct Node
{
    type data;
    Node * next;
};

template<typename type>
class multiset
{
    Node<type> *head;
public:
    multiset();
    void insert(type value);
    void pop(type value);
    int nraparitii(type value);
    bool exista(type value);
    void elimin(type value);
    int nr_elem_distincte();
    virtual ~multiset();
    multiset(const multiset& other);
    multiset& operator=(const multiset& other);
    friend std::ostream& operator<<(std::ostream& out, multiset<type>& multiset_)
    {
        Node<type> *n= multiset_.head;
        while(n!=NULL)
        {
            out<<n->data;
            n=n->next;
        }
        return out;
    }

};


#endif // MULTISET_H
