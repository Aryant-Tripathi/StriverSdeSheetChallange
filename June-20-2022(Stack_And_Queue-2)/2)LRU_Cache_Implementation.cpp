#include<bits/stdc++.h>
class LRUCache
{
public:
    // making doubly linked list
    class Node
    {
        public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int keycome, int value)
        {
            key = keycome;
            val = value;
        }
    };
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    int mxsize;
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity)
    {
        // Write your code here
        mxsize = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void AddNode(Node* newnode)
    {
        Node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        
        head -> next = newnode;
        temp -> prev = newnode;
    }
    
    void DeleteNode(Node* delnode)
    {
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key_)
    {
        // Write your code here
        if(mp.find(key_) != mp.end())
        {
            Node* answerNode = mp[key_];
            int ans = answerNode -> val;
            mp.erase(key_);
            
            DeleteNode(answerNode);
            AddNode(answerNode);
            mp[key_] = head -> next;
            
            return ans;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        // Write your code here
        if(mp.find(key_) != mp.end())
        {
            Node* existingNode = mp[key_];
            mp.erase(key_);
            DeleteNode(existingNode);
        }
        
        if(mp.size() == mxsize)
        {
            mp.erase(tail -> prev -> key);
            DeleteNode(tail -> prev);
        }
        
        Node* ToAdd = new Node(key_, value);
        AddNode(ToAdd);
        mp[key_] = head -> next;
        
    }
};

