load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_test (
    name = "partition_test",
    srcs = [
        "partition_test.cpp",
    ],
    deps = [
        "//sort:quick_sort",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)

cc_test (
    name = "quick_sort_test",
    srcs = [
        "quick_sort_test.cpp",
    ],
    deps = [
        "//sort:quick_sort",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)

cc_binary (
    name = "quick_sort_bench",
    srcs = [
        "quick_sort_bench.cpp",
    ],
    deps = [
        "//sort:quick_sort",
        "@benchmark//:benchmark_main",
    ],
)
