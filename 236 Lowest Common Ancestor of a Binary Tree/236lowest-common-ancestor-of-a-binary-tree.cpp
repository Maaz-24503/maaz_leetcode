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
        setPar(root);
        unordered_set<TreeNode*> qPar;
        qPar.insert(q);
        TreeNode* iter = q;
        while(par.find(iter) != par.end()){
            qPar.insert(par[iter]);
            iter = par[iter];
        }
        iter = p;
        while(par.find(iter) != par.end()){
            if(qPar.find(iter) != qPar.end()) return iter;
            iter = par[iter];
        }
        return iter;
    }

private:
    unordered_map<TreeNode*, TreeNode*> par;

    void setPar(TreeNode* root){
        if(root->right != nullptr){
            par[root->right] = root;
            setPar(root->right);
        }
        if(root->left != nullptr){
            par[root->left] = root;
            setPar(root->left);
        }
    }
};