#include <bits/stdc++.h> 
 // hm yhi dekhenge ki agr mai..aaj hi bech dun toh, mujhe sbse jyada fyada kitna hoga..hr din hm yhi soch kr chalenge ki agr main aaj hi bech dun toh mujhe kitna profit hoga
    // iske liye hme ek minimum lekr chalna padhega, ki aaj ke din se phle mujhe abhi tk sbse minimum kya dikha hai..(basically hm yeh minimum isiliye lekr chalnge ki hm suppose krenge ki agr hm iss din buy kr lete toh ..profit main hme sbse jyada fyada hoga)

int maximumProfit(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    
    int minimum_so_far = arr[0];
    int ans = 0;
    
    for(int i = 1; i < n; i++)
    {
        ans = max(ans, arr[i] - minimum_so_far);
        minimum_so_far = min(minimum_so_far, arr[i]);
    }
    
    return ans;
}