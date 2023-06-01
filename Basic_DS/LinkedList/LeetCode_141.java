package Basic_DS.LinkedList;

import LeetCodeHot100.Hot41to50.Hot50;

import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_141 {
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

    public static boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast){
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        ListNode head = new ListNode();
        ListNode pre = head;

        for (int num : nums){
            pre.next = new ListNode(num);
            pre = pre.next;
        }

        int pos = sc.nextInt();

        ListNode tail = pre;
        pre = head.next;
        if (pos != -1){
            for (int i = 0; i < pos; i++) {
                pre = pre.next;
            }
            tail.next = pre;
        }

        boolean res = hasCycle(head.next);
        System.out.println(res);
    }
}
