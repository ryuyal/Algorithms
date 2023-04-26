package LeetCodeHot100.Hot1to10;

import java.util.Arrays;
import java.util.Scanner;

public class Hot10_19 {
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
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode newHead = new ListNode(0, head);

        ListNode first = head;
        for (int i = 0; i < n; ++i){
            first = first.next;
        }
//        System.out.println(first.val);

        ListNode pre = newHead;
        while(first != null){
            pre = pre.next;
            first = first.next;
        }
//        System.out.println(pre.val);

        pre.next = pre.next.next;

        return newHead.next;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int [] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int n = sc.nextInt();

        ListNode head = new ListNode();
        ListNode pre = head;
        for (int num : nums){
            pre.next = new ListNode(num);
            pre = pre.next;
        }

        ListNode res = removeNthFromEnd(head.next, n);

        while(res != null){
            System.out.println(res.val);
            res = res.next;
        }
    }
}
