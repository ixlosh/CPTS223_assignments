
#include "testSeparateChaining.h"
#include "testLinearProbing.h"

// using namespace std;


void testChainingHash()
{
    ChainingHash<Employee> employeeChainingHash;
    initializeHash(employeeChainingHash);
    testInsertToHash(employeeChainingHash);
    testRemoveFromHash(employeeChainingHash);
    testRehash(employeeChainingHash);
}

void testProbingHash()
{
    ProbingHash<Employee> employeeProbingHash;
    initializeHash(employeeProbingHash);
    testInsertToHash(employeeProbingHash);
    testRemoveFromHash(employeeProbingHash);
    testRehash(employeeProbingHash);
}

int main()
{
    testChainingHash();
    std::cout << std::endl;
    testProbingHash();

    return 0;
}
