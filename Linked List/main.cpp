/******************************************************************************
linked list:

Linked list should have head and tail pointer.

Append              -   O(1)
Remove last         -   O(n)
Prepend             -   O(1)
remove first        -   O(1)
insert middle       -   O(n)
remove middle       -   O(n)
Look up by value    -   O(n)
look up by index    -   O(n)

*******************************************************************************/
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int v):value(v),next(nullptr){
        
    }
};

class linkedList
{
    Node* Head;
    Node* Tail;
    int length;
    
public:

    linkedList() = default;

    linkedList(int value)
    {
        Node* newNode = new Node(value);
        Head = newNode;
        Tail = newNode;
        length = 1;
    }
    
    ~linkedList()
    {
        Node* temp = Head;
        while(temp)
        {
            Head = temp->next;
            delete temp;
            temp = Head;
        }
    }

    void print()
    {
        Node* temp = Head;
        
        cout << "linked list length = " << length << " :: ";
        
        while(temp)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    
    int getValue(Node* temp)
    {
        return temp->value;
    }
    
    void append(int val)
    {
        Node* newNode = new Node(val);
        Tail->next = newNode;
        Tail = newNode;
        length++;
    }
    
    void removeLast()
    {
        Node* temp = Head;
        //if length == 0
        if(length == 0)
            return;
        //length == 1 temp will be deleted at the end
        if(length == 1)
        {
            Head = nullptr;
            Tail = nullptr;
        }
        else
        {
            Node* pre = Head;
            while(temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            Tail = pre;
            Tail->next = nullptr;
        }
        --length;
        delete temp;
    }
    
    void prepend(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = Head;
        Head = newNode;
        length++;
    }
    
    void removeFirst()
    {
        if(length == 0)
            return;
        
        Node* temp = Head;
        Head = temp->next;
        delete temp;
        length--;
    }
    
    Node* get(int index)
    {
        if(index < 0 || index > length)
            return nullptr;
            
        Node* temp = Head;
        for(int i = 0; i < length; i++)
        {
            if(i == index)
            {
                cout << "get = " << temp->value << endl;
                break;
            }
            temp = temp->next;
        }
        
        return temp;
    }
    
    bool set(int val, int index)
    {
        if(index < 0 || index > length)
            return false;
            
        Node* temp = Head;
        for(int i = 0; i < length; i++, temp=temp->next)
        {
            if(i == index)
            {
                temp->value = val;
                break;
            }
        }
        return true;
    }
    
    bool insert(int val, int index)
    {
        if(index < 0 || index > length)
            return false;
            
        if(index == 0)
        {
            prepend(val);
            return true;
        }
            
        if(index == length)
        {
            append(val);
            return true;
        }
            
        Node* newNode = new Node(val);
        Node* temp = get(index-1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }
    
    void deleteNode(int index)
    {
        if(index < 0 || index >= length)
            return;
            
        if(index == 0)
            return removeFirst();
        if(index == length-1)
            return removeLast();
            
        Node* pre = get(index-1);
        Node* temp = pre->next;
        
        pre->next = temp->next;
        delete temp;
        length--;
    }
    
    void reverse()
    {
        Node* currunt = Head;
        Node* forward = Head;
        Node* rev = nullptr;
        Node* temp = Head;
        Head = Tail;
        Tail = temp;
        
        while(forward)
        {
            forward = currunt->next;
            currunt->next = rev;
            rev = currunt;
            currunt = forward;
        }
    }
    
    void reverse(int m, int n)
    {
        Node* temp = Head;
        Node* pre = Head;
        int i = 0;
        for(; i < m; ++i)
        {
            pre = temp;
            temp = temp->next;
        }
        
        Node* currunt = temp;
        Node* forward = temp;
        Node* rev = pre;
        
        cout << "cur = " << currunt->value;
        
        // while(i < n)
        // {
        //     forward = currunt->next;
        //     currunt->next = rev;
        //     rev = currunt;
        //     currunt = forward;
        //     i++;
        // }
    }
    /*Implement a member function, findMiddleNode(), which finds and returns the middle node of the linked list.

    Note: this LinkedList implementation does not have a length member variable.*/
    Node* findMiddleNode()
    {
        if(Head == Tail)
            return Head;
        
        Node* slow = Head;
        Node* fast = Head;
        
        while(slow&&fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << "middle node is " << slow->value << endl;
        return slow;
    }
    
    /*Implement a function called hasLoop to detect if a given singly-linked list contains a loop (a cycle) or not.

    The function should return true if a loop is detected in the linked list, and false otherwise.*/
    
    bool hasLoop()
    {
        if(Head == nullptr || Head->next == nullptr)
            return false;
        if(Tail->next == Head)
            return true;
        
        Node* slow = Head;
        Node* fast = Head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
                return true;
        }
        return false;
    }
    
    /*Implement the findKthFromEnd member function for the LinkedList class, which returns the k-th node from the end of the linked list 
    WITHOUT USING THE LENGTH of the list.

    If the value of k is greater than the length of the list, the function should return nullptr.*/
    Node* findKthFromEnd(int k)
    {
        if(Head == nullptr)
            return nullptr;
        
        Node* slow = Head;
        Node* fast = Head;
        while(fast && fast->next)
        {
            if(k == 0)
            {
                fast = fast->next;
                slow = slow->next;
            }
            else
            {
                fast = fast->next;
                k--;
            }
        }
        if(k == 0)
        {
            cout <<"Kth node from end is " << slow->value << endl;
            return slow;
        }
        else
            return nullptr;
    }
    
    /*Implement the removeDuplicates member function for the LinkedList class, which removes all duplicate values from a singly linked list.

    The function should preserve the original order of the non-duplicate elements.

    Note:  This linked list class does NOT have a tail which will make this method easier to implement.*/
    
    void deleteNode(Node* node)
    {
        Node* temp = Head;
        Node* pre = Head;
        
        while(temp && (temp != node))
        {
            pre = temp;
            temp = temp->next;
        }
        
        pre->next = temp->next;
        delete temp;
        length--;
    }
    
    void removeDuplicates()
    {
        Node* currunt = Head;
        
        while(currunt)
        {
            Node* runner = currunt->next;
            while(runner)
            {
                if(runner->value == currunt->value)
                {
                    deleteNode(runner);
                    break;
                }
                runner = runner->next;
            }
            currunt = currunt->next;
        }
    }
    
    /*You have a linked list where each node represents a binary digit (0 or 1). The goal of the binaryToDecimal function is to 
    convert this binary number, represented by the linked list, into its decimal equivalent.*/
    int binaryToDecimal()
    {
        if(length == 0)
            return 0;
        
        int num = 0;
        Node* temp = Head;
        
        while(temp)
        {
            num = num*2 + temp->value;
            temp = temp->next;
        }
        return num;
    }
    
    
    
};



int main()
{
    linkedList* ll = new linkedList(6);
    ll->append(8);
    ll->append(10);
    ll->removeLast();
    //ll->removeLast();
    //ll->removeLast();
    ll->prepend(4);
    //linkedList* ll1 = new linkedList();
    //ll1->prepend(2);
    ll->removeFirst();
    // ll->removeFirst();
    // ll->removeFirst();
    // ll->removeFirst();
    // ll->removeFirst();
    ll->append(12);
    ll->prepend(2);
    
    Node* temp = ll->get(2);
    
    cout << "set success = " << ll->set(14, 1) << endl;
    
    ll->insert(16, 3);
    ll->insert(18, 1);
    ll->prepend(1);
    ll->insert(20, 0);
    ll->insert(22, 6);
    
    ll->print();
    
    ll->deleteNode(8);
    
    ll->print();
    
    ll->reverse();
    ll->print();
    ll->prepend(1);
    ll->print();
    
    ll->findMiddleNode();
    
    if(ll->hasLoop())
        cout << "Linked list has a loop" << endl;
    else
        cout << "Linked list does not have a loop" << endl;
        
    Node* temp1 = ll->findKthFromEnd(3);
    if(temp1 == nullptr)
        cout << "failed to get kth from end" << endl;
    else
        cout << "kth node from end is " << ll->getValue(temp1) << endl;
    
    ll->append(8);
    ll->prepend(20);
    ll->print();
    
    ll->reverse(2,6);
    ll->print();
    
    ll->removeDuplicates();
    ll->print();
    
    linkedList* binarylist = new linkedList(1);
    binarylist->append(0);
    binarylist->append(1);
    
    cout << "decimal = " << binarylist->binaryToDecimal() << endl;
    
}


