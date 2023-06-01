package JianZhiOffer2;

import java.util.Scanner;

public class Offer2_019 {

    // 判断字符串是否为回文串
    public static boolean isPalidrome(String s, int left, int right){

        while(left < right){
            if (s.charAt(left) == s.charAt(right)){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }

    public static boolean validPalindrome(String s) {
        if(isPalidrome(s, 0, s.length()-1)){
            return true;
        }

        int left = 0, right = s.length()-1;
        while(left <= right){
            if (s.charAt(left) == s.charAt(right)){
                left++;
                right--;
            }else{
                return isPalidrome(s, left+1, right) || isPalidrome(s, left, right-1);
            }
        }

        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();
        boolean res = validPalindrome(str);

        System.out.println(res);
    }
}
