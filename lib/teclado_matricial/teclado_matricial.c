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
    int tecMat1 [4][4]{ //ERROR: Pide ";" pero esta puesto
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
};
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
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
int teclado_matricial(int f1, int f2, int f3, int f4){
    for(i=0 ;i < 4 ;i++){//filas
        for(j=0; j < 4; j++){//columnas
            int tecMat1 [i][j] = 0;
            if(GPIOA -> IDR & (1<<j) == 0){//si la lectura del GPIOA = 0 en alguna columna
                input [i][j];//se guardan las coordenadas en el vector "input"
                tecMat=input;//uso las coordenadas obtenidas para que mi vectro bidimensional de char ubique el valor que debe adoptar
            }
        }
}
return 0;
}





