

#ifndef STACKCALC_HPP
#define STACKCALC_HPP

#include "token.hpp"
#include<stack>
#include<iostream>
#include<stdexcept>

using namespace std;
template <typename Iter> double RPN(Iter first, Iter last) {

double a;
double b;
double val;

stack<double> container;
for(;first!=last;++first){
  if(first->is_operand()){
    container.push(first->as_operand());
  }
  if(first->is_operator()){
    if(container.size()>1){
      if(first->as_operator()=='+'){
        b=container.top();
        container.pop();
        a=container.top();
        container.pop();
        val = a + b;
        container.push(val);
      }
      if(first->as_operator()=='-'){
        b = container.top();
        container.pop();
        a = container.top();
        container.pop();
        val = a - b;
        container.push(val);
      }
      if(first->as_operator()=='*'){
        b = container.top();
        container.pop();
        a=container.top();
        container.pop();
        val = a*b;
        container.push(val);
      }
      if(first->as_operator()=='/'){
        if(container.top()!=0){
          b = container.top();
          container.pop();

          a = container.top();
          container.pop();
          val = a/b;
          container.push(val);
        }else{throw std::runtime_error("error");}
      }
    }else{throw runtime_error("error");}
  }



}// End of for loop
if(container.size()>1){throw runtime_error("error");}
return container.top();
} // RPN

#endif // STACKCALC_HPP
