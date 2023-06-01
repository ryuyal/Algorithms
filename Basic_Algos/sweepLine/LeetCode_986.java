package Basic_Algos.sweepLine;

import java.util.ArrayList;
import java.util.List;

public class LeetCode_986 {
    public static int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> res = new ArrayList<>();
        int i = 0, j = 0;

        while(i < firstList.length && j < secondList.length){
            int low = Math.max(firstList[i][0], secondList[j][0]); // 较晚的开始时间
            int high = Math.min(firstList[i][1], secondList[j][1]); // 较早的结束时间

            if(low <= high){ // 说明有overlapping
                res.add(new int[]{low, high});
            }
            if (firstList[i][1] < secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return res.toArray(new int[res.size()][]);
    }
    public static void main(String[] args) {
        int[][] firstList = {{0,2},{5,10},{13,23},{24,25}};
        int[][] secondList = {{1,5},{8,12},{15,24},{25,26}};

        int[][] res = intervalIntersection(firstList, secondList);

        for (int[] nums : res){
            System.out.print("[");
            for (int num : nums){
                System.out.print(num + " ");
            }
            System.out.print("] ");
        }
    }
}
