///////////////////  内部静态变量的懒汉实现  //////////////////
// instance is created lazily at runtime
namespace myspace
{
class Single
{
public:
    // 获取单实例对象
    static Single &GetInstance()
    {
        // c++11内部静态变量具有线程安全性，所以可以利用这个特性很简单就实现一个线程安全的单例类
        // 局部静态特性的方式实现单实例
        static Single instance;
        return instance;
    }

private:
    Single();                                      // 禁止外部构造
    ~Single();                                     // 禁止外部析构
    Single(const Single &signal);                  // 禁止外部复制构造
    const Single &operator=(const Single &signal); // 禁止外部赋值操作
};

} // namespace myspace
