#include <fstream>

int main() {
    constexpr int nx = 1920;
    constexpr int ny = 1080;
    
    // Open file in BINARY mode
    std::ofstream image("../image_hex.ppm", std::ios::binary);
    
    // Write Header (P6 instead of P3)
    image << "P6\n" << nx << " " << ny << "\n255\n";

    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            // Calculate colors as before
            unsigned char r = static_cast<unsigned char>(255.999 * i / (nx - 1));
            unsigned char g = static_cast<unsigned char>(255.999 * j / (ny - 1));
            unsigned char b = static_cast<unsigned char>(255.999 * 0.25);            
            // Write raw bytes directly (no spaces, no newlines between pixels)
            image << r << g << b;
        }
    }
    return 0;
}   