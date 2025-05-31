#include "teclado_matricial.h"
#include "stm32f103xb.h"
char input [4][4];//para guardar la salida que luego voy a devolver al vector char (el de aabajo)
char tecMat[4][4]={
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};


void teclado_matricial_init(){
    
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Habilito el reloj del puerto A

    //pongo las filas en 1 lógico
    GPIOA->CRL &= ~(0xF<<(f1* 4));    // f1 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1 << (f1 * 4));
    GPIOA->BSRR|=(1<<(f1));

    GPIOA->CRL &= ~(0xF<<(f2* 4));    // f2 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1 << (f2 * 4));
    GPIOA->BSRR|=(1<<(f2));

    GPIOA->CRL &= ~(0xF<<(f3* 4));    // f3 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1 << (f3 * 4));
    GPIOA->BSRR|=(1<<(f3));

    GPIOA->CRL &= ~(0xF<<(f4* 4));    // f4 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1 << (f4 * 4));
    GPIOA->BSRR|=(1<<(f4));

    //pongo las columnas en pull-up
    GPIOA->CRL &= ~ (0xF<< (c1* 4));  // c1 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1<< (c1* 4)+3);
    GPIOA->BSRR |=  (1<< c1);

    GPIOA->CRL &= ~ (0xF<< (c2* 4));  // c2 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1<< (c2* 4)+3);
    GPIOA->BSRR |=  (1<< c2);

    GPIOA->CRL &= ~ (0xF<< (c3* 4));  // c3 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1<< (c3* 4)+3);
    GPIOA->BSRR |=  (1<< c3);

    GPIOA->CRL &= ~ (0xF<< (c4* 4));  // c4 SI esta definido (en "teclado_matricial.h")
    GPIOA->CRL |=  (1<< (c4* 4)+3);
    GPIOA->BSRR |=  (1<< c4);

}
char teclado_matricial(int f1, int f2, int f3, int f4, int c1, int c2, int c3, int c4)
{
    int filas[4] = {f1, f2, f3, f4};
    int columnas[4] = {c1, c2, c3, c4};
    for(int f=0; f<4; f++){ //escaneo filas
        GPIOA -> BSRR |= (1 << filas[f]) 
        for (int c = 0; c < 4; c++) { //escaneo columnas
            if ((GPIOA->IDR & (1 << columnas[c]) == 0)  {
                return tecMac[f][c];
            }
        }
        GPIOA->BSRR |= (1 << filas[f]+16);//prendo la fila
}
    return'x';
}

