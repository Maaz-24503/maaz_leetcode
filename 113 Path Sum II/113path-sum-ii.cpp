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
    vector<vector<int>> helper(TreeNode* root, int targetSum){
        if(root == nullptr) return {};
        if(root->right == nullptr && root->left == nullptr) {
            if(root->val == targetSum) return {{root->val}};
            else return {};
        }
        vector<vector<int>> rPath = helper(root->right, targetSum - root->val);
        vector<vector<int>> lPath = helper(root->left, targetSum - root->val);
        vector<vector<int>> ans;
        for(int i = 0; i<rPath.size(); i++){
            rPath[i].push_back(root->val);
            ans.push_back(rPath[i]);
        }
        for(int i = 0; i<lPath.size(); i++){
            lPath[i].push_back(root->val);
            ans.push_back(lPath[i]);
        }
        return ans;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans = helper(root, targetSum);
        for(int i = 0; i<ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};