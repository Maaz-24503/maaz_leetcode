class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        if(numRows == 2){
            string ans = "";
            for(int i = 0; i<s.size(); i+=2) ans += s[i];
            for(int i = 1; i<s.size(); i+=2) ans += s[i];
            return ans;
        }
        if(numRows>=s.size()) return s;
        int val = ((2*numRows) - 2);
        int cols = (s.size() + val - 1)/val;
        cols *= (s.size()-1);
        vector<string> grid(numRows, "");
        int currRow = 0;
        bool down = true;
        for(int i = 0; i<s.size(); i++){
            // cout<<currRow<<" "<<currCol<<endl;
            grid[currRow] += s[i];
            if(currRow == numRows-1){
                down = false;
                currRow--;
            }
            else{
                if(down) currRow++;
                else{
                    if(currRow == 0){
                        down = true;
                        currRow++;
                    }
                    else {
                        currRow--;
                    }
                }
            }
        }
        string ans = "";
        for(int i = 0; i<numRows; i++) ans += grid[i];
        return ans;
    }
};