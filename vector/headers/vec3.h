#pragma once
#include<iostream>
#include<cmath>
#include<cstdlib>

class vec3{
    public:
        float x,y,z;
        vec3():x(0),y(0),z(0){}; 
        vec3(float e0,float e1,float e2):x(e0),y(e1),z(e2){};        
        inline float get_x() const { return x; }
        inline float get_y() const { return y; }
        inline float get_z() const { return z; }
        inline float get_r() const { return x; }
        inline float get_g() const { return y; }
        inline float get_b() const { return z; }
        inline vec3 operator-()const{ return vec3(-x,-y,-z);}
        inline vec3 &operator+= (const vec3 &d){x+=d.x;y+=d.y;z+=d.z; return *this;}        
        inline vec3 &operator*= (const float v){x*=v;y*=v;z*=v; return *this;}
        inline vec3 &operator/= (const float t){return *this*=1/t;}
        inline float length() const { return std::sqrt(x*x+y*y+z*z);}
        inline float squared_length() const { return x*x+y*y+z*z;}
        inline void make_unit_vector(){
            float k=1.0f/length();
            x*=k;y*=k;z*=k;
        };
};

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}
inline vec3 operator*(float t, const vec3 &v) {
    return vec3(t * v.x, t * v.y, t * v.z);
}
inline vec3 operator*(const vec3 &v, float t) {
    return vec3(t * v.x, t * v.y, t * v.z);
}
inline vec3 operator/(const vec3 &v, float t) { 
    return vec3(v.x / t, v.y / t, v.z / t);
}
inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3((v1.y * v2.z - v1.z * v2.y), (-(v1.x * v2.z - v1.z * v2.x)), (v1.x * v2.y - v1.y * v2.x));
}

inline std::istream &operator>>(std::istream &is,vec3 &t){
    is>>t.x>>t.y>>t.z;
    return is;
}

inline std::ostream &operator<<(std::ostream &os,const vec3 &t){
    os<<t.x<<t.y<<t.z;
    return os;
}
inline vec3 unit_vector(vec3 v){
    return v/v.length();
}

std::string get_current_time();