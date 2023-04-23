package LeetCodeHot100.Hot1to10;

public class Hot2 {
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    /*
    最开始想到的方法
     */
    public static ListNode addTwoNumbersOne(ListNode l1, ListNode l2) {
        int sum1 = 0;
        int sum2 = 0;
        int n = 1;

        while(l1 != null){
            sum1 += l1.val * n;
            n *= 10;
            l1 = l1.next;
        }
//        System.out.println(sum1);

        n = 1;
        while(l2 != null){
            sum2 += l2.val * n;
            n *= 10;
            l2 = l2.next;
        }
//        System.out.println(sum2);

        int sum = sum1 + sum2;
        if (sum == 0){
            return new ListNode(0);
        }
        ListNode res = new ListNode();
        ListNode h = res;
        while(sum != 0){
            ListNode tmp = new ListNode(sum % 10);
            sum /= 10;
            h.next = tmp;
            h = h.next;
        }

        return res.next;
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2){
        ListNode head = new ListNode();
        int flag = 0; // flag 代表进位

        ListNode l = head;
        while(l1 != null && l2 != null){
            int s = l1.val + l2.val + flag;
            ListNode tmp = new ListNode();
            if (s < 10){
                tmp.val = s;
                flag = 0;
            }else{
                tmp.val = s % 10;
                flag = 1;
            }
            l.next = tmp;
            l = l.next;
            l1 = l1.next;
            l2 = l2.next;
        }

        while(l1 != null){
            int s = l1.val + flag;
            ListNode tmp = new ListNode();
            if (s < 10) {
                tmp.val = s;
                flag = 0;
            }else{
                tmp.val = s % 10;
                flag = 1;
            }
            l.next = tmp;
            l = l.next;
            l1 = l1.next;
        }

        while(l2 != null){
            int s = l2.val + flag;
            ListNode tmp = new ListNode();
            if (s < 10) {
                tmp.val = s;
                flag = 0;
            }else{
                tmp.val = s % 10;
                flag = 1;
            }
            l.next = tmp;
            l = l.next;
            l2 = l2.next;
        }

        if (flag == 1){
            l.next = new ListNode(1);
        }

        return head.next;

    }
    public static void main(String[] args) {
        System.out.println("This is LeetCode Hot100-2!!!");
        System.out.println("Good Luck!");

        ListNode h1 = new ListNode(2);
        ListNode h2 = new ListNode(4);
        ListNode h3 = new ListNode(3);
        h1.next = h2;
        h2.next = h3;

        ListNode s1 = new ListNode(5);
        ListNode s2 = new ListNode(6);
        ListNode s3 = new ListNode(4);
        s1.next = s2;
        s2.next = s3;

//        ListNode res = new ListNode();

        ListNode res = addTwoNumbers(h1, s1);

        while(res != null){
            System.out.println(res.val);
            res = res.next;
        }
    }
}
