/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


struct Node // how a trie node looks like
{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    
    bool setEnd()
    {
        flag = true;
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
    Node* root; // making the root node
    
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); // accquring memory for root node
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        // T.C -> O(length of the word)
        Node* node = root; // a dummy pointer which points to root
        
        for(int i = 0; i < word.length(); i++)
        {
            // if on the node i m currently standing does 
            // not contain this particular character of word[i]
            // so for this we have to make a new referenced node
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            }
            // after this move to this referenced node
            node = node -> get(word[i]);
        }
        
        // when word ends, for the last referenced word, 
        // we have to mark the flag of this as true
        // so setEnd will do that work for us
        node -> setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        // T.C -> O(length of the word)
        Node* node = root; // a dummy pointer which points to root
        
        for(int i = 0; i < word.length(); i++)
        {
            // if the node on which we are standing,
            // does not contains this particular character
            // simply return false
            if(!node -> containsKey(word[i]))
            {
                return false;
            }
            // or otherwise if it contains move node to next 
            // reference of this character
            node = node -> get(word[i]); 
        }
        
        // if word ended we simply retuen isEnd of word node
        return (node -> isEnd());
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // T.C -> O(length of the word)
        Node* node = root; // a dummy pointer which points to root
        
        for(int i = 0; i < prefix.length(); i++)
        {
            // if the node on which we are standing,
            // does not contains this particular character
            // simply return false
            if(!node -> containsKey(prefix[i]))
            {
                return false;
            }
            
            // or otherwise if it contains move node to next 
            // reference of this character
            node = node -> get(prefix[i]); 
        }
        
        // else we find the prefix
        return true;
    }
};