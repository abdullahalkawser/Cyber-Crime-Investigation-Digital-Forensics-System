#pragma once
#include <string>
struct CaseRecord {
    int id{};
    std::string victim, crimeType, description, status;
    int priority{};
};
struct Evidence {
    int id{}, caseId{};
    std::string type, description, source;
    int risk{};
};
struct Action {
    std::string description;
    Action* next;
    explicit Action(const std::string& value) : description(value), next(nullptr) {}
};
