package JianZhiOffer2;

import java.util.Scanner;

public class Offer2_002 {
    /*
    不够健壮
     */
//    public static String addBinary(String a, String b) {
//        return Integer.toBinaryString(
//                Integer.parseInt(a, 2) + Integer.parseInt(b, 2)
//        );
//    }

    /*
    舶来主义
     */
    public static String addBinary(String a, String b) {
        StringBuilder sb=new StringBuilder();
        int i=a.length()-1,j=b.length()-1,c=0;
        while(i>=0||j>=0||c!=0){
            int ii=i>=0?a.charAt(i--)-'0':0;
            int jj=j>=0?b.charAt(j--)-'0':0;
            c=ii+jj+c;
            sb.append(c%2);
            c/=2;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.nextLine();
        String b = sc.nextLine();

        String res = addBinary(a, b);
        System.out.println(res);
    }
}
