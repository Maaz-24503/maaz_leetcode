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

    vector<int> count;

    int path(TreeNode* root){
        if(root->right == nullptr && root->left == nullptr){
            bool done = false;
            for(int i = 1; i<10; i++){
                if(count[i] % 2 == 1){
                    if(!done) done = true;
                    else return 0;
                }
            }
            return 1;
        }
        int ans = 0;
        if(root->right != nullptr){
            count[root->right->val]++;
            ans += path(root->right);
            count[root->right->val]--;
        }
        if(root->left != nullptr){
            count[root->left->val]++;
            ans += path(root->left);
            count[root->left->val]--;
        }
        return ans;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        count.resize(10, 0);
        count[root->val]++;
        return path(root);
    }
};