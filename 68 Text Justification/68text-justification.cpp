class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> helper;
        vector<int> lineSize;
        int curr = 0;
        for(int i = 0; i<words.size(); i++){
            if(curr == 0){
                curr = words[i].size();
                vector<string> temp{words[i]};
                helper.push_back(temp);
            }
            else{
                if(curr + words[i].size() + 1 > maxWidth){
                    i--;
                    lineSize.push_back(curr);
                    curr = 0;
                }
                else{
                    curr += words[i].size() + 1;
                    helper[helper.size()-1].push_back(words[i]);
                }
            }
        }
        lineSize.push_back(helper[helper.size()-1][0].size());
        vector<string> tbr;
        for(int i = 0; i<helper.size(); i++){
            string curr = "";
            if(i == helper.size()-1){
                curr = helper[i][0];
                for(int p = 1; p<helper[i].size(); p++){
                    curr += " "+helper[i][p];
                }
                while(curr.size()<maxWidth) curr += " ";
            }
            else if(helper[i].size()>1){
                int spaces = maxWidth - lineSize[i] + helper[i].size() - 1; // removed pre-counted spaces
                int bigSpace = spaces%(helper[i].size() - 1);
                spaces = spaces/(helper[i].size() - 1);
                string big = "";
                string small = "";
                cout<<spaces<<endl;
                for(int k = 0; k<spaces; k++){
                    small += " ";
                    big += " ";
                }
                big += " ";
                for(int j = 0; j<helper[i].size()-1; j++){
                    curr += j<bigSpace ? (helper[i][j] + big) : (helper[i][j] + small);
                }
                curr += helper[i][helper[i].size()-1];
            }
            else{
                curr = helper[i][0];
                while(curr.size()<maxWidth) curr += " ";
            }
            tbr.push_back(curr);
        }
        return tbr;
    }
};