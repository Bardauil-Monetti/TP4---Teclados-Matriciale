#ifndef TECLADO_MATRICIAL_H
#define TECLADO_MATRICIAL_H
#include <stm32f103xb.h>
void teclado_matricial_init(int f1, int f2, int f3, int f4, int c1, int c2, int c3, int c4); 
int teclado_matricial(int f1, int f2, int f3, int f4, int c1, int c2, int c3, int c4); 
#endif