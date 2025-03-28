class Solution {
private:
    vector<vector<bool>> isVisited;
    vector<vector<int>> d{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int n, m, k;

    int enc(int i, int j){
        return i*m + j;
    }

    pair<int, int> dec(int ind){
        return{ind / m, ind % m};
    }

    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m && !isVisited[i][j];
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n= grid.size(), m = grid[0].size(), k = queries.size();
        int score = 0;
        isVisited.resize(n, vector<bool> (m, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dk;
        vector<pair<int, int>> q(k);
        for(int i = 0; i<k; i++) q[i] = {queries[i], i};
        sort(q.begin(), q.end());
        dk.push({grid[0][0], 0});
        isVisited[0][0] = true;
        vector<int> ans(k);
        for(int i = 0; i<k; i++){
            while(!dk.empty() && dk.top().first < q[i].first){
                auto [val, ind] = dk.top();
                dk.pop();
                // cout<<ind<<endl;
                score++;
                auto [ii, jj] = dec(ind);
                for(int a = 0; a<4; a++){
                    int mv = enc(ii + d[a][0], jj + d[a][1]);
                    if(isValid(ii + d[a][0], jj + d[a][1])){
                        isVisited[ii + d[a][0]][jj + d[a][1]] = true;
                        dk.push({grid[ii + d[a][0]][jj + d[a][1]], mv});
                    }
                }
            }
            ans[q[i].second] = score;
        }
        return ans;
    }
};