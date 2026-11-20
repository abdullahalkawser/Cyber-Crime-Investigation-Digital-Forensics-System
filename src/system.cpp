#include "system.h"
#include "ui.h"
#include "storage.h"
#include <algorithm>
#include <iostream>
CyberTrace::CyberTrace(){cases=Storage::loadCases();evidence=Storage::loadEvidence();for(auto&c:cases)nextCaseId=std::max(nextCaseId,c.id+1);for(auto&e:evidence)nextEvidenceId=std::max(nextEvidenceId,e.id+1);}
void CyberTrace::save(){Storage::saveCases(cases);Storage::saveEvidence(evidence);}
void CyberTrace::addHistory(const std::string&s){
 Action* node=new Action(s); node->next=historyHead; historyHead=node;
 Storage::appendLog(s);
}
void CyberTrace::run(){
 UI::banner();UI::loading("Starting secure investigation workspace");UI::sleep(250);
 int ch;do{UI::banner();std::cout<<UI::WHITE<<"  SYSTEM STATUS: ONLINE | CASES: "<<cases.size()<<" | EVIDENCE: "<<evidence.size()<<"\n"<<UI::R;
 std::cout<<"\n [01] Case Management\n [02] Digital Evidence Register\n [03] Evidence Search Engine\n [04] Evidence Sorting Engine\n [05] Investigation Activity History\n [06] Investigation Request Queue\n [07] Forensic Analytics & Export Report\n [08] DSA Visualization Lab\n [00] Exit\n";
 UI::line();ch=UI::input(" Select module: ");
 switch(ch){case 1:caseMenu();break;case 2:evidenceMenu();break;case 3:searchMenu();break;case 4:sortingMenu();break;case 5:historyMenu();break;case 6:stackMenu();break;case 7:requestMenu();break;case 8:reportsMenu();break;case 9:visualizationMenu();break;case 0:save();UI::ok("All records saved. Secure shutdown.");break;default:UI::error("Invalid menu option.");UI::pause();}
 }while(ch);
}
