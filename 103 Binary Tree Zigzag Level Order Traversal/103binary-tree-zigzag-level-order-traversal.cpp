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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> l;
        stack<TreeNode*> r;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        l.push(root);
        bool left = true;
        while(!l.empty() || !r.empty()){
            vector<int> level;
            if(left)
                while(!l.empty()){
                    TreeNode* curr = l.top();
                    l.pop();
                    level.push_back(curr->val);
                    if(curr->left != nullptr) r.push(curr->left);
                    if(curr->right != nullptr) r.push(curr->right);
                    left = false;
                }
            else
                while(!r.empty()){
                    TreeNode* curr = r.top();
                    r.pop();
                    level.push_back(curr->val);
                    if(curr->right != nullptr) l.push(curr->right);
                    if(curr->left != nullptr) l.push(curr->left);
                    left = true;
                }
            ans.push_back(level);
        }
        return ans;
    }
};