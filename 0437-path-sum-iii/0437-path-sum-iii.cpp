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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> preSum;
        preSum[0] = 1;
        function<int(TreeNode*,long long)> dfs = [&](TreeNode* root, long long currSum){
            if(root == nullptr) return 0;
            currSum += root->val;
            int ans = 0;
            if(preSum.count(currSum - targetSum)) ans = preSum[currSum - targetSum];
            preSum[currSum]++;
            int left = dfs(root->left, currSum), right = dfs(root->right, currSum);
            preSum[currSum]--;
            return left + right + ans;
        };
        return dfs(root, 0);
    }
};