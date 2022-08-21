#include "Memory.h"

Memory::Memory()
{
    memory = new uint16_t[65536];
}

Memory::~Memory()
{
    delete [] memory;
}

void Memory::pushMemory(uint16_t adr, int32_t num)
{
    memory[adr] = num;
}

int32_t Memory::getMemory(uint16_t adr)
{
    return memory[adr];
}
