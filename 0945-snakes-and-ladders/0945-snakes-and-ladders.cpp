class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        function<pair<int, int>(int)> conv = [&](int ind){
            int y = n - ((ind - 1) / n) - 1;
            int x = (ind - 1) % n;
            if((ind - 1) / n % 2) x = n - x - 1;
            pair<int, int> ans = {y, x};
            return ans;
        };
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;
        while(!q.empty()){
            auto [i, moves] = q.front(); q.pop();
            if(i == n * n) return moves;
            for(int k = 1; k <= 6; k++){
                int next = i + k;
                if(next > n * n) continue;
                auto [y, x] = conv(next);
                if(board[y][x] != -1) next = board[y][x];
                if(!visited[next]){
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
