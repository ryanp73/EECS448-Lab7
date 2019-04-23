#include "LinkedListOfInts.h"
#include "Test.h"
#include <iostream>

Test::Test() 
{
    buglist.open("buglist.txt");
}

Test::~Test()
{
    buglist.close();
}

void Test::writeBug(std::string bug) 
{
    buglist << bug;
}

void Test::runAllTests()
{
    testIsEmpty();
}

void Test::testConstructor() 
{
    LinkedListOfInts testList;

}

void Test::testIsEmpty()
{
    // Create empty list
    LinkedListOfInts testList;
    
    // Checks if list isEmpty on construction
    if (!testList.isEmpty())
    {
        writeBug("isEmpty() returns false when given empty list.");
    }

    testList.addBack(10);

    if (testList.isEmpty())
    {
        writeBug("isEmpty() returns true when given non-empty list.");
    }
}