package JianZhiOffer2;

import java.util.Scanner;

public class Offer2_018 {
    public static boolean isLetterDigit(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A') || (ch >= '0' && ch <= '9') ){
            return true;
        }
        return false;
    }
    public static boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length()-1;

        while(left < right){
            // 先找到第一个left和right为英文或数字字符
            while ((left < right) && !isLetterDigit(s.charAt(left))){
                left++;
            }
            while((left < right) && !isLetterDigit(s.charAt(right))){
                right--;
            }

            if (Character.toUpperCase(s.charAt(left)) != Character.toUpperCase(s.charAt(right))){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        boolean res = isPalindrome(s);
        System.out.println(res);
    }
}
