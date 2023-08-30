class Solution {
public:
    int bestClosingTime(string customers) {
        int help[customers.length()];
    int scores[customers.length()+1];
    int sum_yes = 0;
    int sum_no = 0;
    for(int i = 0; i<customers.length(); i++){
        if(customers[i]=='Y'){
            sum_yes++;
            help[i] = 1;
        }
        else {
            sum_no++;
            help[i] = 0;
        }
    }
    int count_yes = 0;
    int count_no = 0;
    int min_score = 999999;
    int min_ind = 0;
    for(int i = 0; i<customers.length(); i++){
        if(help[i] == 1) count_yes++;
        else count_no++;
        int left = count_no;
        int right = sum_yes-count_yes ;
        scores[i+1] = left+right;
    }
    scores[0] = sum_yes;
    for(int i = 0; i<customers.length()+1; i++){
        if(scores[i]<min_score){
            min_score = scores[i];
            min_ind = i;
        } 
    }
    
    return min_ind;
    }
};