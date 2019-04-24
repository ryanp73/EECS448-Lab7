#include "LinkedListOfInts.h"
#include "Test.h"
#include <iostream>

Test::Test() 
{
    resetList();
    buglist.open("buglist.txt");
}

Test::~Test()
{
    buglist.close();
    if (testList != nullptr)
    {
        delete testList;
    }
}

void Test::writeBug(std::string bug) 
{
    buglist << bug;
}

void Test::resetList()
{
    if (testList != nullptr)
    {
        delete testList;
    }
    testList = nullptr;
}

void Test::runAllTests()
{
    testIsEmpty();
}

void Test::testConstructor() 
{
    resetList();
    testList = new LinkedListOfInts();

    if (!testList->isEmpty())
    {
        writeBug("Constructor should create an empty list.");
    }    
}

void Test::testIsEmpty()
{
    resetList();
    testList = new LinkedListOfInts();

    // Checks if list isEmpty on construction
    if (!testList->isEmpty())
    {
        writeBug("isEmpty() returns false when given empty list.");
    }

    testList->addBack(10);

    if (testList->isEmpty())
    {
        writeBug("isEmpty() returns true when given non-empty list.");
    }
}

void Test::testConstructor() 
{
    resetList();
    testList = new LinkedListOfInts();
    
    std::vector<int> testVec = testList->toVector();

    if (!testVec.empty()) 
    {
        writeBug("Constructor should create an empty list.");
    }
}

void Test::testDestructor()
{
    // TODO: Not sure how to test this
    resetList();
}

void Test::testSize()
{
    LinkedListOfInts testList;

    if (!testList.size() != 0) 
    {
        writeBug("size() should be 0 upon instantiation.");
    }

    testList.addBack(10);

    if (!testList.size() != 1)
    {
        writeBug("size() should be 1 after an element is added.");
    }
}

void Test::testAddBack()
{
    int length = testList->toVector().size();

    testList->addBack(73);

    if (testList->size() - length != 1)
    {
        writeBug("addBack() should increase the size of the list by 1.");
    }

    if (testList->toVector().back() != 73)
    {
        writeBug("addBack() should add a value to ");
    }

}

