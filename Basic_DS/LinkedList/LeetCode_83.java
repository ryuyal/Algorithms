package Basic_DS.LinkedList;

import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_83 {
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
    public static ListNode deleteDuplicates(ListNode head) {

        ListNode pre = head;

        while(pre != null && pre.next != null){
            if (pre.val == pre.next.val){
                pre.next = pre.next.next;
            }else{
                pre = pre.next;
            }
        }
        return head;
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

        ListNode res = deleteDuplicates(head.next);

        while(res != null){
            System.out.print(res.val + "->");
            res = res.next;
        }
    }
}
