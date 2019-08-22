/*
 * File:   main_testando_o_tcc.c
 * Author: Cesar
 *
 * Created on 15 de Agosto de 2019, 08:19
 */

#include <stdio.h>      //Inclusa a biblioteca C
#include <stdlib.h>     //Inclusa a biblioteca do windows
#include "Config_16F871.h"      //Inclusa a configuraÃÂ§ÃÂ£o do PIC
#include "lcd.h"        //Incluso a biblioteca do LCD

#define cima RB0;           // botÃ£o cima identificado como RB0
#define baixo RB1;          // botÃ£o baixo identificado como RB1
#define confirma RB2;       // botÃ£o confirma como RB2
#define volta RB3;          // botÃ£o volta como RB3

#define led1 RA0;           // define saidas do portA como led's
#define led2 RA1;
#define led3 RA2;
#define led4 RA3;
#define led5 RA5;

void main ()
{                               //Inicio da main
    TRISD = 0x00;               // configuraçao para o lcd
    PORTD = 0x00;               // configuraçao para o lcd
    TRISA = 0x00;               // configura saidas para os leds    
    PORTA = 0x00;               // configura saidas para os leds         
    TRISB = 0x0F;               // configura entrada para os botÃµes
    TRISE = 0x01;               // config do lcd

    char  inicio=0;             // variavel para iniciar o lcd 
    
    
    lcd_iniciar ();  //inicia o lcd
    lcd_limpar ();  // limpa o lcd

    while (1)
    {                                       // inicio da laÃ§o de repetiÃ§Ã£o
        lcd_cursor (2,7);                   
        lcd_envia_texto("Aperte");
        lcd_cursor (3,7);
        lcd_envia_texto("confirma");
            
        if (inicio == 0);                    // caso variÃ¡vel de inÃ­cio for 0
        { // inicio do laÃ§o de inÃ­cio
        if (RB2 == 1)                   // caso botÃ£o confirma for pressionado
        {
            lcd_limpar();   
            lcd_cursor(1,1);
            lcd_envia_texto("Bem vindo ao simulador didatico");
            __delay_ms(500);
            lcd_cursor(3,1);
            lcd_envia_texto("Por favor,");
            __delay_ms(500);
            lcd_cursor(4,1);
            lcd_envia_texto("antes de utilizar leia o manual do usuario");
            __delay_ms(8000);
            inicio=1;                       // seta variÃ¡vel de inÃ­cio como 1                           
        }
        
        
        
        }// fim do laÃ§o de inÃ­cio
        }


    }// Fim da Main

      
