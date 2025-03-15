/******************************************************************************

Hash table

*******************************************************************************/
#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

class Node
{
public:
	string key;
	int value;
	Node* next;

	Node(string k, int val)
	{
		key = k;
		value = val;
		next = nullptr;
	}

};

class hashTable
{
private:
	static const int SIZE = 7;
	Node* dataMap[SIZE];


public:
	hashTable()
	{
		for(int i = 0; i < SIZE; ++i)
		{
			dataMap[i] = nullptr;
		}
	}

	~hashTable()
	{
		for(int i = 0; i < SIZE; ++i)
		{
			Node* head = dataMap[i];
			while(head)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
	}

	void printTable()
	{
		for(int i = 0; i < SIZE; ++i)
		{
			cout << "index " << i << " : ";
			Node* head = dataMap[i];
			while(head)
			{
				cout << "[ " << head->key << " : " << head->value << "]";
				head = head->next;
			}
			cout << endl;
		}
	}

	int hash(string k)
	{
		int sum = 0;
		for(int i = 0 ; i < k.length(); ++i)
		{
			sum += (k[i]*23);
		}
		return (sum % SIZE);
	}

	void set(string k, int val)
	{
		int index = hash(k);
        
		Node* newNode = new Node(k, val);
		if(dataMap[index] == nullptr)
		{
			dataMap[index] = newNode;
			
		}
		else
		{
			Node* temp = dataMap[index];
			while(temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	
	int get(string k)
	{
	    int index = hash(k);
	    
	    Node* temp = dataMap[index];
	    while(temp)
	    {
	        if(temp->key == k)
	            return temp->value;
	       
	        temp = temp->next;
	    }
	    return 0;
	}
	
	vector<string> getKeys()
	{
	    vector<string> vstr;
	    for(int i = 0; i < SIZE; ++i)
	    {
	        Node* temp = dataMap[i];
	        while(temp)
	        {
	            vstr.push_back(temp->key);
	            temp = temp->next;
	        }
	    }
	    return vstr;
	}
	
	

};

int main()
{
	hashTable h;

	h.set("amar", 31);
	h.set("neha", 29);
	h.set("aniket", 27);
	h.set("nishant", 25);
	h.set("nikhil", 27);
	h.printTable();
	
	cout << h.get("amar") << endl;
	
	auto v = h.getKeys();
	
	for(auto it : v)
	{
	    cout << it << " ";
	}
	cout << endl;

	return 0;
}