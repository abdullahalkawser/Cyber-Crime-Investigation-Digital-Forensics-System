#include "system.h"
#include "ui.h"
void CyberTrace::stackMenu(){
 int ch;do{UI::clear();UI::title("INVESTIGATION ACTION STACK (LIFO)");
 std::cout<<"1. PUSH - add action/evidence ID to top\n2. POP - remove latest action\n3. Peek top action\n4. Display stack\n0. Back\n";ch=UI::input("Choose: ");
 if(ch==1){int id=UI::input("Action or Evidence ID: ");actionStack.push_back(id);addHistory("PUSH action ID "+std::to_string(id));UI::ok("Action pushed onto stack.");}
 else if(ch==2){if(actionStack.empty())UI::error("Stack underflow - no action to pop.");else{int id=actionStack.back();actionStack.pop_back();addHistory("POP action ID "+std::to_string(id));UI::ok("Latest action popped: "+std::to_string(id));}}
 else if(ch==3){if(actionStack.empty())UI::warn("Stack is empty.");else std::cout<<"TOP -> "<<actionStack.back()<<"\n";}
 else if(ch==4){if(actionStack.empty())UI::warn("Stack is empty.");for(int i=(int)actionStack.size()-1;i>=0;--i)std::cout<<"| "<<actionStack[i]<<" |\n";std::cout<<"--- BOTTOM ---\n";}
 if(ch)UI::pause();
 }while(ch);
}
