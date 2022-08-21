#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <iostream>
#include <cinttypes>
#include "GRP.h"
#include "Types.h"

class Memory
{
public:
    uint16_t *memory;
    Registers regs;

    Memory();
    ~Memory();

    void pushMemory(uint16_t adr, int32_t num);
    int32_t getMemory(uint16_t adr);
};

#endif // MEMORY_H_INCLUDED
