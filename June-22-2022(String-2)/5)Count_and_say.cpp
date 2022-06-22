string writeAsYouSpeak(int n) 
{
    // Write your code here.
     if(n == 1)
            return "1";
        
        string s = "1";
        for(int i = 2; i <= n; i++)
        {
            s += '$'; // just to include last character, see j loop u got it
            string temp = "";
            int count = 1;
            
            for(int j = 1; j < s.length(); j++)
            {
                if(s[j] == s[j - 1])
                {
                    count++;
                }
                else
                {
                    temp += to_string(count);
                    temp += s[j - 1];
                    count = 1;
                }
            }
            
            s = temp;
        }
        
        return s;
    
}