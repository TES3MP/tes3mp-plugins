#pragma once

#include <stdint.h>
#include <stddef.h>

uint32_t MurmurHash3A(const uint8_t *key, size_t len, uint32_t seed);
