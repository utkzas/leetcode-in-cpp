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

/*
only requirement is that this value must be different from the root value, k.

If the root value of a subtree == k, 
         keep searching its children.
else, 
return the root value because it is the minimum of current subtree.
         */

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL) return -1;
        int ans=getmin(root,root->val);
        return ans;
    }
    int getmin(TreeNode *curr, int first){
        if(curr==NULL) return -1;
        //if its something new, return it
        if(curr->val!=first) return curr->val;
        
        // get the min from left and right
        int left=getmin(curr->left,first);
        int right=getmin(curr->right,first);
        //edge case: if all nodes of a subtree = root->val, 
        // there is no second minimum value, return -1
        if (left == -1) return right;
        if (right == -1) return left;
        
        // return the min of all
        return min(left,right);
    }
};