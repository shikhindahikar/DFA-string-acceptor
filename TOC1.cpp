#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector< vector<string> > input_matrix(int n){
    int i, j, k;
    string x;
    vector< vector<string> > moves;
    for(i=0;i<n;i++){
            cout<<"For state "<<i<<endl;
        for(j=0;j<n;j++){
            cout<<"For state "<<j<<endl;
            cin>>x;
            moves[i].push_back(x);


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
    }
    return res;
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
    string symbols;
    cout<<"Enter list of symbols as a string\n";
    cin>>symbols;
    vector< vector<string> > mat=input_matrix(symbols.size());
    cout<<"Enter any string to check\n";
    string query;
    cin>>query;
    if(accept(symbols, mat, query)==1){
        cout<<"accepted\n";
    }
    else{
        cout<<"not accepted\n";
    }
    return 0;
}
  /* for(i=0;i<query.end();i++){
        for(j=0;j<n;j++){
            if(query[i]==moves[state][j]){
                state=j;
                break;
            }
        }
    } */




