class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int curr = 0;
        int currLength = 1;
        for(int i = 0; i<n-1; i++){
            if(chars[i] == chars[i+1]) currLength++;
            else{
                chars[curr] = chars[i];
                if(currLength == 1) curr++;
                else{
                    string freq = to_string(currLength);
                    for(int j = 0; j<freq.size(); j++){
                        chars[curr + j + 1] = freq[j];
                    }
                    curr += freq.size()+1;
                    currLength = 1;
                }
            }
        }
        chars[curr] = chars[n-1];
        if(currLength == 1) curr++;
        else{
            string freq = to_string(currLength);
            for(int i = 0; i<freq.size(); i++){
                chars[curr + i + 1] = freq[i];
            }
            curr += freq.size()+1;
        }
        return curr;
    }
};