#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

struct log{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    string action;
};

bool comp(log l1, log l2){
    //primeiro ver se meses sao diferentes
    if(l1.month < l2.month) return true;
    else if(l1.month > l2.month) return false;
    else{
        //agora vamos pros dias
        if(l1.day < l2.day) return true;
        else if(l1.day > l2.day) return false;
        else{
            //agora hora
            if(l1.hour < l2.hour) return true;
            else if(l1.hour > l2.hour) return false;
            else{
                //minutos
                if(l1.minute < l2.minute) return true;
                else return false;
            }
        }
    }
}

int find_num(string s){
    int i, resp;
    resp = 0;
    string ansr = "";
    bool num =  false;;
    for(i = 0; i < s.size(); i++){
        if(num){
            if(!s[i] == ' ') break;
            else ansr += s[i];
        }
        if(s[i] == '#') num = true;
    }
    stringstream val(ansr);
    val >> resp;
    return resp;
}

int main(){
    
    //ordena as entradas
    int year, month, day, hour, minute;
    string action;
    vector<log> valores;

    while(scanf("[%d-%d-%d %d:%d] ", &year, &month, &day, &hour, &minute) != EOF){
        getline(cin, action);
        log lg;
        lg.year = year;
        lg.month = month;
        lg.day = day;
        lg.hour = hour;
        lg.minute = minute;
        lg.action = action;
        valores.push_back(lg);
    
    }

    sort(valores.begin(), valores.end(), comp);

    // pega os tempos
    map<string, vector<int> > horarios;
    int i, j, begin_time;
    string curr_guard = "";

    for(i = 0; i < valores.size(); i++){
        log lg = valores[i];
//        cout << lg.action << endl;
        if(lg.action.substr(0,5) == "Guard") curr_guard = lg.action;

        else if(lg.action == "falls asleep") begin_time = lg.minute;

        else if(lg.action == "wakes up"){
            for(j = begin_time; j < lg.minute; j ++){
                //chave ainda nao existe
                if(horarios.find(curr_guard) == horarios.end()){
                    vector<int> vetor;
                    vetor.resize(65);
                    vetor[j]++;
                    vetor[60]++;
                    horarios.insert(pair<string, vector<int> > (curr_guard, vetor));
                    //horarios[curr_guard] = vetor;
                }
                else{
//                  cout << horarios.at(curr_guard).size() << endl;
                    horarios[curr_guard][j] = horarios[curr_guard][j] + 1;
                    horarios[curr_guard][60] = horarios[curr_guard][60] + 1;
                }
            }
        }

//        else cout << "Erro no parsing" << endl;

    }

    //pega o guarda de maior tempo
    
    string maior_guarda;
    int valor_maior, maior_min, num_maior;
    valor_maior = 0;
    map<string, vector<int> >::iterator it;

    for (it = horarios.begin(); it != horarios.end(); it++ ){
        for(i = 0; i < 60; i ++){
            if(it->second[i] > valor_maior){
                valor_maior = it->second[i];
                maior_min = i;
                maior_guarda = it->first;
            }
        }
            
    }

    num_maior = find_num(maior_guarda);
    
    cout << "Guarda: " << num_maior << "  Minuto: " << maior_min << endl;
    cout << num_maior * maior_min << endl;
}
