#include <cstdint>
#include <keyboard/keyboard.h>

#include <utils/read.h>
#include <utils/write.h>

void Keyboard::initializeKeyboard()
{
    outb(0x60, 0xF4);
}

uint8_t Keyboard::readKeyboard()
{
    while (!(inb(0x64) & 0x01));
    return inb(0x60); 
}