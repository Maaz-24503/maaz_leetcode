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
    int sumRootToLeaf(TreeNode* root) {
        function<int(TreeNode*, int)> helper = [&](TreeNode *curr, int value) -> int {
            if(curr == nullptr) return 0;
            
            if(curr->right == nullptr && curr->left == nullptr) return (value<<1) + curr->val;
            return helper(curr->left, (value<<1) + curr->val) + helper(curr->right, (value<<1) + curr->val);
        };
        return helper(root, 0);
    }
};