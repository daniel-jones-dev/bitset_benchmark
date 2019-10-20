#include <benchmark/benchmark.h>

#include <bitset>
#include <cstdint>
#include <limits>

std::bitset<64> &getNewBitset();
uint64_t &getNewMask();
uint64_t getNewNum();

static void BM_CreateNoInit_Bitset(benchmark::State &state) {
    for (auto _ : state) {
        std::bitset<64> empty_bitset;
        static_cast<void>(empty_bitset);
    }
}

static void BM_CreateNoInit_Mask(benchmark::State &state) {
    for (auto _ : state) {
        uint64_t empty_mask;
        static_cast<void>(empty_mask);
    }
}

BENCHMARK(BM_CreateNoInit_Bitset);
BENCHMARK(BM_CreateNoInit_Mask);

static void BM_CreateInit_Bitset(benchmark::State &state) {
    for (auto _ : state) {
        std::bitset<64> empty_bitset = std::numeric_limits<uint64_t>::max();
        static_cast<void>(empty_bitset);
    }
}

static void BM_CreateInit_Mask(benchmark::State &state) {
    for (auto _ : state) {
        uint64_t empty_mask = std::numeric_limits<uint64_t>::max();
        static_cast<void>(empty_mask);
    }
}

BENCHMARK(BM_CreateInit_Bitset);
BENCHMARK(BM_CreateInit_Mask);

static void BM_Equality_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    std::bitset<64> zero = 0;
    for (auto _ : state) {
        benchmark::DoNotOptimize(set == zero);
    }
}

static void BM_Equality_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    uint64_t zero = 0;
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask == zero);
    }
}

BENCHMARK(BM_Equality_Bitset);
BENCHMARK(BM_Equality_Mask);

static void BM_TestBit_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set[0]);
    }
}

static void BM_TestBit_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask & 0x1ULL);
    }
}

BENCHMARK(BM_TestBit_Bitset);
BENCHMARK(BM_TestBit_Mask);

static void BM_All_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set.all());
    }
}

static void BM_All_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask == std::numeric_limits<uint64_t>::max());
    }
}

BENCHMARK(BM_All_Bitset);
BENCHMARK(BM_All_Mask);

static void BM_Any_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set.any());
    }
}

static void BM_Any_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask != 0);
    }
}

BENCHMARK(BM_Any_Bitset);
BENCHMARK(BM_Any_Mask);

static void BM_None_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set.none());
    }
}

static void BM_None_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask == 0);
    }
}

BENCHMARK(BM_None_Bitset);
BENCHMARK(BM_None_Mask);

static void BM_Count_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set.count());
    }
}

std::size_t countbits(uint64_t mask) { // TODO improve
    std::size_t c = 0;
    for (uint64_t i = 0; i < 64ULL; ++i) {
        if (mask & (0x1ULL << i))
            ++c;
    }
    return c;
}

static void BM_Count_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(countbits(mask));
    }
}

BENCHMARK(BM_Count_Bitset);
BENCHMARK(BM_Count_Mask);

static void BM_ShiftLeft_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set << 1);
    }
}

static void BM_ShiftLeft_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask << 1ULL);
    }
}

BENCHMARK(BM_ShiftLeft_Bitset);
BENCHMARK(BM_ShiftLeft_Mask);

static void BM_ShiftRight_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set >> 1ULL);
    }
}

static void BM_ShiftRight_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask >> 1ULL);
    }
}

BENCHMARK(BM_ShiftRight_Bitset);
BENCHMARK(BM_ShiftRight_Mask);

static void BM_SetBit_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set.set(0));
    }
}

static void BM_SetBit_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask |= 0x1ULL);
    }
}

BENCHMARK(BM_SetBit_Bitset);
BENCHMARK(BM_SetBit_Mask);

static void BM_ResetBit_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set.reset(0));
    }
}

static void BM_ResetBit_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask &= ~0x1ULL);
    }
}

BENCHMARK(BM_ResetBit_Bitset);
BENCHMARK(BM_ResetBit_Mask);

static void BM_FlipBit_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set.flip(0));
    }
}

static void BM_FlipBit_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask ^= 0x1ULL);
    }
}

BENCHMARK(BM_FlipBit_Bitset);
BENCHMARK(BM_FlipBit_Mask);

static void BM_SetBits_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    std::bitset<64> &set2 = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set |= set2);
    }
}

static void BM_SetBits_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    uint64_t &mask2 = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask |= mask2);
    }
}

BENCHMARK(BM_SetBits_Bitset);
BENCHMARK(BM_SetBits_Mask);

static void BM_ResetBits_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    std::bitset<64> &set2 = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set &= ~set2);
    }
}

static void BM_ResetBits_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    uint64_t &mask2 = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask &= ~mask2);
    }
}

BENCHMARK(BM_ResetBits_Bitset);
BENCHMARK(BM_ResetBits_Mask);

static void BM_FlipBits_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    std::bitset<64> &set2 = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(set ^= set2);
    }
}

static void BM_FlipBits_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    uint64_t &mask2 = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(mask ^= mask2);
    }
}

BENCHMARK(BM_FlipBits_Bitset);
BENCHMARK(BM_FlipBits_Mask);

static void BM_Not_Bitset(benchmark::State &state) {
    std::bitset<64> &set = getNewBitset();
    for (auto _ : state) {
        benchmark::DoNotOptimize(~set);
    }
}

static void BM_Not_Mask(benchmark::State &state) {
    uint64_t &mask = getNewMask();
    for (auto _ : state) {
        benchmark::DoNotOptimize(~mask);
    }
}

BENCHMARK(BM_Not_Bitset);
BENCHMARK(BM_Not_Mask);

// Test a function: given a uint64_t, determine if any pairs of bits are both set
bool checkPairsBitset(uint64_t value_)
{
    constexpr std::bitset<64> lowBits = 0x5555555555555555ULL;
    std::bitset<64> value = value_;
    std::bitset<64> shift = (value >> 1) & lowBits;
    value &= shift;
    return value.any();
}
bool checkPairsMask(uint64_t value)
{
    constexpr uint64_t lowBits = 0x5555555555555555ULL;
    uint64_t shift = (value >> 1ULL) & lowBits;
    value &= shift;
    return value > 0;
}

static void BM_CheckPairs_Bitset(benchmark::State &state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(checkPairsBitset(getNewNum()));
    }
}

static void BM_CheckPairs_Mask(benchmark::State &state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(checkPairsMask(getNewNum()));
    }
}

BENCHMARK(BM_CheckPairs_Bitset);
BENCHMARK(BM_CheckPairs_Mask);
