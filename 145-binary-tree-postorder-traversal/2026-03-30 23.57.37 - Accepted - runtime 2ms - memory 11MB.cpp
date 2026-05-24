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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL) return {};
        postorder(root,res);
        return res;
    }
    private:
    void postorder(TreeNode* curr,vector<int>&res){
        if(curr==NULL) return;
        postorder(curr->left,res);
        postorder(curr->right,res);
        res.push_back(curr->val);
    }
};