package LeetCodeHot100.Hot21to30;

import java.util.Scanner;

public class Hot29_70 {
    public static int climbStairs(int n) {
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 2;
        }
        int [] dp = new int[n+1];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int res = climbStairs(n);
        System.out.println(res);
    }
}
