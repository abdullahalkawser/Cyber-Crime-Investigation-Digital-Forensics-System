# CYBER TRACE
## Cyber Crime Investigation & Digital Forensics Management System

A C++17 console-based educational project. The listed DSA topics are integrated into one simulated investigation workflow rather than presented as unrelated standalone demos.

### Core workflow
1. Register a cyber-crime case and assign a generated Case ID.
2. Add evidence records linked to a valid case.
3. Search evidence using Linear Search or Binary Search.
4. Sort evidence using Bubble, Selection, Insertion, Merge, Counting, or Radix Sort.
5. Track investigation actions using a singly linked-list activity timeline.
6. Queue case requests using FIFO Queue.
7. Review case/evidence analytics and export a report.

### DSA mapping
| Topic | Integrated use |
|---|---|
| Array insertion/deletion | Evidence register add/delete |
| Linear Search | Sequential evidence lookup |
| Binary Search | Lookup on sorted evidence copy |
| Bubble Sort | Sort evidence by risk |
| Selection Sort | Prioritize highest-priority evidence/cases (selection by priority field) |
| Insertion Sort | Sort evidence IDs |
| Merge Sort | Sort evidence IDs by divide-and-merge |
| Counting Sort | Group evidence by risk level |
| Radix Sort | Sort numeric evidence IDs |
| Singly Linked List | Investigation activity history (new activity nodes at head) |
| Stack PUSH/POP | Working investigation action stack with push, pop, peek and display |
| Queue ENQUEUE/DEQUEUE | Pending case request processing |

### Build and run (Ubuntu)
```bash
sudo apt update
sudo apt install g++ make
```
Extract the ZIP, open a terminal in the `CYBER_TRACE` folder, then:
```bash
make
./cyber_trace
```
Or compile without Make:
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o cyber_trace
./cyber_trace
```

### Data files
- `data/cases.csv` - case records
- `data/evidence.csv` - evidence records
- `data/activity.log` - activity log
- `data/latest_report.txt` - latest exported summary

Records are saved locally as plain CSV. Keep text fields simple (avoid commas) because the teaching version uses a basic CSV parser.

### Important
This is a classroom simulation. It does not access devices, networks, accounts, or real forensic evidence. Use only data you are authorized to handle.
# Cyber-Crime-Investigation-Digital-Forensics-System
