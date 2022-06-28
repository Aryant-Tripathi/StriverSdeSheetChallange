int kthLargest(vector<int>& arr, int size, int k)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}