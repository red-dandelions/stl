//
// Created by 莫寿华 on 2021/11/18.
//

#ifndef STL_VECTOR_TEST_HPP
#define STL_VECTOR_TEST_HPP
#include <vector>

TEST(vector, push_back) {
    std::vector<int> v;
    v.push_back(2);
    EXPECT_EQ(v[0], 2) << "v[0] is not equl 2\n";
}
#endif //STL_VECTOR_TEST_HPP
