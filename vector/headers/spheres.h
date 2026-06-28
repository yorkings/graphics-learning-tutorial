#pragma once
#include "hits.h"

class sphere:public hitable{
    public:
        vec3 center;
        float radius;
        sphere(){};
        sphere(vec3 cen,float r):center(cen),radius(r){};
        virtual bool hit(const Ray &r,float t_min,float t_max,hit_record &rec)const;
        
};

bool sphere::hit(const Ray &r,float t_min,float t_max,hit_record &rec)const{
    vec3 oc=r.origin()-center;
    float a=dot(r.direction(),r.direction());
    float b=2*dot(r.direction(),oc);
    float c= dot(oc,oc)- radius*radius;
    float discriminant=b*b - 4*a*c;
    if(discriminant>0){
        float temp=(-b - sqrt(b*b - a*c))/(2.0*a);
        if(temp<t_max && temp>t_min){
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal=(rec.p-center)/radius;
            return true;
        }
        temp=(-b + sqrt(b*b - a*c))/(2.0*a);
        if(temp<t_max && temp>t_min){
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal=(rec.p-center)/radius;
            return true;
        }       
    }
    return false;
}