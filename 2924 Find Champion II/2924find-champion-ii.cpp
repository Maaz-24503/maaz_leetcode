class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> check(n, false);
        for(int i = 0; i<edges.size(); i++){
            check[edges[i][1]] = true;
        }
        int ans = -1;
        for(int i = 0; i<n; i++){
            if(!check[i]){
                if(ans == -1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};