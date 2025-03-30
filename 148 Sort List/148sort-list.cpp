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
    ListNode* merge(ListNode *left, ListNode *right, int n1, int n2){
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        ListNode *head, *curr;
        int lCount = 0, rCount = 0;
        if(left->val < right->val){
            head = left;
            left = left->next;
            lCount++;
        }
        else{
            head = right;
            right = right->next;
            rCount++;
        }
        curr = head;
        while(lCount < n1 && rCount < n2){
            if(left->val < right->val){
                curr->next = left;
                left = left->next;
                curr = curr->next;
                lCount++;
            }
            else{
                curr->next = right;
                right = right->next;
                curr = curr->next;
                rCount++;
            }
        }
        if(lCount == n1) curr->next = right;
        else curr->next = left;
        curr = head;
        for(int i = 1; i<n1 + n2; i++) curr = curr->next;
        curr->next = nullptr;
        return head;
    }

    ListNode* mergeSort(ListNode* head, int n){
        if(n == 1) return head;
        if(n == 0) return nullptr;
        int mid = n/2;
        ListNode *r = head;
        for(int i = 0; i<mid; i++) r = r->next;
        ListNode *left = mergeSort(head, mid);
        ListNode *right = mergeSort(r, n - mid);
        return merge(left, right, mid, n - mid);
    }
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode *curr = head;
        while(curr != nullptr) {
            curr = curr->next;
            n++;
        }
        return mergeSort(head, n);
    }
};