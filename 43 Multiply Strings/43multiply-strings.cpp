class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        vector<int> ans(num1.size() + num2.size(), 0);
        for(int i = 0; i<num1.size(); i++){
            for(int j = 0; j<num2.size(); j++){
                ans[i+j] += (num1[num1.size() - i -1] - '0') * (num2[num2.size() - j -1] - '0');
                ans[i+j+1] += ans[i+j] / 10;
                ans[i+j] %= 10;
            }
        }
        string answer = "";
        for(int i = 0; i<ans.size() - 1; i++) answer = to_string(ans[i]) + answer;
        if(ans[ans.size()-1] != 0) answer = to_string(ans[ans.size()-1]) + answer;
        return answer;
    }
};