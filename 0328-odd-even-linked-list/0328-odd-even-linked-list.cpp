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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode *odd1 = head, *even1 = head->next, *evenHead = head->next;
        ListNode *odd2 = even1->next, *even2 = even1->next->next;
        // cout<<"gotHere1"<<endl;
        while(odd2 != nullptr && even2 != nullptr){
            odd1->next = odd2;
            even1->next = even2;
            odd1 = odd2;
            even1 = even2;
            odd2 = even2->next;
            if(odd2 == nullptr){
                even2 = nullptr;
                even1->next = nullptr;
                break;
            }
            else even2 = odd2->next;
        }
        // cout<<"gotHere2"<<endl;
        if(odd2 != nullptr){ 
            // cout<<"gotHere1"<<endl;
            odd1->next = odd2;
            // cout<<evenHead->val<<endl;
            odd2->next = evenHead;
            even1->next = nullptr;
            return head;
        }
        odd1->next = evenHead;
        return head;
    }
};