class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<bool> bull(n, false);
        int bulls = 0;
        for(int i = 0; i<n; i++)
            if(secret[i] == guess[i]) {
                bull[i] = true;
                bulls++;
            }
        vector<int> sec(10, 0), gu(10, 0);
        for(int i = 0; i<n; i++){
            if(!bull[i]){
                sec[secret[i] - '0']++;
                gu[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for(int i = 0; i<10; i++) cows += min(sec[i], gu[i]);
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};