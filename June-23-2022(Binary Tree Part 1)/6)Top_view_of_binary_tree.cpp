/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root == NULL) return {};
    
    map<int, int> mp; // line, node -> data
    // we should use map, because it reaarange in sorted order
    
    queue<pair<TreeNode<int>*, int>> q; // node, line
    
    q.push({root, 0});
    mp[0] = root -> val;
    
    while(!q.empty())
    {
        TreeNode<int>* curr_node = q.front().first;
        int curr_line = q.front().second;
        q.pop();
        
        if(mp.find(curr_line) == mp.end())
        {
            mp[curr_line] = curr_node -> val;
        }
        
        if(curr_node -> left)
        {
            q.push({curr_node -> left, curr_line - 1});
        }
        
        if(curr_node -> right)
        {
            q.push({curr_node -> right, curr_line + 1});
        }
    }
    
    vector<int> ans;
    for(auto x: mp)
    {
        ans.push_back(x.second);
    }
    
    return ans;
}