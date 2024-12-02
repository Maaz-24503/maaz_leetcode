class Solution {
public:
    string s;
    bool isValid(long long mask){
        unordered_set<string> seen;
        int prev = 0;
        int bits = 0;
        for(int i = 1; i<=mask; i = i<<1){
            bits++;
            if((mask & i) != 0){
                string curr = s.substr(prev, bits-prev);
                // cout<<curr<<" ";
                if(seen.find(curr) != seen.end()) return false;
                seen.insert(curr);
                prev = bits;
            }
        }
        string curr = s.substr(bits);
        // cout<<endl;
        // cout<<mask<<" "<<curr<<" "<<(seen.find(curr) == seen.end())<<endl;
        return seen.find(curr) == seen.end();
    }
    int maxUniqueSplit(string s) {
        this->s = s;
        int maxi = 0;
        long long lim = 1<<(s.size()-1);
        for(long long i = 0; i<lim; i++){
            int count = 1;
            for(long long j = 1; j<=i; j = j<<1) if((j & i) != 0) count++;
            if(isValid(i)) maxi = max(maxi, count);
        }
        return maxi;
    }
};