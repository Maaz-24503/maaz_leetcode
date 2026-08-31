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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;
        int prev = head->val;
        ListNode* curr = head->next;
        for (int i = 0; curr->next != nullptr; i++) {
            int rn = curr->val, nxt = curr->next->val;
            if (rn < prev && rn < nxt || rn > prev && rn > nxt)
                points.push_back(i);
            prev = rn;
            curr = curr->next;
        }
        if (points.size() < 2)
            return vector<int>{-1, -1};
        int smallest = INT_MAX;
        for (int i = 0; i < points.size() - 1; i++)
            smallest = min(smallest, points[i + 1] - points[i]);
        return vector<int>{smallest, points.back() - points[0]};
    }
};