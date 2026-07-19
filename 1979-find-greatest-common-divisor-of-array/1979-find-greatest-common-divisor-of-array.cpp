class Solution {
public:
    int findGCD(vector<int>& nums) {
        function<int(int, int)> gcd = [&](int a, int b) -> int {
            if(a % b == 0) return b;
            return gcd(b, a % b);
        };
        return gcd(*max_element(nums.begin(), nums.end()), *min_element(nums.begin(), nums.end()));
    }
};