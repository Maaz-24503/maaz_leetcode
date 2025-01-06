class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int leftMoves = 0, leftBoxes = 0;
        int rightMoves = 0, rightBoxes = 0;
        for(int i = 0; i<n; i++){
            ans[i] += leftMoves;
            leftBoxes += boxes[i] - '0';
            leftMoves += leftBoxes;
            ans[n - i - 1] += rightMoves;
            rightBoxes += boxes[n - i - 1] - '0';
            rightMoves += rightBoxes;
        }
        return ans;
    }
};