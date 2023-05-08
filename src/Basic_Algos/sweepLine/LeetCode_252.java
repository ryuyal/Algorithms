package Basic_Algos.sweepLine;

import java.util.*;

/*
给定会议的开始时间和结束时间 判断一个人是否可以参加所有的会议
 */
public class LeetCode_252 {
    static class Interval {
        int start, end;
        Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static boolean canAttendMeetings(Interval[] meetings){
        Arrays.sort(meetings, (a, b) -> a.start - b.start);
        for (int i = 0; i < meetings.length-1; ++i){
            if (meetings[i+1].start < meetings[i].end){ // 判断当前meeting的结束时间不能晚于后一个meeting的开始时间
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Interval[] meetings = new Interval[2];

        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 2; ++i){
            int s = sc.nextInt();
            int e = sc.nextInt();
            Interval meeting = new Interval(s, e);
            meetings[i] = meeting;
        }

        boolean res = canAttendMeetings(meetings);

        System.out.println(res);
    }
}
