class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head->next == nullptr) return head;
        ListNode* dummy = new ListNode(INT_MIN, head);
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nx = head->next;
        while(curr != nullptr){
            nx = curr->next;
            if(curr->val < prev->val){
                cout<<curr->val<<endl;
                prev->next = curr->next; 
                ListNode* pr2 = dummy;
                for(ListNode* temp = dummy->next; temp != curr->next; temp = temp->next){ 
                    if(temp->val >= curr->val) {
                        pr2->next = curr;
                        curr->next = temp;
                        break;
                    }
                    pr2 = temp;
                }
            }
            else prev = curr; 

            curr = nx; 
        }
        return dummy->next;
    }
};
