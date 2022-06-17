int minimumElement(int low, int high, int n, int* arr)
{
    if(arr[low] <= arr[high])
    {
        return low;
    }
    
    int index;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        
        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            index = mid;
            break;
        }
        
        if(arr[low] <= arr[mid])
        {
            low = mid + 1;
        }
        else if(arr[mid] <= arr[high])
        {
            high = mid - 1;
        }
    }
    
    return index;
}

int search(int low, int high, int target, int* arr)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;
}

int search(int* arr, int n, int target) {
    // Write your code here.
    int index = minimumElement(0, n - 1, n, arr);
    
    int firstHalf = search(0, index - 1, target, arr);
    int secondHalf = search(index, n - 1, target, arr);
    
    if(firstHalf == -1 && secondHalf == -1)
    {
        return -1;
    }
    else if(firstHalf == -1 || secondHalf != -1)
    {
        return secondHalf;
    }
    else
    {
        return firstHalf;
    }
    
}