package LeetCodeHot100.Hot11to20;

import java.util.Scanner;
import java.util.Stack;

/*
Hot100题单中的题号为20
 */
public class Hot11 {
    public static boolean isMatch(char c1, char c2){
        if (c1 == '(' && c2 == ')'){
            return true;
        }
        if (c1 == '{' && c2 == '}'){
            return true;
        }
        if (c1 == '[' && c2 == ']'){
            return true;
        }
        return false;
    }
    public static boolean isValid(String s) {
        Stack<Character> sta = new Stack<>();

        for (int i = 0; i < s.length(); ++i){
            char ch = s.charAt(i);
            if (sta.empty()){
                sta.push(ch);
            }else{
                if (isMatch(sta.peek(), ch)){
                    sta.pop();
                }else{
                    sta.push(ch);
                }
            }
        }
        return sta.empty();
    }
    public static void main(String[] args) {
        System.out.println("This is LeetCode Hot100-11!!!");
        System.out.println("Good Luck!");

        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        boolean res = isValid(s);
        System.out.println(res);
    }
}
