package JianZhiOffer2;

import java.util.Scanner;

public class Offer2_003 {
    /*
    奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
    偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。
        因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。
     */
    public static int[] countBits(int n) {
        int [] res = new int[n+1];
        for (int i = 0; i <= n; ++i){
            /*
            i&1 可以判断i为奇数还是偶数
            i>>1 相当于将i除以 2
             */
//            res[i] = res[i>>1] + (i&1);
            res[i] = res[i/2] + i % 2;
        }

        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int[] res = countBits(a);
        for (int num : res){
            System.out.println(num);
        }
    }
}
