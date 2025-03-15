#include <iostream>

using namespace std;

template<typename T>
class Node
{
    public:
    T value;
    Node<T>* next;

    Node(T value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

template<typename T>
class stack
{
private:
    Node<T>* top;
    int height;
public:
    stack(T value)
    {
        top = new Node<T>(value);
        height = 1;
    }
    
    ~stack()
    {
        while(top != nullptr)
        {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    void push(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        height++;
    }
    
    T getTop()
    {
        return top->value;
    }
    
    void pop()
    {
        if(height == 0)
            return;
            
        Node<T>* temp = top;
        if(height == 1)
            top = nullptr;
        else
            top = temp->next;
            
        delete temp;
        height--;
    }
    
    void printStack()
    {
        Node<T>* temp = top;
        while(temp)
        {
            cout << temp->value << " " << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    stack<int> s(5);
    s.push(10);
    s.push(20);
    s.printStack();
    s.pop();
    s.printStack();
    
    cout << s.getTop() << endl;

    
    return 0;

}