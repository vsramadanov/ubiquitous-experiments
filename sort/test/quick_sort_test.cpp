#include <quick_sort.h>

#include <random>
#include <vector>

#include <gtest/gtest.h>

class QuickSortTest : public testing::TestWithParam<size_t> {
    std::random_device                    rd;
    std::mt19937                          gen{rd()};
    std::uniform_real_distribution<float> dis{0.f, 100.f};
    std::uniform_int_distribution<size_t> idx_dis{0U, std::numeric_limits<size_t>::max()};

    void shuffle(std::vector<float>& vec) {
        size_t N = vec.size();
        for (size_t idx = 0; idx < N; idx++) {
            size_t rndidx = idx_dis(gen) % N;
            std::swap(vec[idx], vec[rndidx]);
        }
    }

  public:
    void SetUp() override {
        size_t N = GetParam();
        if (N) {
            src.resize(N);
            src[0] = dis(gen);
            for (size_t idx = 1; idx < N; idx++) {
                src[idx] = src[idx - 1] + dis(gen);
            }

            vec = src;
            shuffle(vec);
        }
    }

    void TearDown() override { }

  protected:
    std::vector<float> src;
    std::vector<float> vec;
};

TEST_P(QuickSortTest, Sort) {
    quick_sort(vec.data(), vec.size());
    EXPECT_EQ(src, vec);
};

size_t test_lenghts[] = {0, 1, 4, 7, 10, 110, 127, 1100, 2500};
INSTANTIATE_TEST_SUITE_P(QuickSortTestSuite, QuickSortTest, testing::ValuesIn(test_lenghts));
