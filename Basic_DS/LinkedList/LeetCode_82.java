package Basic_DS.LinkedList;

import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_82 {
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
        ListNode newHead = new ListNode();
        newHead.next = head;

        ListNode pre = newHead;
        ListNode cur = pre.next;

        while(cur != null && cur.next != null){
            if (cur.val == cur.next.val){
                int temp = cur.val;
                while(cur != null && temp == cur.val){ // 找到不是 val 的节点
                    cur = cur.next;
                }
                pre.next = cur;

            }else{
                pre = pre.next;
                cur = cur.next;
            }
        }

        return newHead.next;
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
