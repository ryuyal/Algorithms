package Basic_Algos.sweepLine;

import java.util.*;

/*
给定会议的开始时间和结束时间 判断最少需要几个会议室
 */
public class LeetCode_253 {
    static class Interval {
        int start, end;
        Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
    public static int minMeetingRooms1(int[][] intervals){
        Arrays.sort(intervals, (a, b)-> a[0] - b[0]); // 按开始时间升序

        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b)->a[1]-b[1]); // 按结束时间 从小到大排序
        if (intervals.length != 0){
            heap.offer(intervals[0]);
        }

        for (int i = 1; i < intervals.length; ++i){
            int[] cur = heap.poll();
            if (cur[1] <= intervals[i][0]){ // heap中最早的结束时间 小于 当前遍历到的会议的开始时间
                cur[0] = intervals[i][0]; // 加不加都可
                cur[1] = intervals[i][1];
            }else{
                heap.offer(intervals[i]);
            }
            heap.offer(cur);
        }

        return heap.size();
    }
    public static int minMeetingRooms(int[][] intervals){
        List<int[]> list = new ArrayList<>();

        for (int[] interval : intervals){
            list.add(new int[]{interval[0], 1}); // 会议开始时间
            list.add(new int[]{interval[1], -1}); // 会议结束时间
        }

        for (int[] l : list){
            System.out.print(Arrays.toString(l));
        }
        System.out.println();

        Collections.sort(list, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]); // 如果时间相同 结束排在前面

        System.out.println("After sort");
        for (int[] l : list){
            System.out.print(Arrays.toString(l) + " ");
        }
        System.out.println();

        int res = 0;
        int count = 0;

        for (int[] tmp : list){
            count += tmp[1];

            if (count > res){
                res = count;
            }
        }
        return res;

    }

    public static int minMeetingRooms2(int[][] intervals){
        int[] starts = new int[intervals.length];
        int[] ends = new int[intervals.length];
        for(int i = 0; i < intervals.length; i++){
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        Arrays.sort(starts);
        Arrays.sort(ends);

        int room = 0;
        int end = 0;

        for (int i = 0; i < starts.length; i++){
            if (starts[i] < ends[end]){
                room++;
            }else{
                end++;
            }
        }
        return room;
    }
    public static void main(String[] args) {
//        int[][] intervals = {{0, 30}, {5, 10}, {15, 20}};
        int[][] intervals = {{1, 10}, {2, 7}, {3, 19}, {8, 12}, {10, 20}, {11, 30}};

//        int res = minMeetingRooms(intervals);
//        int res2 = minMeetingRooms1(intervals);
        int res3 = minMeetingRooms2(intervals);

//        System.out.println(res);
//        System.out.println(res2);
        System.out.println(res3);
    }
}
