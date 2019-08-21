/*
 * File:   main_testando_o_tcc.c
 * Author: Cesar
 *
 * Created on 15 de Agosto de 2019, 08:19
 */

#include <stdio.h>      //Inclusa a biblioteca C
#include <stdlib.h>     //Inclusa a biblioteca do windows
#include "Config_16F871.h"      //Inclusa a configuraÃ§Ã£o do PIC
#include "lcd.h"        //Incluso a biblioteca do LCD

#define RB0 cima;           // botão cima identificado como RB0 
#define RB1 baixo;
#define RB2 confirma;
#define RB3 volta;

#define RA1 led1;
#define RA2 led2;
#define RA3 led3;
#define RA4 led4;
#define RA5 led5;

void main ()
{       //Inicio da main
    TRISD = 0x00;
    PORTD = 0x00;
    TRISA = 0x01;
    PORTA = 0x01;
    TRISB = 0x0F;

    char  inicio=0;
    
    
    lcd_iniciar ();  //inicia o lcd
    lcd_limpar ();  // limpa o lcd

    while (1)
    {                                       // inicio da laço de repetição
        lcd_cursor (2,7);
        lcd_envia_texto("Aperte");
        lcd_cursor (3,7);
        lcd_envia_texto("confirma");
        
        
        
        if (inicio == 0);
        {
        if (confirma ==1 )
        {
            lcd_limpar();
            lcd_cursor(1,1);
            lcd_envia_texto("Bem vindo ao simulador didático");
            lcd_cursor(3,1);
            lcd_envia_texto("Por favor,");
            lcd_cursor(4,1);
            lcd_envia_texto("antes de utilizar leia o manual do usuário");
            inicio=1;
        }
        
        
        
        }
        }


    }

}       // Fim da Main
