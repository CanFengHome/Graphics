//
//  SingletonTemplate.h
//  SharpEliminate
//
//  Created by ccf on 14-9-15.
//  提供单例模式模板，方便单例模式的构建
//

#ifndef JellyBlast_SingletonTemplate_h
#define JellyBlast_SingletonTemplate_h


template<typename T>
class SingletonTemplate
{
public:
    static T* getInstance()
    {
        static T _instance;
        return &_instance;
    }
protected:
    SingletonTemplate(){}
    virtual ~SingletonTemplate(){}
    SingletonTemplate(const SingletonTemplate<T>&); //拷贝构造函数不实现
    SingletonTemplate<T>& operator=(const SingletonTemplate<T>&); //赋值函数不实现
};


/*使用范例-第一种方式,此种方式相对于第二种方式而言，构造方法和析构函数没有自定义为private，不严谨，但是相对方便灵活
class TestClassName
{
public:
    void outPut()
    {
        cout<<"调用了方法哦"<<endl;
    }
};
typedef SingletonTemplate<TestClassName> TestClassNameSingleton;

int main()
{
    TestClassNameSingleton::getInstance()->outPut();
    
    return true;
}
 */


/*使用范例第二种方式
class ChildClassSingleton : public SingletonTemplate<ChildClassSingleton>
{
public:
    void printInfo()
    {
        cout<<"print info aaaaaaaaaaaaaaaaaa"<<endl;
    }
private:
    ChildClassSingleton(){};
    virtual ~ChildClassSingleton(){};
    friend class SingletonTemplate<ChildClassSingleton>;
};

 调用：
 ChildClassSingleton::getInstance()->printInfo();
 
 */

#endif
