package JianZhiOffer2;

public class Offer2_027 {
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

    // 反转链表
    public static ListNode reverse(ListNode head){
        ListNode pre = null, cur = head;

        while(cur != null){
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }
    public static ListNode midNode(ListNode head){
        ListNode slow = head;
        ListNode fast = head;

        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }
    public static boolean isPalindrome(ListNode head) {
        ListNode mid = midNode(head);
        ListNode newH = reverse(mid.next);


        while(newH != null){
            if (head.val != newH.val){
                return false;
            }
            head = head.next;
            newH = newH.next;
        }
        return true;
    }

    public static void main(String[] args) {

    }
}
