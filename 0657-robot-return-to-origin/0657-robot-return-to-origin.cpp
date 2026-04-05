class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, vector<int>> mp;
        mp['U'] = {0, 1};
        mp['D'] = {0, -1};
        mp['R'] = {1, 0};
        mp['L'] = {-1, 0};
        int x = 0, y = 0;
        for(char &c : moves){
            x += mp[c][0];
            y += mp[c][1];
        }
        return x == 0 && y == 0;
    }
};