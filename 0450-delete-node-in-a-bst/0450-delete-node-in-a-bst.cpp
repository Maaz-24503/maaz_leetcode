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
    tuple<TreeNode*, TreeNode*, bool> finder(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        bool isLeft = false;

        while (current) {
            if (current->val == key) {
                return {parent, current, isLeft};
            } else if (key < current->val) {
                parent = current;
                current = current->left;
                isLeft = true;
            } else {
                parent = current;
                current = current->right;
                isLeft = false;
            }
        }
        return {nullptr, nullptr, false};  
    }

    TreeNode* deleteHelper(TreeNode* par, TreeNode* tbd, bool isLeft){
        if (!tbd->left && !tbd->right) {
            if (par) {
                if (isLeft) par->left = nullptr;
                else par->right = nullptr;
            }
            return (par == nullptr) ? nullptr : par;
        }
        if (tbd->right) {
            TreeNode* succParent = tbd;
            TreeNode* succ = tbd->right;
            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }
            tbd->val = succ->val;
            if (succParent->left == succ) {
                succParent->left = succ->right;
            } else {
                succParent->right = succ->right;
            }
            return tbd;
        }
        TreeNode* predParent = tbd;
        TreeNode* pred = tbd->left;
        while (pred->right) {
            predParent = pred;
            pred = pred->right;
        }
        tbd->val = pred->val;
        if (predParent->right == pred) {
            predParent->right = pred->left;
        } else {
            predParent->left = pred->left;
        }
        return tbd;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto [par, tbd, isLeft] = finder(root, key);
        if(!tbd) return root;
        TreeNode* temp = deleteHelper(par, tbd, isLeft);
        if(tbd == root) return temp;
        else return root;
    }
};