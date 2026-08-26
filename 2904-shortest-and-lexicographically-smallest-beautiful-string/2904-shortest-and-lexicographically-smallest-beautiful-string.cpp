class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<string> subs;
        function<bool(string)> check = [&k](string curr) -> bool {
            int count  = 0; 
            for(int i = 0; i < curr.size(); i++) if(curr[i] == '1') count++;
            return count == k;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= n - i; j++){
                string curr = s.substr(i, j);
                if(check(curr)) subs.push_back(curr);
            }
        }
        sort(subs.begin(), subs.end(), [](const auto a, const auto b){
            if(a.size() != b.size()) return a.size() < b.size();
            return a < b;
        });
        return subs.size() ? subs[0] : "";
    }
};