class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> l(n , 0);
        vector<int> r(n , 0);
        for(int i = 1; i<n; i++) l[i] = s[i-1] == '0' ? l[i-1] + 1 : l[i-1];
        for(int i = n - 2; i>=0; i--) r[i] = s[i+1] == '1' ? r[i+1] + 1 : r[i+1];
        // for(int i = 0; i<n; i++){
        //     cout<<"left: "<<l[i];
        //     cout<<" right: "<<r[i]<<endl;
        // }
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            ans = max(ans, l[i+1] + r[i]);
        }
        return ans;
    }
};