#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include "nocopy.h"

template<typename T>
class Singleton : public Nocopy {
public:
    static T& Get() {
        static T instance;
        return instance;
    }

protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};

#endif // _SINGLETON_H_