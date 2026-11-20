#include "system.h"
#include "ui.h"
#include <algorithm>
void CyberTrace::searchMenu(){
 int ch=UI::input("1. Linear search by Evidence ID\n2. Binary search by Evidence ID (sorted copy)\nChoose: ");
 int id=UI::input("Evidence ID: ");
 if(ch==1){bool found=false;for(size_t i=0;i<evidence.size();++i){std::cout<<"Linear scan index "<<i<<" -> "<<evidence[i].id<<"\n";UI::sleep(160);if(evidence[i].id==id){auto&e=evidence[i];std::cout<<UI::GREEN<<"FOUND: Case "<<e.caseId<<" | "<<e.type<<" | "<<e.description<<UI::R<<"\n";found=true;break;}}if(!found)UI::error("Evidence not found.");}
 else if(ch==2){auto a=evidence;std::sort(a.begin(),a.end(),[](auto&x,auto&y){return x.id<y.id;});int l=0,r=(int)a.size()-1;bool found=false;while(l<=r){int m=l+(r-l)/2;std::cout<<"low="<<l<<" mid="<<m<<" high="<<r<<" | checking "<<a[m].id<<"\n";UI::sleep(250);if(a[m].id==id){std::cout<<UI::GREEN<<"FOUND: Case "<<a[m].caseId<<" | "<<a[m].type<<" | "<<a[m].description<<UI::R<<"\n";found=true;break;}if(a[m].id<id)l=m+1;else r=m-1;}if(!found)UI::error("Evidence not found.");}
 else UI::warn("Invalid option.");
 addHistory("Searched evidence ID "+std::to_string(id));UI::pause();
}
