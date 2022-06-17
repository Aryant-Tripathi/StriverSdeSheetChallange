long double Multiply_possible(double mid, int n)
{
    long double ans = 1.00;
    for(int i = 1; i <= n; i++)
    {
        ans *= mid;
    }
    
    return (ans);
}

double findNthRootOfM(int n, long long m) {
	
	// binary search is not working
	
	// Write your code here.
//     long double low = 1.00;
//     long double high = (long double)m;
//     long double minimum_space = 1e-9;
    
//     while((high - low) > minimum_space)
//     {
//         long double mid = (low + high) / 2.00;
        
//         if(Multiply_possible(mid, n) < (long double)m)
//         {
//             low = mid;
//         }
//         else
//         {
//             high = mid;
//         }
//     }
    
//     return high; // low
	
	
	// this will work
	
    // Variable to store maximum possible error in order
    // to obtain the precision of 10^(-6) in the answer.
    double error = 1e-7;

    // Difference between the current answer, and the answer
    // in next iteration, which we take as big as possible initially.
    double diff = 1e18;

    // Guessed answer value
    double xk = 2;

    // We keep on finding the precise answer till the difference between
    // answer of two consecutive iteration become less than 10^(-7).
    while (diff > error) {

        // Answer value in the next iteration.
        double xk_1 = (pow(xk, n) * (n - 1) + m) / (n * pow(xk, n - 1));

        // Difference of answer in consecutive states updated.
        diff = abs(xk - xk_1);

        // Updating the current answer with the answer of next iteration.
        xk = xk_1;
    }

    // Returning the nthRootOfM with precision upto 6 decimal places
    // which is xk.
    return xk;

}

