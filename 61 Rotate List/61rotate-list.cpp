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

        if(head==nullptr) return nullptr;
        int length = 0;
        
        for(ListNode *curr = head; curr!=nullptr; curr = curr->next){
            length++;
        }

        k = length-(k%length);
        if(k == 0) return head;

        int i = 0;
        ListNode* mid = head;
        ListNode* end;

        for(ListNode *curr = head; curr!=nullptr; curr = curr->next){
            i++;
            if(i == k){
                mid = curr;
            }
            if(curr->next == nullptr) end = curr;
        }
        end->next = head;
        head = mid->next;
        mid->next = nullptr;
        return head;
    }
};