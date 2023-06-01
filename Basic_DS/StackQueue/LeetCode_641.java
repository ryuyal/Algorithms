package Basic_DS.StackQueue;

public class LeetCode_641 {
    static class MyCircularDeque {

        int[] deque;
        int front, rear, size, capacity;
        public MyCircularDeque(int k) {
            deque = new int[k];
            size = 0;
            front = 0;
            rear = -1;
            capacity = k;
        }

        public boolean insertFront(int value) {
            if (isFull()){
                return false;
            }

            if (--front < 0){
                front += capacity;
            }
            deque[front] = value;
            size++;
            if (size == 1){ // 只有一个元素的时候
                rear = front;
            }
            return true;
        }

        public boolean insertLast(int value) {
            if (isFull()){
                return false;
            }

            rear = (rear+1) % capacity;
            deque[rear] = value;
            size++;
            return true;
        }

        public boolean deleteFront() {
            if (isEmpty()){
                return false;
            }

            front = (front+1) % capacity;
            size--;
            return true;
        }

        public boolean deleteLast() {
            if (isEmpty()){
                return false;
            }

            if (--rear < 0){
                rear += capacity;
            }
            size--;
            return true;
        }

        public int getFront() {
            return isEmpty() ? -1 : deque[front];
        }

        public int getRear() {
            return isEmpty() ? -1 : deque[rear];
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public boolean isFull() {
            return size == capacity;
        }
    }

    public static void main(String[] args) {

        MyCircularDeque circularDeque = new MyCircularDeque(3); // 设置容量大小为3
        circularDeque.insertLast(1);			        // 返回 true
        circularDeque.insertLast(2);			        // 返回 true
        circularDeque.insertFront(3);			        // 返回 true
        circularDeque.insertFront(4);			        // 已经满了，返回 false
        circularDeque.getRear();  				// 返回 2
        circularDeque.isFull();				        // 返回 true
        circularDeque.deleteLast();			        // 返回 true
        circularDeque.insertFront(4);			        // 返回 true
        circularDeque.getFront();				// 返回 4
    }
}
