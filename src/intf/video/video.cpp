#include <video/video.h>

extern "C" void set_vga_mode();

void VideoMode::setHDVideoMode() {
    set_vga_mode();
}