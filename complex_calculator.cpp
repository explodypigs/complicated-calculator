#include<iostream>
#include<string>
#include<vector>
using namespace std;
string* find_sub_operations(string);
string solve_eq(string,int);
string format_equation(string,int,int,string);
int main(){
    string opera;
    cout<<"use conventional formats"<<endl;
    cout<<"type in your problem"<<endl;
    cin>>opera;
    solve_eq(opera,1);
    string* sube = find_sub_operations(opera);
    cout<<sube;
    return 0;
}
string* find_sub_operations(string oper){
        if(oper.find('(')!=-1){
            bool pcheck=true;
            int p1=oper.find_last_of('(');
            int p2=oper.find(')',p1);
            string sp1 = std::to_string(p1);
        string sp2 = std::to_string(p2);
        string* subeq = new string[3];
        subeq[0]=sp1;
        subeq[1]=sp2;
        subeq[2]=oper.substr(p1+1,p2-p1-1);
        return subeq;
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
string solve_eq(string operation, int pos){
    int startpos;
    int endpos;
    //fix the following
    for(int i=1;i<operation.length()-pos;i++){
        if(i<operation.length()){
            switch (operation.at(pos-i)){
                case '1':break;
                case '2':break;
                case '3':break;
                case '4':break;
                case '5':break;
                case '6':break;
                case '7':break;
                case '8':break;
                case '9':break;
                case '0':break;
                default:startpos=pos-i;i=operation.length()+1;break;
            }
        }
    }
    for(int i=1;i<operation.length()-pos;i++){
        if(i<operation.length()){
            switch (operation.at(pos+i)){
                case '1':break;
                case '2':break;
                case '3':break;
                case '4':break;
                case '5':break;
                case '6':break;
                case '7':break;
                case '8':break;
                case '9':break;
                case '0':break;
                default:endpos=pos-i;i=operation.length()+1;break;
            }
        }
    }
    cout<<startpos<<operation.substr(startpos,pos+1-startpos)<<endl;
    int x = stoi(operation.substr(startpos,pos+1-startpos));
    int y = stoi(operation.substr(pos+1,endpos-pos));
    int ans;
    cout<<x<<endl;
    if (operation.at(pos)=='+'){
        
    }
    else if (operation.at(pos)=='-'){
        
    }
    else if (operation.at(pos)=='/'){
        
    }
    else if (operation.at(pos)=='*'){
        
    }
}
string format_eq(string txt,int start, int end,string insert){
        switch (txt.at(start)){
            case '1':break;
            case '2':break;
            case '3':break;
            case '4':break;
            case '5':break;
            case '6':break;
            case '7':break;
            case '8':break;
            case '9':break;
            case '0':break;
            default:break;
        }
    }