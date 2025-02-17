class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string recur = countAndSay(n-1);
        int count = 1;
        string ans = "";
        int k = recur.size();
        ans.reserve(2*k);
        for(int i = 0; i<k-1; i++){
            if(recur[i] == recur[i+1]) count++;
            else{
                ans = ans + to_string(count) + recur[i];
                count = 1;
            }
        }
        ans = ans + to_string(count) + recur[k-1];
        return ans;
    }
};