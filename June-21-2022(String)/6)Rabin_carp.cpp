vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int> ans;
    for(int i=0;i<=str.length()-pat.length();i++)
    {
        int k=0;
        int count=0;
        for(int j=i;j<i+pat.length();j++)
        {
            if(str[j]==pat[k])
            {
                count++;
            }
            k++;
        }
        if(count==pat.length())   ans.push_back(i);
    }
    return ans;
}

