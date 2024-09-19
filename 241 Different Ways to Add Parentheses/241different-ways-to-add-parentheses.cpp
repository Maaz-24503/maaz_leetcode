class Solution {
public:
    int eva(string num1, string num2, string oper){
        if(oper == "+") return stoi(num1) + stoi(num2);
        else if(oper == "-") return stoi(num1) - stoi(num2);
        else return stoi(num1) * stoi(num2);
    }
    vector<int> evalArr(vector<int> num1, vector<int> num2, string oper){
        vector<int> ans;
        if(oper == "+") 
            for(int i = 0; i<num1.size(); i++) 
                for(int j = 0; j<num2.size(); j++) 
                    ans.push_back(num1[i] + num2[j]);
        else if(oper == "-") 
            for(int i = 0; i<num1.size(); i++) 
                for(int j = 0; j<num2.size(); j++) 
                    ans.push_back(num1[i] - num2[j]);
        else 
            for(int i = 0; i<num1.size(); i++) 
                for(int j = 0; j<num2.size(); j++) 
                    ans.push_back(num1[i] * num2[j]);
        return ans;
    }
    vector<int> helper(vector<string> expression, int i, int j, unordered_map<string, vector<int>>& memo){
        if(i == j) return vector<int>{stoi(expression[i])};
        // if(i == j-2) return vector<int>{eva(expression[i], expression[j], expression[i+1])};
        string key = to_string(i)+" "+to_string(j);
        if(memo.find(key) != memo.end()) return memo[key];
        vector<int> ans;
        for(int p = i+1; p<j; p += 2){
            vector<int> left = helper(expression, i, p-1, memo);
            vector<int> right = helper(expression, p+1, j, memo);
            vector<int> mid = evalArr(left, right, expression[p]);
            for(int t = 0; t<mid.size(); t++) ans.push_back(mid[t]);
        }
        return memo[key] = ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        if (expression.length() == 0) return vector<int>{};
        int length = 0;
        int start = 0;
        unordered_set<char> op{'+', '-', '*'};
        vector<string> exp;
        bool check = false;
        for(int i = 0; i<expression.length(); i++){
            if(op.find(expression[i]) != op.end()){
                check = true;
                exp.push_back(expression.substr(start,i-start));
                start = i + 1;
                exp.push_back(expression.substr(i,1));
            }
        }
        if(!check) return vector<int>{stoi(expression)};
        exp.push_back(expression.substr(start, expression.length() - start));
        // for(int i = 0; i<exp.size(); i++) cout<<exp[i]<<"  ";
        unordered_map<string, vector<int>> memo;
        return helper(exp, 0, exp.size()-1, memo);
    }
};