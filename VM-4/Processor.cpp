#include "Processor.h"

// -- translate file in binary --
void Processor::convertToBinary(std::string filename)
{
    std::ifstream in(filename);
    std::ofstream out("input.bin", std::ios::binary);

    std::string str;
    while(in >> str)
        out.write((char*)&str, sizeof(str));

    in.close();
    out.close();
}

// -- translate file in txt --
void Processor::convertToTxt(std::string filename)
{
    std::ifstream in(filename, std::ios::binary);
    std::ofstream out("output.txt");

    char temp;
    while (in.read(&temp, sizeof(char)))
        out << temp;

    in.close();
    out.close();
}

// -- load program --
void Processor::load(std::string fname)
{
    command48 cmd; // -- command --
    Memory mem; // -- memory --

    std::ifstream f(fname, std::ios::binary);
    if(!f)
    {
        std::cout << "\nFile not found.\n" << std::endl;
        system("pause");
        exit(0);
    }
    uint16_t regis = 0; // -- address --

    uint16_t PC = 0;
    char temp;
    while (f.read(&temp, sizeof(char)))
    {
        mem.memory[PC] = temp;
        PC++;
    }

    PC = 0;
    while(true)
    {
        temp = mem.memory[PC];
        if(temp == 112)
        {
            regis = 0;
            PC += 5;
        } else
        if(temp == 105)
        {
            PC += 2;
            temp = mem.memory[PC];
            int32_t num = (int32_t)temp;
            mem.regs.grp.pushInt(regis, num);
            regis++;
            PC += 2;
        } else
        if(temp == 115)
        {
            PC += 2;
            temp = mem.memory[PC];
            int16_t num = (int16_t)temp;
            mem.regs.grp.pushShort(regis, num);
            regis++;
            PC += 2;
        } else
        if(temp == 102)
        {
            PC += 2;
            temp = mem.memory[PC];
            float num = (float)temp;
            mem.regs.grp.pushFloat(regis, num);
            regis++;
            PC += 2;
        } else
        if(temp == 99)
        {
            std::string code;
            PC += 2;
            char temp0 = mem.memory[PC];
            code.push_back(temp0);
            cmd.cmd32.cmd16.opcode = std::stoi(code);
            PC += 2;
            cmd.cmd32.cmd16.s = mem.memory[PC];
            PC += 2;

            char temp1, temp2;
            temp1 = mem.memory[PC];
            PC++;
            temp2 = mem.memory[PC];
            std::string s; s.push_back(temp1); s.push_back(temp2);
            if(s == "00")
                cmd.cmd32.cmd16.dd = 0;
            if(s == "01")
                cmd.cmd32.cmd16.dd = 1;
            if(s == "10")
                cmd.cmd32.cmd16.dd = 2;
            if(s == "11")
                cmd.cmd32.cmd16.dd = 3;
            PC += 2;
            cmd.cmd32.cmd16.r1 = mem.memory[PC];
            PC += 2;
            cmd.cmd32.cmd16.r2 = mem.memory[PC];
            PC += 2;
            cmd.cmd32.o1 = mem.memory[PC];
            PC += 2;
            cmd.o2 = mem.memory[PC];

            if(cmd.cmd32.cmd16.opcode == 1)
            {
                Input()(mem, cmd);
                PC += 3;
            }
            if(cmd.cmd32.cmd16.opcode == 2)
            {
                Output()(mem, cmd);
                PC += 3;
            }
            if(cmd.cmd32.cmd16.opcode == 3 || cmd.cmd32.cmd16.opcode == 4
               || cmd.cmd32.cmd16.opcode == 5 || cmd.cmd32.cmd16.opcode == 6)
            {
                SMath()(mem, cmd);
                PC += 4;
            }
            if(cmd.cmd32.cmd16.opcode == 7 || cmd.cmd32.cmd16.opcode == 8
               || cmd.cmd32.cmd16.opcode == 9 || cmd.cmd32.cmd16.opcode == 10)
            {
                UMath()(mem, cmd);
                PC += 4;
            }
            if(cmd.cmd32.cmd16.opcode == 11 || cmd.cmd32.cmd16.opcode == 12
               || cmd.cmd32.cmd16.opcode == 13 || cmd.cmd32.cmd16.opcode == 14)
            {
                IMath()(mem, cmd);
                PC += 4;
            }
            if(cmd.cmd32.cmd16.opcode == 15 || cmd.cmd32.cmd16.opcode == 16
               || cmd.cmd32.cmd16.opcode == 17 || cmd.cmd32.cmd16.opcode == 18)
            {
                FMath()(mem, cmd);
                PC += 4;
            }
            if(cmd.cmd32.cmd16.opcode == 19 || cmd.cmd32.cmd16.opcode == 20
               || cmd.cmd32.cmd16.opcode == 21 || cmd.cmd32.cmd16.opcode == 22)
            {
                Transition()(mem, cmd);
                PC += 4;
            }
            if(cmd.cmd32.cmd16.opcode >= 23 || cmd.cmd32.cmd16.opcode <= 31)
            {
                Jump()(mem, cmd);
                PC += 6;
            }
        } else
        if(temp == 101) // -- if prefix "e" --
        {
            std::cout << "\nStop processor.\n" << std::endl;
            PC = 0;
            system("pause");
            exit(0); // -- exit in app --
        }
    }
}

// -- run interpeter --
void Processor::run(std::string name)
{
    std::ifstream f(name);
    if(!f)
    {
        std::cout << "\nFile not found.\n" << std::endl;
        system("pause");
        exit(0);
    }
    else
        std::cout << "\nFile load.\n" << std::endl;
    load(name); // -- download command --
}
