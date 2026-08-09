#include "pch.h"

struct SortTestCase {
    std::vector<int> input{};
    std::vector<int> expected{};
};

using sortFunc = std::function<void(std::vector<int>&)>;

class sortTest : public testing::TestWithParam<std::tuple<sortFunc, SortTestCase>> {
};

std::vector<SortTestCase> testCases = {
    SortTestCase{ {}, {} },
    SortTestCase{ {1}, {1} },
    SortTestCase{ {3, 1, 2}, {1, 2, 3} },
    SortTestCase{ {5, 4, 3, 2, 1}, {1, 2, 3, 4, 5} },
    SortTestCase{ {1, 1, 1}, {1, 1, 1} },
    SortTestCase{ {-5, 0, 10, -1}, {-5, -1, 0, 10} }
};

std::vector<sortFunc> sorters = {
    bubbleSort,
    insertionSort
};

TEST_P(sortTest, SortsCorrectly) {
    auto [sorter, test] = GetParam();

    std::vector<int> copy = test.input;

    sorter(copy);

    EXPECT_EQ(copy, test.expected);
}

INSTANTIATE_TEST_CASE_P(
    AllSorts,
    sortTest,
    testing::Combine(
        testing::ValuesIn(sorters),
        testing::ValuesIn(testCases)
    )
);