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
Brute Force: Do any dfs traversal, store all the nodes in a vector, and then sort it. now get the kth element
TC: O(N)+O(NlogN) // to traverse + sort the vector
SC: O(N) // to store entire BST into the vector

Optimised: 
inorder of a bst gives elements in sorted order, then we can use a counter till k.

TC:
Iterative and recursive traversal will give TC: O(N) SC: O(N)
But Morris Treversal will give TC:(N) SC: O(1)
*/
/*
            Recursive
Time complexcity O(H+K) H is height of bst
Space complexcity O(1)
            Iterative
Time complexcity O(H+K) H is height of bst
Space complexcity O(H+K)
    */
class Solution {
public: // Recursive Solution
    int kthSmallestRec(TreeNode* root, int &k) { // added a & here. but why?
        if(root==NULL) return -1;
        
        int left=kthSmallest(root->left,k); // left call
        if(left!=-1) return left; // left has the ans? return it!
        k--;
        if(k==0) return root->val; // this is the ans! the kth smallest! 
        
        int right=kthSmallest(root->right,k); // right call
        if(right!=-1) return right; // right has the answ? return it!
        
        return -1; // no answer from this call ;( return -1
    }
    
 public: //Iterative Solution
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode *> stk;
        while(1)
        {
            while(root!=NULL)
            {
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            k--;
            if(k==0) return root->val;
            root=root->right;
        }
    }
};

