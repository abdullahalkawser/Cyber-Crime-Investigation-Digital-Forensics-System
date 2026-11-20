#include "system.h"
#include "ui.h"
void CyberTrace::requestMenu(){
 int ch;do{UI::clear();UI::title("INVESTIGATION REQUEST QUEUE (FIFO)");
 std::cout<<"1. Enqueue case request\n2. Process next request (dequeue)\n3. View queue\n0. Back\n";ch=UI::input("Choose: ");
 if(ch==1){int id=UI::input("Case ID to queue: ");bool ok=false;for(auto&c:cases)if(c.id==id)ok=true;if(ok){requests.push(id);UI::ok("Case request queued.");}else UI::error("Unknown Case ID.");}
 else if(ch==2){if(requests.empty())UI::warn("Queue is empty.");else{std::cout<<UI::GREEN<<"Processing Case #"<<requests.front()<<UI::R<<"\n";requests.pop();}}
 else if(ch==3){auto q=requests;if(q.empty())UI::warn("Queue is empty.");while(!q.empty()){std::cout<<"[Case "<<q.front()<<"] <- ";q.pop();}std::cout<<"END\n";}
 if(ch)UI::pause();
 }while(ch);
}
