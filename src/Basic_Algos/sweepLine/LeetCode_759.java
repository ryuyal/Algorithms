package Basic_Algos.sweepLine;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class LeetCode_759 {
    static class Interval{
        int start;
        int end;
        Interval(int start, int end){
            this.start = start;
            this.end = end;
        }
    }

    public static List<Interval> employeeFreeTime(List<List<Interval>> schedule){
        List<Interval> res = new ArrayList<>();

        PriorityQueue<Interval> pq = new PriorityQueue<>((a, b) ->(a.start - b.start));
        for (List<Interval> list : schedule){
            for (Interval interval : list){
                pq.add(interval);
            }
        }
        Interval cur = pq.poll();

        while(!pq.isEmpty()){
            if (cur.end >= pq.peek().start){ // 有overlapping
                cur.end = Math.max(cur.end, pq.poll().end);
            }else {
                res.add(new Interval(cur.end, pq.peek().start)); // 两个interval中间有空隙
                cur = pq.poll();
            }
        }
        return res;
    }
    public static void main(String[] args) {

    }
}
