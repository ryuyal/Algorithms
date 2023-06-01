package LeetCodeHot100.Hot91to100;

import java.util.Scanner;

public class Hot91_461 {
    /*
    异或运算: 相同为0 不同为1
     */
    public static int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while(n > 0){
            if (n % 2 == 1){
                count++;
            }
            n/=2;
        }
        return count;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();

        int res = hammingDistance(x, y);

        System.out.println(res);
    }
}
