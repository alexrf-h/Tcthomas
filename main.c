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
#define RB1 baixo;          // botão baixo identificado como RB1
#define RB2 confirma;       // botão confirma como RB2
#define RB3 volta;          // botão volta como RB3

#define RA1 led1;           // define saidas do portA como led's
#define RA2 led2;
#define RA3 led3;
#define RA4 led4;
#define RA5 led5;

void main ()
{                               //Inicio da main
    TRISD = 0x00;               // configuração para o lcd
    PORTD = 0x00;               // configuração para o lcd
    TRISA = 0x00;               // configura saidas para os leds    
    PORTA = 0x00;               // configura saidas para os leds         
    TRISB = 0x0F;               // configura entrada para os botões 

    char  inicio=0;             // variavel para iniciar o lcd 
    
    
    lcd_iniciar ();  //inicia o lcd
    lcd_limpar ();  // limpa o lcd

    while (1)
    {                                       // inicio da laço de repetição
        lcd_cursor (2,7);                   
        lcd_envia_texto("Aperte");
        lcd_cursor (3,7);
        lcd_envia_texto("confirma");
            
        if (inicio == 0);                    // caso variável de início for 0
        { // inicio do laço de início
        if (confirma ==1 )                   // caso botão confirma for pressionado
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
            inicio=1;                       // seta variável de início como 1                           
        }
        
        
        
        }// fim do laço de início
        }


    }

}       // Fim da Main
