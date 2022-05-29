// AUTOR: ALBERTO ANTONIO HERNANDEZ HERNANDEZ
// FECHA: 16/03/2022
// EMAIL: alu0101433905@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class vector_t {
 public:
  vector_t(const int = 0);
  ~vector_t();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

  //modi 1
  vector_t<T> PosicionPar() const;

  //modi 6
  bool Palindromo() const;

 private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};



template<class T>
vector_t<T>::vector_t(const int n) { sz_ = n;
  build();
}



template<class T>
vector_t<T>::~vector_t() {
  destroy();
}



template<class T>
void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}



template<class T>
void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}



template<class T>
void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}



template<class T>
inline T
vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
inline int
vector_t<T>::get_size() const {
  return sz_;
}



template<class T>
void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



template<class T>
T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
T& vector_t<T>::operator[](const int i) {
  return at(i);
}



template<class T>
const T&
vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
const T&
vector_t<T>::operator[](const int i) const {
  return at(i);
}



template<class T>
void vector_t<T>::write(ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T>
void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
//Producto escalar de dos vectores (metodo double)
template<class T>
T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
  assert(v.get_size() == w.get_size());
  T product {0};
  for (int i = 0; i < v.get_size(); ++i) {
    product = product + (v.at(i) * w.at(i));
  }
  return product;
}

//Producto escalar de dos vectores (metodo rational_t)
double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  assert(v.get_size() == w.get_size());
  double product {0.0}; 
  for (int i = 0; i < v.get_size(); ++i) {
    product = product + (v.at(i) * w.at(i)).value();
  }
  return product;
}

// //modi 1
// template<class T>
// vector_t<T> vector_t<T>::PosicionPar() const {
//   vector_t<T> par;
//   par.resize(get_size()/2);
//   for (int i = 0; i < this->get_size(); ++i) {
//     if (i % 2 == 0) {
//       par[i/2] = this->at(i);
//     }
//   }
//   return par;
// }

// //modi 6
// template<class T>
// bool vector_t<T>::Palindromo() const {
//   for (int i = 0; i < get_size()/2; ++i) {
//     if (at(i) != at(get_size() - 1 - i)) {
//       return false;
//     }
//   }
//   return true;
// }
