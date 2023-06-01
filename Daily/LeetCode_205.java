package Daily;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LeetCode_205{
    public static boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }

        return mapping(s, t) && mapping(t, s);
    }

    public static boolean mapping(String s, String t){
        Map<Character, Character> hashMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++){
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);

            if (hashMap.isEmpty()){
                hashMap.put(ch1, ch2);
            }else{
                if (hashMap.containsKey(ch1)){
                    if (hashMap.get(ch1) != ch2){
                        return false;
                    }
                }
                hashMap.put(ch1, ch2);
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();

        boolean res = isIsomorphic(s, t);

        System.out.println(res);
    }
}
