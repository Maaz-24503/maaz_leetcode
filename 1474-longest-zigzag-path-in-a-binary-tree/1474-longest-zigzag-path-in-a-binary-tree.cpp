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
private:
    vector<unordered_map<TreeNode*, int>> memo;

    int helper(TreeNode* root, bool isLeft){
        if(memo[isLeft].count(root)) return memo[isLeft][root];
        if((isLeft && root->left == nullptr) || (!isLeft && root->right == nullptr)) return memo[isLeft][root] = 0;
        return memo[isLeft][root] = 1 + helper(isLeft ? root->left : root->right, !isLeft);
    };

public:
    int longestZigZag(TreeNode* root) {
        memo.resize(2);
        int ans = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            if(root == nullptr) return;
            int temp = max(helper(root, true), helper(root, false));
            ans = max(temp, ans);
            dfs(root->right);
            dfs(root->left);
        };
        dfs(root);
        return ans;
    }
};