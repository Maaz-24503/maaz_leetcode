class Solution {
private:
    string ans;
    unordered_set<string> visited;
    int len, n, k;

    bool helper(){
        if(visited.size() == len) return true;
        string prev = ans.substr(ans.size() - n + 1, n - 1);
        for(int i = 0; i<k; i++){
            if(visited.find(prev + to_string(i)) == visited.end()){
                ans += to_string(i);
                visited.insert(prev + to_string(i));
                if(helper()) return true;
                visited.erase(prev + to_string(i));
                ans.pop_back();
            }
        }
        return false;
    }

public:
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        ans = "";
        for(int i = 0; i<n; i++) ans += '0';
        len = pow(k, n);
        visited.insert(ans);
        helper();
        return ans;
    }
};