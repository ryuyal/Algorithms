package JianZhiOffer2;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Offer2_032 {
    public static boolean isAnagram2(String s, String t){
        if (s.length() != t.length() || s.equals(t)){
            return false;
        }
        // 字符串s和t，分别转换为字符数组arr1和arr2;
        char[] arr1 = s.toCharArray();
        char[] arr2 = t.toCharArray();
        // 对于字符数组arr1和arr2进行排序，若是排序后的结果是一样的话，则代表其为一组变位词;
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        return Arrays.equals(arr1 , arr2);
    }

    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length() || s.equals(t)){
            return false;
        }

        HashMap<Character, Integer> sMap = new HashMap<>();

        for (char ch : s.toCharArray()){
            sMap.put(ch, sMap.getOrDefault(ch, 0)+1);
        }

        for (char ch : t.toCharArray()){
            if (sMap.containsKey(ch) && sMap.get(ch) >= 1){
                sMap.put(ch, sMap.get(ch)-1);
            }else{
                return false;
            }
        }
        return s.length() == t.length();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        String t = sc.nextLine();

        boolean res = isAnagram(s, t);

        System.out.println(res);
    }
}
