//
// Created by zhuxingyu on 2022/9/27.
//

#ifndef HPART_DATA_STRUCTURE_H
#define HPART_DATA_STRUCTURE_H

#include "noncopyable.h"

namespace HPart {
    using IndexType = int;
    using WeightType = int;

    // 图的邻接矩阵
    struct AdjacencyMatrix: public NonCopyable{
        AdjacencyMatrix(AdjacencyMatrix&& tmp){
            n_vertices = tmp.n_vertices;
            n_edges = tmp.n_edges;
            xadj = tmp.xadj;
            adjncy = tmp.adjncy;
            w_vertices = tmp.w_vertices;
            w_edges = tmp.w_edges;

            tmp.n_vertices = 0;
            tmp.n_edges = 0;
            tmp.xadj = nullptr;
            tmp.adjncy = nullptr;
            tmp.w_vertices = nullptr;
            tmp.w_edges = nullptr;
        }

        ~AdjacencyMatrix(){
            delete xadj;
            delete adjncy;
            delete w_vertices;
            delete w_edges;
        }

        IndexType n_vertices = 0; // 顶点的数量
        IndexType n_edges = 0; // 边的数量

        // CSR格式存储邻接矩阵
        IndexType* xadj = nullptr;
        IndexType* adjncy = nullptr;

        WeightType* w_vertices = nullptr; // 图顶点的权值
        WeightType* w_edges = nullptr; // 图边的权值
    };

}//namespace HPart

#endif //HPART_DATA_STRUCTURE_H
