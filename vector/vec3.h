#pragma once
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>

class Vec3 ;

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

};
