//
// Created by carlo on 08/06/2016.
//
#include <iostream>
#include <unordered_set>

using namespace std;

typedef unordered_set<string> stringSet;
typedef unordered_multiset<string> stringMultiset;

template <typename T>
T cmerge (T a,T b) {
    T temp(a);
    temp.insert(b.begin(),b.end());
    return temp;
}

void unorderedSet(){
    stringSet primero;
    stringSet segundo ({"uno","dos","tres"});
    stringSet tercero ({"cuatro","cinco"});
    stringSet cuarto(segundo);
    stringSet quinto(cmerge(tercero,cuarto));
    stringSet sexto(quinto.begin(),quinto.end());
    stringSet::const_iterator iterador = sexto.find("tres");
    cout<<"sexto contiene"<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    cout<<endl;
    cout<<sexto.empty()<<endl;
    cout<<sexto.size()<<endl;
    cout<<sexto.max_size()<<endl;
    if(iterador==sexto.end()) cout<<"No se encontró"<<endl;
    else cout<<*iterador<<" existe en sexto"<<endl;
    for(auto& x: {"uno","dos","tres","cuatro","quinto","sexto"}){
        if(sexto.count(x)>0) cout<<"sexto tiene "<<x<<endl;
        else cout<<"sexto no tiene "<<x<<endl;
    }
    string str = "seis";
    array<string,2> arreglo = {"siete","ocho"};
    sexto.insert(str);
    sexto.insert(str+"2");
    sexto.insert(arreglo.begin(),arreglo.end());
    sexto.insert({"nueve","diez"});
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    sexto.emplace("octavo");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    sexto.erase(sexto.begin());
    sexto.erase("octavo");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    cout<<endl<<"sexto contiene: "<<sexto.bucket_count()<<" buckets"<<endl;
    cout<<endl<<"sexto contiene max: "<<sexto.max_bucket_count()<<" buckets"<<endl;
    for (unsigned i = 0; i < sexto.bucket_count(); ++i) {
        cout<<"bucket #"<<i<<" contiene: ";
        for (auto j = sexto.begin(i); j != sexto.end(i) ; ++j) {
            cout<<"["<<*j<<"]";
        }
        cout<<endl;
    }
    cout<<"size: "<<sexto.size()<<endl;
    cout<<"bucket count: "<<sexto.bucket_count()<<endl;
    cout<<"load_factor: "<<sexto.load_factor()<<endl;
    cout<<"max_load_factor: "<<sexto.max_load_factor()<<endl;
    sexto.clear();
    for(auto& x: sexto) cout<<" "<<x;
}

void unorderedMultiset(){
    stringMultiset primero;
    stringMultiset segundo ({"uno","dos","tres"});
    stringMultiset tercero ({"uno","dos","tres"});
    stringMultiset cuarto(segundo);
    stringMultiset quinto(cmerge(tercero,cuarto));
    stringMultiset sexto(quinto.begin(),quinto.end());
    stringMultiset::const_iterator iterador = sexto.find("tres");
    cout<<"sexto contiene"<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    cout<<endl;
    cout<<sexto.empty()<<endl;
    cout<<sexto.size()<<endl;
    cout<<sexto.max_size()<<endl;
    if(iterador==sexto.end()) cout<<"No se encontró"<<endl;
    else cout<<*iterador<<" existe en sexto"<<endl;
    for(auto& x: {"uno","dos","tres","cuatro","quinto","sexto"}){
        if(sexto.count(x)>0) cout<<"sexto tiene "<<x<<endl;
        else cout<<"sexto no tiene "<<x<<endl;
    }
    string str = "seis";
    array<string,2> arreglo = {"siete","ocho"};
    sexto.insert(str);
    sexto.insert(str+"2");
    sexto.insert(arreglo.begin(),arreglo.end());
    sexto.insert({"nueve","diez"});
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    sexto.emplace("octavo");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    sexto.erase(sexto.begin());
    sexto.erase("octavo");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x;
    cout<<endl<<"sexto contiene: "<<sexto.bucket_count()<<" buckets"<<endl;
    cout<<endl<<"sexto contiene max: "<<sexto.max_bucket_count()<<" buckets"<<endl;
    for (unsigned i = 0; i < sexto.bucket_count(); ++i) {
        cout<<"bucket #"<<i<<" contiene: ";
        for (auto j = sexto.begin(i); j != sexto.end(i) ; ++j) {
            cout<<"["<<*j<<"]";
        }
        cout<<endl;
    }
    cout<<"size: "<<sexto.size()<<endl;
    cout<<"bucket count: "<<sexto.bucket_count()<<endl;
    cout<<"load_factor: "<<sexto.load_factor()<<endl;
    cout<<"max_load_factor: "<<sexto.max_load_factor()<<endl;
    sexto.clear();
    for(auto& x: sexto) cout<<" "<<x;
}

void muestraSets(){
    unorderedSet();
    unorderedMultiset();
    uint32_t a = 10;
    cout<<a<<endl;
}