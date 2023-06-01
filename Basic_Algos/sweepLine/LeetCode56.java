package Basic_Algos.sweepLine;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode56 {
    public static int[][] merge(int[][] intervals) {
        List<int[]> res = new ArrayList<>();

        if (intervals == null || intervals.length==0){
            return new int[0][];
        }

        Arrays.sort(intervals, (a, b) -> a[0]-b[0]);
//        for (int[] r : intervals) {
//            System.out.print(Arrays.toString(r) + " ");
//        }
//        System.out.println();

        int[] cur = intervals[0];
        for (int[] inter : intervals){
            if (cur[1] >= inter[0]){ // 前一个的结束时间大于当前的开始时间（有重叠）
                cur[1] = Math.max(cur[1], inter[1]);
            }else{
                res.add(cur);
                cur = inter;
            }
        }
        res.add(cur);
        return res.toArray(new int[res.size()][]);

    }
    public static void main(String[] args) {
        int[][] intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

        int[][] res = merge(intervals);

        for (int[] r : res) {
            System.out.print(Arrays.toString(r) + " ");
        }
        System.out.println();
    }
}
