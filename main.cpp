#include "multiset.cpp"

int main()
{
    multiset<int> a,b;
    a.insert(2);
    a.insert(4);
    a.insert(2);
    a.insert(1);
    a.insert(5);
    a.insert(3);
    a.insert(5);
    b=a;
    multiset<int> c(a);
    c.insert(4);
    c.insert(-1);
    b.insert(1);


    cout<<a<<'\n';
    b.pop(5);
    b.elimin(2);
    b.elimin(1);
    cout<<b<<'\n';
    cout<<c<<'\n';
    cout<<a.nr_aparitii(2)<<'\n';
    cout<<a.nr_elem_distincte()<<'\n';
    cout<<b.nr_elem_distincte()<<'\n';
    a.pop(2);
    a.pop(4);
    cout<<a.exista(4)<<' '<<a.exista(2)<<'\n';
    cout<<a<<'\n';


    multiset<char> d;
    d.insert('g');
    d.insert('t');
    d.insert('d');
    d.insert('a');
    d.insert('g');
    d.insert('r');
    cout<<'\n';
    cout<<d<<'\n';
    cout<<d.nr_elem_distincte()<<'\n';
    cout<<d.nr_aparitii('g')<<'\n';
    d.elimin('g');
    d.pop('a');
    cout<<d<<'\n';
    return 0;
}
