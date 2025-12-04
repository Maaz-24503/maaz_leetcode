class Solution {
public:
    int countCollisions(string directions) {
        int l = 0;
        while(l < directions.size() && directions[l] == 'L') l++;
        if(l == directions.size()) return 0;
        directions = directions.substr(l);
        int n = directions.size();
        stack<char> st;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(directions[i] == 'R') {
                if(!st.empty() && st.top() != 'R') st.pop(); 
                st.push('R');
            }
            if(directions[i] == 'S') {
                while(!st.empty()){
                    if(st.top() == 'R') ans++;
                    st.pop();
                }
                st.push('S');
            }
            if(directions[i] == 'L') {
                if(st.top() == 'R') ans += 2;
                else ans++;
                st.pop();
                while(!st.empty()){
                    ans++;
                    st.pop();
                }
                st.push('S');
            }
        }
        return ans;
    }
};