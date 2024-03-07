#include <MyVector.hpp>
#include <gtest/gtest.h>

TEST(push, testPushBack) {
    MyVector v{3};
    v.pushBack(0);
    v.pushBack(1);
    v.pushBack(2);

    EXPECT_TRUE(v[0] == 0 && v[1] == 1 && v[2] == 2);

    v.pushBack(3);
    EXPECT_TRUE(v[0] == 0 && v[1] == 1 && v[2] == 2 && v[3] == 3);
}
 
TEST(pop, testPopBack) {
    MyVector v{3};
    v.pushBack(0);
    v.pushBack(1);
    v.pushBack(2);
    
    v.popBack();
    v.popBack();
    v.popBack();

    EXPECT_TRUE(v.length() == 0);
    v.popBack();
}

TEST(at, testIndexOperator) {
    MyVector v{3};
    v.pushBack(0);
    v.pushBack(1);
    v.pushBack(2);

    v[0] = 5;
    EXPECT_TRUE(v[0] == 5);

    int i = v[1];
    EXPECT_TRUE(i == v[1]);
}

