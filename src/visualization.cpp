#include "system.h"
#include "ui.h"
#include <iostream>
void CyberTrace::visualizationMenu(){
 int ch=UI::input("1 Bubble Sort trace\n2 Linked List structure\n3 Stack PUSH/POP simulation\n4 Queue ENQUEUE/DEQUEUE simulation\nChoose: ");
 if(ch==1){int a[]={7,3,5,2};for(int i=0;i<3;i++)for(int j=0;j<3-i;j++){std::cout<<"Compare "<<a[j]<<" and "<<a[j+1];if(a[j]>a[j+1]){std::swap(a[j],a[j+1]);std::cout<<" -> SWAP";}else std::cout<<" -> KEEP";std::cout<<" | ";for(int x:a)std::cout<<"["<<x<<"]";std::cout<<"\n";UI::sleep(400);}}
 else if(ch==2){std::cout<<"HEAD -> [Evidence A] -> [Evidence B] -> [Evidence C] -> NULL\n";UI::warn("Each node stores a link to the next investigation event.");}
 else if(ch==3){std::cout<<"PUSH A: ";UI::sleep(250);std::cout<<"[A]\nPUSH B: ";UI::sleep(250);std::cout<<"[B]\n[A]\nPOP: B removed; A is now TOP.\n";}
 else if(ch==4){std::cout<<"ENQUEUE 101 -> [101]\nENQUEUE 102 -> [101] [102]\nDEQUEUE -> 101 processed; 102 is next.\n";}
 else UI::warn("Invalid option.");
 UI::pause();
}
