class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for(char &c : s) freq[c - 'a']++;
        int odd = 0, even = INT_MAX;
        for(int &f : freq){
            if(f % 2) odd = max(odd, f);
            else if(f > 0) even = min(even, f); 
        }
        return odd - even;
    }
};