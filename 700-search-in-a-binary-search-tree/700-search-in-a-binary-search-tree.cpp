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
// In a BST, 
// Condition 1. LeftNode<RootNode<RightNode
// Condition 2. each subtree should also be a BST
// Generally, ht of BST is log(n)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){ // till it's not the end
            if(val < root->val){
                root=root->left; // search on left, val will be in left
            } else {
                root=root->right; // search on right as val is in right
            }
        }
        return root;//return null if not found, else its found return curr
    }
};