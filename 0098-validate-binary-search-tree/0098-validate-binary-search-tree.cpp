/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long mini = LLONG_MIN;
    long long maxi = LLONG_MAX;

    bool solve(TreeNode* root, long long l, long long r) {

        if (!root)
            return true;
        if (root->val <= l || root->val >= r) {
            return false;
        }
        return solve(root->left, l, root->val) &&
               solve(root->right, root->val, r);
    }

    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right)
            return true;

        return solve(root, mini, maxi);
    }
};