#include "queue.h"
#include "testQueue.h"

/* Test ID: Queue size check - QSC
Unit: queue::size()
Description: test to determine if queue::size() returns 4 if a queue object
has 4 integers stored.
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue 4 times with any integer
3. Invoke queue::size()
4. Conditionally evaluate the value returned by queue::size()
Test data: size = 4
Precondition: queue object has 4 integers
Postcondition: queue object still has 4 integers
Expected result: 4 is returned
Actual result: 5 is returned, 1 more than expected
Status: failed
*/
void queueSizeTest() {

    queue testQueue;
    for (int i=0;i<4;i++) testQueue.enqueue(7);
    cout <<"Size value:"<<testQueue.size()<<endl;

}
/* Test ID: Empty queue check - EQC
Unit: queue::isEmpty()
Description: test to determine if queue::isEmpty () returns 1 if a queue object
is empty.
Test steps:
1. Construct an empty queue object
2. Invoke queue::isEmpty()
3. Conditionally evaluate the value returned by queue::isEmpty ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty; true is returned
Actual result: queue is empty but false is returned
Status: failed
*/
void queueEmptinessTest() {

    queue testQueue;
    if (testQueue.isEmpty()) cout<<"success"<<endl;
    else cout <<"fail"<<endl;

}
/* Test ID: Queue full or not check
Unit: queue::isFull()
Description: test to determine if queue::isEmpty () returns 1 if a queue object
is empty.
Test steps:
1. Construct an empty queue object with max size 4
2. Invoke queue::enqueue 4 times with any integer
3. Invoke queue::isFull()
4. Conditionally evaluate the value returned by queue::isFull()
Test data: size = 4
Precondition: queue object has max size 4
Postcondition: queue object has max size 4 and has no empty space left
Expected result: true is returned
Actual result: false is returned
Status: failed
*/
void queueFullnessTest () {

    queue testQueue(4);
    for (int i=0;i<4;i++) testQueue.enqueue(7);
    if(testQueue.isFull()) cout<<"success"<<endl;
    else cout <<"fail"<<endl;

}

/* Test ID: Deueue on non empty queue
Unit: queue::dequeue()
Description: test to determine behaviour when queue::dequeue() is called on a
non empty queue.
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue 4 times with any integer
3. Invoke queue::dequeue() 4 times
4. Conditionally evaluate the boolean returned by queue::isEmpty
Precondition: queue object has 4 elements
Postcondition: queue object has no elements
Expected result: true is returned
Actual result: false is returned
Status: failed
*/
void dequeueTestOnNonEmpty() {

    queue testQueue;
    for (int i=0;i<4;i++) testQueue.enqueue(7);
    for (int m=0;m<4;m++) testQueue.dequeue();
    if (testQueue.isEmpty()) cout <<"success"<<endl;
    else cout <<"fail"<<endl;

}

/* Test ID: Deueue on empty queue
Unit: queue::dequeue()
Description: test to determine behaviour when queue::dequeue() is called on an
empty queue.
Test steps:
1. Construct an empty queue object
2. Invoke queue::dequeue()
3. Conditionally evaluate the boolean returned by queue::isEmpty
Precondition: queue object has no elements
Postcondition: queue object has no elements
Expected result: true is returned
Actual result: false is returned
Status: failed
*/
void dequeueTestOnEmpty() {

    queue testQueue;
    testQueue.dequeue();

}

/* Test ID: Enqueue on non empty queue
Unit: queue::enqueue()
Description: test to determine behaviour when queue::enqueue() is called on a
non empty queue.
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue() 4 times with any integer
3. Invoke queue::enqueue() 4 more times with any integer
4. Conditionally evaluate the boolean returned by queue::isEmpty
Precondition: queue object has 4 elements
Postcondition: queue object has 8 elements
Expected result: true is returned
Actual result: false is returned
Status: failed
*/
void enqueueTestOnNonEmpty() {

    queue testQueue;
    for (int i=0;i<4;i++) testQueue.enqueue(7);
    for (int m=0;m<4;m++) testQueue.enqueue(7);
    if (testQueue.size()==8) cout <<"success"<<endl;
    else cout <<"fail"<<endl;

}

/* Test ID: Enqueue on non empty queue
Unit: queue::enqueue()
Description: test to determine behaviour when queue::enqueue() is called on a
non empty queue.
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue() 4 times with any integer
3. Invoke queue::enqueue() 4 more times with any integer
4. Conditionally evaluate the boolean returned by queue::isEmpty
Precondition: queue object has 4 elements
Postcondition: queue object has 8 elements
Expected result: true is returned
Actual result: false is returned
Status: failed
*/
void enqueueTestOnEmpty() {

    queue testQueue;
    for (int i=0;i<4;i++) testQueue.enqueue(7);
    if (testQueue.size()==4) cout <<"success"<<endl;
    else cout <<"fail"<<endl;

}

/* Test ID: Peek test on non empty queue
Unit: queue::peek()
Description: test to determine behaviour when queue::peek() is called on a
non empty queue.
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue() 4 times with any integer
3. Invoke queue::peek to check last integer
Precondition: queue object has 4 elements
Postcondition: queue object has 4 elements
Expected result: last element correctly identified
Actual result: only able to identify the same element
Status: failed
*/
void peekTestOnNonEmpty() {

    queue testQueue;
    for (int i=0;i<4;i++) testQueue.enqueue(7);
    if (testQueue.peek()==7) cout <<"success"<<endl;
    else cout <<"fail"<<endl;


}

/* Test ID: Peek test on empty queue
Unit: queue::peek()
Description: test to determine behaviour when queue::peek() is called on an
empty queue.
Test steps:
1. Construct an empty queue object
3. Invoke queue::peek
Precondition: queue object has no elements
Postcondition: queue object has no elements
Expected result: exits because no element to identify
Actual result: exits because no element to identify
Status: passed
*/
void peekTestOnEmpty() {

    queue testQueue;
    testQueue.peek();

}