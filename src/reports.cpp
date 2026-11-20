#include "system.h"
#include "ui.h"
#include <fstream>
#include <iostream>
void CyberTrace::reportsMenu(){
 int open=0,closed=0,high=0,risks[6]={};
 for(auto&c:cases){if(c.status=="CLOSED")closed++;else open++;if(c.priority>=4)high++;}
 for(auto&e:evidence)if(e.risk>=1&&e.risk<=5)risks[e.risk]++;
 UI::title("FORENSIC ANALYTICS & REPORT");
 std::cout<<"Total cases       : "<<cases.size()<<"\nOpen/in progress  : "<<open<<"\nClosed cases      : "<<closed<<"\nHigh priority     : "<<high<<"\nTotal evidence    : "<<evidence.size()<<"\n";
 std::cout<<"\nEvidence risk distribution:\n";for(int i=1;i<=5;i++)std::cout<<"Risk "<<i<<" : "<<risks[i]<<"\n";
 std::ofstream f("data/latest_report.txt");f<<"CYBER TRACE - INVESTIGATION SUMMARY\nTotal cases: "<<cases.size()<<"\nOpen/in progress: "<<open<<"\nClosed: "<<closed<<"\nHigh priority: "<<high<<"\nEvidence: "<<evidence.size()<<"\nRisk distribution:\n";for(int i=1;i<=5;i++)f<<"Risk "<<i<<": "<<risks[i]<<"\n";
 UI::ok("Report exported to data/latest_report.txt");UI::pause();
}
