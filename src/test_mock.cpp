#include <gtest/gtest.h>
#include <gmock/gmock.h>

// 定义一个接口
class MyInterface {
public:
    virtual ~MyInterface() = default;
    virtual int Foo(int x) = 0;
};


// 使用gmock生成Mock类
class MockMyInterface : public MyInterface {
public:
    MOCK_METHOD(int, Foo, (int x), (override));
};

TEST(MockTestSuite, MockTestCase) {
    MockMyInterface mock;
    EXPECT_CALL(mock, Foo(5)).Times(1).WillOnce(testing::Return(10));

    ASSERT_EQ(mock.Foo(5), 10);
}