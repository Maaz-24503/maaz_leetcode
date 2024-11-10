class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int> minHeap;
        int n = times.size();
        vector<int> occupied(n);
        for(int i = 0; i<(1<<17); i++){
            minHeap.push(-i);
        }
        vector<pair<int, int>> arrival;
        vector<pair<int, int>> departure;
        for(int i = 0; i<n; i++){
            arrival.push_back({times[i][0], i});
            departure.push_back({times[i][1], i});
        }
        sort(departure.begin(), departure.end());
        sort(arrival.begin(), arrival.end());
        int a = 0;
        int d = 0;
        while(a<n || d<n){
            if(arrival[a].first < departure[d].first){
                if(arrival[a].second == targetFriend) return -minHeap.top();
                else{
                    occupied[arrival[a].second] = -minHeap.top();
                    minHeap.pop();
                }
                a++;
            }
            else{
                minHeap.push(-occupied[departure[d].second]);
                d++;
            }
        }
        return -1;
    }
};