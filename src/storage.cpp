#include "storage.h"
#include <fstream>
#include <sstream>
namespace { const char* CASE_FILE="data/cases.csv"; const char* EVIDENCE_FILE="data/evidence.csv"; }
std::vector<CaseRecord> Storage::loadCases(){
 std::vector<CaseRecord> v; std::ifstream f(CASE_FILE); std::string l;
 while(std::getline(f,l)){std::stringstream s(l);CaseRecord c;std::string p;
  if(std::getline(s,p,','))c.id=std::stoi(p); if(std::getline(s,c.victim,',')){}
  if(std::getline(s,c.crimeType,',')){} if(std::getline(s,c.description,',')){}
  if(std::getline(s,c.status,',')){} if(std::getline(s,p,','))c.priority=std::stoi(p);
  if(c.id)v.push_back(c);
 }return v;
}
std::vector<Evidence> Storage::loadEvidence(){
 std::vector<Evidence> v;std::ifstream f(EVIDENCE_FILE);std::string l;
 while(std::getline(f,l)){std::stringstream s(l);Evidence e;std::string p;
  if(std::getline(s,p,','))e.id=std::stoi(p);if(std::getline(s,p,','))e.caseId=std::stoi(p);
  if(std::getline(s,e.type,',')){}if(std::getline(s,e.description,',')){}
  if(std::getline(s,e.source,',')){}if(std::getline(s,p,','))e.risk=std::stoi(p);
  if(e.id)v.push_back(e);
 }return v;
}
void Storage::saveCases(const std::vector<CaseRecord>&v){
 std::ofstream f(CASE_FILE);for(auto&c:v)f<<c.id<<","<<c.victim<<","<<c.crimeType<<","<<c.description<<","<<c.status<<","<<c.priority<<"\n";
}
void Storage::saveEvidence(const std::vector<Evidence>&v){
 std::ofstream f(EVIDENCE_FILE);for(auto&e:v)f<<e.id<<","<<e.caseId<<","<<e.type<<","<<e.description<<","<<e.source<<","<<e.risk<<"\n";
}
void Storage::appendLog(const std::string&s){std::ofstream f("data/activity.log",std::ios::app);f<<s<<"\n";}
