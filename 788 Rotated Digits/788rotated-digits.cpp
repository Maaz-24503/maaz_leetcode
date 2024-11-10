class Solution {
public:
    vector<int> rot;
    int rotatedDigits(int n) {
        rot.resize(10);
        rot[0] = -2;
        rot[1] = -2;
        rot[8] = -2;
        rot[2] = 5;
        rot[5] = 2;
        rot[6] = 9;
        rot[9] = 6;
        rot[3] = -1;
        rot[4] = -1;
        rot[7] = -1;
        int count = 0;
        for(int i = 2; i<=n; i++){
            int tens = 10;
            bool valid = true;
            bool switched = false;
            while(tens<(i*10)){
                int currDig = (i%tens)/(tens/10);
                // cout<<currDig<<" k\n";
                if(rot[currDig] == -1){
                    valid = false;
                    break;
                }
                if(rot[currDig] > 0) switched = true;
                tens *= 10;
            }
            if(valid && switched){
                count++;
                // cout<<i<<endl;
            }
        }
        return count;
    }
};