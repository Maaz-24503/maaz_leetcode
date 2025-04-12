class Solution {
private:
    vector<int> f;
    int n, k;
    
    void factorial(){
        f.resize(11, 1);
        for(int i = 1; i<=10; i++) f[i] = f[i-1]*i;
    }

    vector<string> genNums(int p) {
        vector<string> curr{""};
        for (int i = 1; i <= p; i++) {
            vector<string> next;
            for (const string& s : curr) {
                for (int d = (i == p ? 1 : 0); d < 10; d++) {
                    next.push_back(to_string(d) + s);
                }
            }
            curr = move(next);
        }
        return curr;
    }


    set<vector<int>> fixNums(const vector<string>& nums){
        set<vector<int>> tbr;
        for(int i = 0; i<nums.size(); i++){
            string curr = nums[i];
            string full;
            full.reserve(n);
            full = curr + string(curr.rbegin() + (n % 2), curr.rend());
            if(stoll(full)%k == 0){
                vector<int> temp(10,0);
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
        set<vector<int>> nums = fixNums(genNums((n+1)/2));
        long long ans = 0;
        for(auto& rep:nums){
            long long curr = 0;
            long long div = 1;
            for(int i = 0; i<rep.size(); i++){
                if(rep[i] > 1) div *= f[rep[i]];
            }
            curr = f[n]/div;
            if(rep[0]){
                div /= rep[0];
                long long zeros = f[n-1]/div;
                ans += curr - zeros;
            }
            else ans += curr;
        }
        return ans;
    }
};