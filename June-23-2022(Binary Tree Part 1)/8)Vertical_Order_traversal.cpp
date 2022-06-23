/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    
    if(root == NULL) return {};
    // vertical level, horizontal level, nodes ki value 
        map<int, map<int, vector<int>>> storeAns; 
        
        //           {node, {vertical, horizontal}
        queue<pair<TreeNode<int>*, pair<int, int>>> q; 
        
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            TreeNode<int>* node = q.front().first;
            int vertical = q.front().second.first;
            int horizontal = q.front().second.second;
            
            q.pop();
            
            storeAns[vertical][horizontal].push_back(node -> data);
            
            if(node -> left)
            {
            q.push({node -> left, {vertical - 1, horizontal + 1}});
            }
            
            if(node -> right)
            {     
           q.push({node -> right, {vertical + 1, horizontal + 1}});
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto it: storeAns)
        {
            vector<int> col;
            for(auto x: it.second)
            {
                for(auto t: x.second)
                {
                    col.push_back(t);
                }
            }
            ans.push_back(col);
        }
        
        vector<int> finalAns;
     for(auto it : ans)
     {
       for(auto p : it)
       {
           finalAns.push_back(p);
       }
     }
    return finalAns;
}