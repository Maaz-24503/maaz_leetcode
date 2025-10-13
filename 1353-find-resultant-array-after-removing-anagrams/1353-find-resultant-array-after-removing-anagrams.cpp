class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> aux(n, vector<string>{"", "", ""});
        for(int i = 0; i<n; i++){
            aux[i][0] = words[i];
            string temp = words[i];
            sort(temp.begin(), temp.end());
            aux[i][1] = temp;
        }
        for(int i = 1; i < n; i++) {
            if(aux[i][1] == aux[i - 1][1]){
                aux[i][2]  = ".";
            }
        }
        vector<string> ans;
        for(int i = 0; i<n; i++)
            if(!aux[i][2].size()) ans.push_back(aux[i][0]);
        return ans;
    }
};