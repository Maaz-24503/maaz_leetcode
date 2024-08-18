class Solution {
public:
    vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> ones{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> spec{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string threeDigits(int num) {
        string ans = "";
        if (num % 100 >= 20 || num % 100 < 10) {
            if(num % 10 != 0)ans = ones[num % 10];
            if((num % 100) / 10 != 0)ans = tens[(num % 100) / 10] + " " + ans;
        } else {
            ans = spec[num % 10];
        }
        if(num / 100 != 0)ans = ones[num / 100] + " Hundred " + ans;
        while(ans[0] == ' ') ans.erase(0,1);
        while(ans[ans.size()-1] == ' ') ans.erase(ans.size()-1, 1);
        return ans;
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> pre { "", "Thousand", "Million", "Billion", "Trillion" };
        int count = 0;
        string ans = "";
        while(num>0){
            if(num%1000 != 0) {
                string curr = threeDigits(num%1000);
                ans = curr+" "+pre[count] +" "+ans; 
            }
            count++;
            num /= 1000;
        }
        while(ans[0] == ' ') ans.erase(0,1);
        while(ans[ans.size()-1] == ' ') ans.erase(ans.size()-1, 1);
        return ans;
    }
};