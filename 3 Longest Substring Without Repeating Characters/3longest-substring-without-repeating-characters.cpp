class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<int> track;
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            if(track.find(s[i]) != track.end()){
                while(s[l]!=s[i]){
                    track.erase(s[l]);
                    l++;
                }
                track.erase(s[l]);
                l++;
            }
            ans = max(i - l + 1, ans);
            track.insert(s[i]);
        }
        return ans;
    }
};