#include<bits/stdc++.h>

int find(int k,int n,vector<vector<int>> &memo)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        if(memo[k][n]!=-1) return memo[k][n];
        int ans=1000000,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=find(k-1,mid-1,memo);   //egg broken check for down floors of mid
            int right=find(k,n-mid,memo) ;   // not broken check for up floors of mid
            temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
     
     return memo[k][n]=ans;
     
    }

int cutLogs(int K, int N)
{
    // Write your code here.
     vector<vector<int>> memo(K+1,vector<int> (N+1,-1));
        return find(K,N,memo);
}

