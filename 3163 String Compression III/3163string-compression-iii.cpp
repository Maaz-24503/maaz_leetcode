class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i = 0;
        for(; i<word.size(); i++){
            int k = i;
            while(k<word.size() && word[k] == word[i]) k++;
            int count = k-i;
            while(count>9){
                ans += to_string(9) + word[i];
                count -= 9;
            }
            if(count != 0) ans += to_string(count) + word[i];
            i = k-1;
        }
        return ans;
    }
};