section .text
global read_directory

read_directory:
    ; Input:
    ;   ebx - Directory path or address of the directory structure
    ;   ecx - Maximum number of directory entries to read
    ; Output:
    ;   eax - Number of valid directory entries read

    ; Initialize the count to zero
    xor eax, eax

    ; Loop through directory entries
.loop:
    ; Read a directory entry from the disk or memory pointed by ebx
    ; (This involves reading a sector and parsing the directory entry format)

    ; Check if the entry is valid (not deleted or empty)
    ; (Check the attribute byte of the directory entry)
    ; If valid, increment the count

    ; Extract and process the file name or store information as needed

    ; Move to the next directory entry
    add ebx, 32  ; Assuming each entry is 32 bytes in size

    ; Decrement the counter
    dec ecx

    ; Check if we've reached the end of the directory or processed the desired number of entries
    jz .done

    ; Continue looping
    jmp .loop

.done:
    ; Set the return value (eax) to the count
    mov eax, ecx  ; Assuming ecx still contains the count

    ; Clean up and return
    ret
