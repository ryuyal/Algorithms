package LeetCodeHot100.Hot11to20;

import java.util.List;
import java.util.Scanner;

public class Hot13_22 {
    public static List<String> generateParenthesis(int n) {
        return null;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        List<String> res = generateParenthesis(n);

        for (String s : res){
            System.out.println(s);
        }
    }
}
