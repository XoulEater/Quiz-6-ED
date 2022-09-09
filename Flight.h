#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el test.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

class Flight {

    private: 
        time_t flightTime;
        string aerolinea;
        int flightID;
        int passengers;  

    public: 
        Flight(int pHour, int pMinutes) {
            flightTime = time(NULL);
            tm * currentTime = localtime(&flightTime);
            currentTime->tm_hour = pHour;
            currentTime->tm_min = pMinutes;
            flightTime = mktime(currentTime);
        }

        char* flightTimeString() {
            char* result = ctime(&flightTime);
            return result;
        }

        int getIntTimeValue() {
            int result = 0;        
            tm * midnight = localtime(&flightTime);
            midnight->tm_hour = 0;
            midnight->tm_min = 0;
            midnight->tm_sec = 0; 
            result = difftime(flightTime, mktime(midnight)) / 60;
            return result;
        }
};