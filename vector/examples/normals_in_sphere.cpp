#include <iostream>
#include "../headers/rays.h"
#include<fstream>

//t*t*dot(​B​,​B​) + 2*t*dot(​B,A​-​C​) + dot(​A-C,A​-​C​) - R*R = 0
float ray_hit_sphere(const vec3 &center,float radius,const Ray &r){
 vec3 oc=r.origin()-center;
 float a=dot(r.direction(),r.direction());
 float b=2*dot(r.direction(),oc);
 float c= dot(oc,oc)- radius*radius;
 float discriminant=b*b - 4*a*c;
 if(discriminant< 0){
    return -1.0;
 }else{
    return (-b - sqrt(discriminant))/(2.0*a);
 }
}

vec3 color(const Ray &r){
    float t=ray_hit_sphere(vec3(0,0,-1),0.5,r);
    if(t>0.0){
        vec3 N =unit_vector(r.point_at_parameter(t)-vec3(0,0,-1));
        return 0.5*vec3(N.get_x()+1,N.get_y()+1,N.get_z()+1);
    }
    vec3 unit_direction=unit_vector(r.direction());
    t=0.5*(unit_direction.get_y()+1.0);
    return (1.0-t)*vec3(1.0,1.0,1.0) +t*vec3(0.5,0.1,1.0);
}
int main(){
    constexpr int nx=1920;
    constexpr int ny=1080;
    std::ofstream image("../data/normals_in_sphere_image_" + get_current_time() + ".ppm",std::ios::binary);
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