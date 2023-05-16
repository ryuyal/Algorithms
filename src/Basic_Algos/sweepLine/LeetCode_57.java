package Basic_Algos.sweepLine;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode_57 {
    public static int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();

        for (int[] ints : intervals){
            if (newInterval == null || ints[1] < newInterval[0]){
                res.add(ints);
            }else if(ints[0] > newInterval[1]){
                res.addAll(List.of(newInterval, ints));
                newInterval = null;
            }else{
                newInterval[0] = Math.min(newInterval[0], ints[0]);
                newInterval[1] = Math.max(newInterval[1], ints[1]);
            }
        }
        if (newInterval != null){
            res.add(newInterval);
        }
        return res.toArray(new int[res.size()][]);
    }
    public static void main(String[] args) {
        int[][] intervals = {{1, 3}, {6, 9}};

        int[] newInterval = {2, 5};

        int[][] res = insert(intervals, newInterval);

        for (int[] r : res){
            System.out.print(Arrays.toString(r) + " ");
        }
    }
}
