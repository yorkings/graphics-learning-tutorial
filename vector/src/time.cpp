#include "../headers/vec3.h"
#include<ctime>
#include<chrono>
#include <iomanip>
#include <sstream>

std::string  get_current_time(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);
    std::ostringstream oss;
    oss << std::put_time(local_time, "%Y_%m_%d_%H_%M_%S");
    return oss.str();
}