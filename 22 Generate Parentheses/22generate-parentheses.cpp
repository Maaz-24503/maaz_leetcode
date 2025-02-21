class Solution {
public:
    int n;

    vector<string> helper(int opened, int closed){
        if(opened > n || opened < closed || closed > n) return {};
        if(opened == n && closed == n) return {""};
        vector<string> aux;
        vector<string> ans;
        aux = helper(opened + 1, closed);        // '(' rec
        for(int i = 0; i<aux.size(); i++){
            aux[i] = '(' + aux[i];
            ans.push_back(aux[i]);
        }
        aux = helper(opened, closed + 1);      // ')' rec
        for(int i = 0; i<aux.size(); i++){
            aux[i] = ')' + aux[i];
            ans.push_back(aux[i]);
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        return helper(0, 0);
    }
};