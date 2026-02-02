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
    map<int, int> mpp;
    int idx=0;
    
    TreeNode* solve( int s, int e, vector<int> &pre){
        if(s > e) return NULL;
        
        int value = pre[idx++];
        TreeNode* root = new TreeNode(value);
        
        int mid = mpp[root->val];
        
        root->left = solve(s, mid-1, pre);
        root->right = solve(mid+1, e, pre);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        
        return solve(0, inorder.size()-1, preorder);
        
    }
};