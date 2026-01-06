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
    int maxLevelSum(TreeNode* root) {
        map<int, long long> sums;
        function<void(int, TreeNode*)> dfs = [&](int level, TreeNode* curr) -> void {
            if(curr == nullptr) return;
            sums[level] += curr->val;
            dfs(level + 1, curr->right);
            dfs(level + 1, curr->left);
        };
        dfs(1, root);
        long long maxi = INT_MIN;
        int ans = -1;
        for(auto [level, sum] : sums){
            if(maxi < sum){
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};