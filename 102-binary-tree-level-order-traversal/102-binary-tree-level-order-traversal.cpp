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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answ;
        if(root==NULL) return answ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level; // to store the contents of the level
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left); // put the childs simultaneously
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val); // push the element into the level
            }
            answ.push_back(level);
        }
        return answ;
    }
};
// TC:O(N) SC:O(N)