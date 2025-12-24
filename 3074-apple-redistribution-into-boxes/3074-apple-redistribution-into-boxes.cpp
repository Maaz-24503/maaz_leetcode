class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size();
        int total = 0;
        for (int i = 0; i < n; i++)
            total += apple[i];
        sort(capacity.begin(), capacity.end(),
             [](const int a, const int b) { return a > b; });
        for(int i = 0; i < m; i++){
            total -= capacity[i];
            if(total <= 0) return i + 1;
        }
        return m;
    }
};