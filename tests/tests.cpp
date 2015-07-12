
#include "sourcesdk/bitbuf.h"
#include <cstdint>
#include <iostream>

void PrintBits(std::uint8_t value)
{
    std::cout << ((value & 0x80) ? "1" : "0");
    std::cout << ((value & 0x40) ? "1" : "0");
    std::cout << ((value & 0x20) ? "1" : "0");
    std::cout << ((value & 0x10) ? "1" : "0");
    std::cout << ((value & 0x08) ? "1" : "0");
    std::cout << ((value & 0x04) ? "1" : "0");
    std::cout << ((value & 0x02) ? "1" : "0");
    std::cout << ((value & 0x01) ? "1" : "0");
}

int main()
{
    std::uint8_t buffer[4] = {};
    bf_write bitwrite(buffer, sizeof(buffer));

    const uint8_t initialData = 0xC0; // [1100 0000]
    const uint8_t dataToWrite = 0x0D; // [0000 1101]
    const uint8_t dataAfter   = 0x0C; // [0000 1100]
    const uint8_t finalData   = 0x00; // [0000 0000]

    bitwrite.WriteBits(&initialData, 5); // [1100 0]
    bitwrite.WriteBits(&dataToWrite, 2); // [1100 000]
    bitwrite.WriteBits(&dataAfter, 6);   // [1100 0000 0001 1]
    bitwrite.WriteBits(&finalData, 3);   // [1100 0000 0001 1000]

    std::cout << "initialData: ";
    PrintBits(initialData);
    std::cout << std::endl;

    std::cout << "dataToWrite: ";
    PrintBits(dataToWrite);
    std::cout << std::endl;

    std::cout << "dataAfter:   ";
    PrintBits(dataAfter);
    std::cout << std::endl;

    std::cout << "finalData:   ";
    PrintBits(finalData);
    std::cout << std::endl;

    std::cout << "expected:    1100000000011000" << std::endl;

    std::cout << "actual:      ";
    PrintBits(buffer[0]);
    PrintBits(buffer[1]);
    std::cout << std::endl;
    // buffer:  20 06 00 00
    return 0;
}
