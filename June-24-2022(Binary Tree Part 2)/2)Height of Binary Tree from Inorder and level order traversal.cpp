#include<bits/stdc++.h>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int N){
    // Write your code here.
    queue<vector<int>> q;
   unordered_map<int,int> umap;
   for(int i=0;i<inorder.size();i++)
   {
       umap[inorder[i]]=i;
   }
   int k=0;
   if(umap.find(levelorder[0])!=umap.end())
   {
       if(umap[levelorder[0]]==inorder.size()-1)
           q.push({0,umap[levelorder[0]]-1,1});
       else if(umap[levelorder[0]]==0)
           q.push({1,(int)(inorder.size()-1),1});
       else {
           q.push({0,umap[levelorder[0]]-1,1});
           q.push({umap[levelorder[0]]+1,(int)(inorder.size()-1),1});
       }
   }
   k++;
   int ans=0;
   while(!q.empty())
   {
       vector<int> temp=q.front();
       q.pop();
       ans=max(ans,temp[2]);
       if(umap.find(levelorder[k])!=umap.end())
       {
           if(temp[1]==temp[0])
           {
              ans=max(ans,temp[2]+1);
             
           }
          else if(umap[levelorder[k]]==temp[1])
               q.push({temp[0],umap[levelorder[k]]-1,temp[2]+1});
           else if(umap[levelorder[k]]==temp[0])
               q.push({umap[levelorder[k]]+1,(int)(temp[1]),temp[2]+1});
           else {
               q.push({temp[0],umap[levelorder[k]]-1,temp[2]+1});
     q.push({umap[levelorder[k]]+1,(int)(temp[1]),temp[2]+1});
           }
       }
       k++;
   }
   return ans-1;
}

/* TLE APPROACH
// int getIndex(vector<int>& inorder, int low, int high, 
//             int curr_root)
// {
//     for(int i = low; i <= high; i++)
//     {
//         if(curr_root == inorder[i])
//             return i;
//     }
    
//     return -1;
// }
// int getHeight(int low, int high, vector<int>& inorder, 
//               vector<int>& levelorder, int& h, int n)
// {
//     if(low > high)
//         return 0;
    
//     int curr_root_index = getIndex(inorder, 
//                                    low, high, levelorder[0]);
    
//     if(curr_root_index == -1)
//         return 0;
    
//     int leftCount = curr_root_index - low;
//     int rightCount = high - curr_root_index;
    
//     vector<int> newLeftArray(leftCount);
//     vector<int> newRightArray(rightCount);
    
//     int lHeight = 0, rHeight = 0;
//     int k = 0;
    
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = low; j < curr_root_index; j++)
//         {
//             if(levelorder[i] == inorder[j])
//             {
//                 newLeftArray[k] = levelorder[i];
//                 k++;
//                 break;
//             }
//         }
//     }
    
//     k = 0;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = curr_root_index + 1; j <= high; j++)
//         {
//             if(levelorder[i] == inorder[k])
//             {
//                 newRightArray[k] = levelorder[i];
//                 k++;
//                 break;
//             }
//         }
//     }
    
//     if(leftCount > 0)
//     {
//         lHeight = getHeight(low, curr_root_index - 1, inorder,
//                             newLeftArray, h, leftCount);
//     }
    
//     if(rightCount > 0)
//     {
//         rHeight = getHeight(curr_root_index + 1, high, inorder,
//                             newRightArray, h, rightCount);
//     }
    
//     newLeftArray.clear();
//     newRightArray.clear();
    
//     h = max(lHeight + 1, rHeight + 1);
    
    
//     return h;
    
// }
int search(vector<int>& arr, int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

// Function to calculate the height
// of the Binary Tree
int getHeight(vector<int>& in, vector<int>& level, int start,
            int end, int& height, int n)
{

    // Base Case
    if (start > end)
        return 0;

    // Get index of current root in InOrder Traversal
    int getIndex = search(in, start, end, level[0]);

    if (getIndex == -1)
        return 0;

    // Count elements in Left Subtree
    int leftCount = getIndex - start;

    // Count elements in right Subtree
    int rightCount = end - getIndex;

    // Declare two arrays for left and
    // right subtrees
    vector<int> newLeftLevel(leftCount);
    vector<int> newRightLevel(rightCount);

    int lheight = 0, rheight = 0;
    int k = 0;

    // Extract values from level order traversal array
    // for current left subtree
    for (int i = 0; i < n; i++) {
        for (int j = start; j < getIndex; j++) {
            if (level[i] == in[j]) {
                newLeftLevel[k] = level[i];
                k++;
                break;
            }
        }
    }

    k = 0;

    // Extract values from level order traversal array
    // for current right subtree
    for (int i = 0; i < n; i++) {
        for (int j = getIndex + 1; j <= end; j++) {
            if (level[i] == in[j]) {
                newRightLevel[k] = level[i];
                k++;
                break;
            }
        }
    }

    // Recursively call to calculate height of left Subtree
    if (leftCount > 0)
        lheight = getHeight(in, newLeftLevel, start,
                            getIndex - 1, height, leftCount);

    // Recursively call to calculate height of right Subtree
    if (rightCount > 0)
        rheight = getHeight(in, newRightLevel,
                            getIndex + 1, end, height, rightCount);

    // Current height
    height = max(lheight + 1, rheight + 1);

    // Delete Auxiliary arrays
//     delete[] newRightLevel;
//     delete[] newLeftLevel;

    // return height
    return height;
}
int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int n){
    // Write your code here.
    int h = 0;
    //if(inorder == levelorder) return n - 1;
    
   return getHeight(inorder, levelorder, 0, n - 1, h, n) - 1;
} */