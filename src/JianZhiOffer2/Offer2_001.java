package JianZhiOffer2;

import java.util.Scanner;

public class Offer2_001 {
    /*
    不能处理边界情况
     */
//    public static int divide(int a, int b) {
//        int count = 0;
//        boolean flag = (a < 0 && b > 0) || (a > 0 && b < 0);
//
//        a = Math.abs(a);
//        b = Math.abs(b);
//        while (a > 0) {
//            a -= b;
//            if (a > 0) {
//                count++;
//            }
//        }
//        if (flag){
//            return -count;
//        }
//        return count;
//    }
    public static int divide(int a, int b) {
        //特殊情况1, b=1
        if (b == 1){
            return a;
        }
        //特殊情况2, b=-1
        if (b == -1){
            return a == Integer.MIN_VALUE ? Integer.MAX_VALUE : -a;
        }
        //特殊情况3, a=0
        if (a == 0){
            return 0;
        }

        //确定符号
        boolean positive = (a ^ b) >= 0;
        //为避免溢出, 转换为负数进行计算
        a = a < 0 ? a : -a;
        b = b < 0 ? b : -b;
        //快速相减
        int quotient = 0;
        while (a <= b){
            int base = 1;
            int divisor = b;
            //使用减法, 避免溢出
            while (a - divisor <= divisor){
                divisor <<= 1; // 左移1位相当于乘 2
                base <<= 1;
            }
            quotient += base;
            a -= divisor;
        }
        return positive ? quotient : -quotient;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        int res = divide(a, b);
        System.out.println(res);
    }
}
