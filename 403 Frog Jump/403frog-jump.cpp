class Solution {
public:
    bool helper(int i, int k, vector<int>& stones, unordered_map<string, bool>& memo, unordered_map<int, int>& pos){
        if(i == stones.size() - 1) return true;
        string key = to_string(i)+" "+to_string(k);
        if(memo.find(key) != memo.end()) return memo[key];
        memo[key] = false;
        if(k != 1 && pos.find(stones[i]+k-1) != pos.end()){
            memo[key] = memo[key] || helper(pos[stones[i]+k-1], k-1, stones, memo, pos);
        }
        if(k != 0 && pos.find(stones[i]+k) != pos.end()){
            memo[key] = memo[key] || helper(pos[stones[i]+k], k, stones, memo, pos);
        }
        if(pos.find(stones[i]+k+1) != pos.end()){
            memo[key] = memo[key] || helper(pos[stones[i]+k+1], k+1, stones, memo, pos);
        }
        return memo[key];
    }
    bool canCross(vector<int>& stones) {
        if(stones.size() == 1) return true;
        unordered_map<string, bool> memo;
        unordered_map<int, int> pos;
        for(int i = 0; i<stones.size(); i++)
            pos[stones[i]] = i;
        return helper(0, 0, stones, memo, pos);
    }
};