class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        function<bool(int)> check = [&](int guess) -> bool {
            unordered_map<int, int> window;
            int odd = 0, even = 0;
            for(int i = 0; i < guess; i++){
                window[nums[i]]++;
                if(nums[i] % 2 && window[nums[i]] == 1) odd++;
                else if(window[nums[i]] == 1) even++;
            }
            if(odd == even) return true;
            for(int i = guess; i < n; i++){
                window[nums[i - guess]]--;
                if(window[nums[i - guess]] == 0){ 
                    if(nums[i - guess] % 2) odd--;
                    else even--;
                }
                window[nums[i]]++;
                if(window[nums[i]] == 1){
                    if(nums[i] % 2) odd++;
                    else even++;
                }
                if(even == odd) return true;
            }
            return false;
        };

        // Wont work dumbass, there might be i, j such that i < j and
        // check(i) == false but check(j) == true, so were not monotonous :(

        // int l = 0, r = n, ans = 0;
        // while(l <= r){
        //     int mid = (l + r) / 2;
        //     if(check(mid)){
        //         ans = mid;
        //         l = mid + 1;
        //     } else r = mid - 1;
        // }

        for(int i = n; i > 0; i--)
            if(check(i)) return i;
        return 0;
    }
};