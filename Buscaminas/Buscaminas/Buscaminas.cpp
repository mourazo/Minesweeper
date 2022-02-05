// Buscaminas.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//@@author alvaro mourazo novillo
// 
//

#include <time.h>
#include <iostream>
#define MAX 32

using namespace std;

void mensaje();
int elegir_nivel();
int elegir_filas(int level);
int elegir_columnas(int level);
int elegir_minas(int level);
void inicializaTablero(int row, int col, char space[MAX][MAX]);
void ColocaMinas(int row, int col, char space[MAX][MAX], int minas);
void ColocaNumeros(int row, int col, char space[MAX][MAX]);
void ImprimeTablero(int jugadafila, int jugadacol, char space[MAX][MAX],
                    char space2[MAX][MAX], int row, int col);
int VerificaGanador(int row, int col, char space[MAX][MAX], int minas);


int main() {
  int level, row, col, min;
  int jugada_fila, jugada_columna;
  int situacion; 
  char space[MAX][MAX], space2[MAX][MAX];
  mensaje();
  level = elegir_nivel();
  row = elegir_filas(level);
  col = elegir_columnas(level);
  min = elegir_minas(level);
  inicializaTablero(row, col, space);
  ColocaMinas(row, col, space2, min);
  ColocaNumeros(row, col, space2);




  while (1) {
      cout << "Ingresa la fila elegida: ";
      cin >> jugada_fila ;
      cout << "Ingresa la columna elegida: ";
      cin >> jugada_columna;
      if (jugada_fila > 0 && jugada_fila < row + 1 && jugada_columna < col + 1 && jugada_columna>0) {
          ImprimeTablero(jugada_fila, jugada_columna, space, space2, row, col);
          situacion = VerificaGanador(row, col, space, min);
          if (situacion == 1) {
              cout << "Winner!!" << endl;
              break;
          }
          else if (situacion == 2) {
              cout << "Boooom, perdio..."   << endl;
              break;
          }
      }
      else cout << "valores incorrectos..." << endl;


  }

  return 0;


  /*
cout << endl;
for (int i = 1; i < row + 1; i++) {
for (int j = 1; j < col + 1; j++) {
cout << space2[i][j];
}
cout << endl;
}
*/
}

int elegir_nivel() {
  int l;
  while (1) {
    cout << "ingrese el nivel: ";
    cin >> l;
    cout << l;
    if (l == 1)
      break; 
    else if (l == 2)
      break;
    else if (l == 3)
      break;
    else if (l == 4)
      break;
  }
  return l;
}

int elegir_filas(int level) {
  int fila;
  if (level == 1)
    fila = 8;
  else if (level == 2)
    fila = 16;
  else if (level == 3)
    fila = 30;
  else if (level == 4) {
    while (1) {
      cout << "Ingresa el numero de filas: ";
      cin >> fila;
      if (fila <= 30) break;
    }
  }
  return fila;
}

int elegir_columnas(int level) {
  int colmnas;
  if (level == 1)
    colmnas = 8;
  else if (level == 2)
    colmnas = 16;
  else if (level == 3)
    colmnas = 30;
  else if (level == 4) {
    while (1) {
      cout << "Ingresa el numero de colmnas: ";
      cin >> colmnas;
      if (colmnas <= 30) break;
    }
  }
  return colmnas;
}

int elegir_minas(int level) {
  int minas;
  if (level == 1)
    minas = 10;
  else if (level == 2)
    minas = 40;
  else if (level == 3)
    minas = 99;
  else if (level == 4) {
    while (1) {
      cout << "Ingresa el numero de minas: ";
      cin >> minas;
      if (minas <= 200) break;
    }
  }
  return minas;
}

void inicializaTablero(int row, int col, char space[MAX][MAX]) {
  for (int i = 0; i < row + 2; i++) {
    for (int j = 0; j < col + 2; j++) {
      space[i][j] = '0';
    }
  }
  cout << endl << "El talbero actual es: " << endl;
  for (int i = 1; i < row + 1; i++) {
    for (int j = 1; j < col + 1; j++) {
      cout << space[i][j];
    }
    cout << endl;
  }
}

void ColocaMinas(int row, int col, char space[MAX][MAX], int minas) {
  int pcol, pfil;
  for (int i = 0; i < row + 2; i++) {
    for (int j = 0; j < col + 2; j++) {
      space[i][j] = '0';
    }
  }

  srand(time(NULL));
  while (1) {
    pfil = 1 + rand() % row;
    pcol = 1 + rand() % col;
    if (space[pfil][pcol] == '0') {
      space[pfil][pcol] = 'M';
      minas--;
    }
    if (minas == 0) break;
  }
}

void ColocaNumeros(int row, int col, char space[MAX][MAX]) {
  int number;
  for (int i = 1; i < row + 1; i++) {
    for (int j = 1; j < col + 1; j++) {
      if (space[i][j] == '0') {
        number = 0;
        if (space[i - 1][j] == 'M') number++;
        if (space[i - 1][j - 1] == 'M') number++;
        if (space[i - 1][j + 1] == 'M') number++;
        if (space[i][j - 1] == 'M') number++;
        if (space[i][j + 1] == 'M') number++;
        if (space[i + 1][j] == 'M') number++;
        if (space[i + 1][j - 1] == 'M') number++;
        if (space[i + 1][j + 1] == 'M') number++;

        if (number == 0)
          space[i][j] = ' ';
        else
          space[i][j] = number + '0';
      }
    }
  }
}

void ImprimeTablero(int jugadafila, int jugadacol, char space[MAX][MAX],
                    char space2[MAX][MAX], int row, int col) {

  space[jugadafila][jugadacol] = space2[jugadafila][jugadacol];

  for (int i = 1; i < row + 1; i++) 
  {
    for (int j = 1; j < col + 1; j++) 
	{
      cout << space[i][j];
    }
    cout << endl;

  }

}

int VerificaGanador(int row, int col, char space[MAX][MAX], int minas)
{   
    int situacion = 0;
    int casillas_falta =0, cantidad_minas=0;
    for (int i = 1; i < row + 1; i++) {
        for (int j = 1; j < col + 1; j++) {
            if (space[i][j] == 'M') cantidad_minas++;
            else if (space[i][j] == '0') casillas_falta++;
        }
    }

    if (cantidad_minas != 0) situacion = 2;
    else if (casillas_falta == minas) situacion = 1;

    return situacion;
}

void mensaje() {
  cout << "Bienvenido al buscaminas\n" << endl;
  cout << "Los niveles son:" << endl;
  cout << "[1] Principiante" << endl;
  cout << "[2] Intermedio" << endl;
  cout << "[3] Avanzado" << endl;
  cout << "[4] Personalizado" << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de
// soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código
//   fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros
//   mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de
//   código, o a Proyecto > Agregar elemento existente para agregar archivos de
//   código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir
//   > Proyecto y seleccione el archivo .sln
