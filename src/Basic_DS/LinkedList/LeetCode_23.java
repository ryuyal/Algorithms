package Basic_DS.LinkedList;

import LeetCodeHot100.Hot11to20.Hot12;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class LeetCode_23 {
    static class ListNode{
        int val;
        ListNode next;

        ListNode(){}
        ListNode(int val){
            this.val = val;
        }
        ListNode(int val, ListNode next){
            this.val = val;
            this.next = next;
        }
    }

    public static ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode(0);
//        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        // 效果同上
        PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                return o1.val - o2.val;
            }
        });
//        System.out.println("Len: " + lists.length);
//        return null;
        // 酱所有的元素加到 pq中
        for (int i = 0; i < lists.length; i++){
            ListNode tmp = lists[i];

            while(tmp != null){
                pq.offer(tmp);
                tmp = tmp.next;
            }
        }

//        System.out.println(pq.size());

//        while( !pq.isEmpty()){
//            System.out.println(pq.poll().val);
//        }

//        return null;

        ListNode pre = dummy;

        while(!pq.isEmpty()){
            pre.next = new ListNode(pq.poll().val);
            pre = pre.next;
        }

//        while(dummy != null){
//            System.out.print(dummy.val + "->");
//            dummy = dummy.next;
//        }

        return dummy.next;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] list1 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int[] list2 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int[] list3 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        ListNode head1 = new ListNode();
        ListNode pre = head1;
        for (int num : list1) {
            pre.next = new ListNode(num);
            pre = pre.next;
        }


        ListNode head2 = new ListNode();
        pre = head2;
        for (int num : list2){
            pre.next = new ListNode(num);
            pre = pre.next;
        }

        ListNode head3 = new ListNode();
        pre = head3;
        for (int num : list3){
            pre.next = new ListNode(num);
            pre = pre.next;
        }

        ListNode[] lists = new ListNode[] {head1.next, head2.next, head3.next};

        ListNode res = mergeKLists(lists);

        while(res != null){
            System.out.print(res.val + "->");
            res = res.next;
        }
    }
}
