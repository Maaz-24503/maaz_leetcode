class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i = 0; i<n; i++) freq[s[i] - 'a']++;
        int rem = 0;
        for(int i = 0 ; i<26; i++){
            if(freq[i] > 2){
                if(freq[i] % 2 == 1)
                    rem += (freq[i] - 1);
                else
                    rem += (freq[i] - 2);
            }
        }
        return n - rem;
    }
};