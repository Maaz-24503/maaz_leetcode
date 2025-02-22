class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> sml;
        vector<int> big;
        for(int i = 1; i*i<=n; i++){
            if(n % i == 0){
                sml.push_back(i);
                if(i * i != n) big.push_back(n/i);
            }
        }
        for(int i = 0; i<big.size(); i++){
            sml.push_back(big[big.size() - i - 1]);
        }
        // for(int i = 0; i<sml.size(); i++) cout<<sml[i]<<" ";
        if(k>sml.size()) return -1;
        else return sml[k-1];
    }
};