class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> boxUsed(n, false);
        vector<bool> haveBox(n, false);
        queue<int> q;
        unordered_set<int> toVisit;
        
        for (int i = 0; i < initialBoxes.size(); i++) {
            int box = initialBoxes[i];
            haveBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
                boxUsed[box] = true;
            } else {
                toVisit.insert(box);
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            totalCandies += candies[curr];
            for (int key : keys[curr]) {
                if (status[key] == 0) {
                    status[key] = 1;
                    if (haveBox[key] && !boxUsed[key]) {
                        q.push(key);
                        boxUsed[key] = true;
                        toVisit.erase(key);
                    }
                }
            }

            for (int nextBox : containedBoxes[curr]) {
                haveBox[nextBox] = true;
                if (status[nextBox] == 1 && !boxUsed[nextBox]) {
                    q.push(nextBox);
                    boxUsed[nextBox] = true;
                } else {
                    toVisit.insert(nextBox);
                }
            }

            vector<int> boxesToErase;
            for (int box : toVisit) {
                if (status[box] == 1 && !boxUsed[box]) {
                    q.push(box);
                    boxUsed[box] = true;
                    boxesToErase.push_back(box);
                }
            }

            for (int i = 0; i < boxesToErase.size(); i++) {
                toVisit.erase(boxesToErase[i]);
            }
        }

        return totalCandies;
    }
};
