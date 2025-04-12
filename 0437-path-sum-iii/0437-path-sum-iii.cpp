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
        int ans = 0;
        unordered_map<long long, int> sums{{0,1}};
        long long sum = 0;
        function<void(TreeNode*)> helper = [&](TreeNode* root){
            if(root == nullptr) return;
            sum += root->val;
            if(sums.count(sum - targetSum)) ans += sums[sum - targetSum];
            sums[sum]++;
            helper(root->left);
            helper(root->right);
            sums[sum]--;
            sum -= root->val;
        };
        helper(root);
        return ans;
    }
};