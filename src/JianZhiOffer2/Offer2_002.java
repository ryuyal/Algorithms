package JianZhiOffer2;

import java.util.Scanner;

public class Offer2_002 {
    /*
    不够健壮
     */
    public static String addBinary(String a, String b) {
        return Integer.toBinaryString(
                Integer.parseInt(a, 2) + Integer.parseInt(b, 2)
        );
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.nextLine();
        String b = sc.nextLine();

        String res = addBinary(a, b);
        System.out.println(res);
    }
}
