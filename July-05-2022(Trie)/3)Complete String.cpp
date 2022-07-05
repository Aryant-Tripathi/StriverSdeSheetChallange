/* IDEA:
   1) hm ek trie bnayenge aur array ke hr word ko trie main daal denge.
   2) trie ka flag variable isiliye use hota hai ki kya yahan koi word end ho
   rha hai yaa nhi.
   3) hr word ko trie main daalne ke baad hm hr word ki prefix ke liye hm trie 
   main hi dekhenge ki kya koi word iska present hai yaa nhi.
   4) agr uss particular word ka hr prefix present hua trie main toh length and
   uske baad lexigraphically check kr lenge
   
   T.C -> trie main insert krne ki time complexity 
        O(length of word) aur hm hr word ko insert kr rhe hain
        toh O(n) * O(len of each word) + 
        hr word ke prefix ka word search krne ke liye T.C O(length of word)
        and isme bhi hr word ke liye krenge so O(n) + O(length of word)
        
        so overall Time Complexity huyi
        T.C = ( (O(n) * O(len of each word)) + (O(n) + O(len of each word)) )
        
        See commented code also
*/

struct Node // Trie ka node kaise dikhega
{
    Node* links[26]; // for 26 charaters
    bool flag = false; // to tell whether a word is present or not
    
    bool containsKey(char ch)//check whether this character already exist or not
    {
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node) // for putting a character into the trie
    {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) // to get the reference of this character
    {
        return links[ch - 'a'];
    }
    
    void setEnd() // if we find a word then we set it's flag so for that
    {
        flag = true;
    }
    
    bool isEnd()//to tell whether any word exist at this particular point or not
    {
        return flag;
    }
};

class Trie // trie class 
{
    private: Node* root; // make a root node
    public:
    
    Trie()
    {
        root = new Node(); // acquring memory for root node
    }
    
    // to insert a string in the trie
    void insert(string& word)
    {
        Node* node = root; // pointer to reference the root node
        
        // travel in the whole string
        for(int i = 0; i < word.length(); i++)
        {
            // if this particular character is not present in the trie
            // (checked by containsKey function) 
            // then we have to make a reference node in the trie
            // (done by put function)
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            }
            
            // move node to next referenced node
            node = node -> get(word[i]);
        }
        
        // since we insert this string into our trie
        // so at this point set it's flag true so that we know 
        // that at this point a word ends here
        // done by setEnd function
        node -> setEnd(); 
    }
    
    // for a string check for all its prefixes
    // whether a word present in trie or not
    bool checkAllPrefix(string& word)
    {
        Node* node = root; // pointer to reference the root node
        
         // travel in the whole string
        for(int i = 0; i < word.length(); i++)
        {
            // if this particular character is not present in the trie
            // (checked by containsKey function) 
            // then simply we return false saying that this word is not present
            // in our trie
            if(!node -> containsKey(word[i]))
            {
                return false;
            }
            else // else if this character is present in our trie 
            {
                // then there should be a word end at this positon 
                // because only after this, this string qualifies the criteria 
                // of becoming the complete string
                
                node = node -> get(word[i]);
                
                if(!node -> isEnd())
                {
                    // if no word ends at here
                    // simply return false because now it can't be a 
                    // complete string
                    return false;
                }
            }
        }
        
        // at last return isEnd, isEnd tells us that whether a word 
        // ends at here or not, if yes it returns true
        // otherwise it returns false
        return node -> isEnd();
    }
    
};

string completeString(int N, vector<string> &arr){
    // Write your code here.
    int n = arr.size(); // extract the size of the array
        
        Trie trie; // make a data type of class Trie
        
        // insert each word into our trie
        for(string& word: arr)
        {
            trie.insert(word);
        }
        
        string longest = ""; // this should be my answer
        
        // now for every word we check whether it is our complete string or not
        // if yes, then find longest
        for(string& word: arr)
        {
            // if it's all of the prefixes present in our trie, then
            // compute answer
            // checkAllPrefix function will do that
            
            if(trie.checkAllPrefix(word)) // if it is a complete string
            {
                // and it's length is larger than current longest string
                if(word.length() > longest.length())
                {
                    longest = word; // make this answer
                }
                else if(word.length() == longest.length() 
                       && word < longest)
                {
                    // we have to pick lexicographically smallest
                    longest = word;
                }
            }
        }
        
    if(longest == "") return "None";
        return longest; // finally return the longest string as answer
        
}