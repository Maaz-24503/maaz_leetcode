class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        
        for (int i = 0; i < recipes.size(); i++) {
            for (auto& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }
        
        queue<string> q;
        for (const string& item : supplies) {
            q.push(item);
        }

        vector<string> result;
        
        while (!q.empty()) {
            string item = q.front();
            q.pop();
            
            if (find(recipes.begin(), recipes.end(), item) != recipes.end()) {
                result.push_back(item);
            }
            
            for (auto& nextRecipe : graph[item]) {
                if (--inDegree[nextRecipe] == 0) {
                    q.push(nextRecipe);
                }
            }
        }
        
        return result;
    }
};
