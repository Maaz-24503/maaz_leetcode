class Solution {
public:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    int findTheWinner(int n, int k) {
        if(k == 1) return n;
        if(n == 1) return 1;
        Node* head = new Node(1);
        Node* curr = head;
        for(int i = 2; i<=n; i++){
            curr->next = new Node(i);
            curr = curr->next;
        }
        curr->next = head;
        Node* temp = head;
        while(temp->next != temp){
            Node* prev = temp;
            for(int i = 0; i<k-1; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            temp = prev->next;
        }
        return temp->data;
    }
};