#include "stm32f103xb.h"
#include "TECLADO_MATRICIAL_H"
#include STRING.h
int main(void) {
int lr = 1, lv = 2; //leds indicativos
    char contra_default[7] = {'A', '1', '1', '3', '4', '8', '\0'};
    char new_contra[7] = {'0', '0', '0', '0', '0', '0', '\0'};
    int pos;//indice
    char contra_ingresada[7] = {'0', '0', '0', '0', '0', '0', '\0'};
    GPIOA->CRL |=  (0b0010 << (lr * 4));
    GPIOA->CRL |=  (0b0010 << (lv * 4));
    bool cambio = false, check = false;
        while(1){
            char car = teclado_matricial(f1, f2, f3, f4, c1, c2, c3, c4);
            if(car != 'x'){
                if(cambio){
                    //lectura en vector de nueva contraseña
                    new_contra[pos] = tecMac;
                    if(pos==6){
                        //copio vector nuevo en el viejo
                        strcpy(contra_default, new_contra);
                    }
                    //reseteo vector de nueva contraseña
                    memset(new_contra, 0, sizeof(new_contra));
                    pos = 0;
                    cambio=false;
                }else if(check){
                    if(car == '#'){
                        cambio = true;
                        pos = 0;
                        check = false;
                    }
                }else{
                    //almacena contraseña ingresada
                    strcpy(tecMat, new_contra);
                    if(pos == 6){
                     if (strcmp (new_contra, contra_default) == 0) {//comparo contraseña ingresada con la correcta                                              
                         GPIOA->BSRR |= (1 << lv);  //prendo led verde
                        GPIOA -> BSRR |= (1<<lr+16);
                            check = false;  
                             }else{  
                         GPIOA->BSRR |= (1 << lr); //prendo led rojo    
                         GPIOA -> BSRR |= (1<<lv+16);

                        check = false;  
                        memset(new_contra, 0, sizeof(new_contra));//borro contraseña ingresada
                        pos = 0; //reset de posición
                    
                    
                    }
                }
          }

}
}
    return 0;
}
