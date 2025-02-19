class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string curr = searchWord.substr(0,1);
        vector<vector<string>> ans(searchWord.size());
        sort(products.begin(), products.end());

        for(int i = 0; i<products.size(); i++){
            if(products[i][0] == curr[0]) ans[0].push_back(products[i]);
        }
        // for(int i = 0; i<ans[0].size(); i++) cout<<ans[0][i]<<endl;
        for(int i = 1; i<searchWord.size(); i++){
            curr = curr + searchWord[i];
            for(int j = 0; j<ans[i-1].size(); j++){
                if(ans[i-1][j][i] == searchWord[i]) ans[i].push_back(ans[i-1][j]);
            }
        }

        vector<vector<string>> finalized(searchWord.size());
        for(int i = 0; i<searchWord.size(); i++){
            for(int j = 0; j<ans[i].size() && j<3; j++){
                finalized[i].push_back(ans[i][j]);
            }
        }
        return finalized;
    }
};