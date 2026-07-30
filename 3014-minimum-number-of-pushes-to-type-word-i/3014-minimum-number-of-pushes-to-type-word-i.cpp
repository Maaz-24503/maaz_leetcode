class Solution {
public:
    int minimumPushes(string word) {
        int left = word.size();
        int moves = 1, ans = 0;
        while(left > 0){
            int curr = min(left, 8);
            left -= curr;
            ans += moves * curr;
            moves++;
        }
        return ans;
    }
};