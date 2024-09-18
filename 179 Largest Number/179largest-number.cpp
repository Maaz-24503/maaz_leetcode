class Solution {
public:
    static bool customComp(int a, int b){
        string a1 = to_string(a);
        string b1 = to_string(b);
        return ((a1+b1) > (b1+a1));
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), customComp);
        string ans = "";
        if(nums.size() == 0) return "";
        if(nums[0] == 0) return "0";
        for(int i = 0; i<nums.size(); i++) ans += to_string(nums[i]);
        return ans;
    }
};