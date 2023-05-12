package Basic_DS.LinkedList;

import java.util.Scanner;

public class LeetCode_206 {
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
    public static ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;

        while(cur != null){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ListNode root = new ListNode();
        ListNode pre = root;

        while(sc.hasNext()){
            int val = sc.nextInt();
            if (val == -1){
                break;
            }
            pre.next = new ListNode(val);
            pre = pre.next;
        }

        ListNode res = reverseList(root.next);

        while(res != null){
            System.out.print(res.val + "->");
            res = res.next;
        }
    }
}
