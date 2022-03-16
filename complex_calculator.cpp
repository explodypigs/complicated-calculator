#include<iostream>
#include<string>
#include<vector>
using namespace std;
string* find_par(string);
string* solve_eq(string,int);
string* order_eq(string);
string format_eq(string,int,int,string);
int main(){
    bool check=true;
    string* ins=new string[3];
    string opera;
    cout<<"use conventional formats"<<endl;
    cout<<"type in your problem"<<endl;
    cin>>opera;
    while(check){
        string* info=new string[3];
        info=find_par(opera);
        if(info[0]!="stop"){
            ins=order_eq(info[2]);
            opera=format_eq(opera,stoi(info[0]),stoi(info[1]),ins[2]);
        }
        else{
            check=false;
        }
    }
    ins=order_eq(opera);
    opera=format_eq(opera,0,opera.length(),ins[2]);
    cout<<opera<<endl;
    return 0;
}
string* find_par(string oper){
    string* subeq = new string[3];
        if(oper.find('(')!=-1){
            bool pcheck=true;
            int p1=oper.find_last_of('(');
            int p2=oper.find(')',p1);
            string sp1 = std::to_string(p1);
        string sp2 = std::to_string(p2);
        subeq[0]=sp1;
        subeq[1]=sp2;
        subeq[2]=oper.substr(p1+1,p2-p1-1);
        return subeq;
        }
    subeq[0]="stop";
    return subeq;
}
string* order_eq(string oper){
    vector <int> muldivpos;
    vector <int> subaddpos;
    for(int i=0;i<5;i++){
        char operations[4]={'+','-','*','/'};
        bool cont=true;
        if(oper.find(operations[i])!=-1){
            int pos = oper.find(operations[i]);
            while(cont){
                if(i==0 or i==1){
                    subaddpos.push_back(pos);
                }
                else if(i==2 or i==3){
                    muldivpos.push_back(pos);
                }
                if(oper.find(operations[i],pos+1)!=-1){
                    pos=oper.find(operations[i],pos+1);
                }
                else{
                    cont=false;
                }
            }
        }
    }
    string* operinfo=new string[3];
    if(muldivpos.size()!=0){
        for(int i=0;i<muldivpos.size();i++){
            operinfo=solve_eq(oper,muldivpos[i]);
        }
    }
    if(subaddpos.size()!=0){
        for(int i=0;i<subaddpos.size();i++){
            operinfo=solve_eq(oper,subaddpos[i]);
        }
    }
    return operinfo;
}
string* solve_eq(string operation, int pos){
    int startpos=0;
    int endpos=0;
    int num;
    for(int i=1;(pos-i)>=0;i++){
            switch (operation[pos-i]){
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
            if(startpos!=0){
                i=324343;
            }
            num=i;
    }
    if(startpos==0){
        startpos=pos-num;
    }
    cout<<operation.substr(startpos,pos-startpos)<<endl;
    for(int i=1;pos+i<operation.length();++i){
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
                default:endpos=pos+i;i=operation.length()+1;break;
        }
    }
    float x = std::stof(operation.substr(startpos,pos-startpos));
    float y = std::stof(operation.substr(pos+1,endpos-pos));
    cout<<"worked"<<endl;
    double ans;
    if (operation.at(pos)=='+'){
        ans = x+y;;
    }
    else if (operation.at(pos)=='-'){
        ans=x-y;;
    }
    else if (operation.at(pos)=='/'){
        ans=x/y;
    }
    else if (operation.at(pos)=='*'){
        ans=x*y;
    }
    string strans=to_string(ans);
    string* operinfo=new string[3];
    operinfo[0]=to_string(startpos+1);
    operinfo[1]=to_string(endpos);
    operinfo[2]=strans;
    return operinfo;
}
string format_eq(string txt,int start, int end,string insert){
    bool set1=false;
    bool set2=false;
    cout<<start;
    if(start-1>0){
        switch (txt.at(start-1)){
            case '-':break;
            case '+':break;
            case '/':break;
            case '*':break;
            case ')':break;
            default:set1=true;
        }
    }
    if(end-1<=txt.length()){
        cout<<"ye";
        switch (txt.at(end-1)){
            case '-':break;
            case '+':break;
            case '/':break;
            case '*':break;
            case ')':break;
            default:set2=true;
        }
        cout<<set2;
    }
    if(set1==false and set2==false){
        txt.replace(start,end-start,insert);
        return txt;
    }
    else if(set1==true and set2==true){
        txt.replace(start,end-start,"*"+insert+"*");
        return txt;
    }
    else if(set1==true){
        txt.replace(start,end-start,"*"+insert);
        return txt;
    }
    else{
        txt.replace(start,end-start,insert+"*");
        return txt;
    }
}