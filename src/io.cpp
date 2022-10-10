//
// Created by zhuxingyu on 2022/9/28.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include "io.h"

using namespace HPart;

ErrorType GraphIO::ReadMetisGraph(std::string_view filename, AdjacencyMatrix &graph) {
    FILE* file = fopen(filename.data(), "r");
    HPART_EXCEPT_ASSERT(file != nullptr, return IO_ERROR);

    char* line = nullptr;
    size_t len_line = 0;
    char io_buffer[HPART_IO_BUFFER_SIZE];
    size_t p_io_buffer = 0;
    size_t len_io_buffer;

    if(getline(&line, &len_line, file) == -1){
        fclose(file); free(line); return IO_ERROR;
    }
    if(sscanf(line, "%d %d", &graph.n_vertices, &graph.n_edges) != 2){
        fclose(file);free(line); return IO_ERROR;
    }
    free(line);

    graph.xadj = new int[graph.n_vertices + 1];
    std::fill(graph.xadj, graph.xadj + graph.n_vertices + 1, 0);

    graph.adjncy = new int[graph.n_edges * 2];
    std::fill(graph.adjncy, graph.adjncy + graph.n_edges * 2, 0);

    len_io_buffer = fread(io_buffer, sizeof(char), HPART_IO_BUFFER_SIZE, file);
    for(int i = 0; i < graph.n_vertices; ++i){
        int buf_pos = p_io_buffer;
        for(;buf_pos<len_io_buffer; ++buf_pos){
            if(io_buffer[buf_pos] == '\n'){
                io_buffer[buf_pos] = '\0';
                break;
            }
        }
        if(buf_pos == len_io_buffer && len_io_buffer == HPART_IO_BUFFER_SIZE){
            if(p_io_buffer == 0){ // BUFFER SIZE IS TOO SMALL!
                fclose(file);
                return IO_ERROR;
            }
            fseek(file, p_io_buffer - len_io_buffer, SEEK_CUR);
            p_io_buffer = 0;
            len_io_buffer = fread(io_buffer, sizeof(char), HPART_IO_BUFFER_SIZE, file);
            for (buf_pos = 0; buf_pos < len_io_buffer && io_buffer[buf_pos] != '\n'; ++buf_pos) {
                if (io_buffer[buf_pos] == '\n') {
                    io_buffer[buf_pos] = '\0';
                    break;
                }
            }
        }
        if(buf_pos == len_io_buffer && len_io_buffer != HPART_IO_BUFFER_SIZE){ //EOF
            fclose(file);
            return IO_ERROR;
        }
        line = &io_buffer[p_io_buffer];
        p_io_buffer = buf_pos;

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
    return NONE;
}
