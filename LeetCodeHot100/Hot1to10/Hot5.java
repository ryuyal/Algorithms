package LeetCodeHot100.Hot1to10;

import java.util.Scanner;

public class Hot5 {
    /*
    方法一: 暴力解
    超出时间限制
     */
    public static boolean isPalindrome(String s, int start, int end){
        while(start < end){
            if (s.charAt(start) != s.charAt(end)){
                return false;
            }else{
                start++;
                end--;
            }
        }
        return true;
    }
    public static String longestPalindromeOne(String s) {
        int maxLen = 0;
        String res = "";
        for (int i = 0; i < s.length(); i++){
            for (int j = 0; j < s.length(); j++ ){
                if (isPalindrome(s, i, j) && j-i+1 > maxLen){
                    maxLen = j-i+1;
                    res = s.substring(i, j+1);
                }
            }
        }
        return res;
    }

    /*
    中心扩展法
     */
    public static String longestPalindrome(String s){
        if (s.isEmpty()){
            return "";
        }

        int maxLen = 0;
        String res;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); ++i){
            int left = i, right = i;
            /*
            首先要找到中间有连续重复子字符串的边界
            eg: cbbd
             */
            while(left > 0 && s.charAt(left-1) == s.charAt(left)){
                left--;
            }
            while(right < s.length()-1 && s.charAt(right) == s.charAt(right+1)){
                right++;
            }

            while(left >= 0 && right < s.length() && s.charAt(left)==s.charAt(right)){
                left--;
                right++;
                if (right - left - 1 > maxLen){
                    maxLen = right - left -1;
                    start = left+1;
                    end = right-1;
                }
            }

        }
        return s.substring(start, end+1);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        String res = longestPalindrome(s);
        System.out.println(res);
    }
}
