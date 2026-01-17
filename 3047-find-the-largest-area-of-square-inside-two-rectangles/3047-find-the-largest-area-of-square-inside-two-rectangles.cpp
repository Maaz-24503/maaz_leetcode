class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        function<int(int, int)> intersection = [&](int i, int j) -> int {
            int minX = max(bottomLeft[i][0], bottomLeft[j][0]);
            int maxX = min(topRight[i][0], topRight[j][0]);
            int minY = max(bottomLeft[i][1], bottomLeft[j][1]);
            int maxY = min(topRight[i][1], topRight[j][1]);

            if (minX < maxX && minY < maxY) 
                return min(maxX - minX, maxY - minY);
            return 0;
        };
        int ans = 0;
        for(int i = 0; i< n - 1; i++){
            for(int j = i + 1; j < n; j++){
                ans = max(ans, intersection(i, j));
            }
        }
        return (ans + 0LL) * ans;
    }
};