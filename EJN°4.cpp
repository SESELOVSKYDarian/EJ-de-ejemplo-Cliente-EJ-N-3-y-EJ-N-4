#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <random>
using namespace std;

class CPassword {
    private:
        string contrasenia;
        int longitud;
    public:
        CPassword(string contrasenia){
            this->contrasenia = setPassword(contrasenia);
            this->longitud = setLongitud(contrasenia);
        }
        string setPassword(string con){
            return con;
        }
        int setLongitud(string con){
            return con.size();
        }
        string getPassword(){
            return contrasenia;
        }
        int getLongitud(){
            return longitud;
        }
        bool esFuerte(){
            bool flag = false;
            int mayuscula = 0, minuscula = 0, numero = 0;
            for(int i = 0; i < contrasenia.size(); i++){
                if(isupper(contrasenia[i])){
                    mayuscula++;
                }
                if(islower(contrasenia[i])){
                    minuscula++;
                }
                if(isdigit(contrasenia[i])){
                    numero++;
                }
            }
            if(mayuscula >= 2 && minuscula >= 1 && numero >= 5){
                flag = true;
            }
            return flag;
        }
        void generarPassword(){
            string msg = "No es necesario el cambio de contrasenia";
            int randNum, may = 0, min = 0, num = 0;
            srand(time(NULL));
            string password = "";
            if(!esFuerte()){
                for(int i = 0; i < longitud; i++){
                    if (may < 2){
                        randNum = rand() % 26;
                        password += 'A' + randNum;
                        may++;
                    }
                    if (min < 1){
                        randNum = rand() % 26;
                        password += 'a' + randNum;
                        min++;
                    }
                    if (num < 5){
                        randNum = rand() % 10;
                        password += '0' + randNum;
                        num++;
                    }
                }
                msg = "Tu contrasenia no es fuerte, tu nueva contrasenia es: " + password;
            }
            cout << msg << endl;
        }
};

int main(){
    string contrasenia;
    cout << "Ingrese contrasenia: ";
    getline(cin, contrasenia);
    CPassword password(contrasenia);
    cout << "Tu contrasenia es: " << password.getPassword() << endl;
    cout << "Su longitud es: " << password.getLongitud() << endl;
    password.generarPassword();
    return 0;
}
