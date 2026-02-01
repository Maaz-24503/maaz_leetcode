class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st{num[0]};
        int n = num.size();
        for(int i = 1; i < n; i++){
            while(!st.empty() && st[st.size() - 1] > num[i] && k){
                k--;
                st.pop_back();
            }
            st.push_back(num[i]);
        }
        while(k){
            st.pop_back(); k--;
        }
        string ans(st.begin(), st.end());
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        string tbr = ans.substr(i);
        return tbr == "" ? "0" : tbr;
    }
};