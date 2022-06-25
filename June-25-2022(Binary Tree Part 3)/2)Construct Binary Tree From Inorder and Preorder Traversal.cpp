/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

unordered_map<int, int> mp;
int idx;

TreeNode<int>* solve(int low, int high, vector<int> &preorder)
{
    if(low > high)
    {
        return NULL;
    }
    
    TreeNode<int>* node = new TreeNode<int>(preorder[idx]);
    
    int findIndex = mp[preorder[idx]];
    idx++;
    
    node -> left = solve(low, findIndex - 1, preorder);
    node -> right = solve(findIndex + 1, high, preorder);
    
    return node;
    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    int n = inorder.size();
    mp.clear();
    idx = 0;
    
    for(int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    
    return solve(0, n - 1, preorder);
}