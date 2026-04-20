#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
using namespace std;

string extraerValor(const string& json, const string& clave);
string extraerSeccion(const string& json, const string& clave);
vector<string> splitObjetos(const string& texto);

#endif