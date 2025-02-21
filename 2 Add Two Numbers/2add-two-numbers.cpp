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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        carry = (p1->val + p2->val)/10;
        ListNode* head = new ListNode((p1->val + p2->val) % 10);
        p1 = p1->next;
        p2 = p2->next;
        ListNode* ans = head;
        while(p1 != nullptr || p2 != nullptr){
            if(p1 == nullptr){
                ans->next = new ListNode((p2->val + carry)%10);
                carry = (p2->val + carry)/10;
                ans = ans->next;
                p2 = p2->next;
            }
            else if(p2 == nullptr){
                ans->next = new ListNode((p1->val + carry)%10);
                carry = (p1->val + carry)/10;
                ans = ans->next;
                p1 = p1->next;
            }
            else{
                int sum = p1->val + p2->val + carry;
                ans->next = new ListNode(sum%10);
                ans = ans->next;
                carry = sum/10;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        if(carry != 0){
            ans->next = new ListNode(carry);
            ans = ans->next;
        }
        ans->next = nullptr;
        return head;
    }
};