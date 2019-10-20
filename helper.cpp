//
// Created by Daniel on 20/10/2019.
//

#include <bitset>
#include <cstdint>
#include <limits>

#include "helper.h"

//template<>
//uint8_t getMask<8>() {
//
//}
//template<>
//uint16_t getMask<16>() {
//
//}
//template<>
//uint32_t getMask<32>() {
//
//}
//template<>
//uint64_t getMask<64>() {
//
//}

template<>
std::bitset<8> &getNewBitset<8>() {

  static std::bitset<8> bitset;
  bitset = std::numeric_limits<uint8_t>::max();
  return bitset;
}
template<>
std::bitset<16> &getNewBitset<16>() {

  static std::bitset<16> bitset;
  bitset = std::numeric_limits<uint16_t>::max();
  return bitset;
}
template<>
std::bitset<32> &getNewBitset<32>() {

  static std::bitset<32> bitset;
  bitset = std::numeric_limits<uint32_t>::max();
  return bitset;
}
template<>
std::bitset<64> &getNewBitset<64>() {

  static std::bitset<64> bitset;
  bitset = std::numeric_limits<uint64_t>::max();
  return bitset;
}

template<>
uint8_t &getNewMask<8>() {

  static uint8_t mask;
  mask = std::numeric_limits<uint8_t>::max();
  return mask;
}
template<>
uint16_t &getNewMask<16>() {

  static uint16_t mask;
  mask = std::numeric_limits<uint16_t>::max();
  return mask;
}
template<>
uint32_t &getNewMask<32>() {

  static uint32_t mask;
  mask = std::numeric_limits<uint32_t>::max();
  return mask;
}
template<>
uint64_t &getNewMask<64>() {

  static uint64_t mask;
  mask = std::numeric_limits<uint64_t>::max();
  return mask;
}

uint64_t getNewNum() {
  return 0xFF00FF00ULL;
}