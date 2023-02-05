#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

struct Alumno {
    
    int DNI;
    string nombre;
    string apellido;
    double calificaciones[3];

};
double calcularPromedio( double* calificacion, int numeroDeExamenes){
    double promedio = 0;
    for(int i = 0; i < numeroDeExamenes; i++)
    {
        promedio += calificacion[i];
    }
    return promedio / numeroDeExamenes;


}

int main()
{
    const double  NUMERO_DE_EXAMENES =3;
    int indiceDelAlumno = 0, AlumnosMejorPromedio=0;
    double mejorPromedio =0;
    vector<Alumno*> alumnos;
    struct Alumno* alumno;

    while(true){
        alumno = new Alumno;
        cout << setw(120) << setfill('=') << left << "=" << endl;
        cout << "Ingrese el DNI del alumno: ";
        cin >> alumno->DNI;
        if(alumno->DNI == 0)
            break;
        cout << "Ingrese el nombre del alumno: ";
        cin >> alumno->nombre;
        cout << "Ingrese el apellido del alumno: ";
        cin >> alumno->apellido;
        for(int i = 0; i < NUMERO_DE_EXAMENES; i++)
        {
            cout << "Ingrese la calificacion del examen " << i+1 << ": ";
            cin >> alumno->calificaciones[i];
        }
        alumnos.push_back(alumno);
        indiceDelAlumno++;
    }

    cout << endl << endl;
    cout << setw(8) << setfill(' ') << left << "DNI";
    cout << setw(20) << setfill(' ') << left << "Nombre";
    cout << setw(20) << setfill(' ') << left << "Apellido";
    cout << setw(20) << setfill(' ') << left << "Calificacion 1";
    cout << setw(20) << setfill(' ') << left << "Calificacion 2";
    cout << setw(20) << setfill(' ') << left << "Calificacion 3";
    cout << setw(10) << setfill(' ') << left << "Promedio" << endl;

    for(int i = 0; i< alumnos.size(); i++){

        double promedio = calcularPromedio(alumnos[i]->calificaciones, NUMERO_DE_EXAMENES);
        if(promedio > mejorPromedio){
            mejorPromedio = promedio;
            AlumnosMejorPromedio = 1;
        }

        cout << setw(8) << setfill(' ') << left << alumnos[i]->DNI;
        cout << setw(20) << setfill(' ') << left << alumnos[i]->nombre;
        cout << setw(20) << setfill(' ') << left << alumnos[i]->apellido;
        cout << setw(20) << setfill(' ') << left << alumnos[i]->calificaciones[0];
        cout << setw(20) << setfill(' ') << left << alumnos[i]->calificaciones[1];
        cout << setw(20) << setfill(' ') << left << alumnos[i]->calificaciones[2];
        cout << setw(10) << setfill(' ') << left << promedio << endl;
        
    }
    cout << endl << endl
            << "El mejor promedio es: " << mejorPromedio << endl
            << "El numero de alumnos con el mejor promedio es: " << AlumnosMejorPromedio << endl;

    for(auto i : alumnos)
    {

        cout << "Eliminando alumno: " << i->nombre << " " << i->apellido << endl;
        
        delete i;

    }
    cout << "Fin del programa"
    << "Hecho por Juan Daniel ";
    return 0;



}