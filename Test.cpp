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

void Test::assertEqual(std::string test, int act, int exp)
{
    std::cout << test << std::endl;
    std::cout << "Expected: " << exp << std::endl;
    std::cout << "Actual:" << act << std::endl;
    if (act == exp)
    {
        std::cout << "Test succeeded!" << std::endl;
    }
    else
    {
        std::cout << "Test failed!" << std::endl;
        writeBug(test);
    }
}

void Test::assertEqual(std::string test, bool act, bool exp)
{
    std::cout << test << std::endl;
    std::cout << "Expected: " << exp << std::endl;
    std::cout << "Actual:" << act << std::endl;
    if (act == exp)
    {
        std::cout << "Test succeeded!" << std::endl;
    }
    else
    {
        std::cout << "Test failed!" << std::endl;
        writeBug(test);
    }
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
    assertEqual("isEmpty() returns false when given empty list.", 
                testList.isEmpty(), 
                false);

    testList.addBack(10);
    assertEqual("isEmpty() returns true when given non-empty list.",
                testList.isEmpty(),
                true);
}

void Test::testConstructor() 
{
    LinkedListOfInts testList;
    
    std::vector<int> testVec = testList.toVector();

    assertEqual("Constructor should create an empty list." , 
                testVec.empty(),
                true);
}

void Test::testDestructor()
{
    // TODO: Not sure how to test this
}

void Test::testSize()
{
    LinkedListOfInts testList;

    assertEqual("size() should be 0 upon instantiation.",
                testList.size(),
                0);
    
    testList.addBack(10);

    assertEqual("size() should be 1 after element added.",
                testList.size(),
                1);
}

void Test::testAddFront()
{
    LinkedListOfInts testList;

    testList.addFront(15);

    assertEqual("addFront() should increase the size of the list by 1.",
                testList.size(),
                1);

    testList.addFront(42);

    assertEqual("addFront() should add passed value to front of list.",
                testList.toVector().front(),
                42);
}

void Test::testAddBack()
{
    LinkedListOfInts testList;

    testList.addBack(12);

    assertEqual("addBack() should increase the size of the list by 1.",
                testList.size(),
                1);

    testList.addBack(40);

    assertEqual("addBack() should add passed value to back of list.",
                testList.toVector().back(),
                40);
}

void Test::testRemoveFront()
{
    LinkedListOfInts testList;

    assertEqual("removeFront() should return false for an empty list.", 
                testList.removeFront(),
                false);

    testList.addFront(15);
    testList.addFront(10);

    assertEqual("removeFront() should return true for a non-empty list.",
                testList.removeFront(),
                true);

    assertEqual("List size should have 1 fewer element after removeFront().",
                testList.size(),
                1);

    assertEqual("Front of the list should be removed when removeFront() is called.",
                testList.toVector().front(),
                10);
}

void Test::testRemoveBack()
{
    LinkedListOfInts testList;

    assertEqual("removeBack() should return false for an empty list.",
                testList.removeBack(),
                false);

    testList.addBack(24);
    testList.addBack(12);

    assertEqual("removeBack() should return true for a non-empty list.",
                testList.removeBack(),
                true);

    assertEqual("List size should have 1 fewer element after removeBack().",
                testList.size(),
                1);

    assertEqual("Back of the list should be removed when removeBack() is called.",
                testList.toVector().back(),
                24);
}

void Test::testSearch()
{
    LinkedListOfInts testList;

    testList.addFront(40);

    assertEqual("search() should return false when item is not present.", 
                testList.search(25),
                false);

    assertEqual("search() should return true when item is present.",
                testList.search(40),
                true);
}
