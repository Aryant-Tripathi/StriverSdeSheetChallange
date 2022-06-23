/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int>* root){

    // Write your code here.
    if(root == NULL) return {};
    
    map<int, int> mp; // line, node value
    queue<pair<BinaryTreeNode<int>*, int>> q; // node, line
    
    int line = 0;
    q.push({root, line});
    mp[line] = root -> data;
    
    while(!q.empty())
    {
        BinaryTreeNode<int>* curr_node = q.front().first;
        int curr_line = q.front().second;
        q.pop();
        
        mp[curr_line] = curr_node -> data;
        
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

