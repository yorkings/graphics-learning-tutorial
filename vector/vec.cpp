#include "headers/vec3.h"
#include<fstream>
int main(){
    constexpr int nx=1920;
    constexpr int ny=1080;
    std::ofstream image("../data/image_" + get_current_time() + ".ppm",std::ios::binary);
    image << "P6\n" << nx << " " << ny << "\n255\n";
    for(int j=ny-1;j>=0;j--){
        for(int i=0;i<nx;i++){
            vec3 color(float(i)/float(nx),float(j)/float(ny),0.25);
            auto ir = static_cast<unsigned char>(255.999f * color.get_r());
            auto ig = static_cast<unsigned char>(255.999f * color.get_g());
            auto ib = static_cast<unsigned char>(255.999f * color.get_b());
            unsigned char pixel[3] = {ir, ig, ib};
            image.write(reinterpret_cast<char*>(pixel), sizeof(pixel));
        }
    }    
    return 0;
}