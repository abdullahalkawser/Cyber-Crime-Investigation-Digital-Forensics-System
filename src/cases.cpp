#include "system.h"
#include "ui.h"
#include "storage.h"
#include <algorithm>
#include <iostream>
void CyberTrace::caseMenu(){
 int ch;do{UI::clear();UI::title("CASE MANAGEMENT");std::cout<<"1. Register new case\n2. List all cases\n3. Update case status\n4. Delete case\n0. Back\n";ch=UI::input("Choose: ");
 if(ch==1){CaseRecord c;c.id=nextCaseId++;c.victim=UI::text("Victim / reporter name: ");c.crimeType=UI::text("Crime category: ");c.description=UI::text("Case description: ");c.status="OPEN";c.priority=UI::input("Priority (1 low - 5 critical): ");if(c.priority<1||c.priority>5)c.priority=3;cases.push_back(c);addHistory("Registered case #"+std::to_string(c.id));UI::ok("Case registered. Case ID: "+std::to_string(c.id));}
 else if(ch==2){for(auto&c:cases)std::cout<<"#"<<c.id<<" | "<<c.victim<<" | "<<c.crimeType<<" | "<<c.status<<" | Priority "<<c.priority<<"\n";if(cases.empty())UI::warn("No cases registered.");}
 else if(ch==3){int id=UI::input("Case ID: ");auto it=std::find_if(cases.begin(),cases.end(),[&](auto&c){return c.id==id;});if(it==cases.end())UI::error("Case not found.");else{it->status=UI::text("New status (OPEN/IN PROGRESS/CLOSED): ");addHistory("Updated case status #"+std::to_string(id));UI::ok("Case status updated.");}}
 else if(ch==4){int id=UI::input("Case ID to delete: ");auto n=cases.size();cases.erase(std::remove_if(cases.begin(),cases.end(),[&](auto&c){return c.id==id;}),cases.end());if(n==cases.size())UI::error("Case not found.");else{evidence.erase(std::remove_if(evidence.begin(),evidence.end(),[&](auto&e){return e.caseId==id;}),evidence.end());addHistory("Deleted case #"+std::to_string(id));UI::ok("Case and linked evidence deleted.");}}
 if(ch) {save();UI::pause();}
 }while(ch);
}
