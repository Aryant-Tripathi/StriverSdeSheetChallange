#include<bits/stdc++.h>

struct Node
{
    Node* links[2]; // For 0 and 1
    
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
    
    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
};

class Trie
{
    private: Node* root;
    public:
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(int num)
    {
        Node* node = root;
        for(int i = 31; i >= 0; i--)
        {
            // this bit gives me set or not on ith index in binary
            int bit = (num >> i) & 1; 
            
            if(!node -> containsKey(bit))
            {
                node -> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    }
    
    int getMax(int num)
    {
        Node* node = root;
        int maxNum = 0;
        
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            
            // since i want to maximise my bit by doing xor, 
            // so at that position i want opposite of it
            // because 1 ^ 0 = 1 && 0 ^ 1 = 1
            // and 1 ^ 1 = 0 && 0 ^ 0 = 1
            // !bit is opposite of bit
            
            if(node -> containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node -> get(!bit);
            }
            else
            {
                node = node -> get(bit);
            }
        }
        
        return maxNum;
    }
};


bool static cmp(vector<int>& arr1, vector<int>& arr2)
{
    return arr1[1] < arr2[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    //  Write your coode here.
    int n = arr.size();
    int m = queries.size();
    
    for (int i = 0; i < queries.size(); i++) {
        queries[i].push_back(i);
    }
    
    sort(arr.begin(), arr.end());
    
    sort(queries.begin(), queries.end(), cmp);
    
    vector<int> ans(m, -1);
    Trie trie;
    int move = 0;
    
    for(int i = 0; i < m; i++)
    {
        int xi = queries[i][0];
        int ai = queries[i][1];
        int queryIndex = queries[i][2];
        
        while(move < n && arr[move] <= ai)
        {
            trie.insert(arr[move]);
            move++;
        }
        
        if(move == 0) ans[queryIndex] = -1;
        else
        ans[queryIndex] = trie.getMax(xi);
    }
    
    return ans;
}