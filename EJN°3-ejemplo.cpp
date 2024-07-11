#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CCliente {
	private:
		string nombre;
		int documento;
	public:
		CCliente(string nombre, int documento){
			this-> nombre = nombre;
			this-> documento = documento;
		}
		string getNombre(){
			return nombre;
		}
		int getDocumento(){
			return documento;
		}
};

int main(){
	int cantidadClientes;
	string nombre;
	int documento;
	vector<CCliente> clientes;
	cout<<"Ingrese la cantidad de clientes: ";
	cin>>cantidadClientes;
	for(int i = 0; i < cantidadClientes; i++){
		cout<<"Ingrese su nombre: ";
		cin>>nombre;
		cout<<"Ingrese su numero de documento: ";
		cin>>documento;
		CCliente nuevocliente(nombre, documento);
		clientes.push_back(nuevocliente);
	}
	for(int j = 0; j < cantidadClientes; j++){
		cout<<"El nombre del cliente "<<j<<": "<<clientes[j].getNombre()<<endl;
		cout<<"El documento del cliente "<<j<<": "<<clientes[j].getDocumento()<<endl;
	}
	return 0;
}