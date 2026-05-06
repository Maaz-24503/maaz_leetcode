class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans[i][m - j - 1] = boxGrid[j][i];
        for(int j = 0; j < m; j++){
            int feathers = 0;
            for(int i = 0; i < n; i++){
                if(ans[i][j] == '#'){
                    feathers++;
                    ans[i][j] = '.';
                }
                if(ans[i][j] == '*'){
                    int curr = i - 1;
                    while(feathers){
                        feathers--;
                        ans[curr][j] = '#';
                        curr--;
                    }
                }
            }
            int curr = n - 1;
            while(feathers){
                feathers--;
                ans[curr][j] = '#';
                curr--;
            }
        }
        return ans;
    }
};