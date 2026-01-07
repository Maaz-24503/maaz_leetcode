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
    int maxProduct(TreeNode* root) {
        map<TreeNode*, long long> postSum;
        function<long long (TreeNode*)> sum = [&](TreeNode *curr) -> long long {
            if(curr == nullptr) return 0LL;
            long long currSum = curr->val + sum(curr->left) + sum(curr->right);
            return postSum[curr] = currSum;
        };
        long long total = sum(root), maxi = 0;
        for(auto [curr, val] : postSum){
            maxi = max(maxi, val * (total - val));
        }
        return maxi % ( (int) 1e9 + 7);
    }
};