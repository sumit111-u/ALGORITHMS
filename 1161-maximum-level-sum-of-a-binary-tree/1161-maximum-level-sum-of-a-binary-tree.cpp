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
    int maxLevelSum(TreeNode* root) {
     
    int ansLevel = 1;
    int currLevel = 1;   
    if(root==NULL) return ansLevel;
    
    int maxi = root->val;
    
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        
        int sum = 0;
        
      for( int i=0; i<size;i++){
        auto top=q.front();
        q.pop();
        sum+=top->val;
     
        if(top->left){
            q.push(top->left);
        }
        if(top->right){
            q.push(top->right);
        }
      }
      if(sum > maxi){
        maxi = sum;
        ansLevel = currLevel;
      }
        currLevel++;
    }
    return ansLevel;
        
    }
};