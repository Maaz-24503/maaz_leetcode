class Solution {
private:
    unordered_map<string, vector<string>> adjList;
    int des;
    vector<string> ans;

    bool dfs(string u){
        if(ans.size() == des) return true;
        if(adjList[u].size() == 0) return false;
        vector<string> tempNb = adjList[u];
        for(int i = tempNb.size() - 1; i>=0; i--){
            string curr = tempNb[i];
            adjList[u].erase(adjList[u].begin() + i);
            ans.push_back(curr);
            if(dfs(curr)) return true;
            ans.pop_back();
            adjList[u].insert(adjList[u].begin() + i, curr);
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        des = tickets.size()+1;
        for(int i = 0; i<tickets.size(); i++) adjList[tickets[i][0]].push_back(tickets[i][1]);
        for(auto [loc, edg] : adjList) {
            sort(adjList[loc].begin(), adjList[loc].end());
            reverse(adjList[loc].begin(), adjList[loc].end());
        }
        ans.push_back("JFK");
        dfs("JFK");
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};