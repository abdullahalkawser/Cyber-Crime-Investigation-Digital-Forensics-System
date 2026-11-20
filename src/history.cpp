#include "system.h"
#include "ui.h"
#include "storage.h"
void CyberTrace::historyMenu(){
 int ch;do{UI::clear();UI::title("INVESTIGATION ACTIVITY TIMELINE (SINGLY LINKED LIST)");
 std::cout<<"1. View activity history\n2. Add manual note\n0. Back\n";ch=UI::input("Choose: ");
 if(ch==1){Action* current=historyHead;if(!current)UI::warn("No activity in this session.");int i=1;while(current){std::cout<<"["<<i++<<"] "<<current->description<<" -> ";current=current->next;}std::cout<<"NULL\n";}
 else if(ch==2){auto note=UI::text("Activity note: ");addHistory(note);UI::ok("Activity node added at linked-list head.");}
 if(ch)UI::pause();
 }while(ch);
}
