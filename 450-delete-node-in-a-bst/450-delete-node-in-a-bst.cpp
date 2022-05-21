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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(root->right){
                TreeNode* left = root->left;
                root = root->right;
                TreeNode* temp = root;
                while(temp->left) temp = temp->left;
                temp->left = left;
            } 
            else root = root->left;
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

/*
IDK WHY BUT STRIVER MADE IT TOO COMPLEX

When we delete a node, three possibilities arise:

1.Node to be deleted is a leaf node: Simply remove it from the tree.
2.Node to be deleted has only one child: Copy that child to the node and delete the child.
3.Node to be deleted has two children: Find the inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor.

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) 
            return NULL;
        
        if(root->val==key) 
            return helper(root);
        
        TreeNode *dummy=root;
        while(root!=NULL){
            if(root->val > key){ // target exists on the left
                 if(root->left!=NULL && root->left->val==key){ // found?
                     root->left= helper(root->left); //delete & rearrange
                     break;
                 } else { // not found? keep iterating
                     root=root->left;
                 }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode *root){
        if(root->left==NULL){ 
            return root->right; // connect it's right directly
        }
        else if(root->right==NULL){
            return root->left; // connect it's left directly
        }
        else { // left and right both exist
            TreeNode * rightChild =root->right;
            TreeNode * lastRight = findLastRight(root->left);
            lastRight->right=rightChild; //connect from the pt it was cut
            return root->left; // return our new left
        }
    }
    TreeNode* findLastRight(TreeNode *root){
        if(root->right==NULL)
            return root;      
        return findLastRight(root->right);
    }
    
};

/* tried
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*root1=root;
        if(root==NULL) return NULL;
        
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right= deleteNode(root->right,key);
        }
        else {
            if(root->left==NULL && root->right==NULL) {
                return NULL;
            }
            else if(root->right && root->left==NULL) {
                return root->right;
            } 
            else if(root->left && root->right==NULL) {
                return root->right;
            }
            else {
         root->val= root->left->val < root->right->val ? root->left->val : root->right->val;
                delete(root->left); delete(root->right);
                //root->left=NULL; root->right=NULL;
            }
        }
        return root1;
    }
};
*/