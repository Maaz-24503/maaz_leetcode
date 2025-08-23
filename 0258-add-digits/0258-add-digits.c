int addDigits(int num) {
    while(num >= 10) {          // num = 11,  rem = 1000,  div = 100, newNum = 0
        int newNum = 0;
        long long rem = 10, div = 1;
        while(div <= num){
            int dig = (int) ((num % rem) / div);
            newNum += dig;
            rem *= 10;
            div *= 10;
        }
        num = newNum;
    }
    return num;
}