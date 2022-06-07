#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int i = 0;
    int j = n - 1;
    int move = 0;
    
    while(move <= j)
    {
        if(arr[move] == 0)
        {
            swap(arr[move], arr[i]);
            move++;
            i++;
        }
        else if(arr[move] == 1)
        {
            move++;
        }
        else if(arr[move] == 2)
        {
            swap(arr[move], arr[j]);
            j--;
        }
    }
}