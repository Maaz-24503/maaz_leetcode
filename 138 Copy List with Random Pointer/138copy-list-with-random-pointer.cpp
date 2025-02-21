/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        if(head == NULL) return NULL;
        Node* h2 = new Node(head->val);
        Node* temp1 = h2;
        Node* org = head;
        mapping[head] = temp1;
        while(org->next != NULL){
            org = org->next;
            temp1->next = new Node(org->val);
            temp1 = temp1->next;
            mapping[org] = temp1;
        }
        temp1->next = NULL;
        temp1 = h2;
        org = head;
        while(org != NULL){
            Node* ptr = org->random;
            if(ptr == NULL) temp1->random = NULL;
            else temp1->random = mapping[ptr];
            org = org->next;
            temp1 = temp1->next;
        }
        return h2;
    }
};