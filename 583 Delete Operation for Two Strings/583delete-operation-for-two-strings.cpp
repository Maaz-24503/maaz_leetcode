class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length()+1, vector<int>(word2.length()+1, 0));
        for(int i =0; i<=max(word1.length(),word2.length()); i++){
            if(i<=word1.length()) memo[i][0] = i;
            if(i<=word2.length()) memo[0][i] = i;
        }
        for(int i = 0; i<word1.length(); i++){
            for(int j = 0; j<word2.length(); j++){
                if(word1[i] == word2[j]) memo[i+1][j+1] = memo[i][j];
                else {
                    memo[i+1][j+1] = 1 + min(memo[i+1][j], memo[i][j+1]);
                }
            }
        }
        return memo[word1.length()][word2.length()];
    }
};