class Solution {
private:
    bool vDone(unordered_map<char, int>& vowels){
        for(auto [v, freq] : vowels){ if(freq == 0) return false;}
        return true;
    }

    long long helper(string word, int k){
        unordered_map<char, int> vowels{{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int l = 0, r = 0, count = 0;
        long long ans = 0;
        while(r < word.size()){
            if(!vDone(vowels) || count<k){
                if(vowels.find(word[r]) != vowels.end()) vowels[word[r]]++;
                else count++;
                r++;
            }
            while(vDone(vowels) && count >= k){
                ans += word.size() - r + 1;
                if(vowels.find(word[l]) != vowels.end()) vowels[word[l]]--;
                else count--;
                l++;
            }
        }
        return ans;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k+1);
    }
};
