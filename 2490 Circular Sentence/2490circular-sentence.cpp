class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string curr;
        char currLast = ';';
        char start;
        while(ss>>curr){
            if(currLast == ';'){
                currLast = curr[curr.size()-1];
                start = curr[0];
            }
            else{
                if(currLast != curr[0]) return 0;
                currLast = curr[curr.size()-1];
            }
        }
        return start == currLast;
    }
};