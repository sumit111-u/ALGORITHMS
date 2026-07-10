/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 TreeNode* wahh(vector<int>& preorder, int&i,int mini, int maxi) {
    if( i>=preorder.size()) return NULL;
    if( preorder[i]<mini || preorder[i]> maxi) return NULL;
TreeNode* root= new TreeNode(preorder[i++]);
root->left=wahh(preorder,i,mini,root->val);
root->right=wahh(preorder,i,root->val,maxi);
return root;
    
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return wahh(preorder,i,INT_MIN,INT_MAX);
    }
};