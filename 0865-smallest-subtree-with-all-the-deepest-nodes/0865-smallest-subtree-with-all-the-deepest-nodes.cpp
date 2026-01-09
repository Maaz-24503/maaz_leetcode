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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*, int> depth;
        function<int(TreeNode*)> dfs = [&](TreeNode* curr) -> int {
            if(curr == nullptr) return 0;
            return depth[curr] = 1 + max(dfs(curr->left), dfs(curr->right));
        };
        dfs(root);
        depth[nullptr] = 0;
        function<TreeNode*(TreeNode*)> helper = [&](TreeNode* curr) -> TreeNode* {
            TreeNode *l = curr->left, *r = curr->right;
            if(depth[l] < depth[r]) return helper(r);
            else if(depth[l] > depth[r]) return helper(l);
            else return curr;
        };
        return helper(root);
    }
};