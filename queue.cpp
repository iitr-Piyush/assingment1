#include <iostream>
#include "ll.cpp"
using namespace std;

template <class T>
class Queue
{
public:
   LList<int> L1;
   void ins(T value)
    {
        L1.Insertion(value,-1);
        
    }
    void del()
    {
        L1.DeleteItemAt(1);
    }
    void display()
    {
        L1.display();
    }
};
int main()
{
    Queue<int> S;
    S.ins(1);S.display();
    S.ins(2);S.display();
    S.del();S.display();
    S.ins(3);S.display();
    S.ins(4);S.display();
    S.ins(5);S.display();
    S.del();S.display();
    S.del();S.display();
    S.ins(7);S.display();
}
