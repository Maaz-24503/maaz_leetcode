class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time(dist.size());
        for(int i = 0; i<dist.size(); i++) time[i] = (dist[i]*1.0)/(speed[i]*1.0);
        sort(time.begin(), time.end());
        for(int i = 0; i<time.size(); i++) cout<<time[i]<<" ";
        cout<<endl;
        int i;
        for(i = 1; i<speed.size(); i++) if(i - time[i]>=0) break;
        return i;
    }
};