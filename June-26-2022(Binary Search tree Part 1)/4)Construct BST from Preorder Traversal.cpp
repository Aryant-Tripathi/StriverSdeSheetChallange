/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>

//const int high = 1e9;
TreeNode<int>* solve(int& i, int mxLimit, vector<int>& preorder)
{
    if(i >= preorder.size() || preorder[i] > mxLimit)
    {
        return NULL;
    }
    
    TreeNode<int>* node = new TreeNode<int>(preorder[i]);
    i++;
    
    node -> left = solve(i, node -> data, preorder);
    node -> right = solve(i, mxLimit, preorder);
    
    return node;
    
}
TreeNode<int>* preOrderTree(vector<int> &preorder){
    // Write your code here.
    
    int n = preorder.size();
    int i = 0;
    int mxLimit = INT_MAX;
    
    return solve(i, mxLimit, preorder);
}