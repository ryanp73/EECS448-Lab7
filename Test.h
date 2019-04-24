#ifndef TEST_H
#define TEST_H

#include <string>
#include <fstream>

class Test
{
private:
    std::ofstream buglist;
    LinkedListOfInts* testList;

    void writeBug(std::string bug);
    void resetList();

public:
    Test();
    ~Test();
    void runAllTests();
    void testConstructor();
    void testDestructor();
    void testIsEmpty();
    void testSize();
};

#endif