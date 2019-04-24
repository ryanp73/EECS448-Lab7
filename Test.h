#ifndef TEST_H
#define TEST_H

#include <string>
#include <fstream>

class Test
{
private:
    std::ofstream buglist;

    void writeBug(std::string bug);

public:
    Test();
    ~Test();
    void runAllTests();
    void testConstructor();
    void testDestructor();
    void testIsEmpty();
    void testSize();
    void testAddFront();
    void testAddBack();
    void testRemoveFront();
    void testRemoveBack();
    void testSearch();
};

#endif
