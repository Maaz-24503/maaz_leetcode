class Solution {
private:
    vector<int> f;
    int n, k;
    
    void factorial(){
        f.resize(11, 1);
        for(int i = 1; i<=10; i++) f[i] = f[i-1]*i;
    }

    vector<string> genNums(int p){
        if(p == 0) return vector<string>{""};
        vector<string> prev = genNums(p - 1);
        vector<string> curr;
        for(int i = 0; i<prev.size(); i++){
            for(int j = (p == (n+1)/2 ? 1 : 0); j < 10; j++){
                curr.push_back(to_string(j) + prev[i]);
            }
        }
        return curr;
    }

    set<map<int, int>> fixNums(const vector<string>& nums){
        set<map<int, int>> tbr;
        for(int i = 0; i<nums.size(); i++){
            string curr = nums[i];
            string full;
            full.reserve(n);
            full = curr + string(curr.rbegin() + (n % 2), curr.rend());
            if(stoll(full)%k == 0){
                map<int, int> temp;
                for(int i = 0; i<full.size(); i++) temp[full[i] - '0']++;
                tbr.insert(temp);
            }
        }
        return tbr;
    }

public:
    long long countGoodIntegers(int n, int k) {
        this->n = n; 
        this->k = k;
        factorial();
        set<map<int, int>> nums = fixNums(genNums((n+1)/2));
        long long ans = 0;
        for(auto& mp:nums){
            vector<int> rep;
            long long curr = 0;
            for(auto [val, freq] : mp){
                if(freq > 1) rep.push_back(freq);
            }
            long long div = 1;
            for(auto& num : rep) div = div * f[num];
            curr = f[n]/div;
            if(mp.count(0)){
                div /= mp.at(0);
                long long zeros = f[n-1]/div;
                ans += curr - zeros;
            }
            else ans += curr;
        }
        return ans;
    }
};