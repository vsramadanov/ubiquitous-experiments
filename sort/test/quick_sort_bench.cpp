#include <quick_sort.h>

#include <algorithm>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

class QuickSortFixture : public benchmark::Fixture {
    std::random_device                    rd;
    std::mt19937                          gen{rd()};
    std::uniform_real_distribution<float> dis{-100.f, 100.f};

  public:
    void SetUp(::benchmark::State& state) {
        size_t N = state.range(0);
        vec.resize(N);
        for (size_t idx = 0; idx < N; idx++) {
            vec[idx] = dis(gen);
        }
    }

    void TearDown(::benchmark::State&) { }

  protected:
    std::vector<float> vec;
};

BENCHMARK_DEFINE_F(QuickSortFixture, QuickSort)(benchmark::State& state) {
    for (auto _ : state) {
        quick_sort(vec.data(), vec.size());
    }
}

BENCHMARK_DEFINE_F(QuickSortFixture, StdSort)(benchmark::State& state) {
    for (auto _ : state) {
        std::sort(vec.begin(), vec.end());
    }
}

BENCHMARK_REGISTER_F(QuickSortFixture, QuickSort)->RangeMultiplier(4)->Range(8, 2<<15);
BENCHMARK_REGISTER_F(QuickSortFixture, StdSort)->RangeMultiplier(4)->Range(8, 2<<15);
