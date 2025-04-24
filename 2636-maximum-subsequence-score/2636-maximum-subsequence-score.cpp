class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> comb(n);
        for(int i = 0; i<n; i++) comb[i] = {nums2[i], nums1[i]};
        sort(comb.begin(), comb.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first > b.first;});
        long long sum = 0LL, ans = 0LL;
        priority_queue<int, vector<int>, greater<>> minpq;
        for(int i = 0; i<k; i++){ 
            sum += comb[i].second;
            minpq.push(comb[i].second);
        }
        ans = sum*comb[k-1].first;
        for(int i = k; i<n; i++){
            sum += comb[i].second;
            minpq.push(comb[i].second);
            int curr = minpq.top();
            minpq.pop();
            sum -= curr;
            ans = max(ans, sum * comb[i].first);
        }
        return ans;
    }
};