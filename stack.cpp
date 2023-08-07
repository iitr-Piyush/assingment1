#include <iostream>
#include "ll.cpp"
using namespace std;

template <class T>
class Stack
{
public:
   LList<int> L1;
   void push(T value)
    {
        L1.Insertion(value,1);
        
    }
    void pop()
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
    Stack<int> S;
    S.push(1);S.display();
    S.push(2);S.display();
    S.pop();S.display();
    S.push(3);S.display();
    S.push(4);S.display();
    S.push(5);S.display();
    S.pop();S.display();
    S.pop();S.display();
    S.push(7);S.display();
}