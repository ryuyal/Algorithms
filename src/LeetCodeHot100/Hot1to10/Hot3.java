package LeetCodeHot100.Hot1to10;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Hot3 {
    public static int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>(); // 存放字符及其下标
        int maxLen = 0;
        int newStart = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);

            if (map.isEmpty()){
                map.put(ch, i);
                maxLen = 1;
            }else{
                if (!map.containsKey(ch)){
                    map.put(ch, i);
                }else{
                    newStart = Math.max(map.get(ch)+1, newStart);
                    map.put(ch, i);
                }
            }
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
