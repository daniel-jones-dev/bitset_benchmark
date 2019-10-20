#include <benchmark/benchmark.h>

#include "helper.h"

template<uint32_t Size_>
struct SizeWrapper {
  constexpr static const uint32_t Size = Size_;
};

template<class SizeWrapper>
static void BM_CreateNoInit_Bitset(benchmark::State &state) {
  for (auto _ : state) {
    std::bitset<SizeWrapper::Size> empty_bitset;
    static_cast<void>(empty_bitset);
  }
}

template<class SizeWrapper>
static void BM_CreateNoInit_Mask(benchmark::State &state) {
  for (auto _ : state) {
    MASK_TYPE(SizeWrapper::Size) empty_mask;
    static_cast<void>(empty_mask);
  }
}

template<class SizeWrapper>
static void BM_CreateInit_Bitset(benchmark::State &state) {
  for (auto _ : state) {
    std::bitset<SizeWrapper::Size> empty_bitset = std::numeric_limits<uint64_t>::max();
    static_cast<void>(empty_bitset);
  }
}

template<class SizeWrapper>
static void BM_CreateInit_Mask(benchmark::State &state) {
  for (auto _ : state) {
    MASK_TYPE(SizeWrapper::Size) empty_mask = std::numeric_limits<MASK_TYPE(SizeWrapper::Size)>::max();
    static_cast<void>(empty_mask);
  }
}

template<class SizeWrapper>
static void BM_Equality_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  std::bitset<SizeWrapper::Size> zero = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(set == zero);
  }
}

template<class SizeWrapper>
static void BM_Equality_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  MASK_TYPE(SizeWrapper::Size) zero = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask == zero);
  }
}

template<class SizeWrapper>
static void BM_TestBit_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set[0]);
  }
}

template<class SizeWrapper>
static void BM_TestBit_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask & 0x1ULL);
  }
}

template<class SizeWrapper>
static void BM_All_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set.all());
  }
}

template<class SizeWrapper>
static void BM_All_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask == std::numeric_limits<MASK_TYPE(SizeWrapper::Size)>::max());
  }
}

template<class SizeWrapper>
static void BM_Any_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set.any());
  }
}

template<class SizeWrapper>
static void BM_Any_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask != 0);
  }
}

template<class SizeWrapper>
static void BM_None_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set.none());
  }
}

template<class SizeWrapper>
static void BM_None_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask == 0);
  }
}

template<class SizeWrapper>
static void BM_Count_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set.count());
  }
}

template<class SizeWrapper>
std::size_t count_bits(MASK_TYPE(SizeWrapper::Size) mask) { // TODO improve
  std::size_t c = 0;
  for (MASK_TYPE(SizeWrapper::Size) i = 0; i < 64ULL; ++i) {
    if (mask & (MASK_TYPE(SizeWrapper::Size)(0x1U) << i))
      ++c;
  }
  return c;
}

template<class SizeWrapper>
static void BM_Count_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(count_bits<SizeWrapper>(mask));
  }
}

template<class SizeWrapper>
static void BM_ShiftLeft_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set << 1);
  }
}

template<class SizeWrapper>
static void BM_ShiftLeft_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask << 1ULL);
  }
}

template<class SizeWrapper>
static void BM_ShiftRight_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set >> 1ULL);
  }
}

template<class SizeWrapper>
static void BM_ShiftRight_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask >> 1ULL);
  }
}

template<class SizeWrapper>
static void BM_SetBit_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set.set(0));
  }
}

template<class SizeWrapper>
static void BM_SetBit_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask |= 0x1ULL);
  }
}

template<class SizeWrapper>
static void BM_ResetBit_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set.reset(0));
  }
}

template<class SizeWrapper>
static void BM_ResetBit_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask &= ~0x1ULL);
  }
}

template<class SizeWrapper>
static void BM_FlipBit_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set.flip(0));
  }
}

template<class SizeWrapper>
static void BM_FlipBit_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask ^= 0x1ULL);
  }
}

template<class SizeWrapper>
static void BM_SetBits_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  std::bitset<SizeWrapper::Size> &set2 = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set |= set2);
  }
}

template<class SizeWrapper>
static void BM_SetBits_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  MASK_TYPE(SizeWrapper::Size) &mask2 = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask |= mask2);
  }
}

template<class SizeWrapper>
static void BM_ResetBits_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  std::bitset<SizeWrapper::Size> &set2 = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set &= ~set2);
  }
}

template<class SizeWrapper>
static void BM_ResetBits_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  MASK_TYPE(SizeWrapper::Size) &mask2 = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask &= ~mask2);
  }
}

template<class SizeWrapper>
static void BM_FlipBits_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  std::bitset<SizeWrapper::Size> &set2 = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(set ^= set2);
  }
}

template<class SizeWrapper>
static void BM_FlipBits_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  MASK_TYPE(SizeWrapper::Size) &mask2 = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(mask ^= mask2);
  }
}

template<class SizeWrapper>
static void BM_Not_Bitset(benchmark::State &state) {
  std::bitset<SizeWrapper::Size> &set = getNewBitset<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(~set);
  }
}

template<class SizeWrapper>
static void BM_Not_Mask(benchmark::State &state) {
  MASK_TYPE(SizeWrapper::Size) &mask = getNewMask<SizeWrapper::Size>();
  for (auto _ : state) {
    benchmark::DoNotOptimize(~mask);
  }
}

// Test a function: given an integer, determine if any pairs of bits are both set
template<class SizeWrapper>
bool checkPairsBitset(MASK_TYPE(SizeWrapper::Size) value_) {
  constexpr std::bitset<SizeWrapper::Size> lowBits = 0x5555555555555555ULL;
  std::bitset<SizeWrapper::Size> value = value_;
  std::bitset<SizeWrapper::Size> shift = (value >> 1) & lowBits;
  value &= shift;
  return value.any();
}

template<class SizeWrapper>
bool checkPairsMask(MASK_TYPE(SizeWrapper::Size) value) {
  constexpr MASK_TYPE(SizeWrapper::Size) lowBits = 0x5555555555555555ULL;
  MASK_TYPE(SizeWrapper::Size) shift = (value >> 1ULL) & lowBits;
  value &= shift;
  return value > 0;
}

template<class SizeWrapper>
static void BM_CheckPairs_Bitset(benchmark::State &state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(checkPairsBitset<SizeWrapper>(getNewNum()));
  }
}

template<class SizeWrapper>
static void BM_CheckPairs_Mask(benchmark::State &state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(checkPairsMask<SizeWrapper>(getNewNum()));
  }
}


// Test another function: given an integer, if any pairs have both bits set, clear them
template<class SizeWrapper>
MASK_TYPE(SizeWrapper::Size) clearPairsBitset(MASK_TYPE(SizeWrapper::Size) value_) {
  constexpr std::bitset<SizeWrapper::Size> lowBits = 0x5555555555555555ULL;
  const std::bitset<SizeWrapper::Size> value = value_;
  std::bitset<SizeWrapper::Size> shift = (value >> 1) & lowBits;
  std::bitset<SizeWrapper::Size> pairs = value & shift;
  pairs |= pairs << 1;
  return (value & ~pairs).to_ullong();
}

template<class SizeWrapper>
MASK_TYPE(SizeWrapper::Size) clearPairsMask(const MASK_TYPE(SizeWrapper::Size) value) {
  constexpr MASK_TYPE(SizeWrapper::Size) lowBits = 0x5555555555555555ULL;
  MASK_TYPE(SizeWrapper::Size) shift = (value >> 1) & lowBits;
  MASK_TYPE(SizeWrapper::Size) pairs = value & shift;
  pairs |= pairs << 1;
  return (value & ~pairs);
}

template<class SizeWrapper>
static void BM_ClearPairs_Bitset(benchmark::State &state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(clearPairsBitset<SizeWrapper>(getNewNum()));
  }
}

template<class SizeWrapper>
static void BM_ClearPairs_Mask(benchmark::State &state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(clearPairsMask<SizeWrapper>(getNewNum()));
  }
}

#define GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(FUNC) \
  BENCHMARK_TEMPLATE(FUNC ## _Bitset, SizeWrapper<8>); \
  BENCHMARK_TEMPLATE(FUNC ## _Mask, SizeWrapper<8>); \
  BENCHMARK_TEMPLATE(FUNC ## _Bitset, SizeWrapper<16>); \
  BENCHMARK_TEMPLATE(FUNC ## _Mask, SizeWrapper<16>); \
  BENCHMARK_TEMPLATE(FUNC ## _Bitset, SizeWrapper<32>); \
  BENCHMARK_TEMPLATE(FUNC ## _Mask, SizeWrapper<32>); \
  BENCHMARK_TEMPLATE(FUNC ## _Bitset, SizeWrapper<64>); \
  BENCHMARK_TEMPLATE(FUNC ## _Mask, SizeWrapper<64>)

GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_CreateNoInit);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_CreateInit);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_Equality);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_TestBit);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_All);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_Any);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_None);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_Count);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_ShiftLeft);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_ShiftRight);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_SetBit);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_ResetBit);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_FlipBit);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_SetBits);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_ResetBits);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_FlipBits);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_Not);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_CheckPairs);
GENERATE_BENCHMARK_FOR_FUNCTION_ROOT(BM_ClearPairs);
