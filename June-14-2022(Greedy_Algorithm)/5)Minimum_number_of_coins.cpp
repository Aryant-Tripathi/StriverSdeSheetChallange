int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    int number = 0;
   
    for(int i = n - 1; i >= 0; i--)
    {
        if(amount == coins[i])
        {
            return (number + 1);
        }
        
        if(amount > coins[i])
        {
            int times = amount / coins[i];
            number += times;
            
            amount -= (times * coins[i]);
        }
        
        if(amount == 0) break;
    }
    
    return number;
}

