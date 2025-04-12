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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q) return p;
        unordered_map<TreeNode*, TreeNode*> par;
        par[root] = root;
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            if(root->right != nullptr){
                par[root->right] = root;
                dfs(root->right);
            }
            if(root->left != nullptr){
                par[root->left] = root;
                dfs(root->left);
            }
        };
        dfs(root);
        unordered_set<TreeNode*> seenP, seenQ;
        while(true){
            seenP.insert(p);
            seenQ.insert(q);
            if(seenP.count(q)) return q;
            if(seenQ.count(p)) return p;
            p = par[p];
            q = par[q];
        }
        return root;
    }
};