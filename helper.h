//
// Created by Daniel on 20/10/2019.
//

#ifndef BITSET_BENCHMARK__HELPER_H_
#define BITSET_BENCHMARK__HELPER_H_

#include <bitset>
#include <cstdint>
#include <limits>

#define MASK_TYPE(SIZE) typename std::conditional<SIZE == 8, uint8_t, \
  typename std::conditional<SIZE==16, uint16_t, \
  typename std::conditional<SIZE == 32, uint32_t, \
  typename std::conditional<SIZE == 64, uint64_t, void>::type>::type>::type>::type

//#define MASK_TYPE(SIZE) typename std::conditional<SIZE == 32, uint32_t, typename std::conditional<SIZE == 64, uint64_t, void>::type>::type

//template<uint32_t Size>
//MASK_TYPE(Size) getMask();

template<uint32_t Size>
std::bitset<Size> &getNewBitset();

template<uint32_t Size>
MASK_TYPE(Size) &getNewMask();


//template<>
//uint8_t getMask<8>();
//template<>
//uint16_t getMask<16>();
//template<>
//uint32_t getMask<32>();
//template<>
//uint64_t getMask<64>();

template<>
std::bitset<8> &getNewBitset<8>();
template<>
std::bitset<16> &getNewBitset<16>();
template<>
std::bitset<32> &getNewBitset<32>();
template<>
std::bitset<64> &getNewBitset<64>();

template<>
uint8_t& getNewMask<8>();
template<>
uint16_t& getNewMask<16>();
template<>
uint32_t& getNewMask<32>();
template<>
uint64_t& getNewMask<64>();

uint64_t getNewNum();

#endif //BITSET_BENCHMARK__HELPER_H_
