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
private:
    ListNode* rev(ListNode* head) {
        ListNode *curr = head, *currNext = head->next;
        curr->next = nullptr;
        while(currNext != nullptr) {
            ListNode* temp = currNext;
            currNext = temp->next;
            temp->next = curr;
            curr = temp;
        }
        return curr;
    }

public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = head;
        while(fast != nullptr){
            prev = slow;
            slow = slow->next;
            fast = (fast->next)->next;
        }
        prev->next = nullptr;
        ListNode* h1 = head, *h2 = rev(slow);
        int ans = 0;
        while(h1 != nullptr){
            ans = max(ans, h1->val + h2->val);
            h1 = h1->next; h2 = h2->next;
        }
        return ans;
    }
};