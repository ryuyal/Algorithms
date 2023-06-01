package Basic_DS.LinkedList;

import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_234 {
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

    public static boolean isPalindrome(ListNode head) {
        ListNode midNode = findMidNode(head);
        ListNode secondHalfStart = reverse(midNode.next);

        ListNode p1 = head;
        ListNode p2 = secondHalfStart;

        while(p2 != null){
            if (p1.val != p2.val){
                return false;
            }

            p1 = p1.next;
            p2 = p2.next;
        }

        return true;

    }

    // 快慢指针找出链表的中间节点
    public static ListNode findMidNode(ListNode head){
        ListNode slow = head;
        ListNode fast = head;

        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    // 翻转后一半节点

    public static ListNode reverse(ListNode head){
        ListNode pre = null;
        while(head != null){
            ListNode next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }

        return pre;
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

        boolean res = isPalindrome(head.next);

        System.out.println(res);
    }
}
