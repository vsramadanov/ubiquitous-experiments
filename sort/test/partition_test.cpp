#include <partition.h>

#include <random>
#include <vector>

#include <gtest/gtest.h>

class PartitionTest : public testing::TestWithParam<size_t> {
    std::random_device                    rd;
    std::mt19937                          gen{rd()};
    std::uniform_real_distribution<float> dis{-100.f, 100.f};

  public:
    void SetUp() override {
        int len = GetParam();
        data.resize(len);
        for (int idx = 0; idx < len; idx++) {
            data[idx] = dis(gen);
        }
    }

    void TearDown() override { }

  protected:
    bool is_partitioned(float* arr, int len, int pivot_pos) {
        float pivot = arr[pivot_pos];
        for (int idx = 0; idx < pivot_pos; idx++) {
            if (arr[idx] > pivot)
                return false;
        }

        for (int idx = pivot_pos; idx < len; idx++) {
            if (arr[idx] < pivot)
                return false;
        }

        return true;
    }

    std::vector<float> data;
};

TEST_P(PartitionTest, Partition) {
    int pos = partition(data.data(), data.size());
    EXPECT_TRUE(is_partitioned(data.data(), data.size(), pos));
};

size_t test_lenghts[] = {1, 4, 7, 10, 110, 127, 1100, 2500};
INSTANTIATE_TEST_SUITE_P(PartitionTestSuite, PartitionTest, testing::ValuesIn(test_lenghts));
