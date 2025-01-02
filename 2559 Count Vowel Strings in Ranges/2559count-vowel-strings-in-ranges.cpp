class Solution {
public:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    bool has(char letter){
        return vowels.find(letter) != this->vowels.end();
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<bool> isValid(n, false);
        vector<int> prefix(n+1);

        for(int i = 0; i<n; i++){
            isValid[i] = has(words[i][0]) && has(words[i][words[i].size()-1]);
        }

        vector<int> ans(queries.size());

        for(int i = 1; i<n+1; i++){
            prefix[i] = isValid[i-1] ? prefix[i - 1] + 1 : prefix[i - 1];
        }

        for(int i = 0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            ans[i] = prefix[r] - prefix[l];
        }

        return ans;
    }
};