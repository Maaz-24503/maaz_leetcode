class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int beg = 0, n = colors.size();
        for(int i = 1; i < n+k-1; i++){
            int curr = i % n, prev = (i-1)%n;
            if(colors[curr] == colors[prev]) beg = i;
            if(k <= i - beg + 1) ans++;
        }
        return ans;
    }
};