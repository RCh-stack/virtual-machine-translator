#include <iostream>
#include "Processor.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "VM-4. Developed: Chuprey Roman. ASTU, 2021." << endl;
    Memory memory; // -- memory --
    Processor proc(&memory); // -- init processor --
    string filename; // -- loading file --
    cout << "Input file name: "; cin >> filename;
    proc.convertToBinary(filename); // -- translate file in executable binary --
    proc.convertToTxt(filename); // -- translate file in txt (demonstrate) --
    proc.run(filename); // -- load file, start processor --
    system("pause");
    return 0;
}
