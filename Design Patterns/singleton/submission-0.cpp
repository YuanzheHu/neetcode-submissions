#include <string>
using namespace std;

class Singleton 
{
private:
    string value_;  // 用于存储数据的成员变量

    Singleton() {}  // 私有构造函数，禁止外部直接创建对象

public:
    // 删除拷贝构造和赋值运算符，防止实例被复制
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() 
    {
        static Singleton instance; // 局部静态变量，只在第一次调用时构造
        return &instance;
    }

    string getValue() 
    {
        return value_;
    }

    void setValue(const string &value) 
    {
        this->value_ = value;
    }
};
