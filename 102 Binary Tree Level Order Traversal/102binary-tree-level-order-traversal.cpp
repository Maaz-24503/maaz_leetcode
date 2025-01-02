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
    vector<vector<int>> ans;

    int depth(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(depth(root->right), depth(root->left));
    }

    void helper(int i, TreeNode* root){
        if(root == nullptr) return;
        ans[i].push_back(root->val);
        helper(i+1, root->left);
        helper(i+1, root->right);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = depth(root);
        ans.resize(n);
        helper(0, root);
        return ans;
    }
};