//
// Created by zhuxingyu on 2022/9/28.
//

#include <string>

#include "gtest/gtest.h"

#include "io.h"

using namespace HPart;

class IOTest: public ::testing::Test{
protected:
    void SetUp() override {
        std::string filename = std::string(SOURCE_DIR) + "/graph/cy_002.graph";
        read_status = GraphIO::ReadMetisGraph(filename, adj_matrix);
    }

    ErrorType read_status;
private:
    AdjacencyMatrix adj_matrix;
};

TEST_F(IOTest, TestReadMetisGraph){
    EXPECT_EQ(read_status, NONE);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
