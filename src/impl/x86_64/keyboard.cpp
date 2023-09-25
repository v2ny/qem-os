#include <cstdint>
#include "keyboard/keyboard.h"

#include "asm/read.h"
#include "asm/write.h"

void Keyboard::initializeKeyboard()
{
    outb(0x60, 0xF4);
}

uint8_t Keyboard::readKeyboard()
{
    while (!(inb(0x64) & 0x01));
    return inb(0x60); 
}