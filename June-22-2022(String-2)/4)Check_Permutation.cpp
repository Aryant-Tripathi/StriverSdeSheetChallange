bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int freq1[26] = {0}, freq2[26] = {0};
    
    for(int i = 0; i < str1.size(); i++)
    {
        freq1[str1[i] - 'a']++;
    }
    
    for(char c: str2)
    {
        freq2[c - 'a']++;
    }
    
    bool check = true;
    for(int i = 0; i < 26; i++)
    {
        if(freq1[i] != freq2[i])
        {
            check = false;
            break;
        }
    }
    
    return check;
}