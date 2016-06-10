//
// Created by carlo on 06/06/2016.
//

#ifndef CURSO_C_30_CUENTATIEMPO_HPP
#define CURSO_C_30_CUENTATIEMPO_HPP

#include <iostream>
#include <ctime>

class CuentaTiempo{
private:
    double tiempo;
    clock_t tiempoInicio;
    clock_t tiempoFinal;
    void calculate(){
        tiempo=(double(tiempoFinal-tiempoInicio)/CLOCKS_PER_SEC);
    }
public:
    CuentaTiempo(){
        tiempo=0;
    }
    inline void iniciarCuentaTiempo(){
        tiempoInicio = clock();
    }
    inline void terminarCuentaTiempo(){
        tiempoFinal = clock();
        calculate();
    }
    inline double getTiempo(){
        return tiempo;
    }
};

#endif //CURSO_C_30_CUENTATIEMPO_HPP
