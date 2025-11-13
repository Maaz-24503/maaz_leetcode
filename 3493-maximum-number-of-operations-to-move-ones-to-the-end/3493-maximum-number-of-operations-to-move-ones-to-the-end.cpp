class Solution {
public:
    int maxOperations(string s) {
        vector<int> ones;
        int n = s.size();

        for(int i = 0; i<n; i++){
            int j = i;
            while(j < n && s[j] == '1') j++;
            if(j == n) break;
            if(j != i) {
                ones.push_back(j - i);
                i = j;  // can afford to skip this when i++ bcz its a '0'
            }
        }

        reverse(ones.begin(), ones.end());

        int ans = 0;
        for(int i = 0; i<ones.size(); i++)
            ans += ones[i] * (i + 1);

        return ans;
    }
};