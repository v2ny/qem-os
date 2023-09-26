#include <print/print.h>

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = reinterpret_cast<struct Char*>(0xb8000);
size_t col = 0;
size_t row = 0;
uint8_t character = ' ';
uint8_t color = PRINT_COLOR_WHITE | (PRINT_COLOR_BLACK << 4);

void clear_row(size_t row) {
    struct Char empty = {
        character = ' ',
        color = color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void Print::init() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_ROWS - 1);
}

void Print::jmp_prow()
{
    if ( row > 0 ) row--;
    return;
}

void Print::jmp_frow()
{
    if ( row < NUM_ROWS ) row++;
    return;
}

void Print::pchar(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }

    if (character == '\b')
    {
        struct Char empty = {
            character = ' ',
            color = color,
        };


        if (col <= 0 && row > 0)
        {
            row--;
            for (int c = NUM_COLS; c >= 0 && buffer[c + NUM_COLS * row].character == ' '; c--) col = c;
            return;
        }
        
        if (col != 0) col--;
        buffer[col + NUM_COLS * row] = empty;

        return;
    }

    if (col == NUM_COLS) {
        print_newline();
    }

    if ( character == '\t' )
        for(int i = 0; i <= 4; i++)
        {
            buffer[col + NUM_COLS * row] = {
                ' ',
                color,
            };
            col++;
        }
    else
    {
        buffer[col + NUM_COLS * row] = {
            static_cast<uint8_t>(character),
            color,
        };
        col++;
    }

}

void Print::pstr(const char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        char character = static_cast<uint8_t>(str[i]);
        pchar(character);
    }
}

void Print::pset_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}