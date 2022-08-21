#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

// -- word length command --
struct command16
{
    unsigned short opcode : 7; // -- command code --
    unsigned short s : 2; // -- operand size --
    unsigned short dd : 2; // -- operand format --
    unsigned short r1 : 3; // -- register r1 --
    unsigned short r2 : 3; // -- register r2 --
};

// -- two word length command --
struct command32
{
    command16 cmd16; // -- 16 bit command --
    unsigned short o1 : 16; // -- address --
};

// -- three word length command --
struct command48
{
    command32 cmd32; // -- 32 bit command --
    unsigned short o2 : 16; // -- address --
};

// -- data types used --
union data
{
    int16_t sinteger; // -- short integer, 2 byte --
    uint16_t usinteger; // -- short unsigned integer, 2 byte --
    int32_t integer; // -- integer, 4 byte --
    float real; // -- float, 4 byte --
};

#endif // TYPES_H_INCLUDED
