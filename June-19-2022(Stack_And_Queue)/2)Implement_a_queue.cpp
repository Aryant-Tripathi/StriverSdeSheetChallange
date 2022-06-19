class Queue {
public:
    vector<int> arr;
    int i;
    Queue() {
        arr.clear();
        i = 0;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    
    bool isEmpty() {
        // Implement the isEmpty() function
        if(i == 0 && arr.size() == 0) return true;
        return !(i < arr.size());
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(i >= arr.size()) return -1;
        int top = arr[i++];
        return top;
    }

    int front() {
        // Implement the front() function
        if(i >= arr.size()) return -1;
        return arr[i];
    }
};