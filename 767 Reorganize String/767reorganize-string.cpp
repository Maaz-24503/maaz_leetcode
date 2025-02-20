class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> helper;
        unordered_map<char, int> freq;
        for(int i = 0; i<s.size(); i++) freq[s[i]]++;
        for(auto &item: freq) helper.push({item.second, item.first});
        string ans = "";
        while(!helper.empty()){
            // cout<<ans<<endl;
            if(ans.size() == 0){
                auto [f, c] = helper.top();
                helper.pop();
                if(f > 1) helper.push({f-1, c});
                ans = ans+c;
            }
            else{
                auto [f, c] = helper.top();
                helper.pop();
                if(ans[ans.size()-1] == c){
                    if(helper.empty()) return "";
                    auto [nf, nc] = helper.top();
                    helper.pop();
                    if(nf>1) helper.push({nf-1, nc});
                    helper.push({f, c});
                    ans = ans + nc;
                }
                else {
                    ans = ans + c;
                    if(f>1) helper.push({f-1, c});
                }
            }
        }
        return ans;
    }
};