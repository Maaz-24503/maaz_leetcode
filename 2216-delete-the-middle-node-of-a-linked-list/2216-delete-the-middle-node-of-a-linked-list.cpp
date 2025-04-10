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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast,* slow = head;
        if(head->next == nullptr) return nullptr;
        if(head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }
        fast = head->next->next->next;
        while(fast != nullptr){
            slow = slow->next;
            if(fast->next == nullptr) break;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};