class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> tokens1;

        stringstream check1(sentence1);

        string intermediate;

        while (getline(check1, intermediate, ' ')) {
            tokens1.push_back(intermediate);
        }
        stringstream check2(sentence2);
        vector<string> tokens2;
        while(getline(check2, intermediate, ' ')) tokens2.push_back(intermediate);
        if(tokens1.size() < tokens2.size()){
            vector<string> temp = tokens1;
            tokens1 = tokens2;
            tokens2 = temp;
        }
        int left = 0, right = tokens2.size() - 1;
        int lleft = 0, rright = tokens1.size() - 1;
        while(left<=right){
            cout<<left<<" "<<lleft<<" "<<right<<" "<<rright<<endl;
            if(right == left){
                if(tokens1[lleft] == tokens2[right] || tokens1[rright] == tokens2[right]) return true;
                else return false;
            }
            if(tokens1[lleft] == tokens2[left]){
                left++;
                lleft++;
            }
            else if(tokens1[rright] == tokens2[right]){
                right--;
                rright--;
            }
            else return false;
        }
        return true;
    }
};