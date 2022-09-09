#include "Flight.h"
#include "List.h"

List<Flight>* Vuelos = new List<Flight>();

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    int minutes;
    int hour;
    
    for (int i = 0; i < pCantidad; i++)
    {
        int hour = rand() % (pEndHour-pStartHour) + pStartHour;
        int minutes;
        if (hour != pEndHour)
        {
            minutes = rand() % 60;
        } else {
            minutes = 60;
        }
        Flight* vuelo = new Flight(hour, minutes);
        Vuelos->add(vuelo);
    }
    

} 


int main() {

    fillFlights(19, 1, 23);
    for (int i = 0; i < Vuelos->getSize(); i++)
        cout << Vuelos->find(i)->flightTimeString() << "y el entero es: " << Vuelos->find(i)->getIntTimeValue() << endl;

}