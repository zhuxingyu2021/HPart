//
// Created by zhuxingyu on 2022/9/28.
//

#ifndef HPART_EXCEPTION_H
#define HPART_EXCEPTION_H

namespace HPart{
    enum ErrorType{
        NONE = 0,
        IO_ERROR
    };
}//namespace HPart

#define HPART_EXCEPT_ASSERT(condition, do_something) \
    if (!(condition)) { \
        do_something; \
    }

#endif //HPART_EXCEPTION_H
