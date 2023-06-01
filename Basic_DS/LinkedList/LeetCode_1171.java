package Basic_DS.LinkedList;

import javax.swing.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LeetCode_1171 {
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

    /*
    prefix sum 下标为n的位置保存 前0—n个元素的和
    如果两点间的prefix sum相同, 那么说明这两点间的元素之和为0
     */
    public static ListNode removeZeroSumSublists(ListNode head) {
        ListNode newHead = new ListNode();
        newHead.next = head;
        int prefix = 0;

        Map<Integer, ListNode> map = new HashMap<>();

        ListNode tmp = newHead;
        while(tmp != null){
            prefix += tmp.val;
            map.put(prefix, tmp);
            tmp = tmp.next;
        }

        prefix = 0;

        ListNode pre = newHead;

        while(pre != null){
            prefix += pre.val;
            pre.next = map.get(prefix).next;
            pre = pre.next;
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

        ListNode res = removeZeroSumSublists(head.next);

        while(res != null){
            System.out.print(res.val + "->");
            res = res.next;
        }
    }
}
