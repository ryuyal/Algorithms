package Basic_DS.StackQueue;

public class LeetCode_622 {
    static class MyCircularQueue {

        int[] queue;
        int front, rear, size;
        public MyCircularQueue(int k) {
            queue = new int[k];
            front = 0;
            rear = -1;
            size = 0;
        }

        public boolean enQueue(int value) {
            if (!isFull()){
                rear = (rear+1) % queue.length;
                queue[rear] = value;
                size++;
                return true;
            }
            return false;
        }

        public boolean deQueue() {
            if (!isEmpty()){
                front = (front+1) % queue.length;
                size--;
                return true;
            }
            return false;
        }

        public int Front() {
            return isEmpty() ? -1 : queue[front];
        }

        public int Rear() {
            return isEmpty() ? -1 : queue[rear];
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public boolean isFull() {
            return size == queue.length;
        }
    }

    public static void main(String[] args) {
        MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
        System.out.println(circularQueue.enQueue(1)); // 返回 true
        System.out.println(circularQueue.enQueue(2)); // 返回 true
        System.out.println(circularQueue.enQueue(3)); // 返回 true
        System.out.println(circularQueue.enQueue(4)); // 返回 false，队列已满
        System.out.println(circularQueue.Rear()); // 返回 3
        System.out.println(circularQueue.isFull()); // 返回 true
        System.out.println(circularQueue.deQueue()); // 返回 true
        System.out.println(circularQueue.enQueue(4)); // 返回 true
        System.out.println(circularQueue.Rear()); // 返回 4
    }
}
