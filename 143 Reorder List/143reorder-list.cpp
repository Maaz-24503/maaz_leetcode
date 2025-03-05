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
    void reorderList(ListNode* head) {
        unordered_map<ListNode*, ListNode*> prev;
        int sz = 0;
        ListNode* tail = head;
        for(ListNode* iter = head; iter->next != nullptr; iter = iter->next){
            sz++;
            prev[iter->next] = iter;
            tail = iter->next;
        }
        sz++;
        ListNode* top = head;
        ListNode* bot = tail;
        for(int i = 0; i<(sz+1)/2; i++){
            if(top == bot){
                top->next = nullptr;
                break;
            }
            else if(sz%2 == 0 && i+1 == (sz+1)/2){
                top->next = bot;
                bot->next = nullptr;
                break;
            }
            else {
                ListNode* tempL = top->next;
                top->next = bot;
                bot->next = tempL;
                top = tempL;
                bot = prev[bot];
            }
        }
    }
};