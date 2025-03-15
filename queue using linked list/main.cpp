/******************************************************************************

Queue class implementation.

*******************************************************************************/
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
    T value;
    Node<T>* next;
    
    Node(T val)
    {
        value = val;
        next = nullptr;
    }
};

template<typename T>
class queue
{
private:
    Node<T>* first;
    Node<T>* last;
    int length;
    
public:
    
    queue(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        first = newNode;
        last = newNode;
        length = 1;
    }
    
    ~queue()
    {
        Node<T>* temp = first;
        while(first)
        {
            first = first->next;
            delete temp;
            temp = first;
        }
        length = 0;
    }
    
    void enqueue(int val)
    {
        Node<T>* newNode = new Node<T>(val);
        
        if(length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        
        length++;
    }
    
    void printQueue()
    {
        Node<T>* temp = first;
        
        while(temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void dequeue()
    {
        if(length == 0)
            return;
            
        Node<T>* temp = first;
        
        if(length == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = temp->next;
        }
        
        delete temp;
        length--;
    }
    
    bool empty()
    {
        return (length == 0) ? true : false ;
    }
    
    int size()
    {
        return length;
    }
};

int main()
{
    queue<int> q(1);
    q.enqueue(2);
    q.enqueue(3);
    q.printQueue();
    q.dequeue();
    cout << q.size() << endl;
    q.printQueue();
    q.dequeue();
    q.dequeue();
    q.printQueue();
    
    cout << q.empty() << endl;
}













