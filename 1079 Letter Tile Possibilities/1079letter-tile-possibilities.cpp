class Solution {
public:

    int numTilePossibilities(string tiles) {
        set<string> poss;
        poss.insert("");
        for(int i = 0; i<tiles.size(); i++){
            vector<string> temp;
            for(auto &str: poss){
                temp.push_back(str + tiles[i]);
                temp.push_back(tiles[i] + str);
                for(int j = 1; j<str.size(); j++){
                    // cout<<str.size()-1<<" "<<j<<endl;
                    temp.push_back(str.substr(0, j) + tiles[i] + str.substr(j, str.size() - j));
                }
            }
            for(auto& str: temp){
                poss.insert(str);
            }
        }
        return poss.size()-1;
    }
};