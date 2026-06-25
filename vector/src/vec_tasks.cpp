#include "../headers/vec3.h"

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