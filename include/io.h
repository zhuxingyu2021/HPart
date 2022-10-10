//
// Created by zhuxingyu on 2022/9/28.
//

#ifndef HPART_IO_H
#define HPART_IO_H

#include "data_structure.h"

#include "exception.h"
#include <string_view>

namespace HPart{
    class GraphIO{
    public:
        static ErrorType ReadMetisGraph(std::string_view filename, AdjacencyMatrix& graph);
    };
}// namespace HPart

#define HPART_IO_BUFFER_SIZE 16384

#endif //HPART_IO_H
