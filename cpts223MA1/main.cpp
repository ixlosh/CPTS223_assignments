// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

//Poor design choices
//1. First big one is related to how functions are defined under header file.
//This makes so that if that header file is included twice in the program
//(like this one) will lead to multiple definitions and program will not run.
//(I had to spend some time to figure this out and made the definitions inline insted.)
//2.Using "namespace std" should generally be avoided becuase it may sometimes
//cause unexpected/wanted behaviour
//3. Making dequeue function return a boolean value might be useful to further
// check if the operation was successful or not
//4.Printing "underflow" to terminal with functions such as peek is not
// good design. these functions should only return intended values.
// This might especially be a problem when they are called mid-sentence.
//5. Making single line functions actually single line would help with
// the readability of the code (like simply using ; in a single line instead of
//stretching the code and using {})

#include "queue.h"
#include "testQueue.h"

// main function
int main()
{
    // call your test functions here!
    queueSizeTest();
    queueEmptinessTest();
    queueFullnessTest();
    dequeueTestOnNonEmpty();
    dequeueTestOnEmpty();
    enqueueTestOnNonEmpty();
    enqueueTestOnEmpty();
    peekTestOnNonEmpty();
    peekTestOnEmpty();


    return 0;
}