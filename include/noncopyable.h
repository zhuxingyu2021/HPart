//
// Created by zhuxingyu on 2022/9/28.
//

#ifndef HPART_NONCOPYABLE_H
#define HPART_NONCOPYABLE_H

namespace HPart{
    class NonCopyable{
    public:
        NonCopyable() = default;
        ~NonCopyable() = default;

        NonCopyable(const NonCopyable& noncopyable) = delete;
        NonCopyable& operator=(const NonCopyable& noncopyable) = delete;
    };
}//namespace HPart

#endif //HPART_NONCOPYABLE_H
