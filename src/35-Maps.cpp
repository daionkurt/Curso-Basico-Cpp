//
// Created by carlo on 08/06/2016.
//
#include <iostream>
#include <unordered_map>

using namespace std;

typedef unordered_map<string,string> stringMap;
typedef unordered_multimap<string,string> stringMultimap;

template <typename T>
T merge (T a,T b) {
    T temp(a);
    temp.insert(b.begin(),b.end());
    return temp;
}

void unorderedMap(){
    stringMap primero;
    stringMap segundo ({{"uno","rojo"},{"dos","verde"}});
    stringMap tercero ({{"tres","azul"},{"cuatro","negro"}});
    stringMap cuarto(segundo);
    stringMap quinto(merge(tercero,cuarto));
    stringMap sexto(quinto.begin(),quinto.end());
    stringMap::const_iterator iterador = sexto.find("tres");
    cout<<"sexto contiene"<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    cout<<endl;
    cout<<sexto.empty()<<endl;
    cout<<sexto.size()<<endl;
    cout<<sexto.max_size()<<endl;
    cout<<sexto.at("dos")<<endl;
    cout<<sexto["cuatro"]<<endl;
    if(iterador==sexto.end()) cout<<"No se encontró"<<endl;
    else cout<<iterador->first<<" es "<<iterador->second<<endl;
    for(auto& x: {"uno","dos","tres","cuatro","quinto","sexto"}){
        if(sexto.count(x)>0) cout<<"sexto tiene "<<x<<endl;
        else cout<<"sexto no tiene "<<x<<endl;
    }
    pair<string,string> par("quinto","amarillo");
    sexto.insert(par);
    sexto.insert(make_pair<string,string>("sexto","rosa"));
    sexto.insert({{"septimo","cafe"}});
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    sexto.emplace("octavo","naranja");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    sexto.erase(sexto.begin());
    sexto.erase("octavo");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    cout<<endl<<"sexto contiene: "<<sexto.bucket_count()<<" buckets"<<endl;
    cout<<endl<<"sexto contiene max: "<<sexto.max_bucket_count()<<" buckets"<<endl;
    for (unsigned i = 0; i < sexto.bucket_count(); ++i) {
        cout<<"bucket #"<<i<<" contiene: ";
        for (auto j = sexto.begin(i); j != sexto.end(i) ; ++j) {
            cout<<"["<<j->first<<":"<<j->second<<"]";
        }
        cout<<endl;
    }
    cout<<"size: "<<sexto.size()<<endl;
    cout<<"bucket count: "<<sexto.bucket_count()<<endl;
    cout<<"load_factor: "<<sexto.load_factor()<<endl;
    cout<<"max_load_factor: "<<sexto.max_load_factor()<<endl;
    sexto.clear();
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
}

void unorderedMultimap(){
    stringMultimap primero;
    stringMultimap segundo ({{"uno","rojo"},{"dos","verde"}});
    stringMultimap tercero ({{"uno","azul"},{"uno","negro"}});
    stringMultimap cuarto(segundo);
    stringMultimap quinto(merge(tercero,cuarto));
    stringMultimap sexto(quinto.begin(),quinto.end());
    stringMultimap::const_iterator iterador = sexto.find("tres");
    cout<<endl<<"MULTIMAP"<<endl;
    cout<<"sexto contiene"<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    cout<<endl;
    cout<<sexto.empty()<<endl;
    cout<<sexto.size()<<endl;
    cout<<sexto.max_size()<<endl;
    if(iterador==sexto.end()) cout<<"No se encontró"<<endl;
    else cout<<iterador->first<<" es "<<iterador->second<<endl;
    for(auto& x: {"uno","dos","tres","cuatro","quinto","sexto"}){
        if(sexto.count(x)>0) cout<<"sexto tiene "<<x<<endl;
        else cout<<"sexto no tiene "<<x<<endl;
    }
    pair<string,string> par("quinto","amarillo");
    sexto.insert(par);
    sexto.insert(make_pair<string,string>("sexto","rosa"));
    sexto.insert({{"septimo","cafe"}});
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    sexto.emplace("octavo","naranja");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    sexto.erase(sexto.begin());
    sexto.erase("octavo");
    cout<<endl;
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
    cout<<endl<<"sexto contiene: "<<sexto.bucket_count()<<" buckets"<<endl;
    cout<<endl<<"sexto contiene max: "<<sexto.max_bucket_count()<<" buckets"<<endl;
    for (unsigned i = 0; i < sexto.bucket_count(); ++i) {
        cout<<"bucket #"<<i<<" contiene: ";
        for (auto j = sexto.begin(i); j != sexto.end(i) ; ++j) {
            cout<<"["<<j->first<<":"<<j->second<<"]";
        }
        cout<<endl;
    }
    cout<<"size: "<<sexto.size()<<endl;
    cout<<"bucket count: "<<sexto.bucket_count()<<endl;
    cout<<"load_factor: "<<sexto.load_factor()<<endl;
    cout<<"max_load_factor: "<<sexto.max_load_factor()<<endl;
    sexto.clear();
    for(auto& x: sexto) cout<<" "<<x.first<<":"<<x.second;
}

void muestraMaps(){
    unorderedMap();
    unorderedMultimap();
}