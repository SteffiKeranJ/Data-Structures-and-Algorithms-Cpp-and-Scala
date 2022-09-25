/**
622. Design Circular Queue
Link: https://leetcode.com/problems/design-circular-queue

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

    MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    int Front() Gets the front item from the queue. If the queue is empty, return -1.
    int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
    boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
    boolean isEmpty() Checks whether the circular queue is empty or not.
    boolean isFull() Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language. 

*/
class MyCircularQueue(_k: Int) {
    val circularQueue = new Array[Int](_k)
    var front:Int = -1
    var rear:Int = -1
    val capacity:Int = _k
    

    def enQueue(value: Int): Boolean = {
        if(isFull) return false; 
        if(front == -1){
            front = 0;
            rear = 0;
            circularQueue(rear) = value
            return true;
        }
        rear = next(rear);
        circularQueue(rear) = value
        return true;
    }

    def deQueue(): Boolean = {
        if(isEmpty) return false        
        if(front == rear){
            front = -1;
            rear = -1;
            return true;
        }
        front = next(front)
        return true;
    }
    def Front(): Int = if (isEmpty) -1 else circularQueue(front)
    
    def Rear(): Int = if (rear == -1) -1 else circularQueue(rear)

    def isEmpty(): Boolean = front == -1

    def isFull(): Boolean = front != -1 && next(rear) == front;
    
    private def next(ptr: Int): Int = (ptr+1)%capacity

}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */
