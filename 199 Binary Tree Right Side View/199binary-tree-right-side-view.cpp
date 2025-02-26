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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return vector<int>{};
        queue<pair<TreeNode*, int>> bfs;
        vector<int> ans;
        bfs.push({root, 0});
        int layer = -1;
        while(!bfs.empty()){
            auto [nd, lyr] = bfs.front();
            bfs.pop();
            if(layer < lyr){
                ans.push_back(nd->val);
                layer = lyr;
            }
            if(nd->right != nullptr) bfs.push({nd->right, layer+1});
            if(nd->left != nullptr) bfs.push({nd->left, layer+1});
        }
        return ans;
    }
};