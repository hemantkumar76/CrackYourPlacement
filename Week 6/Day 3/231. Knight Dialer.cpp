class Solution {
    long long mod = pow(10,9)+7;
public:
    int knightDialer(int n) {
        // DP array initialize karte hain jisme hum store karenge har length ke liye kitne distinct numbers dial kar sakte hain
        long long arr[n][10];
        for (int i = 0; i<10;i++) arr[0][i] = 1;
        arr[0][5] =0;
        arr[n-1][5] = 0;

        // DP array fill karte hain
        for (int i = 1; i< n;i++){
            // 0 se knight 4 aur 6 pe ja sakta hai
            arr[i][0] = (arr[i-1][4] + arr[i-1][6]) % mod;
            // 1 se knight 6 aur 8 pe ja sakta hai
            arr[i][1] = (arr[i-1][6] + arr[i-1][8]) % mod; 
            // 2 se knight 7 aur 9 pe ja sakta hai
            arr[i][2] = (arr[i-1][7] + arr[i-1][9])% mod;
            // 3 se knight 4 aur 8 pe ja sakta hai
            arr[i][3] = (arr[i-1][4] + arr[i-1][8])% mod;
            // 4 se knight 3, 9 aur 0 pe ja sakta hai
            arr[i][4] = (arr[i-1][3] + arr[i-1][9] + arr[i-1][0])% mod;
            // 6 se knight 1, 7 aur 0 pe ja sakta hai
            arr[i][6] = (arr[i-1][1] + arr[i-1][7] + arr[i-1][0])% mod;
            // 7 se knight 2 aur 6 pe ja sakta hai
            arr[i][7] = (arr[i-1][2] + arr[i-1][6])% mod;
            // 8 se knight 1 aur 3 pe ja sakta hai
            arr[i][8] = (arr[i-1][1] + arr[i-1][3])% mod;
            // 9 se knight 2 aur 4 pe ja sakta hai
            arr[i][9] = (arr[i-1][2] + arr[i-1][4])% mod;
        }

        // Sabhi numbers ke liye distinct numbers dial karne ki possibilities ko sum karte hain
        long long answer = 0;
        for (int i = 0; i< 10;i++){
            answer += arr[n-1][i];
            answer %= mod;
        }
        // Agar length 1 hai toh 1 add karte hain kyunki knight kisi bhi number pe place ho sakta hai
        return answer + ((n == 1)? 1:0);
    }
};
