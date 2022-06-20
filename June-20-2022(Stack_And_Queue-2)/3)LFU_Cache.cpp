#include<bits/stdc++.h>
struct Node
{
    int key, val, count;
    Node* next;
    Node* prev;
    
    Node(int comingKey, int comingValue)
    {
        key = comingKey;
        val = comingValue;
        count = 1;
    }
};

struct List
{
    int size;
    Node* head;
    Node* tail;
    
    List() 
    {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void AddNode(Node* node)
    {
        Node* temp = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
        size++;
    }
    
    void DeleteNode(Node* node)
    {
        Node* delprev = node -> prev;
        Node* delnext = node -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
        size--;
    }
};


class LFUCache
{
public:
    
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int minFreq;
    int mxsize;
    int currSize;
    
    LFUCache(int capacity)
    {
        // Write your code here.
        mxsize = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateFreqListMap(Node *node) 
    {
        keyNode.erase(node -> key); 
        freqListMap[node -> count]->DeleteNode(node); 
        if(node->count == minFreq && freqListMap[node->count]->size == 0) 
        {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node -> count + 1) != freqListMap.end()) 
        {
            nextHigherFreqList = freqListMap[node->count + 1];
        } 
        
        node->count += 1; 
        nextHigherFreqList->AddNode(node); 
        freqListMap[node->count] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    

    int get(int key)
    {
        // Write your code here.
         if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            int value = node -> val;
            updateFreqListMap(node); 
            return value;
        }
        
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(mxsize == 0)
            return;
        
        if(keyNode.find(key) != keyNode.end()) 
        {
            Node* node = keyNode[key]; 
            node->val = value; 
            updateFreqListMap(node); 
        }
        else
        {
            if(currSize == mxsize)
            {
                List* list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->DeleteNode(list->tail->prev);
                currSize--; 
            }
            
            currSize++;
            
            minFreq = 1;
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) 
            {
                listFreq = freqListMap[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->AddNode(node);
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};

