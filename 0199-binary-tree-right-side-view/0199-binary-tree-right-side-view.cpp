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
        if(!root) return vector<int>{};
        queue<pair<int, TreeNode*>> bfs;
        bfs.push({0, root});
        int lev = -1;
        vector<int> ans;
        while(!bfs.empty()){
            auto [currLev, nd] = bfs.front();
            bfs.pop();
            if(currLev > lev){
                lev = currLev;
                ans.push_back(nd->val);
            }
            if(nd->right) bfs.push({currLev+1, nd->right});
            if(nd->left) bfs.push({currLev+1, nd->left});
        }
        return ans;
    }
};