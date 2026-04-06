class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir = 0;
        vector<vector<int>> move{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> block;
        for(int i = 0; i < obstacles.size(); i++) block.insert({obstacles[i][0], obstacles[i][1]});
        int ans = 0, x = 0, y = 0;
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -1) dir = (dir + 1) % 4;
            else if(commands[i] == -2) dir = (dir + 3) % 4;
            else {
                for(int j = 0; j < commands[i]; j++){
                    pair<int, int> np = {x + move[dir][0], y + move[dir][1]};
                    if(block.find(np) == block.end()){
                        x = np.first; y = np.second;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
    }
};