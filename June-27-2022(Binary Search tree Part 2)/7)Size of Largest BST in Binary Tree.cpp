/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
class NodeValues
{
   public:
    int mxvalue;
    int mnvalue;
    int size;
    
    NodeValues(int mnvalue, int mxvalue, int size)
    {
        this -> mnvalue = mnvalue;
        this -> mxvalue = mxvalue;
        this -> size = size;
    }
};

NodeValues solve(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return NodeValues(INT_MAX, INT_MIN, 0);
    }
    
    NodeValues left = solve(root -> left);
    NodeValues right = solve(root -> right);
    
    if(root -> data > left.mxvalue && root -> data < right.mnvalue)
    {
        NodeValues ToReturn(0,0,0);
        ToReturn.mnvalue = min(root -> data, left.mnvalue);
        ToReturn.mxvalue = max(root -> data, right.mxvalue);
        ToReturn.size = left.size + right.size + 1;
        
        return ToReturn;
    }
    
    NodeValues ToReturn(0,0,0);
    ToReturn.mnvalue = INT_MIN;
    ToReturn.mxvalue = INT_MAX;
    ToReturn.size = max(left.size, right.size);
    
    return ToReturn;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    
    return solve(root).size;
}

