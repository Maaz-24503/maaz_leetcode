class Solution {
public:
    bool helper(int total, bool turn, vector<int>& turns, vector<unordered_map<string, bool>>& memo, long long mask){
        if(total <= 0) return !turn;
        if(mask == 0) return false;
        string key = to_string(mask)+" "+to_string(turn);
        if(memo[total].find(key) != memo[total].end()) return memo[total][key];
        bool ans = !turn;
        for(int i = 0; i<turns.size(); i++){
            long long req = 1<<i;
            req = req & mask;
            if(req != 0){
                req = ~req;
                long long nxt = mask & req;
                int move = turns[i];
                if(turn) ans = ans || helper(total - move, false, turns, memo, nxt);
                else ans = ans && helper(total - move, true, turns, memo, nxt);
            }
        }
        return memo[total][key] = ans;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal == 0) return true;
        vector<int> moves;
        for(int i = 0; i<maxChoosableInteger; i++){
            moves.push_back(i+1);
        }
        vector<unordered_map<string, bool>> memo(desiredTotal+1);
        long long mask = ((long long) pow(2, moves.size())) - 1;
        return helper(desiredTotal, true, moves, memo, mask);
    }
};