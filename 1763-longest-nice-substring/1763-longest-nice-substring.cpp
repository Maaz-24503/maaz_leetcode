class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans = "";
        int length = 0;

        for(int i = 0; i < s.size(); i++){
            string t = "";
            t += s[i];
            for(int j = i + 1; j < s.size(); j++){
                t += s[j];
                
                vector<int> upper(26,0), lower(26,0);

                for(auto y : t)
                if(y >= 'a') lower[y - 'a']++;
                else upper[y - 'A']++;

                int i;
                for(i = 0; i < 26; i++){
                    if((lower[i] > 0 && upper[i] == 0) ||
                        (upper[i] > 0 && lower[i] == 0)){
                        break;
                    }
                }

                if(i == 26 && t.size() > length){
                    length = t.size();
                    ans = t;
                }
            }
        }
        return ans;
    }
};