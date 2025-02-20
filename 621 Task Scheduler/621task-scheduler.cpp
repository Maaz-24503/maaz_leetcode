class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(int i = 0; i<tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int maxi = freq[25];
        int slots = (maxi - 1)*(n);
        cout<<slots<<endl;
        int ans = slots;
        for(int i = 0; i<25; i++){
            if(slots >= freq[i]) {
                slots -= freq[i];
                if(maxi == freq[i]) {
                    ans++;
                    slots++;
                }
            }
            else if(slots == 0){
                ans += freq[i];
            }
            else{
                int pen = freq[i] - slots;
                slots = 0;
                ans += pen;
            }
        }
        return ans + maxi;
    }
};