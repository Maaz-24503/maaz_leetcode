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
    int averageOfSubtree(TreeNode* root) {
        function<vector<int>(TreeNode*)> helper = [&](TreeNode* curr) -> vector<int> {
            if(curr == nullptr) return vector<int> {0, 0, 0};
            vector<int> left = helper(curr->left), right = helper(curr->right);
            int sum = left[1] + right[1] + curr->val, count = left[2] + right[2] + 1, ans = left[0] + right[0];
            if(curr->val == sum / count) ans++;
            return vector<int> {ans, sum, count};
        };
        return helper(root)[0];
    }
};