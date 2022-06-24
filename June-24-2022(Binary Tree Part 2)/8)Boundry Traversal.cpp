/************************************************************

    Following is the Binary Tree node structure:
    
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

bool IsLeaf(TreeNode<int>* node)
{
    if(node -> left == NULL && node -> right == NULL)
        return true;
    
    return false;
}
void addLeft(TreeNode<int>* root, vector<int>& ans)
{
    TreeNode<int>* curr = root -> left;
    while(curr)
    {
        if(IsLeaf(curr) == false)
        {
            ans.push_back(curr -> data);
        }
        
        if(curr -> left) curr = curr -> left;
        else curr = curr -> right;
    }
}

void addRight(TreeNode<int>* root, vector<int>& ans)
{
    TreeNode<int>* curr = root -> right;
    vector<int> temp;
    while(curr)
    {
        if(IsLeaf(curr) == false)
        {
            temp.push_back(curr -> data);
        }
        
        if(curr -> right) curr = curr -> right;
        else curr = curr -> left;
    }
    
    for(int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
}

void addLeaves(TreeNode<int>* root, vector<int>& ans)
{
    if(IsLeaf(root))
    {
        ans.push_back(root -> data);
        return;
    }
    
    if(root -> left) addLeaves(root -> left, ans);
    if(root -> right) addLeaves(root -> right, ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    if(root == NULL) return {};
    
    vector<int> ans;
    if(!IsLeaf(root))
    ans.push_back(root -> data);
    
    addLeft(root, ans);
    addLeaves(root, ans);
    addRight(root, ans);
    
    return ans;
}