#include<bits/stdc++.h>

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a[1] > b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    
//     for(int i = 0; i < n; i++)
//         cout << jobs[i][0] << " " << jobs[i][1] << endl;
    int mxDeadline = 0;
    for(int i = 0; i < n; i++)
        mxDeadline = max(mxDeadline, jobs[i][0]);
    
    vector<int> dayDone(mxDeadline + 1, -1);
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = jobs[i][0]; j > 0; j--)
        {
            if(dayDone[j] == -1)
            {
                dayDone[j] = 0;
                ans += jobs[i][1];
                break;
            }
        }
    }
    return ans;
    
}

