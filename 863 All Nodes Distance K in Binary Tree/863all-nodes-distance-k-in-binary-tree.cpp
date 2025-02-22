/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> par;
    TreeNode* root;

    vector<int> up(TreeNode* curr, int level){
        if(level == 0) return vector<int> {curr->val};
        if(par[curr] == root){
            if(level == 1) return vector<int> {root->val};
            if(root->right == curr) return down(root->left, level - 2);
            else return down(root->right, level - 2);
        }
        vector<int> u = up(par[curr], level - 1);
        vector<int> d = par[curr]->right == curr ? down(par[curr]->left, level - 2) : down(par[curr]->right, level - 2);
        for(int i = 0; i<d.size(); i++) u.push_back(d[i]);
        return u;
    }

    vector<int> down(TreeNode* nd, int level){
        if(nd == nullptr || level < 0) return vector<int> {};
        if(level == 0) return vector<int> {nd->val};
        vector<int> l = down(nd->left, level - 1);
        vector<int> r = down(nd->right, level - 1);
        for(int i = 0; i<r.size(); i++) l.push_back(r[i]);
        return l;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        this->root = root;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            TreeNode* curr = bfs.front();
            bfs.pop();
            if(curr->right != nullptr){
                par[curr->right] = curr;
                bfs.push(curr->right);
            }
            if(curr->left != nullptr){
                par[curr->left] = curr;
                bfs.push(curr->left);
            }
        }
        if(target == root){
            vector<int> l = down(root->left, k-1);
            vector<int> r = down(root->right, k-1);
            for(int i = 0; i<r.size(); i++) l.push_back(r[i]);
            return l;
        }
        vector<int> d = down(target, k);
        vector<int> u = up(target, k);
        for(int i = 0; i<u.size(); i++) d.push_back(u[i]);
        return d;
    }
};