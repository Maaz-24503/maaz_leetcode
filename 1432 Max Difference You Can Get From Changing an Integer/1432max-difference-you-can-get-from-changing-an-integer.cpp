class Solution {
public:
    int increase(int numb){
        string num = to_string(numb);
        int i = 0;
        while(i == num.size() || num[i] == '9') i++;
        if(i == num.size()) return numb;
        char tbc = num[i];
        char target = '9';
        for(int j = 0; j<num.size(); j++) num[j] = num[j] == tbc? target : num[j];
        return stoi(num);
    }
    int reduce(int numb){
        string num = to_string(numb);
        int i = 0;
        while(i == num.size() || num[i] == '1' || num[i] == '0') i++;
        if(i == num.size()) return numb;
        char tbc = num[i];
        char target = '0';
        if(i == 0) target = '1';
        for(int j = 0; j<num.size(); j++) num[j] = num[j] == tbc? target : num[j];
        return stoi(num);
    }
    int maxDiff(int num){
        int a = increase(num);
        int b = reduce(num);
        return a - b;
    }
};