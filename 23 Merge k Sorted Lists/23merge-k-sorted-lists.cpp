/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* head1, ListNode* head2){
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;
        ListNode* left = head1;
        ListNode* right = head2;
        ListNode* tbr;
        if(left->val < right->val){
            tbr = left;
            left = left->next;
        }
        else{
            tbr = right;
            right = right->next;
        }
        ListNode* curr = tbr;
        while(left != nullptr || right != nullptr){
            if(left == nullptr){
                curr->next = right;
                curr = curr->next;
                right = right->next;
            }
            else if(right == nullptr){
                curr->next = left;
                left = left->next;
                curr = curr->next;
            }
            else if(left->val < right->val){
                curr->next = left;
                left = left->next;
                curr = curr->next;
            }
            else{
                curr->next = right;
                curr = curr->next;
                right = right->next;
            }
        }
        curr->next = nullptr;
        return tbr;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> temp = lists;
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];
        int sz = temp.size();
        int l = 0;
        int r = temp.size() - 1;
        while(l<r){
            while(l<r){
                temp[l] = merge(temp[l], temp[r]);
                l++;
                r--;
            }
            sz = (sz+1)/2;
            l = 0;
            r = sz-1;
        }
        return temp[0];
    }
};