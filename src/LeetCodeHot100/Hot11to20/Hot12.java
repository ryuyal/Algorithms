package LeetCodeHot100.Hot11to20;

import java.util.Arrays;
import java.util.Scanner;

/*
Hot100题单中的题号为21
 */
public class Hot12 {
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
    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode();
        ListNode pre = head;
        while(list1 != null && list2 != null){

            if (list1.val <= list2.val){
                pre.next = new ListNode(list1.val);
                pre = pre.next;
                list1 = list1.next;
            }else{
                pre.next = new ListNode(list2.val);
                pre = pre.next;
                list2 = list2.next;
            }
        }
        if (list1 != null){
            pre.next = list1;
        }
        if (list2 != null){
            pre.next = list2;
        }

        return head.next;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] list1 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int[] list2 = Arrays.stream(
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

        ListNode res = mergeTwoLists(head1.next, head2.next);

        while(res != null){
            System.out.println(res.val);
            res = res.next;
        }

    }
}
