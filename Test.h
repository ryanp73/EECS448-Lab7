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
    void testIsEmpty();
    void testSize();
};

#endif