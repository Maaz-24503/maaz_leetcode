class Solution {
private:
    vector<int> matchsticks;
    unordered_map<long long, int> memo;
    int target, n;
    bool isPossible(int i, int a, int b, int c, int d){
        if(i == n){ 
            return a == b && b == c && c == d;
        }
        if(a > target || b > target || c > target || d > target) return false;
        long long key = ((long long)i << 55) | (((long long)a) << 35) | (b << 15) | (c);
        if(memo.find(key) != memo.end()) return memo[key];
        return memo[key] = isPossible(i + 1, matchsticks[i] + a, b, c, d) || 
                           isPossible(i + 1, a, matchsticks[i] + b, c, d) || 
                           isPossible(i + 1, a, b, matchsticks[i] + c, d) || 
                           isPossible(i + 1, a, b, c, matchsticks[i] + d);
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        this->n = matchsticks.size();
        sort(matchsticks.begin(), matchsticks.end(), [](int& a, int& b){return a>b;});
        this->matchsticks = matchsticks;
        for(int i = 0; i < n; i++) sum += matchsticks[i];
        if(sum % 4 != 0) return false;
        target = sum/4;
        return isPossible(0, 0, 0, 0, 0);
    }
};