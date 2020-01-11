// 单例类饿汉式实现
// 本身具有线程安全性
#include <iostream>
using namespace std;

namespace myspace
{

class singleton_early
{
public:
    static singleton_early *GetInstance()
    {
        return g_psingle;
    }

    static void DeleteInstance()
    {
        if (g_psingle)
        {
            delete g_psingle;
            g_psingle = NULL;
        }
    }

    void test()
    {
        printf("test early singleton\n");
    }

private:
    singleton_early() {}
    ~singleton_early() {}
    singleton_early(const singleton_early &single) {}
    const singleton_early &operator=(const singleton_early &single) {}

private:
    static singleton_early *g_psingle;
};

// 静态成员变量的初始化
singleton_early *singleton_early::g_psingle = new singleton_early;
} // namespace myspace
