class Solution {
public:
    int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;
    Matrix identity;

    Matrix matMul(const Matrix& matA, const Matrix& matB){
        Matrix ans(26, vector<long long> (26, 0));
        for(int i = 0; i<26; i++){
            for(int k = 0; k<26; k++){
                for(int j = 0; j<26; j++){
                    ans[i][k] = (ans[i][k] + (matA[i][j] * matB[j][k])) % MOD;
                }
            }
        }
        return ans;
    }

    Matrix matExpo(const Matrix& mat, int p){
        if(p == 0) return identity;
        Matrix div = matExpo(mat, p/2);
        Matrix mul = matMul(div, div);
        if(p % 2) return matMul(mul, mat);
        else return mul;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix transformation(26, vector<long long>(26, 0LL));
        identity.resize(26, vector<long long>(26, 0LL));
        for(int i = 0; i<26; i++) identity[i][i] = 1;
        for(int i = 0; i<26; i++)
            for(int j = 1; j<=nums[i]; j++)
                transformation[(i + j) % 26][i]++;
        vector<long long> freq(26, 0LL);
        for(int i = 0; i<s.size(); i++) freq[s[i] - 'a']++;
        Matrix finalTrans = matExpo(transformation, t);
        long long ans = 0LL;
        for(int i = 0; i<26; i++){
            for(int j = 0; j<26; j++){
                ans = (ans + (finalTrans[i][j] * freq[j])) % MOD;
            }
        } 
        return ans;
    }
};
