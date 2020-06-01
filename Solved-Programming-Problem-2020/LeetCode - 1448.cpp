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
    int cntGood = 0;
    
    void dfs(TreeNode* root, int Max = -1e5) {
        if(root->val >= Max)
            cntGood++;
        if(root->left == 0 && root->right == 0) {
            return;
        }
        if(root->left != 0) {
            dfs(root->left, max(Max, root->val));
        }
        if(root->right != 0){
            dfs(root->right, max(Max, root->val));
        }
    }
    int goodNodes(TreeNode* root) {
        dfs(root);
        
        return cntGood;
    }
};