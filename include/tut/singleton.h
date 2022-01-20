//
// Created by wu on 2022/1/14.
//

#ifndef TUT_SINGLETON_H
#define TUT_SINGLETON_H
namespace tut{
    template <typename T>
    class Singleton{
    public:
        static T& getInstance(){
            static T instance;
            return instance;
        }
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    protected:
        Singleton()  = default;
        ~Singleton() = default;



    };
}
#endif //TUT_SINGLETON_H
