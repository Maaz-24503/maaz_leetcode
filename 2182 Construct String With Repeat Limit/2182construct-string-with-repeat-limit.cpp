class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> helper(26, 0);
        for(int i = 0; i<s.size(); i++) helper[s[i] - 'a']++;
        int currChar = 25;
        string ans;
        while(currChar>=0){
            int count = min(repeatLimit, helper[currChar]);
            for(int i = 0; i<count; i++) ans.push_back('a' + currChar);
            helper[currChar] -= count;
            if(helper[currChar]){
                int nxt = currChar-1;
                if(nxt<0) break;
                bool invalid = false;
                while(!helper[nxt]){
                    nxt--;
                    if(nxt == -1) {
                        invalid = true;
                        break;
                    }
                }
                if(invalid) break;
                helper[nxt]--;
                ans.push_back('a' + nxt);
            }
            else currChar--;
        }
        return ans;
    }
};