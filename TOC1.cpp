#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

vector< vector<string> > input_matrix(int n){
    int i, j;
    string x, filename;
    fstream file;
    cout<<"Enter file name of input\n";
    cin>>filename;
    file.open(filename.c_str(), ios::in);
    vector< vector<string> > moves;
    for(i=0;i<n;i++){
            vector<string> row;
        for(j=0;j<n;j++){
            getline(file, x);
            row.push_back(x);
            x.erase();
        }
        moves.push_back(row);
    }
    file.close();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<moves[i][j]<<"\n";
        }
    }
    return moves;
}

bool hasA(char x, string str){
    int i=0;
    bool res=false;
    while(str[i]!='\0'){
        if(x==str[i]){
            res=true;
            }
            i++;
    }
    return res;
}

int check_query(string q, string sym){
    int i=0, ret=1;
    while(i<q.size()){
        if(!(hasA(q[i], sym))){
            ret=0;
        }
        i++;
    }
    return ret;
}

int accept(string chars, vector< vector<string> > moves, string query){
    int i=0, k, state=0,  flag;
    while(query[i]!='\0'){
        k=0; flag=0;
        while(k<moves.size() && flag==0){
            if(hasA(query[i], moves[state][k])){
                state=k;flag=1;
            }
            k++;
        }
        i++;
    }
    if(state==moves.size()-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int cont=1;
    string symbols;
    cout<<"Enter list of symbols as a string\n";
    cin>>symbols;
    vector< vector<string> > mat=input_matrix(symbols.size());
    while(cont){
    cout<<"Enter any string to check\n";
    string query;
    cin>>query;
    if(check_query(query, symbols)){
        if(accept(symbols, mat, query)==1){
            cout<<"accepted\n";
        }
        else{
            cout<<"not accepted\n";
        }
    }
    else{
        cout<<"Query is not in the language of the DFA\n";
    }
    cout<<"Press 1 if you wish to continue, else press 0\n";
    cin>>cont;
    }
    return 0;
}




