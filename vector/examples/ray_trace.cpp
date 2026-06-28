#include <iostream>
#include "../headers/vec3.h"
#include "../headers/rays.h"
#include<fstream>


vec3 color(const Ray &r){
    vec3 unit_direction=unit_vector(r.direction());
    float t=0.5*(unit_direction.get_y() + 1.0);
    return (1.0-t)*vec3(1.0,1.0,1.0) +t*vec3(0.5,0.1,1.0);
}
int main(){
    constexpr int nx=1920;
    constexpr int ny=1080;
    std::ofstream image("../data/image_" + get_current_time() + ".ppm",std::ios::binary);
    image << "P6\n" << nx << " " << ny << "\n255\n";
    vec3 lower_left_conner(-2.0,-1.0,-1.0);
    vec3 horizontal(4.0,0.0,0.0);
    vec3 vertical(0.0,2.0,0.0);
    vec3 origin(0.0,0.0,0.0);
    for(int j=ny-1;j>=0;j--){
        for(int i=0;i<nx;i++){
            float u=float(i)/float(nx);
            float v=float(j)/float(ny);
            Ray r(origin,lower_left_conner + u*horizontal + v*vertical);
            vec3 col=color(r);
            auto ir = static_cast<unsigned char>(255.999f * col.get_r());
            auto ig = static_cast<unsigned char>(255.999f * col.get_g());
            auto ib = static_cast<unsigned char>(255.999f * col.get_b());
            unsigned char pixel[3] = {ir, ig, ib};
            image.write(reinterpret_cast<char*>(pixel), sizeof(pixel));
        }
    }    
    return 0;
}