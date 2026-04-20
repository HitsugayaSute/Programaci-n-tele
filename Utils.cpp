#include "Utils.h"
using namespace std;

string extraerValor(const string& json, const string& clave){
    size_t pos=json.find("\"" + clave + "\"");
    if (pos == string::npos) return "";
    pos=json.find(":", pos);
    pos++;
    while(json[pos] == ' ' || json[pos] == '\"') pos++;
    string valor;
    while(pos<json.size() && json[pos] != '\"' && json[pos] != ',' && json[pos] != '}'){
        valor += json[pos];
        pos++;
    }
    return valor;
}
string extraerSeccion(const string& json, const string& clave){
    string patron = "\"" + clave + "\":";
    size_t pos=json.find(patron);
    if(pos==string::npos) return "";
    pos=json.find("[", pos);
    if(pos==string::npos) return "";
    int nivel=0;
    size_t inicio=pos;
    for(size_t i=pos; i<json.size(); i++){
        if(json[i] == '[') nivel++;
        if(json[i] == ']') nivel--;
        if(nivel == 0){
            return json.substr(inicio, i - inicio + 1);
        }
    }
    return "";
}
vector<string> splitObjetos(const string& texto) {
    vector<string> resultado;
    string actual;
    int nivel = 0;
    for(char c : texto){
        if(c == '{') nivel++;
        if(nivel > 0) actual += c;
        if(c == '}'){
            nivel--;
            if(nivel == 0){
                resultado.push_back(actual);
                actual.clear();
            }
        }
    }
    return resultado;
}