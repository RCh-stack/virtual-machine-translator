#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED

#include <string>
#include <fstream>
#include "Memory.h"
#include "Command.h"

// -- Class Processor --
class Processor
{
public:
    Memory *memory_; // -- memory object --
    command48 current_cmd; // -- current command --

    Processor(Memory *memory) : memory_(memory) { } // -- constructor --
    inline void load(std::string fname); // -- load programm --
    inline void run(std::string name); // -- run processor --

    inline void convertToBinary(std::string filename); // -- translate file in binary --
    inline void convertToTxt(std::string filename); // -- translate file in txt (demonstrate) --
};

#endif // PROCESSOR_H_INCLUDED
