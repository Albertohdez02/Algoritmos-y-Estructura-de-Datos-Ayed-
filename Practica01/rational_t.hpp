// AUTOR: ALBERTO ANTONIO HERNANDEZ HERNANDEZ 
// FECHA: 06/03/22
// EMAIL: alu0101433905
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: https://google.github.io/styleguide/cppguide.html

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class rational_t {
 public:
  // constructor 
  rational_t(const int = 0, const int = 1);

  //destructor 
  ~rational_t() {}
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  // metodo que obtiene el valor de una fracción
  double value(void) const;

  // comparaciones igual que, menor que y mayor que (FASE II)
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // operaciones de suma, resta, multiplicación y división (FASE III)
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  
  // funciones de entrada y salida de datos
  void write(ostream& = cout) const;
  void read(istream& = cin);

  // Modificación: metodo que nos devuelva si un racional es entero o no
  bool EsEntero() const;

 private:
  int num_, den_;
};

