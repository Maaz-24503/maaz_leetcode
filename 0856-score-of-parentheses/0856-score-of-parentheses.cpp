class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size(), ans = 0;
        vector<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') {   // opening bracket means im about to start a new run
                st.push_back(ans);
                ans = 0;
            } else {    // This may be the first closing run meaning score will be 1 or nested which means we can multiply our current running score by 2, as soon as the run ends (meaning we get an opening bracket), we can just push this runn onto the stack in the upper if condition
                int curr = st.back(); st.pop_back();
                if(ans == 0) ans = curr+1;
                else ans = curr + (ans<<1);
            }
        }
        return ans;
    }
};

// ( ((( () () ) () )) )