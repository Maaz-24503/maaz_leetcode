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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr1 = head;
        ListNode* curr2 = head;
        int count = 0;
        while(curr1 != nullptr) {
            curr1 = curr1->next;
            if(count > n) curr2 = curr2->next;
            count++;
        }
        if(count == n) return head->next;
        curr2->next = curr2->next->next;
        return head;
    }
};