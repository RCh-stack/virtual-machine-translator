#include "Command.h"

void Input::operator()(Memory &mem, const command48 &cmd)
{
    uint16_t s = cmd.cmd32.cmd16.s;
    std::cout << "Input: ";
    if(s == 0)
    {
        int16_t number;
        std::cin >> number;
        mem.regs.grp.pushShort(cmd.cmd32.cmd16.r1, number);
    }
    else if(s == 1)
    {
        int32_t number;
        std::cin >> number;
        mem.regs.grp.pushInt(cmd.cmd32.cmd16.r1, number);
    }
    else
    {
        float number;
        std::cin >> number;
        mem.regs.grp.pushFloat(cmd.cmd32.cmd16.r1, number);
    }
}

void Output::operator()(Memory &mem, const command48 &cmd)
{
    uint16_t s = cmd.cmd32.cmd16.s;
    if(s == 0)
    {
        int16_t result = mem.regs.grp.getShort(cmd.o2);
        std::cout << "Output = " << result << std::endl;
    }
    if(s == 1)
    {
        int32_t result = mem.regs.grp.getInt(cmd.o2);
        std::cout << "Output = " << result << std::endl;
    }
    if(s == 2)
    {
        float result = mem.regs.grp.getFloat(cmd.o2);
        std::cout << "Output = " << result << std::endl;
    }
}

void UMath::operator()(Memory &mem, const command48 &cmd)
{
    auto opc = cmd.cmd32.cmd16.opcode;
    uint16_t num1, num2, result;
    if(cmd.cmd32.cmd16.dd == 0)
    {
        num1 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 1)
    {
        num1 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getShort(cmd.cmd32.o1);
    }
    if(cmd.cmd32.cmd16.dd == 2)
    {
        num2 = mem.regs.grp.getShort(cmd.cmd32.o1);
        num2 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 3)
    {
        num1 = mem.regs.grp.getShort(cmd.cmd32.o1);
        num2 = mem.regs.grp.getShort(cmd.o2);
    }
    switch(opc)
    {
        case 3:
        {
            result = num1 + num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
        case 4:
        {
            result = num1 - num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
        case 5:
        {
            result = num1 * num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
        case 6:
        {
            result = num1 / num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
    }
}

void SMath::operator()(Memory &mem, const command48 &cmd)
{
    auto opc = cmd.cmd32.cmd16.opcode;
    int16_t num1, num2, result;
    if(cmd.cmd32.cmd16.dd == 0)
    {
        num1 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 1)
    {
        num1 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getShort(cmd.cmd32.o1);
    }
    if(cmd.cmd32.cmd16.dd == 2)
    {
        num2 = mem.regs.grp.getShort(cmd.cmd32.o1);
        num2 = mem.regs.grp.getShort(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 3)
    {
        num1 = mem.regs.grp.getShort(cmd.cmd32.o1);
        num2 = mem.regs.grp.getShort(cmd.o2);
    }
    switch(opc)
    {
        case 3:
        {
            result = num1 + num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
        case 4:
        {
            result = num1 - num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
        case 5:
        {
            result = num1 * num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
        case 6:
        {
            result = num1 / num2;
            mem.regs.grp.pushShort(cmd.o2, result);
            break;
        }
    }
}

void IMath::operator()(Memory &mem, const command48 &cmd)
{
    auto opc = cmd.cmd32.cmd16.opcode;
    int32_t num1, num2, result;
    if(cmd.cmd32.cmd16.dd == 0)
    {
        num1 = mem.regs.grp.getInt(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getInt(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 1)
    {
        num1 = mem.regs.grp.getInt(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getInt(cmd.cmd32.o1);
    }
    if(cmd.cmd32.cmd16.dd == 2)
    {
        num2 = mem.regs.grp.getInt(cmd.cmd32.o1);
        num2 = mem.regs.grp.getInt(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 3)
    {
        num1 = mem.regs.grp.getInt(cmd.cmd32.o1);
        num2 = mem.regs.grp.getInt(cmd.o2);
    }
    switch(opc)
    {
        case 11:
        {
            result = num1 + num2;
            mem.regs.grp.pushInt(cmd.o2, result);
            break;
        }
        case 12:
        {
            result = num1 - num2;
            mem.regs.grp.pushInt(cmd.o2, result);
            break;
        }
        case 13:
        {
            result = num1 * num2;
            mem.regs.grp.pushInt(cmd.o2, result);
            break;
        }
        case 14:
        {
            result = num1 / num2;
            mem.regs.grp.pushInt(cmd.o2, result);
            break;
        }
    }
}

void FMath::operator()(Memory &mem, const command48 &cmd)
{
    auto opc = cmd.cmd32.cmd16.opcode;
    float num1, num2, result;
    if(cmd.cmd32.cmd16.dd == 0)
    {
        num1 = mem.regs.grp.getFloat(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getFloat(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 1)
    {
        num1 = mem.regs.grp.getFloat(cmd.cmd32.cmd16.r1);
        num2 = mem.regs.grp.getFloat(cmd.cmd32.o1);
    }
    if(cmd.cmd32.cmd16.dd == 2)
    {
        num2 = mem.regs.grp.getFloat(cmd.cmd32.o1);
        num2 = mem.regs.grp.getFloat(cmd.cmd32.cmd16.r2);
    }
    if(cmd.cmd32.cmd16.dd == 3)
    {
        num1 = mem.regs.grp.getFloat(cmd.cmd32.o1);
        num2 = mem.regs.grp.getFloat(cmd.o2);
    }
    switch(opc)
    {
        case 15:
        {
            result = num1 + num2;
            mem.regs.grp.pushFloat(cmd.o2, result);
            break;
        }
        case 16:
        {
            result = num1 - num2;
            mem.regs.grp.pushFloat(cmd.o2, result);
            break;
        }
        case 17:
        {
            result = num1 * num2;
            mem.regs.grp.pushFloat(cmd.o2, result);
            break;
        }
        case 18:
        {
            result = num1 / num2;
            mem.regs.grp.pushFloat(cmd.o2, result);
            break;
        }
    }
}

void SCompare::operator()(Memory &mem, const command48 &cmd)
{
    if(mem.regs.grp.getShort(cmd.cmd32.cmd16.r1) == mem.regs.grp.getShort(cmd.cmd32.cmd16.r2))
    {
        mem.regs.psw.ZF = 1;
        mem.regs.psw.SF = 0;
        mem.regs.psw.CF = 0;
    } else
    if(mem.regs.grp.getShort(cmd.cmd32.cmd16.r1) < mem.regs.grp.getShort(cmd.cmd32.cmd16.r2))
    {
        mem.regs.psw.ZF = 0;
        mem.regs.psw.SF = 1;
        mem.regs.psw.CF = 1;
    }
    else
    {
        mem.regs.psw.ZF = 0;
        mem.regs.psw.SF = 0;
        mem.regs.psw.CF = 0;
    }
}

void ICompare::operator()(Memory &mem, const command48 &cmd)
{
    if(mem.regs.grp.getInt(cmd.cmd32.cmd16.r1) == mem.regs.grp.getInt(cmd.cmd32.cmd16.r2))
    {
        mem.regs.psw.ZF = 1;
        mem.regs.psw.SF = 0;
        mem.regs.psw.CF = 0;
    } else
    if(mem.regs.grp.getInt(cmd.cmd32.cmd16.r1) < mem.regs.grp.getInt(cmd.cmd32.cmd16.r2))
    {
        mem.regs.psw.ZF = 0;
        mem.regs.psw.SF = 1;
        mem.regs.psw.CF = 1;
    }
    else
    {
        mem.regs.psw.ZF = 0;
        mem.regs.psw.SF = 0;
        mem.regs.psw.CF = 0;
    }
}

void FCompare::operator()(Memory &mem, const command48 &cmd)
{
    if(mem.regs.grp.getFloat(cmd.cmd32.cmd16.r1) == mem.regs.grp.getFloat(cmd.cmd32.cmd16.r2))
    {
        mem.regs.psw.ZF = 1;
        mem.regs.psw.SF = 0;
        mem.regs.psw.CF = 0;
    } else
    if(mem.regs.grp.getFloat(cmd.cmd32.cmd16.r1) < mem.regs.grp.getFloat(cmd.cmd32.cmd16.r2))
    {
        mem.regs.psw.ZF = 0;
        mem.regs.psw.SF = 1;
        mem.regs.psw.CF = 1;
    }
    else
    {
        mem.regs.psw.ZF = 0;
        mem.regs.psw.SF = 0;
        mem.regs.psw.CF = 0;
    }
}

void Transition::operator()(Memory &mem, const command48 &cmd)
{
    auto opc = cmd.cmd32.cmd16.opcode;
    uint16_t s = cmd.cmd32.cmd16.s;
    switch(opc)
    {
        case 19:
        {
            if(s == 0)
            {
                int16_t num = mem.regs.grp.getShort(cmd.cmd32.cmd16.r1);
                num = mem.regs.grp.getShort(cmd.cmd32.cmd16.r2);
                mem.regs.grp.pushShort(cmd.cmd32.cmd16.r1, num);
            }
            else if(s == 1)
            {
                int32_t num = mem.regs.grp.getInt(cmd.cmd32.cmd16.r1);
                num = mem.regs.grp.getInt(cmd.cmd32.cmd16.r2);
                mem.regs.grp.pushInt(cmd.cmd32.cmd16.r1, num);
            }
            else
            {
                float num = mem.regs.grp.getFloat(cmd.cmd32.cmd16.r1);
                num = mem.regs.grp.getFloat(cmd.cmd32.cmd16.r2);
                mem.regs.grp.pushFloat(cmd.cmd32.cmd16.r1, num);
            }
            break;
        }
        case 20:
        {
            if(s == 0)
            {
                int16_t num = mem.regs.grp.getShort(cmd.cmd32.cmd16.r1);
                mem.regs.grp.pushShort(cmd.cmd32.cmd16.r2, num);
                mem.pushMemory(cmd.cmd32.o1, num);
            }
            else if(s == 1)
            {
                int32_t num = mem.regs.grp.getInt(cmd.cmd32.cmd16.r1);
                mem.regs.grp.pushInt(cmd.cmd32.cmd16.r2, num);
                mem.pushMemory(cmd.cmd32.o1, num);
            }
            else
            {
                float num = mem.regs.grp.getFloat(cmd.cmd32.cmd16.r1);
                mem.regs.grp.pushFloat(cmd.cmd32.cmd16.r2, num);
                mem.pushMemory(cmd.cmd32.o1, num);
            }
            break;
        }
        case 21:
        {
            if(s == 0)
                mem.pushMemory(mem.regs.grp.getShort(cmd.cmd32.cmd16.r1), cmd.cmd32.o1);
            else if(s == 1)
                mem.pushMemory(mem.regs.grp.getInt(cmd.cmd32.cmd16.r1), cmd.cmd32.o1);
            else
                mem.pushMemory(mem.regs.grp.getFloat(cmd.cmd32.cmd16.r1), cmd.cmd32.o1);
            break;
        }
        case 22:
        {
            mem.pushMemory(mem.getMemory(cmd.cmd32.o1), cmd.o2);
            break;
        }
    }
}

void Jump::operator()(Memory &mem, const command48 &cmd)
{
    if(cmd.cmd32.cmd16.opcode == 23)
    {
        uint16_t IP = cmd.cmd32.o1;
        mem.memory[IP] = cmd.o2;
    }
    if(cmd.cmd32.cmd16.opcode <= 24 || cmd.cmd32.cmd16.opcode >= 29)
    {
        ICompare()(mem, cmd);
        uint16_t IP = cmd.cmd32.o1;
        mem.memory[IP] = cmd.o2;
    }
    if(cmd.cmd32.cmd16.opcode == 30)
    {
        ICompare()(mem, cmd);
        uint16_t IP = cmd.cmd32.cmd16.r1;
        mem.memory[IP] = cmd.cmd32.o1;
    }
    if(cmd.cmd32.cmd16.opcode == 31)
    {
        Jump()(mem, cmd);
    }

}
