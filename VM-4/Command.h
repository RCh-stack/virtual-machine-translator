#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include "Memory.h"

enum opcode
{
    stop = 0,
    in = 1, out = 2,
    sadd = 3, ssub = 4, smul = 5, sdiv = 6,
    uadd = 7, usub = 8, umul = 9, udiv = 10,
    iadd = 11, isub = 12, imul = 13, idiv = 14,
    radd = 15, rsub = 16, rmul = 17, rdiv = 18,
    movrr = 19, movmr = 20, movrm = 21, movmm = 22,
    jmp = 23, je = 24, jne = 25, jl = 26, jle = 27, jg = 28, jge = 29,
    call = 30, ret = 31
};

class Command
{
public:
    virtual void operator()(Memory &mem, const command48 &cmd) = 0;
};

class Input : public Command
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class Output : public Command
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class Math : public Command
{
public:
    virtual void operator()(Memory &mem, const command48 &cmd) = 0;
};

class UMath : public Math
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class SMath : public Math
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class IMath : public Math
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class FMath : public Command
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class Compare : public Command
{
public:
    virtual void operator()(Memory &mem, const command48 &cmd) = 0;
};

class SCompare : public Compare
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class ICompare : public Compare
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class FCompare : public Compare
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class Transition : public Command
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

class Jump : public Command
{
public:
    void operator()(Memory &mem, const command48 &cmd);
};

#endif // COMMAND_H_INCLUDED
