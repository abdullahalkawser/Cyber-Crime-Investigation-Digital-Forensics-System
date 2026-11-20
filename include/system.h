#pragma once
#include "models.h"
#include <vector>
#include <queue>
#include <string>
class CyberTrace {
 std::vector<CaseRecord> cases;
 std::vector<Evidence> evidence;
 Action* historyHead = nullptr;
 std::vector<int> actionStack;
 std::queue<int> requests;
 int nextCaseId=1001, nextEvidenceId=5001;
 void save();
 void caseMenu();
 void evidenceMenu();
 void searchMenu();
 void sortingMenu();
 void historyMenu();
 void stackMenu();
 void requestMenu();
 void reportsMenu();
 void visualizationMenu();
 void addHistory(const std::string&);
public:
 CyberTrace();
 void run();
};
