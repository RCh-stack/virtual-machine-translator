# Implementation Requirements
### Implement the virtual machine interpreter as a console application.
### Object-oriented approach.

> Processor - a separate class, divided into interface and implementation;

> Command execution - functor call (don't use switch operator!)

> Memory is a field in the class. Memory is a separate independent class; the memory itself is a dynamic array;

> Processor commands - hierarchy of functor classes; base class – abstract class Command with overloaded operator () operation

### Develop and describe in an explanatory note:
> command codes
  
> operand addressing methods
  
> set of flags-results
  
> command formats

> operand formats
  
### The following commands must be implemented:
> Upload/Download/Save

> Arithmetic (integer and fractional)

> Comparisons (integer and fractional)

> Bit operations

> Input-output (integer and fractional)

> Transitions (unconditional, conditional, to subroutine, return from subroutine)

### The program loader for the virtual machine is an independent function called in the main() function of the interpreter.

> The program code for the virtual machine must be written in a text file.

> The format for representing the program code in a file must be developed and described in an explanatory note.

> The loader must be able to load program code at any memory address

> The main program must take the file name as a command line argument, and pass it to the loader as a parameter when called.

# 4. Two-address, with General Purpose Registers, universal addressing of operands

PSW = IP + Flags, 16+16 = 32 bits. 

Memory - words 16 bits, combined into double words. The address size is 16 bits.

Data:

Integer signed, unsigned - 1 word

Integer sign - 2 words

Fractional - 2 words

RON - 8 pieces, 16 bits; content - signed integer, unsigned integer (address)

They are also 4 registers, 32 bits, numbers are even; content is a signed integer

They are also 4 floating point registers of 32 bits each, the numbers are even.

Command structure: 1 word, 2 words, 3 words; result at second address

COP - 7 bits, s - 1 bit, dd - 2 bits, r1 - 3 bits, r2 - 3 bits, o1 - 16 bits, o2 - 16 bits

s is the size of the operand (for integers)

s = 0 - 1 word

s = 1 - 2 words

dd - operand format (first and second)

dd = 00 - operands in registers; o1, o2 – absent;

dd = 01 - register - address

dd = 10 - address - register

dd = 11 - address - address

Address = register + offset (if register is used)

Address = offset (if no register is used)

Special cases: s=1, d = 0 (argument in register) and register number is odd

This is the format of transfers, integer arithmetic, fractional arithmetic;

Shipment:

Register-Register, Register-Memory, Memory-Register, Memory-Memory

fractional arithmetic, integer arithmetic - the same

Transitions:

Unconditional (use of s, dd bits - different from standard)

– s = 0: direct, IP = address

– s = 1: relative, IP = IP + address

dd = 00: address = r1 is an indirect jump

dd = 10: address = r2 is an indirect jump

dd = 11: address = r2+o2

dd = 01: address=o2

Conditional - the same, only flags are checked

Subroutine call - return address stored in r1

Return - unconditional direct transition (by any option)
