//
// Created by Daniel on 20/10/2019.
//

#include <bitset>
#include <cstdint>
#include <limits>

std::bitset<64> &getNewBitset() {
    static std::bitset<64> bitset;
    bitset = std::numeric_limits<uint64_t>::max();
    return bitset;
}

uint64_t &getNewMask() {
    static uint64_t mask;
    mask = std::numeric_limits<uint64_t>::max();
    return mask;
}

uint64_t getNewNum() {
    return 0xFF00FF00ULL;
}