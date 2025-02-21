class Solution {
public:

    vector<bool> isVisited;

    bool isValid(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        bool used = false;
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                if(!used) used = true;
                else return false;
            }
        }
        return used;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> bfs;
        isVisited.resize(wordList.size(), false);
        bool isPossible = false;
        for(int i = 0; i<wordList.size(); i++) 
            if(wordList[i] == endWord){
                isPossible = true;
                break;
            }
        bfs.push({beginWord, 1});
        while(!bfs.empty()){
            auto [word, moves] = bfs.front();
            bfs.pop();
            // cout<<word<<" "<<moves<<endl;
            for(int i = 0; i<wordList.size(); i++){
                if(!isVisited[i]){
                    if(isValid(wordList[i], word)){
                        if(wordList[i] == endWord) return moves+1;
                        bfs.push({wordList[i], moves+1});
                        isVisited[i] = true;
                    }
                }
            }
        }
        return 0;
    }
};