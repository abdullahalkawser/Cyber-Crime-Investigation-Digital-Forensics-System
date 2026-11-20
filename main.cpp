#include "system.h"
#include "ui.h"
int main(){
 UI::banner();
 UI::loading("Initializing Cyber Trace modules");
 UI::warn("Educational simulation only - use lawful, authorized evidence.");
 UI::sleep(500);
 CyberTrace app;
 app.run();
 return 0;
}
