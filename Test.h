#ifndef TEST_H
#define TEST_H

#include <string>
#include <fstream>

class Test
{
private:
    std::ofstream buglist;

    void writeBug(std::string bug);
    void assertEqual(std::string test, int act, int exp);
    void assertEqual(std::string test, bool act, bool exp);

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
