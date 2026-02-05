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
    pair<int, bool> solve(TreeNode* root){  //{height, bool}
        if(!root) return {0, true};
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        
        int leftH = left.first;
        int rightH = right.first;
        
        int height = 1 + max(leftH, rightH);
        
        bool currBal = abs(leftH - rightH) <= 1;
        
        bool dec = currBal && left.second && right.second;
        
        return {height, dec};
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        return solve(root).second;
        
    }
};