package Basic_Algos.binarySearch;

import java.util.Scanner;

public class LeetCode_278 {
    static int bad = 4;
    public static boolean isBadVersion(int b){
        return b == bad;
    }
    public static int firstBadVersion(int n) {
        int left = -1;
        int right = n;

        while(left + 1 != right){
            int mid = left + (right - left)/2;
            if (isBadVersion(mid)){
                right = mid;
            }else{
                left = mid;
            }
        }
        return right;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
//        int bad = sc.nextInt();
        int res = firstBadVersion(n);

        System.out.println(res);
    }
}
