int countDigits(int num) {
    int ans = 0;
    long long rem = 10;
    long long div = 1;
    while(div <= num) {
        long long dig = (num % rem) / div;
        if(num % dig == 0) {
            ans++;
        }
        rem *= 10;
        div *= 10;
    }
    return ans;
}