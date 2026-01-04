class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> div(n);
        function<vector<int> (int)> getDiv = [&](int i) -> vector<int> {
            int num = nums[i];
            vector<int> tbr;
            for(int i = 1; i*i <= num; i++){
                if(num % i == 0) {
                    tbr.push_back(i);
                    if(i*i != num) tbr.push_back(num / i);
                }
            }
            return tbr;
        };
        for(int i = 0; i<n; i++) div[i] = getDiv(i);
        int ans = 0; 
        for(int i = 0; i<n; i++){
            if(div[i].size() == 4){
                for(int j = 0; j < 4; j++){
                    ans += div[i][j];
                }
            }
        }
        return ans;
    }
};