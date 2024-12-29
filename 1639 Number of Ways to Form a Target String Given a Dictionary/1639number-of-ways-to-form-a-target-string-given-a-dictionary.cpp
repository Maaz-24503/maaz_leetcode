class Solution {
public:
    string target;
    vector<string> words;
    vector<vector<int>> memo;
    vector<vector<long long>> preComp;
    int lim;
    int mod = 1000000007;

    int mulMod(long long a, long long b){ 
        long long res = 0; 
        a %= mod; 
        while (b) { 
            if (b & 1) 
                res = (res + a) % mod; 
            a = (2 * a) % mod; 
            b >>= 1; 
        } 
        return res % mod; 
    } 

    int helper(int i, int j){
        if(j == target.size()) return 1;
        if(i == lim) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        long long ans = 0;
        ans = (mulMod(preComp[i][target[j] - 'a'], helper(i+1, j+1)) + ((ans + helper(i+1, j))%mod)) %mod;
        return memo[i][j] = ans;
    }

    void compute(){
        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j<words[i].size(); j++) preComp[j][words[i][j] - 'a']++;
        }
    }

    int numWays(vector<string>& words, string target) {
        this->words = words;
        this->target = target;
        this->lim = words[0].size();
        preComp.resize(lim, vector<long long> (26, 0));
        memo.resize(lim+1, vector<int> (target.size()+1, -1));
        compute();
        return helper(0, 0);
    }
};