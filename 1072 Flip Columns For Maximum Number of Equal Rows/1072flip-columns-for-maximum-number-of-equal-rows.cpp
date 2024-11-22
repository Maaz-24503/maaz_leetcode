class Solution {
public:

    string invert(string temp){
        for(int i = 0; i<temp.size(); i++) temp[i] = temp[i] == '0'?'1':'0';
        return temp;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int maxi = 1;
        vector<string> form(matrix.size(), "");
        unordered_map<string, int> count;

        for(int i = 0; i<matrix.size(); i++)
            for(int j = 0; j<matrix[i].size(); j++) 
                form[i] += to_string(matrix[i][j]);

        for(int i = 0; i<matrix.size(); i++){
            string temp = form[i];
            if(temp[0] == '1') temp = invert(temp);
            count[temp]++;
            maxi = max(maxi, count[temp]);
        }
        return maxi;
    }
};