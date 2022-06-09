#include <bits/stdc++.h> 
/* (ab) mod p = ( (a mod p) (b mod p) ) mod p 

For example a = 50,  b = 100, p = 13
50  mod 13  = 11
100 mod 13  = 9

(50 * 100) mod 13 = ( (50 mod 13) * (100 mod 13) ) mod 13 
or (5000) mod 13 = ( 11 * 9 ) mod 13
or 8 = 8
*/
int modularExponentiation(int xx, int n, int m) {
    // Write your code here.
    long long int ans = 1;
    long long int x = xx;
    while(n > 0)
    {
        if(n & 1)
        {
            ans = ((1LL * ans * ((long long int)x)) % m) % m;
            n = n - 1;
        }
        else
        {
            x = ((x % m) * (x % m)) % m;
            n = n >> 1;
        }
    }
    
    return (int) (ans % m);
}