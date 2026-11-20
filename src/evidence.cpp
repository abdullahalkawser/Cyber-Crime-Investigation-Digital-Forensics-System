#include "system.h"
#include "ui.h"
#include "storage.h"
#include <algorithm>
void CyberTrace::evidenceMenu(){
 int ch;do{UI::clear();UI::title("DIGITAL EVIDENCE REGISTER");std::cout<<"1. Add evidence\n2. View evidence\n3. Delete evidence (array deletion)\n0. Back\n";ch=UI::input("Choose: ");
 if(ch==1){int cid=UI::input("Linked Case ID: ");bool valid=false;for(auto&c:cases)if(c.id==cid)valid=true;if(!valid)UI::error("Register a valid case first.");else{Evidence e;e.id=nextEvidenceId++;e.caseId=cid;e.type=UI::text("Evidence type (email/log/file/device): ");e.description=UI::text("Evidence description: ");e.source=UI::text("Evidence source/reference: ");e.risk=UI::input("Risk level (1-5): ");if(e.risk<1||e.risk>5)e.risk=3;evidence.push_back(e);addHistory("Added evidence #"+std::to_string(e.id));UI::ok("Evidence stored. Evidence ID: "+std::to_string(e.id));}}
 else if(ch==2){for(auto&e:evidence)std::cout<<"E-"<<e.id<<" | Case "<<e.caseId<<" | "<<e.type<<" | Risk "<<e.risk<<" | "<<e.description<<"\n";if(evidence.empty())UI::warn("Evidence register is empty.");}
 else if(ch==3){int id=UI::input("Evidence ID: ");auto n=evidence.size();evidence.erase(std::remove_if(evidence.begin(),evidence.end(),[&](auto&e){return e.id==id;}),evidence.end());if(n==evidence.size())UI::error("Evidence not found.");else{addHistory("Deleted evidence #"+std::to_string(id));UI::ok("Evidence deleted from array.");}}
 if(ch){save();UI::pause();}
 }while(ch);
}
