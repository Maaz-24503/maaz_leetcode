class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> poss{""};
        int n = s.size();

        auto isValid = [](const string& t) -> bool {
            int open = 0;
            for (const char& c : t) {
                if (c == ')') {
                    if (open < 1) return false;
                    open--;
                } else if (c == '(') open++;
            }
            return open == 0;
        };

        for (int i = 0; i < n; i++) {
            unordered_set<string> next;
            if (s[i] != '(' && s[i] != ')') {
                for (const string& t : poss) next.insert(t + s[i]);
            } else {
                for (const string& t : poss) {
                    next.insert(t);
                    next.insert(t + s[i]);
                }
            }
            poss = move(next);
        }

        int maxSize = 0;
        for (const string& t : poss) {
            if (isValid(t)) maxSize = max(maxSize, (int)t.size());
        }

        vector<string> ans;
        for (const string& t : poss) {
            if (t.size() == maxSize && isValid(t)) ans.push_back(t);
        }
        return ans;
    }
};