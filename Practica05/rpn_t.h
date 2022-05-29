// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);
  bool es_binario(const char c);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');
  int number1 = stack_.top();
  stack_.pop();
  int number2;
  int result;
  std::cout << "   Sacamos de la pila un operando: " << number1 << std::endl;
  if (c != 'r' && c != 'l' && c != 'c') {
    number2 = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << number2 << std::endl;
  }
  
  switch (c) {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number2 - number1;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      result = number2 / number1;
      break;
    case '^':
      result = pow(number1, number2);
      break;
    case 'r':
      result = sqrt(number1);
      break;
    case 'l':
      result = log2(number1);
      break;
    case 'c':
      result = number1 * number1;
      break;
    default:
      break;
  }
  stack_.push(result);
  std::cout << "   Metemos en la pila el resultado: " << result << std::endl;
}

template<class T> bool rpn_t<T>::es_binario(const char c) {
  switch (c) {
    case '+':
      return true;
      break;
    case '-':
      return true;
      break;
    case '*':
      return true;
      break;
    case '/':
      return true;
      break;
    case '^':
      return true;
      break;
    default:
      return false;
      break;
  }
}

 
#endif  // RPNT_H_
