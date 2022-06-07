#include <bits/stdc++.h> 

int findDuplicate(vector<int> &arr, int n){
  // Write your code here.
    
    if(n <= 1) return -1;
    
    int slow = arr[0];
    int fast = arr[arr[0]];
    
    // meeting point
    while(slow != fast)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    
    // take one to intial pos
    slow = 0;
    while(slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return slow;
    
}




/* For example, let's assume
nums = [2,1,3,1], then the mapping function is 0->2, {1,3}->1, 2->3. Then the sequence we get definitely has a cycle. 0->2->3->1->1->1->1->1->........ The starting point of this cycle is the duplicate number.
We can use Floyd's Tortoise and Hare Algorithm to find the starting point.

According to Floyd's algorithm, first step, if a cycle does exist, and you advance the tortoise one node each unit of time but the hare two nodes each unit of time, then they will eventually meet. This is what the first while loop does. The first while loop finds their meeting point.

*Second step, take tortoise or hare to the start point of the list (i.e. let one of the animal be 0) and keep the other one staying at the meeting point. Now, advance both of the animals one node each unit of time, the meeting point is the starting point of the cycle. This is what the second while loop does. The second while loop finds their meeting point.*/


