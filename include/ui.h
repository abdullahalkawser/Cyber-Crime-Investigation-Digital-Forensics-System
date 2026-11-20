#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <limits>
#include <cstdlib>
namespace UI {
inline const std::string R="\033[0m", RED="\033[31m", GREEN="\033[32m",
 YELLOW="\033[33m", BLUE="\033[34m", MAGENTA="\033[35m", CYAN="\033[36m",
 WHITE="\033[97m", BOLD="\033[1m";
inline void sleep(int ms=180){std::this_thread::sleep_for(std::chrono::milliseconds(ms));}
inline void clear(){
#ifdef _WIN32
 std::system("cls");
#else
 std::cout<<"\033[2J\033[H";
#endif
}
inline void line(){std::cout<<CYAN<<"===================================================================="<<R<<"\n";}
inline void title(const std::string&s){line();std::cout<<BOLD<<GREEN<<"  "<<s<<R<<"\n";line();}
inline void loading(const std::string&s){
 std::cout<<YELLOW<<"  "<<s<<"\n  ["<<R;
 for(int i=0;i<32;i++){std::cout<<GREEN<<"#"<<R<<std::flush;sleep(18);}
 std::cout<<"] 100%\n";
}
inline void banner(){
 clear(); std::cout<<GREEN<<BOLD;
 std::cout<<"   _____ _   _ ____  _____ ____      _____ ____ _____\n";
 std::cout<<"  / ____| | | |  _ \\| ____|  _ \\    |_   _|  _ \\ ____|\n";
 std::cout<<" | |    | | | | |_) |  _| | |_) |     | | | |_) |  _|\n";
 std::cout<<" | |____| |_| |  _ <| |___|  _ <      | | |  _ <| |___\n";
 std::cout<<"  [ CYBER TRACE // FORENSIC SYSTEM ]\n"<<R;
 line(); std::cout<<MAGENTA<<BOLD<<"       CYBER CRIME INVESTIGATION & DIGITAL FORENSICS\n"<<R;line();
}
inline int input(const std::string&p){
 int x; while(true){std::cout<<YELLOW<<p<<R;if(std::cin>>x)return x;
 std::cout<<RED<<"Please enter a valid number.\n"<<R;std::cin.clear();
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');}
}
inline std::string text(const std::string&p){
 std::cout<<YELLOW<<p<<R; std::string s; std::getline(std::cin>>std::ws,s); return s;
}
inline void pause(){std::cout<<CYAN<<"\nPress ENTER to continue..."<<R;
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');std::cin.get();}
inline void ok(const std::string&s){std::cout<<GREEN<<"[SUCCESS] "<<s<<R<<"\n";}
inline void warn(const std::string&s){std::cout<<YELLOW<<"[INFO] "<<s<<R<<"\n";}
inline void error(const std::string&s){std::cout<<RED<<"[ERROR] "<<s<<R<<"\n";}
}
