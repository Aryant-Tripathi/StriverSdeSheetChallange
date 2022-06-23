/*   
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
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
*/

//We can simply assure that we have our answer stored in the vector by checking if the last element in the storing vector is the Node
// Backtrack in all other situations

vector<int> ans;
void solve(TreeNode<int>* root, int target)
{
    if(root == NULL) return;
    
    ans.push_back(root -> data);
    if(root -> data == target)
    {
        return;
    }
    
    solve(root -> left, target);
    solve(root -> right, target);
    
    if(ans[ans.size() - 1] != target)
        ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int target)
{
    // Write your code here.
    ans.clear();
    solve(root, target);
    return ans;
}

