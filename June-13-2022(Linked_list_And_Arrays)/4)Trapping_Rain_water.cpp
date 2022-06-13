#include <bits/stdc++.h> 
 /* 1) Hr building ke uper paani depend kr rha hai...ki hr ek particular building ke uper kitna paani hai 
    2) Hr building ke uper paani kitna rhega, yeh depend kr rha hai ki uske left main aur uske right main maximum height ki konsi buildings hain. Uske left main aur right main jo bhi maximum height ki building rhegi woh hme btayegi ki kitna paani bhara hai.
    --> toh hm do arrays bnayenge mxl (for left side) and mxr(for right side),
    basicallly mxl hme btayega ki kisi particular index wali building ke liye uske left and right main kon si maximum height ki building hai.
    
    3) accha ka level kitna rhega agr hmne uske left and right main maximum height ki building nikal li toh. Basically, yeh depend krega ki uske left and right main jo buildings aayi hain maximum heights ki unme minimum kon hai. kyunki paani toh whi tk bhra rhega na
    e.g take example 1 
    see for index height[5] = 0, iske left main maximum height ki building hai of height 2(height[3]) and iske right main maximum height ki building hai of height 3(height[7]) 
    pr paani ka level kitna rhega, paani ka level inn dono main jo km hoga utna hi rhega na.  that is min(left highest building, right highest building)
                      min(2,3) --> 2
                      
    4) accha, hmne hr ek building ke liye uske left aur right main highest building nikal lin, pr uss bulding ke uper paani kitna hoga,
    toh uss building ke uper paani hoga 
    --> uss particular building ke (left & right main highest buildings main jo minimum ho) minus (-) (uss building ki height)
    khd socho bhyi, take e.g 1
    suppose for height[6] = 1, hme iss bulding ke uper paani nikala hai, 
    toh iske left main, maximum height ki building 2(height[3]) and iske right main maxm height ki building 3(height[7]), toh maximum level of paani kitna jaa skta hai min(2,3) --> 2
    ab iss bulding ki height khd 1 hai and iske uper paani jaa skta hai maxium 2 height ka, toh iske uper paani kitna jma hoga, obviously 2 - 1 = 1 (see fig)
    so
    --> hm ek water array bnayenge jo yeh store krega ki iske uper kitna paani store ho rha hai, and after that hm sum nikal lenge hr ek building ke uper kitna paani jma hua hai, aur whi hmara answer hoga
    
    
    */
long getTrappedWater(long *arr, int n){
    // Write your code here.
    
    long leftMAX[n]; // for a particuular building iske left main mx
    long rightMAX[n];//for a particuular building iske right main mx
    
    leftMAX[0] = arr[0]; // iske left main kch h hi nhi
    for(int i = 1; i < n; i++)
    {
        leftMAX[i] = max(leftMAX[i - 1], arr[i]);
    }
    
    rightMAX[n - 1] = arr[n - 1]; // iske right main kch h hi nhi
    for(int i = n - 2; i >= 0; i--)
    {
        rightMAX[i] = max(rightMAX[i + 1], arr[i]);
    }
    
    // hr ek building ke uper paani kitna hai aur total sum
    long sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        sum += min(leftMAX[i], rightMAX[i]) - arr[i];
    }
    
    return sum;
}