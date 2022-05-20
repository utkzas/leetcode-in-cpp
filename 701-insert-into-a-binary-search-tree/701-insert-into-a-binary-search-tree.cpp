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

// TC: O(log(N))

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val); // base case
        TreeNode *curr=root;
        
        while(true){
            if(curr->val <= val){ // root is lesser than, search in right
                if(curr->right!=NULL) // there is something on right?
                    curr=curr->right; // keep on searching
                else { // otherwise insert the val
                    curr->right= new TreeNode(val);
                    break;
                }
            } 
            else { // else root is greater than val, search in left
              if(curr->left!=NULL) curr=curr->left;
              else {
                  curr->left = new TreeNode(val);
                  break;
              }
            }
        }
        
        return root;
    }
};

/* Recursive
TreeNode* insertIntoBST(TreeNode* root, int key)  {
   if(root==NULL)
   return new TreeNode(Key);
   
   if(root->data==Key)
   return root;
   
   if(Key<root->data)
   root->left=insert(root->left,Key);
   
   else
   root->right=insert(root->right,Key);
   
   return root;
}
*/