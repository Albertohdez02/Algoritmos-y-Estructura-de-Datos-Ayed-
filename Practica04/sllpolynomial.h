// AUTOR: ALBERTO ANTONIO HERNANDEZ HERNANDEZ 
// FECHA: 23/04/2022
// EMAIL: alu0101433905@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);

  //modificacion
  void Ordenar() const;
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  bool first{true};
  SllPolyNode* prev;
  SllPolyNode* aux;

  for (int i{0}; i < v.get_size(); ++i) {
    if (!IsNotZero(v.get_val(i), eps)) { continue; }

    aux = new SllPolyNode;
    aux->set_data({v.get_val(i), i});

    if (first) {
      push_front(aux);
      first = false;
    } else {
      insert_after(prev, aux);
    }

    prev = aux;
  }
}


// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode* aux = get_head();

  while (aux != NULL) {
    result += aux->get_data().get_val() * pow(x, aux->get_data().get_inx());
    aux = aux->get_next();
  }
  
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
			    const double eps) const {
  bool equals{true};
  SllPolyNode* aux1 = get_head();
  SllPolyNode* aux2 = sllpol.get_head();

  while (aux1 != NULL && aux2 != NULL) {
    if (abs(aux1->get_data().get_val() - aux2->get_data().get_val()) > eps ||
        aux1->get_data().get_inx() != aux2->get_data().get_inx()) {
      equals = false;
    }
    aux1 = aux1->get_next();
    aux2 = aux2->get_next();
  }

  if (empty() && !sllpol.empty() || !empty() && sllpol.empty()) {
    equals = false;
  }

  return equals;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum,
			const double eps) {
 while (!sllpolsum.empty()) {
    delete sllpolsum.pop_front();
  }
  SllPolyNode* aux = new SllPolyNode;
  SllPolyNode* rec2;
  SllPolyNode* prev;
  SllPolyNode* rec = get_head();
  bool first{true};

  while (rec != NULL) {
    aux = new SllPolyNode;
    aux->set_data(rec->get_data());
    if (first) {
      sllpolsum.push_front(aux);
      first = false;
    } else {
      sllpolsum.insert_after(prev, aux);
    }
    prev = aux;
    rec = rec->get_next();
  }

  rec = sllpol.get_head();
  while (rec != NULL) {   // Recorre el pol que se va a sumar
    rec2 = sllpolsum.get_head();

    while (true) {        // Recorre el pol del resultado
      if (rec2 == NULL || rec->get_data().get_inx() < rec2->get_data().get_inx()) {
        aux = new SllPolyNode;
        aux->set_data(rec->get_data());
        if (rec2 == sllpolsum.get_head()) {
          sllpolsum.push_front(aux);
        } else {
          sllpolsum.insert_after(prev, aux);
        }
        break;

      } else if (rec->get_data().get_inx() > rec2->get_data().get_inx()) {
        prev = rec2;
        rec2 = rec2->get_next();
        continue;

      } else {
        if (IsNotZero(rec->get_data().get_val() + rec2->get_data().get_val(), eps)) {
          rec2->set_data({rec->get_data().get_val() + rec2->get_data().get_val(), rec->get_data().get_inx()});
        } else {
          if (rec2 == sllpolsum.get_head()) {
            delete pop_front();
          } else {
            delete sllpolsum.erase_after(prev);
          }
        }
        break;
      } 
    }
    rec = rec->get_next();
  }
}

#endif  // SLLPOLYNOMIAL_H_
