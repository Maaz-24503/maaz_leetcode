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
        vector<int> sums;
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        int level = -1;
        while(!bfs.empty()){
            auto [nd, lev] = bfs.front();
            bfs.pop();
            if(lev > level){
                sums.push_back(0);
                level = lev;
            }
            sums[lev] += nd->val;
            if(nd->right) bfs.push({nd->right, lev+1});
            if(nd->left) bfs.push({nd->left, lev+1});
        }
        int maxi = *max_element(sums.begin(), sums.end());
        for(int i = 0; i<sums.size(); i++) if(sums[i] == maxi) return i+1;
        return -1;
    }
};