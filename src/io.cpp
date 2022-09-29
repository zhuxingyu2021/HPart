//
// Created by zhuxingyu on 2022/9/28.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "io.h"

using namespace HPart;

ErrorType GraphIO::ReadMetisGraph(std::string_view filename, AdjacencyMatrix &graph) {
    FILE* file = fopen(filename.data(), "r");
    HPART_EXCEPT_ASSERT(file != nullptr, return IO_ERROR);

    char* line = nullptr;
    size_t len_line = 0;

    HPART_EXCEPT_ASSERT(getline(&line, &len_line, file) != -1, goto HAPPENED_IO_ERROR);
    HPART_EXCEPT_ASSERT(sscanf(line, "%d %d", &graph.n_vertices, &graph.n_edges) == 2, goto HAPPENED_IO_ERROR);

    graph.xadj = new int[graph.n_vertices + 1];
    std::fill(graph.xadj, graph.xadj + graph.n_vertices + 1, 0);

    graph.adjncy = new int[graph.n_edges * 2];

    for(int i = 0; i < graph.n_vertices; ++i){
        HPART_EXCEPT_ASSERT(getline(&line, &len_line, file) != -1, goto HAPPENED_IO_ERROR);

        char* adj_str = strtok(line, " ");
        while(adj_str != nullptr){
            int adj = atoi(adj_str);
            if(adj != 0){
                graph.adjncy[graph.xadj[i]] = adj - 1;
                ++graph.xadj[i];
            }
            adj_str = strtok(nullptr, " ");
        }
    }

    graph.w_vertices = new int[graph.n_vertices];
    graph.w_edges = new int[graph.n_edges];

    std::fill(graph.w_vertices, graph.w_vertices + graph.n_vertices, 1);
    std::fill(graph.w_edges, graph.w_edges + graph.n_edges, 1);

    fclose(file);
    free(line);
    return NONE;

HAPPENED_IO_ERROR:
    fclose(file);
    free(line);
    return NONE;
}
