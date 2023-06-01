package LeetCodeHot100.Hot1to10;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
Hot100题单中的题号为 17
 */
public class Hot9 {
    public static List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        res.add("");

        String[] map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (int i = 0; i < digits.length(); ++i){
            int num = Integer.parseInt(digits.substring(i, i+1));

            int len = res.size();

            for (int j = 0; j < len; ++j){

                String ch  = res.remove(0); // 取出res中的元素

                for (int k = 0; k < map[num].length(); ++k){
                    res.add(ch + map[num].charAt(k));
                }
            }
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String digits = sc.nextLine();

        List<String> res = letterCombinations(digits);
        for (String s : res){
            System.out.println(s);
        }
    }
}
