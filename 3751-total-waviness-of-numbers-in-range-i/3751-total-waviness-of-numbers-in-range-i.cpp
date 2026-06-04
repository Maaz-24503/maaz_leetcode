class Solution {
public:
    int totalWaviness(int num1, int num2) {
        function<int(int)> helper =  [](int k) -> int {
            vector<int> dig;
            int mask = 1;
            while(mask <= k){
                dig.push_back((k % (mask*10)) / mask);
                mask *= 10;
            }
            int ans = 0;
            for(int i  = 1; i < dig.size() - 1; i++){
                if(dig[i] < dig[i - 1] && dig[i] < dig[i + 1]) ans++;
                else if(dig[i] > dig[i - 1] && dig[i] > dig[i + 1]) ans++;
            }
            return ans;
        };

        int ans = 0;
        for(int i = num1; i <= num2; i++) ans += helper(i);
        return ans;
    }
};