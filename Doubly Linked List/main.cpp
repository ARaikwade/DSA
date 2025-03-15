/******************************************************************************

Doubly linked list

*******************************************************************************/
#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node* prev;
    
    Node(int val)
    {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
    
};

class DoublyLinedList
{
    Node* head;
    Node* tail;
    int length;
    
public:
    DoublyLinedList(int val)
    {
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
        length++;
    }
    
    void printList()
    {
        Node* temp = head;
        
        while(temp)
        {
            cout << temp->value << "<->";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void append(int val)
    {
        Node* newNode = new Node(val);
        if(length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        
        length++;
    }
    
    void deleteLast()
    {
        if(length == 0)
            return;
            
        Node* temp = tail;
            
        if(length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = temp->prev;
            tail->next = nullptr;
        }
        
        delete temp;
        length--;
    }
    
    void prepend(int val)
    {
        Node* newNode = new Node(val);
        
        if(length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        
        length++;
    }
    
    void deleteFirst()
    {
        if(length == 0)
            return;
        
        Node* temp = head;
        
        if(length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = temp->next;
            head->prev = nullptr;
        }
        
        delete temp;
        length--;
    }
    
    Node* get(int index)
    {
        if(index < 0 || index >= length)
            return nullptr;
        
        Node* temp = head;
        for(int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp;
    }
    
    bool set(int val, int index)
    {
        Node* temp = get(index);
        if(temp == nullptr)
            return false;
            
        temp->value = val;
        return true;
    }
    
    bool insert(int index, int value)
    {
        if(index < 0 || index > length)
            return false;
            
        if(index == 0)
        {
            prepend(value);
            return true;
        }
        else if(index == length)
        {
            append(value);
            return true;
        }
            
        Node* newNode = new Node(value);
        Node* before = get(index-1);
        Node* after = before->next;
        
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
            
            
        return true;
    }
    
    bool deleteNode(int index)
    {
        if(index < 0 || index > length)
            return false;
            
        if(index == 0)
        {
            deleteFirst();
            return true;
        }
        
        if(index == length-1)
        {
            deleteLast();
            return true;
        }
            
        Node* temp = get(index);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
        return true;
    }
};

int main()
{
    DoublyLinedList dll(1);
    
    //append
    dll.printList();
    dll.append(2);
    dll.printList();
    
    //delete last
    dll.deleteLast();
    dll.printList();
    dll.deleteLast();
    dll.printList();
    dll.deleteLast();
    dll.printList();
    
    //prepend
    dll.prepend(2);
    dll.printList();
    dll.prepend(1);
    dll.printList();
    
    cout << "delete first" << endl;
    //delete first
    dll.deleteFirst();
    dll.printList();
    dll.deleteFirst();
    dll.printList();
    dll.deleteFirst();
    dll.printList();
    
    //get-set
    dll.append(3);
    dll.append(4);
    dll.prepend(2);
    dll.prepend(1);
    dll.printList();
    
    dll.set(10, 1);
    dll.printList();
    dll.set(20, 4);
    dll.printList();
    
    dll.insert(2, 20);
    dll.insert(0, 30);
    
    dll.printList();
    
    dll.deleteNode(1);
    dll.deleteNode(6);
    dll.printList();

    return 0;
}