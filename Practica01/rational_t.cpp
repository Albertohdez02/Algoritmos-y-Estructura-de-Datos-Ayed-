// AUTOR: ALBERTO ANTONIO HERNANDEZ HERNANDEZ 
// FECHA: 06/03/22
// EMAIL: alu0101433905@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: https://google.github.io/styleguide/cppguide.html

#include "rational_t.hpp"

//constructor
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

//getters 
int rational_t::get_num() const {
  return num_;
}

int rational_t::get_den() const {
  return den_;
}

//setters 
void rational_t::set_num(const int n) {
  num_ = n;
}
  
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

// método que obtiene el valor decimal de una fracción
double rational_t::value() const { 
  return double(get_num()) / get_den();
}

// comparaciones
// operación booleana que dice si dos números racionales son iguales
bool rational_t::is_equal(const rational_t& r, const double precision) const{ 
  return (fabs(this->value() - r.value()) < precision);
}

// operación booleana que dice si un número racional es mayor que otro
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (this->value() - r.value() > precision);
}

// operación booleana que dice si un número racional es mayor que otro
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return (r.value() - this->value() > precision);
}

// operaciones
// suma de números racionales
rational_t rational_t::add(const rational_t& r) {
  rational_t sum;
  sum.set_num(num_ * r.get_den() + den_ * r.get_num());
  sum.set_den(den_ * r.get_den());
  return sum;
}

// resta de números racionales 
rational_t rational_t::substract(const rational_t& r) {
  rational_t subs;
  subs.set_num(num_ * r.get_den() - den_ * r.get_num());
  subs.set_den(den_ * r.get_den());
  return subs;
}

// multiplicación de números racionales
rational_t rational_t::multiply(const rational_t& r) {
  rational_t multiplication;
  multiplication.set_num(num_ * r.get_num());
  multiplication.set_den(den_ * r.get_den());
  return multiplication;
}

// división de números racionales
rational_t rational_t::divide(const rational_t& r) {
  rational_t division;
  division.set_num(num_ * r.get_den());
  division.set_den(den_ * r.get_num());
  return division;
}

// E/S
// método que imprime el objeto rational_t
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

// método que lee un número racional
void rational_t::read(istream& is) {
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

// modificacion
bool rational_t::EsEntero() const {
  return (get_num() % get_den());
}
