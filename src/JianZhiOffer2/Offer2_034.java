package JianZhiOffer2;

import java.util.Arrays;
import java.util.Scanner;

public class Offer2_034 {
    public static boolean isAlienSorted(String[] words, String order) {
        int[] arr = new int[26];

        for (int i = 0; i < 26; ++i){
            arr[order.charAt(i) - 'a'] = i; // arr数组存储字母对应的优先级
        }

        for (int i = 1; i < words.length; ++i){
            boolean flag = false;
            String preStr = words[i-1];
            String curStr = words[i];

            for (int j = 0; j < preStr.length() && j < curStr.length(); ++j){
                if (arr[preStr.charAt(j)-'a'] > arr[curStr.charAt(j)-'a']){ // 若前一个单词的优先级更小
                    return false;
                }else if (arr[preStr.charAt(j)-'a'] < arr[curStr.charAt(j)-'a']){ // 前一个单词的优先级更大
                    flag = true;
                    break;
                }
                // else 的情况：两者当前位置的字母相同
            }

            if (!flag){
                return preStr.length() <= curStr.length();
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String [] words = sc.nextLine().split(" ");

        String order = sc.nextLine();

        boolean res = isAlienSorted(words, order);

        System.out.println(res);
    }
}
