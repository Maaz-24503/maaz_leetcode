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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mapping;
        unordered_set<int> possibleRoot;
        
        for(int i = 0; i < descriptions.size(); i++){
            if(mapping.find(descriptions[i][0]) == mapping.end()){
                mapping[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
                possibleRoot.insert(descriptions[i][0]);
            }
            if(mapping.find(descriptions[i][1]) == mapping.end()){
                mapping[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            }
        }
        
        for(int i = 0; i < descriptions.size(); i++){
            possibleRoot.erase(descriptions[i][1]);
            if(descriptions[i][2] == 1) mapping[descriptions[i][0]]->left = mapping[descriptions[i][1]];
            else mapping[descriptions[i][0]]->right = mapping[descriptions[i][1]];
        }
        return mapping[*(possibleRoot.begin())];
        
    }
};