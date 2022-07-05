struct Node
{
    Node* links[26];
    int countEndWith = 0;
    int countPrefix = 0;
    
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
    
    void increaseEnd()
    {
        countEndWith++;
    }
    
    void increasePrefix()
    {
        countPrefix++;
    }
    
    void deleteEnd()
    {
        countEndWith--;
    }
    
    void reducePrefix()
    {
        countPrefix--;
    }
    
    int getEnd()
    {
        return countEndWith;
    }
    
    int getPrefix()
    {
        return countPrefix;
    }
};

class Trie{
    private: Node* root; // creating new node
    public:

    Trie(){
        // Write your code here.
        root = new Node(); // accquiring memory
    }

    void insert(string &word){
        // insert func is same as first one
        // T.C -> O(length of the word);
        
        Node* node = root; // make a pointer node to the root node
        
        for(int i = 0; i < word.length(); i++)
        {
            // if this node does not contain this chaacter
            // then we have to make a refernce node for this 
            // particular character, and put function will do that
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            }
            
            // move node to next reference chracter with the 
            // help of get function
            node = node -> get(word[i]);
            
            // everytime we will move, we will increase
            // the increasePrefix, as the number of words 
            // with this prefix has been increased
            node -> increasePrefix();
        }
        
        // at last since we reach to the end of the word
        // we have to increase the frequency of word
        // with the help of increaseEnd function
        node -> increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root; // make a pointer node to the root node
        
        // travel from the whole word
        for(int i = 0; i < word.length(); i++)
        {
            // if this particular present in the trie(containskey)
            // move node to the next referenced character (get fn)
            if(node -> containsKey(word[i]))
            {
                node = node -> get(word[i]);
            }
            else // else if does not contain this character that 
                // means it is not present, so return 0;
                return 0;
        }
        
        // after travelling all over the word,
        // we finally return how many words end here with the 
        // help of getEnd function
        return node -> getEnd();
        
    }

    int countWordsStartingWith(string &word){
        Node* node = root; // make a pointer node to the root node
        
         // travel from the whole word
        for(int i = 0; i < word.length(); i++)
        {
            // if this particular present in the trie(containskey)
            // move node to the next referenced character (get fn)
            if(node -> containsKey(word[i]))
            {
                node = node -> get(word[i]);
            }
            // else if does not contain this character that 
            // means it is not present, so return 0;
            else return 0;
        }
        
        // after travelling all over the word,
        // we finally return how many words having prefix herew
        // with the help of getPrefix function
        return node -> getPrefix();
    }

    void erase(string &word){
        Node* node = root; // make a pointer node to the root node
        
        for(int i = 0; i < word.length(); i++)
        {
            if(node -> containsKey(word[i]))
            {
                node = node -> get(word[i]);
                node -> reducePrefix();
            }
            else return;
        }
        
        node -> deleteEnd();
    }
};

