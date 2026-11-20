#include "system.h"
#include "ui.h"
#include <algorithm>
#include <vector>
#include <iostream>
namespace {
void show(const std::vector<Evidence>&a){for(auto&e:a)std::cout<<"E"<<e.id<<"(risk "<<e.risk<<") ";std::cout<<"\n";}
void bubble(std::vector<Evidence>&a){for(int i=0;i<(int)a.size()-1;i++)for(int j=0;j<(int)a.size()-i-1;j++){std::cout<<"Compare "<<a[j].risk<<" and "<<a[j+1].risk<<"\n";if(a[j].risk>a[j+1].risk)std::swap(a[j],a[j+1]);show(a);UI::sleep(180);}}
void selection(std::vector<Evidence>&a){for(int i=0;i<(int)a.size();i++){int m=i;for(int j=i+1;j<(int)a.size();j++)if(a[j].risk>a[m].risk)m=j;std::swap(a[i],a[m]);std::cout<<"Highest risk selected: ";show(a);UI::sleep(180);}}
void insertion(std::vector<Evidence>&a){for(int i=1;i<(int)a.size();i++){auto key=a[i];int j=i-1;while(j>=0&&a[j].id>key.id){a[j+1]=a[j];--j;show(a);UI::sleep(150);}a[j+1]=key;}}
void mergeParts(std::vector<Evidence>&a,int l,int m,int r){std::vector<Evidence>L(a.begin()+l,a.begin()+m+1),R(a.begin()+m+1,a.begin()+r+1);int i=0,j=0,k=l;while(i<(int)L.size()&&j<(int)R.size())a[k++]=(L[i].id<R[j].id)?L[i++]:R[j++];while(i<(int)L.size())a[k++]=L[i++];while(j<(int)R.size())a[k++]=R[j++];show(a);}
void mergeSort(std::vector<Evidence>&a,int l,int r){if(l>=r)return;int m=(l+r)/2;mergeSort(a,l,m);mergeSort(a,m+1,r);mergeParts(a,l,m,r);}
void counting(std::vector<Evidence>&a){int c[6]={};for(auto&e:a)c[e.risk]++;int k=0;for(int r=1;r<=5;r++)while(c[r]--)a[k++].risk=r;std::stable_sort(a.begin(),a.end(),[](auto&x,auto&y){return x.risk<y.risk;});}
void radix(std::vector<Evidence>&a){std::vector<Evidence>out(a.size());int mx=0;for(auto&e:a)mx=std::max(mx,e.id);for(int exp=1;mx/exp>0;exp*=10){int c[10]={};for(auto&e:a)c[(e.id/exp)%10]++;for(int i=1;i<10;i++)c[i]+=c[i-1];for(int i=(int)a.size()-1;i>=0;i--){int d=(a[i].id/exp)%10;out[--c[d]]=a[i];}a=out;if(exp>mx/10)break;}}
}
void CyberTrace::sortingMenu(){
 UI::title("EVIDENCE SORTING ENGINE");
 std::cout<<"1 Bubble Sort - ascending risk\n2 Selection Sort - highest priority first\n3 Insertion Sort - Evidence ID\n4 Merge Sort - Evidence ID\n5 Counting Sort - risk category\n6 Radix Sort - numeric Evidence ID\n";
 int ch=UI::input("Choose algorithm: ");auto a=evidence;
 if(a.empty()){UI::warn("No evidence available to sort.");UI::pause();return;}
 switch(ch){case 1:bubble(a);break;case 2:selection(a);break;case 3:insertion(a);break;case 4:mergeSort(a,0,(int)a.size()-1);break;case 5:counting(a);break;case 6:radix(a);break;default:UI::warn("Invalid option.");UI::pause();return;}
 std::cout<<UI::GREEN<<"Sorted evidence view:\n"<<UI::R;show(a);
 addHistory("Ran sorting algorithm option "+std::to_string(ch));UI::pause();
}
