#include <iostream>
#include <cmath>

using namespace std;
int main (){
    int opcion = 0;
    float sbr10anios = 0.35, sbr3anios = 0.30, FI10anios = 0.01, FI3anios = 0.0175, pmens = 0.0,
    CIAP = 0.0, promedioanual = 0.0, i = 0.0, i_ef = 0.0, IBCi_C = 0.0, IBCi_$ = 0.0, fi = 0.0,
    t = 0.0, w = 0.0, SBR = 0.0, suma1 = 0.0, suma2 = 0.0, IPCr = 0.0, tasaincre1opt = 0.01,
    tasaincre2spp = 0.0175, num_ef = 0.0, den_ef = 0.0, SBRresultado = 0.0;
    int n1 = 20, n2 = 0, n3 = 24, m1opt = -10, m2spp = -3, mp;

    while (opcion != 4) {
        cout << "=====¿Que desea calcular?=====" << endl;
        cout << "1. Pension para los optados" << endl;
        cout << "2. Pension para los afiliados del Sistema Publico de Pensiones (SPP)" << endl;
        cout << "3. Pension de los afiliados al Sistema privado (AFP)" << endl;
        cout << "4. salir" << endl;

        cout << "ingrese su  opcion." << endl;
        cin >> opcion;
        
    switch (opcion){
        case 1: {
            float IBCi_C, IBCi_$, w, t, fi, i, sbr10anios, FI10anios, suma1 = 0, suma2 = 0;

          cout << "Ingrese los datos para la pensión para los optados." <<  endl;
          cout << "ingrese valor de IBCi_C"; cin >> IBCi_C;
          cout <<"Ingrese valor de IBCi_$"; cin >> IBCi_$;
          cout << "ingrese valor de w"; cin >> w;
          cout <<"Ingrese valor de t"; cin >> t;
          cout << "ingrese valor de fi"; cin >> fi;
          cout <<"Ingrese valor de i"; cin >> i;

          for (int k = 1; k <= t - w; ++k) {
            suma1 += (IBCi_C*fi)/8.75;
          } 
          for (int k =t - w + 1; k <= t; k++){
            suma2 += (IBCi_$*fi);
          }  
          SBR = suma1 + suma2;

          cout <<"===================" << endl;
          cout << "SBRresultado: " << SBR << endl;
          cout << "pmens: " << (sbr10anios + SBR + FI10anios) << endl;
          cout <<"=====================" << endl;

          cout <<"Presione ENTER para salir al menu." << endl;
          cin.ignore();
          cin.get();
          break;
        }
        case 2: {
          float IBCi_C, IBCi_$, w, t, fi, i, suma1 = 0.0, suma2 = 0.0;
          
          cout << "Ingrese los datos para pensión para los afiliados del Sistema Público de Pensiones." <<  endl;

          cout << "Ingrese los datos para SBR." << endl;
          cout << "ingrese valor de IBCi_C"; cin >> IBCi_C;
          cout <<"Ingrese valor de IBCi_$"; cin >> IBCi_$;
          cout << "ingrese valor de w"; cin >> w;
          cout <<"Ingrese valor de t"; cin >> t;
          cout << "ingrese valor de fi"; cin >> fi;
          cout <<"Ingrese valor de i"; cin >> i;
          
          for (int k = 1; k <= t - w; ++k) {
            suma1 += (IBCi_C*fi)/8.75;
          } 
          for (int k =t - w + 1; k <= t; k++){
            suma2 += (IBCi_$*fi);
        } 
        SBR = suma1 + suma2;
        fi = IBCi_C/IBCi_$;

        cout <<"===================" << endl;
        cout << "SBR: " << (suma1 + suma2) / t << endl;
        cout << "fi:" << IBCi_C/IBCi_$ << endl;
        cout << "pmens:" << (sbr3anios + SBR + FI3anios) << endl;
        cout <<"=====================" << endl;

        cout <<"Presione ENTER para salir al menu." << endl;
          cin.ignore();
          cin.get();
        break;
    }
    case 3: {
      float i_ef, CIAP, num_ef = 0.0, den_ef = 0.0, suma1 = 0.0, suma2 = 0.0, i;
      int mp;

      cout << "Ingrese los datos para pensión de los afiliados al Sistema privado (AFP)" <<  endl;
      cout << "ingrese valor de i_ef"; cin >> i_ef;
      cout <<"Ingrese valor de CIAP"; cin >> CIAP;
      cout << "ingrese valor de i (en decimal, ej: 0.05 para 5%)"; cin >> i;
      cout <<"Ingrese valor de mp"; cin >> mp;

      suma1 += CIAP / ((pow(1.0 + i, 240.0) - 1.0) / (i * pow(1.0 + i, 240.0)));
      num_ef += (pow(1.0 + i_ef, 20.0) - 1.0) * pow(1.0 + i, mp - 1.0);
      den_ef += i_ef * pow(1.0 + i_ef, 20.0);

      suma2 += 0.5*(num_ef/den_ef);
      pmens = suma1 + suma2;

      cout <<"===================" << endl;
      cout << "i_ef:" << pow(1.0 + i, 12.0) - 1.0 << endl;
      cout << "pmens:" << pmens << endl;
      cout <<"=====================" << endl;

      cout <<"Presione ENTER para salir al menu." << endl;
          cin.ignore();
          cin.get();
      break;
    }
    case 4:{
      cout << "saliedo del programa..." << endl;
      break; 
    }
    default: {
    cout << "opion no valida. Intenta de nuevo." << endl;
    break;
    }
      
    

    }

}
return 0;
}