// 懒汉式单例类，线程安全
// 懒汉式，即第一次引用时才创建实例
#include <mutex> //std::mutex

namespace myspace
{

class Singleton_lazy
{
public:
    static Singleton_lazy *&GetInstance() ； //注意返回值类型，对一个指针变量的引用
        static void DeleteInstance();

private:
    Singleton_lazy() {}
    ~Singleton_lazy() {}
    Singleton_lazy(const Singleton_lazy &singleton) {}
    const Singleton_lazy operator=(const Singleton_lazy &singleton) {}

private:
    static Singleton_lazy *m_instance;
    static std::mutex m_mutex;
};

// 初始化静态成员变量
Singleton_lazy *Singleton_lazy::m_instance = NULL;
std::mutex      Singleton_lazy::m_mutex;

// 成员函数实现
Singleton_lazy *&Singleton_lazy::GetInstance()
{
    if (m_instance == NULL) //双重锁定，防止每次调用GetInstance都要加锁，只有发现需要实例化的时候才加锁
    {
        //如果两个线程同时通过了第一重的m_instance==NULL判断，就会有一个先加锁然后创建出来m_instance。
        //所以还需要第二重判断m_instance==NULL，防止被实例化出多个对象
        std::unique_lock<std::mutex> lock(m_mutex); //加锁
        if (m_instance == NULL)                     //
        {
            m_instance = new Singleton_lazy;
        }
    }
    return m_instance;
}

void Singleton_lazy::DeleteInstance()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_instance)
    {
        delete m_instance;
        m_instance = NULL;
    }
}

} // namespace myspace
