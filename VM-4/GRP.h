#ifndef GRP_H_INCLUDED
#define GRP_H_INCLUDED

#include <cinttypes>

class Registers
{
public:
    // -- flags --
    class PSW
    {
    public:
        uint16_t IP : 16; // -- program counter --
        uint16_t CF; // -- carry flag --
        uint16_t ZF; // -- null flag --
        uint16_t SF; // -- negative flag --

        PSW() : IP(0), CF(0), ZF(0), SF(0) { } // -- constructor --
        void reset_flags() noexcept { ZF = 0; CF = 0; SF = 0; } // -- reset flags --
    } psw{ };

    // -- general purpose registers --
    class GRP
	{
		int16_t grps[8];
		int32_t grpl[4];
		float grpf[4];

    public:
        void pushShort(uint16_t reg, int16_t num) { grps[reg] = num; }
        void pushInt(uint16_t reg, int32_t num) { grpl[reg] = num; }
        void pushFloat(uint16_t reg, float num) { grpf[reg] = num; }

        int16_t getShort(uint16_t reg) { return grps[reg]; }
        int32_t getInt(uint16_t reg) { return grpl[reg]; }
        float getFloat(uint16_t reg) { return grpf[reg]; }

	} grp{ };
};

#endif // GRP_H_INCLUDED
