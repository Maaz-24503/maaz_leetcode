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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        int n = 0;
        ListNode* foot = nullptr;
        for(ListNode* temp = head; temp != nullptr; temp = temp->next) {
            n++;
            foot = temp;
        }
        foot->next = head;
        k %= n;
        ListNode* curr = head;
        for(int i = 0; i < n - k - 1; i++) curr = curr->next;
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        return newHead;
    }
};