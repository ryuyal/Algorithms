package JianZhiOffer.medium;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Offer48 {
    public static int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> hashMap = new HashMap<>();
        int maxLen = 0;
        int newStart = 0;

        for (int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);

            if (hashMap.isEmpty()){
                maxLen = 1;
            }else if (hashMap.containsKey(ch)){
                newStart = Math.max(newStart, hashMap.get(ch)+1);
            }

            hashMap.put(ch, i);
            maxLen = Math.max(maxLen, i - newStart + 1);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        int res = lengthOfLongestSubstring(s);
        System.out.println(res);
    }
}
