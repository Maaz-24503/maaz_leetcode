class Solution {
public:
vector<vector<int>> memo;

    Solution() {
        memo.resize(501, vector<int>(501, -1));
    }
    int mini(int a, int b, int c){
        return min(min(a,b), c);
    }
    int helper(string word1, string word2, int i, int j){
        if(i == -1) return j+1;
        else if(j == -1) return i+1;
        else if(memo[i][j]!=-1) return memo[i][j];
        else if(word1[i] == word2[j]){
            memo[i][j] = helper(word1, word2, i-1, j-1);
        }
        else{
            memo[i][j] = 1 + mini(helper(word1,word2, i-1, j) , helper(word1,word2, i,j-1), helper(word1,word2, i-1,j-1));
        }
        return memo[i][j];
    }
    int minDistance(string word1, string word2) {
        int ans = helper(word1, word2, word1.size()-1, word2.size()-1);
        for(int i = 0; i< word1.size(); i++){
            for(int j = 0; j<word2.size(); j++){
                cout<< memo[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};