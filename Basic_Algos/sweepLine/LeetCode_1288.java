package Basic_Algos.sweepLine;

import java.util.Arrays;

public class LeetCode_1288 {
    public static int removeCoveredIntervals(int[][] intervals) {
        if (intervals.length == 0 || intervals.length == 1){
            return intervals.length;
        }

        int count = 0;
        int cur = 0;

        // start time increasing, end time decreasing
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);

        for (int [] ints : intervals){
            if (cur < ints[1]){ // 比较end time
                cur = ints[1];
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
//        int[][] intervals = {{1,4},{3,6},{2,8}};
        int[][] intervals = {{1,2},{1,4},{3,4}};

        int res = removeCoveredIntervals(intervals);

        System.out.println(res);
    }
}
