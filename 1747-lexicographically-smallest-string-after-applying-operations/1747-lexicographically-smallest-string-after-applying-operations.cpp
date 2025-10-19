class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        set<string> visited;
        function<string(string)> opA = [&](string original) -> string {
            for(int i = 1; i < n; i += 2){
                int curr = original[i] - '0';
                curr = (curr + a) % 10;
                original[i] = curr + '0';
            }
            return original;
        };
        function<string(string)> opB = [&](string original) -> string {
            string ans = string(n, '0');
            for(int i = 0; i<n; i++){
                ans[(i + b) % n] = original[i];
            }
            return ans;
        };
        function<void(string)> dfs = [&](string curr){
            if(visited.find(curr) != visited.end()) return;
            visited.insert(curr);
            dfs(opA(curr));
            dfs(opB(curr));
        };
        dfs(s);
        return *visited.begin();
    }
};