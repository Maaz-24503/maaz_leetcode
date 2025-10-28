class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        vector<int> count;
        for(int i = 0; i<n; i++){
            bool done = false;
            for(int j = 0; j<m; j++) {
                if(bank[i][j] == '1'){
                    if(!done){
                        done = true;
                        count.push_back(0);
                    }
                    count[count.size() - 1]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < int(count.size()) - 1; i++) ans += count[i] * count[i + 1];
        return ans;
    }
};