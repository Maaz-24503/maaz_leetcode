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
private:
    vector<TreeNode*> gen(int i, int j){
        if(i > j) return vector<TreeNode*> {nullptr};
        if(i == j) return vector<TreeNode*> {new TreeNode(i)};
        vector<TreeNode*> ans;
        for(int k = i; k<=j; k++){
            vector<TreeNode*> recLeft = gen(i, k - 1);
            vector<TreeNode*> recRight = gen(k + 1, j);
            for(int ii = 0; ii<recLeft.size(); ii++){
                for(int jj = 0; jj<recRight.size(); jj++){
                    TreeNode* tree = new TreeNode(k);
                    tree->right = recRight[jj];
                    tree->left = recLeft[ii];
                    ans.push_back(tree);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return gen(1, n);
    }
};