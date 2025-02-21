class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<vector<char>> pad{{},
                                 {},
                                 {'a', 'b', 'c'},
                                 {'d', 'e', 'f'},
                                 {'g', 'h', 'i'},
                                 {'j', 'k', 'l'},
                                 {'m', 'n', 'o'},
                                 {'p', 'q', 'r', 's'},
                                 {'t', 'u', 'v'},
                                 {'w', 'x', 'y', 'z'}};
        vector<string> ans;
        for (int i = 0; i < pad[digits[0] - '0'].size(); i++)
            ans.push_back(string(1, pad[digits[0] - '0'][i]));
        for (int i = 1; i < digits.size(); i++) {
            vector<string> temp;
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; k < pad[digits[i] - '0'].size(); k++) {
                    temp.push_back(ans[j] + pad[digits[i] - '0'][k]);
                }
            }
            ans = temp;
        }
        return ans;
    }
};