class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> adjList(n);
        for(int i = 0; i < n; i++){
            int k = i - 1;
            while(k >= 0 && i - k <= d && arr[k] < arr[i]) {
                adjList[i].push_back(k);
                k--;
            }
            k = i + 1;
            while(k < n && k - i <= d && arr[k] < arr[i]) {
                adjList[i].push_back(k);
                k++;
            }
        }
        vector<int> memo(n, -1);
        function<int(int)> dp = [&](int u) -> int {
            if(memo[u] != -1) return memo[u];
            int ans = 0;
            for(int &v : adjList[u]) ans = max(ans, dp(v));
            return memo[u] = 1 + ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, dp(i));
        return ans;
    }
};