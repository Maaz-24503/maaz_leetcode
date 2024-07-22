/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
 *     TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> memo;

    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        if (memo.find(root) != memo.end()) return memo[root];

        int val = 0;
        if (root->left) {
            val += helper(root->left->left) + helper(root->left->right);
        }
        if (root->right) {
            val += helper(root->right->left) + helper(root->right->right);
        }

        int result = max(root->val + val, helper(root->left) + helper(root->right));
        memo[root] = result;
        return result;
    }

    int rob(TreeNode* root) {
        return helper(root);
    }
};
