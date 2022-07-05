/* IDEA:
1) Put all numbers of array in trie
2) Again with each number of array find the maximum xor with trie.

*/
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

int maximumXor(vector<int> arr)
{
    // Write your code here.  
    int n = arr.size();
    
    Trie trie; // trie class object
    for(int i = 0; i < n; i++) // put every number into the trie
    {
        trie.insert(arr[i]);
    }
    
    // seee, what i have to find
    //to select two indexes ‘x’ and ‘y’ such that ‘x’ <= ‘y’ and bitwise xor of values present in these indexes is maximum possible among all such pairs.
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, trie.getMax(arr[i]));
    }
    return ans;
}