class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<int, vector<char>> top; 
        
        for(const auto& s : allowed) {
            int key = (s[0] << 8) | s[1];  
            top[key].push_back(s[2]);
        }
        
        function<bool(const string&, string&)> helper = [&](const string& row, string& next) -> bool {
            int rowSize = row.size();
            if(rowSize == 1) return true;
            
            int nextSize = next.size();
            if(nextSize == rowSize - 1) {
                string empty;
                empty.reserve(nextSize);  
                return helper(next, empty);
            }
            
            int key = (row[nextSize] << 8) | row[nextSize + 1];  
            auto it = top.find(key);
            if(it == top.end()) return false;
            
            const vector<char>& options = it->second;
            for(int i = 0; i < options.size(); i++) { 
                next.push_back(options[i]);
                if(helper(row, next)) return true;
                next.pop_back();
            }
            return false;
        };
        
        string empty;
        empty.reserve(bottom.size());
        return helper(bottom, empty);
    }
};