class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> targetF(26, 0);

        targetF['b' - 'a'] = 1;
        targetF['a' - 'a'] = 1;
        targetF['l' - 'a'] = 2;
        targetF['o' - 'a'] = 2;
        targetF['n' - 'a'] = 1;

        vector<int> f(26, 0);
        for(char &c : text)
            f[c - 'a']++;

        int ans = f[0];
        for(int i = 0; i < 26; i++){
            if(targetF[i]){
                ans = min(ans, f[i] / targetF[i]);
            }
        }
        return ans;
    }
};