class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (m == 0) return {};

        vector<int> suffLast(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (word1[i] == word2[j]) {
                suffLast[j] = i;
                j--;
                if (j == -1) break;
            }
        }

        vector<int> ans;
        j = 0;
        bool specialUsed = false;
        for (int i = 0; i < n; i++) {
            if (j == m) return ans;

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!specialUsed && (j == m - 1 || suffLast[j + 1] > i)) {
                specialUsed = true;
                ans.push_back(i);
                j++;
            }
        }

        if ((int)ans.size() == m) return ans;
        return vector<int>{};
    }
};