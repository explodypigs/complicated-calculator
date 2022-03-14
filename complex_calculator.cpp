#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
string* find_sub_operations(string,bool);
string solve_eq(string,int);
int main(){
    string opera;
    cout<<"type in your problem(no spaces or letters, also stick with conventional formats)"<<endl;
    cin>>opera;
    string* sube=new string[3];
    sube = find_sub_operations(opera);
    cout<<sube[2];
    return 0;
}
string* find_sub_operations(string oper, bool par_found=false){
    if(par_found!=true){
        if(oper.find('(')!=-1){
            bool pcheck=true;
            int p1=oper.find_last_of('(');
            int p2=oper.find(')',p1);
            auto sp1 = std::to_string(p1);
        auto sp2 = std::to_string(p2);
        string* subeq = new string[3];
        subeq[0]=sp1;
        subeq[1]=sp2;
        subeq[2]=oper.substr(p1+1,p2-p1-1);
        return subeq;
        }
        cout<<endl<<"no parenthesis"<<endl;
        return 0;
    }
    vector <int> divpos;
    vector <int> mulpos;
    vector <int> addpos;
    vector <int> subpos;
    for(int i=0;i<5;i++){
        char operations[4]={'+','-','*','/'};
        bool cont=true;
        if(oper.find(operations[i])!=-1){
            int pos = oper.find(operations[i]);
            while(cont){
                if(i==0){
                    addpos.push_back(pos);
                }
                else if(i==1){
                    subpos.push_back(pos);
                }
                else if(i==2){
                    mulpos.push_back(pos);
                }
                else if(i==3){
                    divpos.push_back(pos);
                }
                if(oper.find(operations[i],pos+1)!=-1){
                    pos=oper.find(operations[i],pos+1);
                }
                else{
                    cont=false;
                }
            }
        }
        if(divpos.size()!=0 and mulpos.size()!=0){

        }
        else if(divpos.size()!=0){

        }
        else if(mulpos.size()!=0){

        }
    }
    return 0;
}
string solve_eq(string oper, int pos){
    bool check=true;
    int startpos;
    int endpos;    
    while(check){
        for(int i=2;i<oper.length()-pos;i++){

        }
        for(int i=2;i<oper.length()-pos;i++){
            
        }
    }
    if (oper.at(pos)=='+'){

    }
    else if (oper.at(pos)=='-'){
        
    }
    else if (oper.at(pos)=='/'){
        
    }
    else if (oper.at(pos)=='*'){
        
    }
}