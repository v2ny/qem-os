#pragma once

char toShiftedUpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        // ASCII values of lowercase letters are 32 greater than their uppercase counterparts
        return c - 32;
    }
    else
    {
        switch (c)
        {
            case '`':
                c = '~';
                break;

            case '1':
                c = '!';
                break;
            case '2':
                c = '@';
                break;
            case '3':
                c = '#'; 
                break;
            case '4':
                c = '$';
                break;
            case '5':
                c = '%';
                break;
            case '6':
                c = '^';
                break;       
            case '7':
                c = '&';
                break;     
            case '8':
                c = '*';
                break;     
            case '9':
                c = '(';   
                break; 
                break; 
            case '0':
                c = ')';
                break;     

            case '-':
                c = '_';
                break;
            case '=':
                c = '+';
                break;

            case '[':
                c = '{';
                break;      
            case ']':
                c = '}';
                break;  

            case ';':
                c = ':';
                break;
            case '\'':
                c = '"';
                break;    
            case '\\':
                c = '|';
                break;  
            
            case ',':
                c = '<';
                break;  
            case '.':
                c = '>';
                break;
            case '/':
                c = '?';  
                break;
        }

        return c;
    }
}

char toCappedUpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        // ASCII values of lowercase letters are 32 greater than their uppercase counterparts
        return c - 32;
    }

    return c;
}

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        // ASCII values of lowercase letters are 32 greater than their uppercase counterparts
        return c + 32;
    }
    return c; // If it's not a lowercase letter, return it as-is
}

void uint8ToString(uint8_t value, char* str, size_t bufferSize) {
    if (bufferSize < 4) {
        // Ensure the buffer is large enough to hold the result
        if (str != nullptr) {
            str[0] = '\0'; // Not enough space, return an empty string
        }
        return;
    }

    // Convert the uint8_t value to a string
    int numDigits = 0;
    do {
        str[numDigits] = '0' + (value % 10); // Extract and store the digit
        value /= 10;
        numDigits++;
    } while (value > 0);

    // Reverse the string to get the correct order of digits
    for (int i = 0, j = numDigits - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    str[numDigits] = '\0'; // Null-terminate the string
}