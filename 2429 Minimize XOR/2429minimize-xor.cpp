class Solution {
public:

    string bin1, bin2;
    int n1, n2;

    int countBits(string str){
        int ans = 0;
        for(int i = 0; i<str.size(); i++) if(str[i] == '1') ans++;
        return ans;
    }

    string bin(int n){
        string ans = "";
        while(n>0){
            if(n%2 == 1) ans = "1"+ans;
            else ans = "0"+ans;
            n /= 2;
        }
        return ans;
    }

    int minimizeXor(int num1, int num2) {
        this->bin1 = bin(num1);
        this->bin2 = bin(num2);
        // cout<<bin1<<" "<<bin2<<endl;
        this->n1 = countBits(this->bin1);
        this->n2 = countBits(this->bin2);
        // cout<<n1<<" "<<n2;
        if(n1>n2){
            int ans = 0;
            int mask = 1<<(bin1.size()-1);
            for(int i = 0; i<bin1.size(); i++){
                if(n2 == 0) break;
                if(bin1[i] == '1'){
                    n2--;
                    ans |= mask;
                }
                mask >>= 1;
            }
            return ans;
        }
        else if(n2>n1){
            int diff = n2 - n1;
            int ans = num1;
            int mask = 1;
            while(diff>0){
                ans |= mask;
                if((mask & num1) == 0) diff--;
                mask <<= 1;
            }
            return ans;
        }
        else return num1;
    }
};