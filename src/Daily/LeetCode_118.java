package Daily;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class LeetCode_118 {
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();

        for (int i = 0; i < numRows; i++){
            List<Integer> tmp = new ArrayList<>();
            for (int j = 0; j < i+1; j++){
                if (j == 0 || j == i){
                    tmp.add(1);
                }else{
//                    row.add(ret.get(i - 1).get(j - 1) + ret.get(i - 1).get(j));
                    tmp.add(res.get(i-1).get(j-1) + res.get(i-1).get(j));
                }
            }
            res.add(tmp);
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numRows = sc.nextInt();

        List<List<Integer>> res = generate(numRows);

        for(List<Integer> list : res){
            for (int num : list){
                System.out.print(num + " ");
            }
            System.out.println();
        }

    }
}
