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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> rem(nums.begin(), nums.end());
        ListNode* beg = head;
        ListNode* prev = head;
        for(ListNode* curr = head; curr != nullptr; curr = curr->next){
            if(rem.find(curr->val) != rem.end()){
                if(curr == beg){
                    beg = curr->next;
                } else{
                    prev->next = curr->next;
                }
            }
            else prev = curr;
        }
        return beg;
    }
};