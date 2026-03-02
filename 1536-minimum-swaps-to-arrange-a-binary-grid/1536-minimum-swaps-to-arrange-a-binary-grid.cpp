class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> lastOne(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) lastOne[i] = j;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            for(; j < n; j++){
                if(lastOne[j] <= i) break;
            }
            if(j == n) return -1;
            while(j > i){
                swap(lastOne[j-1], lastOne[j]);
                j--;
                ans++;
            }
        }
        return ans;
    }
};