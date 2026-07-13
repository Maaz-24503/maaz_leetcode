class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string full = "123456789";
        vector<int> ans;
        for(int i = 1; i < 10; i++){
            for(int j = 0; j < 10 - i; j++){
                string curr = full.substr(j, i);
                int num = stoi(curr);
                if(num <= high && num >= low) ans.push_back(num);
            }
        }
        return ans;
    }
};