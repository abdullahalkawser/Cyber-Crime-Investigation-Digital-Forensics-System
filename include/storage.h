#pragma once
#include "models.h"
#include <vector>
#include <string>
class Storage {
public:
 static std::vector<CaseRecord> loadCases();
 static std::vector<Evidence> loadEvidence();
 static void saveCases(const std::vector<CaseRecord>&);
 static void saveEvidence(const std::vector<Evidence>&);
 static void appendLog(const std::string&);
};
