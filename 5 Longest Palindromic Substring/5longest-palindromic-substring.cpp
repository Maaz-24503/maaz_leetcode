class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        pair<int, int> ans = {0, 1};
        int slots = (2*n) + 1;
        for(int i = 0; i<slots; i++){
            int center = i/2;
            if(i % 2 == 0){
                int j = 0;
                while(center > j && center+j<n){
                    if(s[j + center] != s[center - j - 1]) break;
                    j++;
                }
                if(2*j > ans.second){
                    ans = {center - j, 2*j};
                }
            }
            else{
                int j;
                for(j = 1; j+center<n && center-j>=0; j++){
                    if(s[j+center] != s[center-j]) break;
                }
                int sz = 1 + ((j-1) * 2);
                if(sz > ans.second){
                    ans = {center - j + 1, sz};
                }
            }
        }
        return s.substr(ans.first, ans.second);
    }
};