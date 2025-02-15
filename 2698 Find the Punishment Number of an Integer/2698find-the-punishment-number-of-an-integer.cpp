class Solution {
public:
    unordered_map<string, bool> memo;
    string num;

    bool isValid(int i, int sum){
        string key = to_string(i) + " " + to_string(sum);
        if(i == num.size()) return sum == 0;
        if(sum<0) return false;
        if(memo.find(key) != memo.end()) return memo[key];
        bool ans = false;
        for(int k = 1; k<=num.size()-i; k++){
            int number = stoi(num.substr(i, k));
            ans |= isValid(i + k, sum - number);
            if(ans) break;
        }
        return memo[key] = ans;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++){
            int sqr = i*i;
            this->num = to_string(sqr);
            this->memo.clear();
            if(isValid(0, i)) ans += sqr;
        }
        return ans;
    }
};