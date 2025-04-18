class Solution {
private:
    string rle(string org){
        int len = 1, n = org.size();
        string ans = "";
        for(int i = 1; i<n; i++){
            if(org[i] == org[i-1]) len++;
            else{
                ans += to_string(len);
                ans += org[i-1];
                len = 1;
            }
        }
        ans += to_string(len);
        ans += org[n-1];
        return ans;
    }

public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n - 1);
        return rle(prev);
    }
};