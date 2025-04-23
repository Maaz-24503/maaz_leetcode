class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> freq(100, 0);
        function<int(int)> compute = [&](int num){
            int mask = 10;
            int ans = 0;
            while(mask <= num*10){
                ans += (num%mask) / (mask/10);
                mask *= 10;
            }
            return ans;
        };
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            int currSum = compute(i);
            freq[currSum]++;
            maxi = max(maxi, freq[currSum]);
        }
        int ans = 0;
        
        for(int i = 0; i < 100; i++) 
            if(maxi == freq[i])
                ans++;
        return ans;
    }
};