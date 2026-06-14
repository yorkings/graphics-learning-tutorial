#include<iostream>
#include<fstream>

int main() {
    constexpr int nx = 1920;
    constexpr int ny = 1080;
    std::ofstream image("image_int.ppm");

    image << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            int r = static_cast<int>(255.999 * i / (nx - 1));
            int g = static_cast<int>(255.999 * j / (ny - 1));
            int b = static_cast<int>(255.999 * 0.25);
            image << r << " " << g << " " << b << "\n";
        }
    }
    return 0;
}