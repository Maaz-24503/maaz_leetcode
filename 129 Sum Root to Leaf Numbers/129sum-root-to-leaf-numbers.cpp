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
    vector<string> helper(TreeNode* root){
        int curr_num = root->val;
        if(root->right == nullptr && root->left == nullptr) return vector<string> {to_string(curr_num)};
        vector<string> tbr;
        if(root->right != nullptr){
            vector<string> right = helper(root->right);
            for(int i = 0; i<right.size(); i++){
                tbr.push_back(to_string(curr_num) + right[i]);
            }
        }
        if(root->left != nullptr){
            vector<string> left = helper(root->left);
            for(int i = 0; i<left.size(); i++){
                tbr.push_back(to_string(curr_num) + left[i]);
            }
        }
        return tbr;
    }
    int sumNumbers(TreeNode* root) {
        vector<string> comb = helper(root);
        long long total = 0;
        for(int i = 0; i<comb.size(); i++){
            total += stoi(comb[i]);
        }
        return total;
    }
};