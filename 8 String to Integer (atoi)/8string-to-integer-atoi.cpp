class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ')
            i++;
        bool neg = false;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-')
                neg = true;
            i++;
        }
        bool zeroCheck = false;
        int j = i;
        while (isdigit(s[j]))
            j++;
        while (s[i] == '0'){
            i++;
            zeroCheck = true;
        }
        if(j == i) return 0;
        string num = s.substr(i, j-i);
        cout<<num<<endl;
        cout<<i<<" "<<j<<endl;
        if (neg) {
            long long check = INT_MAX ;
            check++;
            string temp = to_string(check);
            if(num.size()>temp.size() || num == temp) return INT_MIN;
            if(num.size() == temp.size()){
                int k = 0;
                while(num[k] == temp[k]) k++;
                if(num[k]>temp[k]) return INT_MIN;
            }
        } else {
            int check = INT_MAX;
            string temp = to_string(check);
            if(num.size()>temp.size() || num == temp) return INT_MAX;
            if(num.size() == temp.size()){
                int k = 0;
                while(num[k] == temp[k]) k++;
                if(num[k]>temp[k]) return INT_MAX;
            }
        }
        int ans = stoi(num);
        return neg ? (ans*-1) : ans;
    }
};