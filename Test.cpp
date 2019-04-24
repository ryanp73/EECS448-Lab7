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
    buglist << bug << std::endl;
}

void Test::runAllTests()
{
    testConstructor();
    testDestructor();
    testSize();
    testIsEmpty();
    testAddFront();
    testRemoveFront();
    testAddBack();
    testRemoveBack();
}

void Test::testIsEmpty()
{
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

void Test::testConstructor() 
{
    LinkedListOfInts testList;
    
    std::vector<int> testVec = testList.toVector();

    if (!testVec.empty()) 
    {
        writeBug("Constructor should create an empty list.");
    }
}

void Test::testDestructor()
{
    // TODO: Not sure how to test this
}

void Test::testSize()
{
    LinkedListOfInts testList;

    if (testList.size() != 0) 
    {
        writeBug("size() should be 0 upon instantiation.");
    }

    testList.addBack(10);

    if (testList.size() != 1)
    {
        writeBug("size() should be 1 after an element is added.");
    }
}

void Test::testAddFront()
{
    LinkedListOfInts testList;

    testList.addFront(15);

    int length = testList.toVector().size();
    
    testList.addFront(42);

    if (testList.size() - length != 1)
    {
        writeBug("addFront() should increase the size of the list by 1.");
    }

    if (testList.toVector().front() != 42)
    {
        writeBug("addFront() should add passed value to front of list.");
    }
}

void Test::testAddBack()
{
    LinkedListOfInts testList;

    testList.addBack(12);

    int length = testList.toVector().size();

    testList.addBack(73);

    if (testList.size() - length != 1)
    {
        writeBug("addBack() should increase the size of the list by 1.");
    }

    if (testList.toVector().back() != 73)
    {
        writeBug("addBack() should add the passed value to back of list.");
    }
}

void Test::testRemoveFront()
{
    LinkedListOfInts testList;

    if (testList.removeFront())
    {
        writeBug("removeFront() should return false for an empty list.");
    }

    testList.addFront(15);
    testList.addFront(10);

    if (!testList.removeFront())
    {
        writeBug("removeFront() should return true for a non-empty list.");
    }

    if (testList.size() != 1)
    {
        writeBug("List size should have 1 fewer element after removeFront().");
    }

    if (testList.toVector().front() == 10)
    {
        writeBug("Front of the list should be removed when removeFront() is called.");
    }
}

void Test::testRemoveBack()
{
    LinkedListOfInts testList;

    if (testList.removeBack())
    {
        writeBug("removeBack() should return false for an empty list.");
    }

    testList.addBack(45);
    testList.addBack(30);

    if (!testList.removeBack())
    {
        writeBug("removeBack() should return true for a non-empty list.");
    }

    if (testList.size() != 1)
    {
        writeBug("List size should have 1 fewer element after removeBack().");
    }

    if (testList.toVector().back() == 30)
    {
        writeBug("Back of the list should be removed when removeBack() is called.");
    }
}

void Test::testSearch()
{
    LinkedListOfInts testList;

    testList.addFront(40);

    if (testList.search(25))
    {
        writeBug("search() should return false when item is not present.");
    }

    if (!testList.search(40))
    {
        writeBug("search() should return true when item is present.");
    }
}
