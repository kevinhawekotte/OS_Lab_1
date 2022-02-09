#include <iostream>
#include <sys/utsname.h>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

void sweetfunc1(){
    std::ifstream sweetif("/proc/stat");
    std::string sweetl;
    while(std::getline(sweetif,sweetl)){
        if(sweetl.find(std::string("btime")) != std::string::npos){
            std::cout << sweetl.substr(6) << std::endl;
            auto t = (time_t) std::stol(sweetl.substr(6));
            auto sweetT = *std::localtime(&t);
            std::cout << std::put_time(&sweetT,"%Y-%m-%d %H:%M:%S");
            std::cout << std::endl;
        }
    }
}
void uptimefunc(long seconds){

    int day = seconds / 86400;
    int hour = (seconds % 86400) / 3600;
    int minutes = (seconds % 3600) / 60;
    int second = (seconds % 60);

    std::cout << day<< ":" << hour << ":" << minutes << ":" << second << std::endl;
}
void sweetfunc2(){
    std::ifstream sweetif("/proc/uptime");
    std::string sweetl;
    while(std::getline(sweetif,sweetl)){

        long uptime = std::stol(sweetl.substr(0 ,sweetl.find(" ")) );
        std::cout << "uptime: ";
        uptimefunc(uptime);
        long idletime = std::stol( sweetl.substr(sweetl.find(" ") + 1));
        std::cout << "idle time: ";
        uptimefunc(idletime);

        sweetl.substr(sweetl.find(" "));
    }
}
void sweetfunc3(){
    std::ifstream sweetif("/proc/stat");
    std::string sweetl;
    while(std::getline(sweetif,sweetl)){
        if(sweetl.find(std::string("cpu")) != std::string::npos){
            sweetl.substr(sweetl.find(" ") + 1);
        }
    }
}
void sweetfunc4(){
    std::ifstream sweetif("/proc/meminfo");
    std::string sweetl;
    while(std::getline(sweetif,sweetl)){
        if(sweetl.find(std::string("MemTotal:")) != std::string::npos ||
                sweetl.find(std::string("MemAvailable:")) != std::string::npos ){
            sweetl.substr(sweetl.find(" ") + 1);
            std::cout << sweetl << std::endl;
        }
    }
}

int main() {
    utsname sweet{};
    uname(&sweet);

    std::cout << "System Name : "<< sweet.sysname << std::endl;
    std::cout << "Nodename : " << sweet.nodename << std::endl;
    std::cout << "Release : " << sweet.release << std::endl;
    std::cout << "Version : "<< sweet.version << std::endl;
    std::cout << "Machine : " << sweet.machine << std::endl;

    std::cout << std::endl;

    sweetfunc1();
    std::cout << std::endl;
    sweetfunc2();
    std::cout << std::endl;
    // Ethan refused to help with sweetfunc3();
    sweetfunc4();

    return 0;
}
