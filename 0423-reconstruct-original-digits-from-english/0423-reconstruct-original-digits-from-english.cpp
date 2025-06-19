class Solution {
public:
    string originalDigits(string s) {
        vector<int> chars(26, 0);
        for(char& c : s) chars[c - 'a']++;
        vector<int> dig(10, 0);
        dig[0] += chars['z' - 'a'];
        chars['e' - 'a'] -= chars['z' - 'a'];
        chars['r' - 'a'] -= chars['z' - 'a'];
        chars['o' - 'a'] -= chars['z' - 'a'];
        chars['z' - 'a'] = 0;
        dig[2] += chars['w' - 'a'];
        chars['t' - 'a'] -= chars['w' - 'a'];
        chars['o' - 'a'] -= chars['w' - 'a'];
        chars['w' - 'a'] = 0;
        dig[4] += chars['u' - 'a'];
        chars['f' - 'a'] -= chars['u' - 'a'];
        chars['o' - 'a'] -= chars['u' - 'a'];
        chars['r' - 'a'] -= chars['u' - 'a'];
        chars['u' - 'a'] = 0;
        dig[6] += chars['x' - 'a'];
        chars['s' - 'a'] -= chars['x' - 'a'];
        chars['i' - 'a'] -= chars['x' - 'a'];
        chars['x' - 'a'] = 0;
        dig[8] += chars['g' - 'a'];
        chars['e' - 'a'] -= chars['g' - 'a'];
        chars['i' - 'a'] -= chars['g' - 'a'];
        chars['h' - 'a'] -= chars['g' - 'a'];
        chars['t' - 'a'] -= chars['g' - 'a'];
        chars['g' - 'a'] = 0;
        dig[1] += chars['o' - 'a'];
        chars['n' - 'a'] -= chars['o' - 'a'];
        chars['e' - 'a'] -= chars['o' - 'a'];
        chars['o' - 'a'] = 0;
        dig[3] += chars['r' - 'a'];
        chars['t' - 'a'] -= chars['r' - 'a'];
        chars['h' - 'a'] -= chars['r' - 'a'];
        chars['e' - 'a'] -= 2 * chars['r' - 'a'];
        chars['r' - 'a'] = 0;
        dig[5] += chars['f' - 'a'];
        chars['i' - 'a'] -= chars['f' - 'a'];
        chars['e' - 'a'] -= chars['f' - 'a'];
        chars['v' - 'a'] -= chars['f' - 'a'];
        chars['f' - 'a'] = 0;
        dig[7] += chars['v' - 'a'];
        chars['s' - 'a'] -= chars['v' - 'a'];
        chars['e' - 'a'] -= 2 * chars['v' - 'a'];
        chars['n' - 'a'] -= chars['v' - 'a'];
        chars['v' - 'a'] = 0;
        dig[9] = chars['e' - 'a'];
        string ans = "";
        for(int i = 0; i<10; i++) 
            for(int j = 0; j<dig[i]; j++)
                ans += to_string(i);
        return ans;
    }
};