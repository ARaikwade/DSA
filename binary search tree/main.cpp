/******************************************************************************
BST

*******************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node* root;
    
public:
    BST()
    {
        root = nullptr;
    }
    
    bool contains(int val)
    {
        if(root == nullptr) return false;
        
        Node* temp = root;
        while(temp)
        {
            if(val < temp->value)
                temp = temp->left;
            else if(val > temp->value)
                temp = temp->right;
            else
                return true;
        }
        return false;
    }
    
    void insert(int val)
    {
        //create new Node
        Node* newNode = new Node(val);
        
        //if tree is empty
        if(root == nullptr)
            root = newNode;
        
        //travers to find the right location.
        Node* temp = root;
        while(temp)
        {
            if(val == temp->value)
            {
                return;
            }
            else if(val < temp->value)
            {
                if(temp->left == nullptr)
                {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            }
            else
            {
                if(temp->right == nullptr)
                {
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
        }
    }
    
    
    //recursive contains
    bool rContains(Node* currNode, int val)
    {
        if(currNode == nullptr)
            return false;
            
        if(currNode->value ==  val)
            return true;
            
        if(val < currNode->value)
            return rContains(currNode->left, val);
        else
            return rContains(currNode->right, val);
    }
    
    bool rContains(int val)
    {
        return rContains(root, val);
    }
    
    //recursive insert
    Node* rinsert(Node* currNode, int val)
    {
        if(currNode == nullptr) 
            return new Node(val);
            
        if(val < currNode->value)
            currNode->left = rinsert(currNode->left, val);
        else
            currNode->right = rinsert(currNode->right, val);
            
        return currNode;
    }
    
    void rinsert(int val)
    {
        if(root == nullptr) 
            root = new Node(val);
            
        rinsert(root, val);
    }
    
    int findMin(Node* currNode)
    {
        while(currNode->left != nullptr)
        {
            currNode = currNode->left;
        }
        return currNode->value;
    }
    
    Node* deleteNode(Node* currNode, int val)
    {
        //If value is not present in tree
        if(currNode == nullptr)
            return nullptr;
            
        //If value is less than currunt node value  
        if(val < currNode->value)
        {
            currNode->left = deleteNode(currNode->left, val);
        }
        //if value is more than currunt node value
        else if(val > currNode->value)
        {
            currNode->right = deleteNode(currNode->right, val);
        }
        //If value matches with currunt node
        else
        {
            //there are four cases,
            //1. If node is leaf and there is no child
            if(currNode->left == nullptr && currNode->right == nullptr)
            {
                delete currNode;
                //This will return to parent of this node and assign nullptr.
                return nullptr;
            }
            //2. If node has left child
            else if(currNode->right == nullptr)
            {
                Node* temp = currNode->left;
                delete currNode;
                //This will return to parent of this node and assign temp as new child.
                return temp;
            }
            //3. If node has right child
            else if(currNode->left == nullptr)
            {
                Node* temp = currNode->right;
                delete currNode;
                return temp;
            }
            //4. if node has both childs
            else
            {
                //Then we need to find the minimum node on right side of currNode.
                //assign its value to curr node value and delete minimum node.
                int min = findMin(currNode->right);
                currNode->value = min;
                currNode->right = deleteNode(currNode->right, min);
            }
            
        }
        
        return currNode;
        
    }
    
    void deleteNode(int val)
    {
        root = deleteNode(root, val);
    }
    
    void BFS()
    {
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            Node* currNode = q.front();
            q.pop();
            
            cout << currNode->value << " ";
            
            if(currNode->left != nullptr)
                q.push(currNode->left);
            if(currNode->right != nullptr)
                q.push(currNode->right);
        }
        cout << endl;
    }
    
    void preOrder(Node* currNode)
    {
        cout << currNode->value << " ";
        if(currNode->left)
            preOrder(currNode->left);
        if(currNode->right)
            preOrder(currNode->right);
    }
    
    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }
    
    void postOrder(Node* currNode)
    {
        if(currNode->left)
            postOrder(currNode->left);
        if(currNode->right)
            postOrder(currNode->right);
            
        cout << currNode->value << " ";
    }
    
    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }
    
    void inOrder(Node* currNode)
    {
        if(currNode->left)
            inOrder(currNode->left);
        if(currNode->right)
            inOrder(currNode->right);
            
        cout << currNode->value << " ";
    }
    
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }
};

int main()
{
    BST* bst = new BST();
    
    bst->insert(10);
    bst->insert(20);
    bst->insert(5);
    cout << bst->contains(7) << endl;
    
    cout << bst->rContains(20) << endl;
    bst->rinsert(30);
    cout << bst->rContains(30) << endl;
    bst->deleteNode(30);
    cout << bst->rContains(30) << endl;
    bst->insert(8);
    bst->insert(12);
    
    bst->BFS();
    bst->preOrder();
    bst->postOrder();
    bst->inOrder();

    return 0;
}