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
    int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftH=depth(root->left);
        int rightH=depth(root->right);
        
        if(abs(leftH-rightH)>1) return false;
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        return left && right;
    }
};