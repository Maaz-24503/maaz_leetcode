class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> ind(26);
        int n = s.size(), m = words.size();
        int res = 0;
        
        for(int i = 0; i<n; i++) ind[s[i] - 'a'].push_back(i);

        function<int(int, int)> bs = [&](int i, int c) -> int {
            if(!ind[c].size()) return -1;
            int l = 0, r = ind[c].size() - 1;
            int ans = -1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(ind[c][mid] <= i) l = mid + 1;
                else {
                    ans = mid;
                    r = mid - 1;
                }
            }
            return ans == -1 ? -1 : ind[c][ans];
        };

        for(string word: words){
            int last = -1;
            bool valid = true;
            for(char c : word){
                last = bs(last, c - 'a');
                if(word == "bb") cout<<last<<" ";
                if(last == -1){
                    valid = false;
                    break;
                }
            }
            if(valid) res++;
        }
        return res;
    }
};