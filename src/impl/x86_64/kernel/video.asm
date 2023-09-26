section .text
global set_vga_mode

set_vga_mode:
    ; Set VGA mode 1280x720 (assuming function 0x4F02)
    mov ax, 0x4F02      ; Function 0x4F02 sets video mode
    mov bx, 0x128       ; Video mode 1280x720 (you may need to adjust this)

    ret
