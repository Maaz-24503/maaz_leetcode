class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> dk;
        vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        int n = moveTime.size(), m = moveTime[0].size();
        auto enc = [&](int i, int j){
            return i*m + j;
        };
        function<pair<int, int>(int)> dec = [&](int coord){
            pair<int, int> tbr = {coord / m, coord % m};
            return tbr;
        };
        function<bool(int,int)> isValid = [&](int i, int j){
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        dk.push({0, 0, 0});
        vector<int> dist(n*m, INT_MAX);
        dist[0] = 0;
        while(!dk.empty()){
            vector<int> temp = dk.top();
            int t = temp[0];
            int coord = temp[1];
            int isAlt = temp[2];
            dk.pop();
            if(dist[coord] < t) continue;
            for(int i = 0; i<4; i++){
                auto [x, y] = dec(coord);
                int nx = x + dx[i], ny = y + dy[i];
                if(isValid(nx, ny)){
                    int nCoord = enc(nx, ny);
                    if(max(t, moveTime[nx][ny]) + (isAlt ? 2 : 1) < dist[nCoord]){
                        dist[nCoord] = max(t, moveTime[nx][ny]) + (isAlt ? 2 : 1);
                        dk.push({max(t, moveTime[nx][ny]) + (isAlt ? 2 : 1), nCoord, !isAlt});
                    }
                }
            }
        }
        return dist[n*m - 1];
    }
};