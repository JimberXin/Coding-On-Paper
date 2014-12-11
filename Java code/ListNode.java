import java.util.List;

/**
 * Created by JimberXin on 14/12/11.
 */
public class ListNode {
    private int value;
    private ListNode next;

    public ListNode(){
        value = -1;
        next = null;
    }

    public ListNode(int x){
        value = x;
        next = null;
    }

    public static ListNode InsertHead(ListNode head, int x){
        ListNode node = new ListNode(x);
        if(head == null)
            head = node;
        else{
            node.next = head;
            head = node;
        }
        return head;
    }

    public static ListNode InsertTail(ListNode head,int x){
        ListNode node = new ListNode(x);
        if(head == null)
            head = node;
        else{
            ListNode p = head;
            while(p.next != null)
                p = p.next;
            p.next = node;
        }
        return head;
    }


    public static ListNode reverseList(ListNode head){
        if(head==null || head.next == null)
            return head;
        ListNode pre = null;
        ListNode cur = head;
        ListNode nex;
        while(cur!=null){
            nex = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }

    public static ListNode deleteList(ListNode head, ListNode toBeDeleted){
        if(head == null)
            return null;
        if(toBeDeleted.next != null){
            toBeDeleted.value = toBeDeleted.next.value;
            toBeDeleted.next = toBeDeleted.next.next;
        }else{
            ListNode p = head;
            while(p.next != null && p.next != toBeDeleted)
                p = p.next;
            p.next = null;
        }
        return head;
    }

    public static boolean hasCycle(ListNode head){
        if(head == null || head.next == null)
            return false;
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
                return true;
        }
        return false;
    }

    public static ListNode CycleBegin(ListNode head){
        if(head == null || head.next == null)
            return head;
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
                break;
        }
        if(fast == null || fast.next == null)
            return null;
        slow = head;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        return fast;
    }

    public static ListNode merge_sort(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && fast.next !=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode first = head;
        ListNode second = slow.next;
        slow.next = null;
        ListNode newhead = merge(merge_sort(first), merge_sort(second));
        return newhead;
    }

    public static ListNode merge(ListNode head1, ListNode head2){
        if(head1 == null) return head2;
        if(head2 == null) return head1;
        ListNode dummy = new ListNode();
        ListNode p = dummy;
        while(head1 != null && head2 != null){
            if(head1.value < head2.value){
                p.next = head1;
                head1 = head1.next;
            }else{
                p.next = head2;
                head2 = head2.next;
            }
            p = p.next;
        }//end for while
        if(head1 != null) p.next = head1;
        if(head2 != null) p.next = head2;
        return dummy.next;
    }

    public static void main(String[] args){
        int[] arr = {2,1,14,23,11,29,20,-21,-8,19,7,6};
        ListNode dummy = new ListNode();
        ListNode p = dummy;
        for(int i=0;i<arr.length;++i){
            ListNode tempNode = new ListNode();
            tempNode.value = arr[i];
            p.next = tempNode;
            p = p.next;
        }
        p.next = null;
        ListNode newhead = merge_sort(dummy.next);
        p = newhead;
        while(p != null){
            System.out.print(p.value + " ");
            p = p.next;
        }


    }

}
