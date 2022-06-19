// question link-
//https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209?topList=striver-sde-sheet-problems

// Stack class.
class Stack {
    
public:
    vector<int> array;
    int size;
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
        array.clear();
    }

    void push(int num) {
        // Write your code here.
        if(array.size() < size)
        array.push_back(num);
    }

    int pop() {
        // Write your code here.
        int top = -1;
        if(!array.empty())
        {
            top = array[array.size() - 1];
            array.pop_back();
        }
        return top;
    }
    
    int top() {
        // Write your code here.
        int top = -1;
        if(!array.empty())
        top = array[array.size() - 1];
        
        return top;
    }
    
    int isEmpty() {
        // Write your code here.
        return (array.empty());
    }
    
    int isFull() {
        // Write your code here.
        return array.size() == size;
    }
    
};