#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool esOperador(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Genera código intermedio tipo TAC
void generarTAC(const string &expr){
    stack<string> pila;
    int t = 1;

    for(char c : expr){
        if(isalpha(c)){  // Si es una variable
            string s(1, c);
            pila.push(s);
        }
        else if(esOperador(c)){
            string op2 = pila.top(); pila.pop();
            string op1 = pila.top(); pila.pop();
            string temp = "t" + to_string(t++);
            cout << temp << " = " << op1 << " " << c << " " << op2 << endl;
            pila.push(temp);
        }
    }

    cout << "Resultado final: " << pila.top() << endl;
}

int main() {
    string expresion;
    cout << "Ingrese expresion posfija (postfix), Ejemplo: ab+c*:" << endl;
    cin >> expresion;

    cout << "\n=== Codigo Intermedio (TAC) ===" << endl;
    generarTAC(expresion);

    return 0;
}