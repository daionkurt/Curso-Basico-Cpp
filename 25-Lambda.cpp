//
// Created by carlo on 01/06/2016.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>

using  namespace std;

void muestraLambda(){
    int resultado = []() ->int{return 4;}();
    cout<<resultado<<endl;
    //[](parametros de entrada) -> tipoRetorno{cuerpo_de_la_lambda}(parametros)
    resultado =[](int a)->int{return a*2;}(10);
    cout<<resultado<<endl;
    resultado=[](int a,int b)->int{return a+b;}(20,30);
    cout<<resultado<<endl;
    resultado=[](int a,int b)->int{return a+b;}([](int a)->int{return a*2;}(10),15);
    cout<<resultado<<endl;
    auto cuadrado=[](int a)->int{return a*a;};
    cout<<cuadrado(10)<<endl;

    int n=10;
    vector<int> vector1(n);
    for (int i = n-1, j=0; i >=0 ; i--,j++) {
        vector1[j] = i+1;
    }
    for (int i = 0; i < n; ++i) {
        cout<<vector1[i]<<" ";
    }
    cout<<endl;
    sort(vector1.begin(),vector1.end(),[](int a,int b)->bool{return a<b;});
    for (int i = 0; i < n; ++i) {
        cout<<vector1[i]<<" ";
    }


    cout<<"Expresiones Regulares"<<endl;
    string input;
    string inte=R"((\+|-)?[[:digit:]]+)";
    regex integer(inte);
    //regex integer("(\\+|-)?[[:digit:]]+");
    regex flotante("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
    for (int k = 0; k < 4; ++k) {
        cout<<"Dame un entero: ";
        cin>>input;
        if(regex_match(input,integer))
            cout<<"Es un entero"<<endl;
        else if(regex_match(input,flotante))
            cout<<"Es un flotante"<<endl;
        else
            cout<<"Entrada invalida"<<endl;
    }

    cout<<"RAW String"<<endl;
    string normal="Primera.\nSegunda.\nTercera.\n";
    string raw=R"(Primera.\nSegunda.\nTercera.\n)";
    cout<<normal<<endl;
    cout<<raw<<endl;
}
