#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CAlumno {
	private:
		string nombreAlumno;
		int cantidadFinesPerdidos;
		string siSirve;
	public:
		CAlumno(string nombreAlumno, int cantidadFinesPerdidos, string siSirve){
			this-> nombreAlumno = nombreAlumno;
			this-> cantidadFinesPerdidos = cantidadFinesPerdidos;
			this-> siSirve = siSirve;
		}
		void noMateria(){
			if(siSirve == "no" || cantidadFinesPerdidos < 5){
				cout<<nombreAlumno<<endl;
			}
		}
};

int main(){
	string nombre, siSirve;
	vector<CAlumno> alumnos;
	int cantidadFinesPerdidos, cantidadAlumnos;
	cout<<"Ingrese cantidad de alumnos: ";
	cin>>cantidadAlumnos;
	for(int i = 0; i < cantidadAlumnos; i++){
		cout<<"Ingrese su nombre: ";
		cin>>nombre;
		cout<<"Ingrese cantidad de fines de semanas perdidos estudiando: ";
		cin>>cantidadFinesPerdidos;
		cout<<"¿Sirve de algo la materia? ";
		cin>>siSirve;
		CAlumno nuevoalumno(nombre, cantidadFinesPerdidos, siSirve);
		alumnos.push_back(nuevoalumno);
	}
	for(int j = 0; j < cantidadAlumnos; j++){
		cout<<"Alumno "<<j<<" ";
		alumnos[j].noMateria();
	}
	return 0;
}