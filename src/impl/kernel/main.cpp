#include <cstdint>

#include <keyboard/keyboard.h>
#include <print/print.h>

#include <helper/helper.h>

extern "C" void kernel_main() {
    Print print_screen;
    Keyboard kbd;

    print_screen.init();
    print_screen.pset_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    kbd.initializeKeyboard();

    bool isDebuggingScanCodes = false;
    bool isShiftKeyPressed    = false;
    bool isCapsLockToggled    = false;

    while (1)
    {
        uint8_t scancode = kbd.readKeyboard();
        // Check if the scancode is within the valid range
        if (scancode == 0x2A || scancode == 54) // If shift key is pressed
            isShiftKeyPressed = true;
        else if (scancode == 0xAA || scancode == 182)
            isShiftKeyPressed = false;

        if (scancode == 58) // If caps key is pressed
            isCapsLockToggled = !isCapsLockToggled;
        
        if (isDebuggingScanCodes)
        {
            char str[6];
            uint8ToString(scancode, str, sizeof(str));
            print_screen.pstr((const char*)str);
        }

        if (scancode < sizeof(scancode_to_char)) {
            char character = scancode_to_char[scancode];
            if (character != 0) {
                if ((isShiftKeyPressed && !isCapsLockToggled))
                    character = toShiftedUpperCase(character);
                if ((!isShiftKeyPressed && isCapsLockToggled))
                    character = toCappedUpperCase(character);

                print_screen.pchar(character);
            }
        }

    }

    return;
}