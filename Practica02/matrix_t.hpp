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

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  
  void resize(const int, const int);
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

  //modi 2
  vector_t<T> SumaFilas() const;

  //modi 3
  T SumaDiagonal() const;

  //modi 4
  void WriteDiagonal(std::ostream& = cout) const;
  void ReverseDiagonal(std::ostream& = cout) const;
  void UpperTriangle(std::ostream& = cout) const;
  void LowerTriangle(std::ostream& = cout) const;

  //modi 5
  vector_t<T> SumaColumnas() const;

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
matrix_t<T>::~matrix_t()
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
inline int
matrix_t<T>::get_m() const
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.get_n() == B.get_m());
  this->resize(A.get_m(), B.get_n());
  for (int i = 1; i <= A.get_m(); ++i) {
    for (int j = 1; j <= B.get_n(); ++j) {
      T suma {0};
      for (int k = 1; k <= A.get_n(); ++k) {
        suma = suma + A.at(i, k) * B.at(k, j);
      }
      this->at(i, j) = suma;
    }
  }
}

// //modi 2
// template<class T>
// vector_t<T> matrix_t<T>::SumaFilas() const{
//   vector_t<T> SumaFilas(get_m());
//   for (int i = 1; i <= get_m(); ++i) {
//     T suma {0};
//     for (int j = 1; j <= get_n(); ++j) {
//       suma = suma + at(i, j);
//     }
//     SumaFilas.at(i - 1) = suma;
//   }
//   return SumaFilas;
// }

// //modi 3 
// template<class T>
// T matrix_t<T>::SumaDiagonal() const {
//   assert(get_m() == get_n());
//   T suma;
//   for (int i = 1; i <= get_n(); ++i) {
//     suma = suma + at(i,i);
//   }
//   return suma;
// }

// //modi 4
// template<class T>
// void matrix_t<T>::WriteDiagonal(std::ostream& os) const {
//   assert(get_m() == get_n());
//   for (int i = 1; i <= get_m(); ++i) {
//     os << at(i,i) << " ";
//   }
//   os << endl;
// }

// template<class T>
// void matrix_t<T>::ReverseDiagonal(std::ostream& os) const {
//   assert(get_m() == get_n());
//   for (int i = 1; i <= get_m(); ++i) {
//     os << at(i,get_m() - i + 1) << " ";
//   }
//   os << endl;
// }

template<class T>
void matrix_t<T>::UpperTriangle(std::ostream& os) const {
  assert(get_m() == get_n());
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j >= i; ++j) {
      os << at(i,j) << " ";
    }
    os << endl;
  }
}

template<class T>
void matrix_t<T>::LowerTriangle(std::ostream& os) const {
  assert(get_m() == get_n());
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= i; ++j) {
      os << at(i,j) << " ";
    }
    os << endl;
  }
}

template<class T>
bool matrix_t<T>::Simetry() const {
  assert(get_m() == get_n());
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= i; ++j) {
      if (at(i, j) != at(j, i)) {
        return false;
      }
    }
  }
  return true;
}

// //modi 5
// template<class T>
// vector_t<T> matrix_t<T>::SumaColumnas() const{
//   vector_t<T> SumaColumnas(get_n());
//   for (int j = 1; j <= get_n(); ++j) {
//     T suma {0};
//     for (int i = 1; i <= get_m(); ++i) {
//       suma = suma + at(i, j);
//     }
//     SumaColumnas.at(j - 1) = suma;
//   }
//   return SumaColumnas;
// }