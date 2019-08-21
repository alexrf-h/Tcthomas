/* 
 * File:   main_testando_o_tcc.c
 * Author: Cesar
 *
 * Created on 15 de Agosto de 2019, 08:19
 */

#include <stdio.h>      //Inclusa a biblioteca C
#include <stdlib.h>     //Inclusa a biblioteca do windows
#include "Config_16F871.h"      //Inclusa a configuração do PIC
#include "lcd.h"        //Incluso a biblioteca do LCD

void main ()
{       //Inicio da main
    TRISD = 0x00;
    PORTD = 0x00;
    TRISA = 0x01;
    PORTA = 0x01;
    TRISB = 0x0F;
    

    Lcd_Iniciar ();
    Lcd_Limpar ();

    while (1)
    {
        Lcd_Limpar ();
        Lcd_Cursor (1,1);
        Lcd_Envia_Texto ("odeio tudo nessa merda");
        __delay_ms (100);
        Lcd_Cursor (2,1);
        Lcd_Envia_Texto ("odeio mesmo");
        __delay_ms (100);
        Lcd_Cursor (3,1);
        Lcd_Envia_Texto ("odeio nmrl");
        __delay_ms (100);
        Lcd_Cursor (4,1);
        Lcd_Envia_Texto ("como odeio");
    }

}       // Fim da Main
