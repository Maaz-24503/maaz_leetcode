class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> ind;
        int n = arr.size();
        if(n<3) return 0;
        for(int i = 0; i<n; i++) ind[arr[i]] = i;
        int ans = 0;
        vector<vector<int>> memo(n, vector<int> (n, 2));
        for(int i = 2; i<n; i++){
            for(int j = 1; j<i; j++){
                int tar = arr[i] - arr[j];
                if(ind.find(tar) != ind.end() && ind[tar] < j){
                    memo[i][j] = memo[j][ind[tar]] + 1;
                    ans = max(ans, memo[i][j]);
                    // if(ans == 6) cout<<arr[i]<<" "<<arr[j];
                }
            }
        }
        return ans;
    }
};