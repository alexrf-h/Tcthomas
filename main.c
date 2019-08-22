/*
 * File:   main_testando_o_tcc.c
 * Author: Cesar
 *
 * Created on 15 de Agosto de 2019, 08:19
 */

#include <stdio.h>      //Inclusa a biblioteca C
#include <stdlib.h>     //Inclusa a biblioteca do windows
#include "Config_16F871.h"      //Inclusa a configuraÃƒÂ§ÃƒÂ£o do PIC
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

void cursor()                                   // void que posiciona um traço para simbolizar onde o crusor esta
{
    char posicao ;
    
    lcd_cursor(posicao,1);
    lcd_envia_texto("-");



}



void sobe ()                                   // void que possibilita a navegacao pelo menu
{
    char posicao ;
    posicao++;
    }


void desce()
{
    char posicao ;   
        posicao--;
    }







void main ()
{                                               //Inicio da main
    TRISD = 0x00;                               // configuraçao para o lcd
    PORTD = 0x00;                               // configuraçao para o lcd
    TRISA = 0x00;                               // configura saidas para os leds
    PORTA = 0x00;                               // configura saidas para os leds
    TRISB = 0x0F;                               // configura entrada para os botÃµes
    TRISE = 0x01;                               // config do lcd

    char  inicio=0,                             // variavel para iniciar o lcd
            menu=0,                             // variavel para inicio do menu
            posicao,
            linha;

          
    lcd_iniciar ();                             //inicia o lcd
    lcd_limpar ();                              // limpa o lcd

    while (1)
    {                                           // inicio da laÃ§o de repetiÃ§Ã£o
        lcd_cursor (2,7);                   
        lcd_envia_texto("Aperte");
        lcd_cursor (3,7);
        lcd_envia_texto("confirma");
            
        if (inicio == 0);                       // caso variÃ¡vel de inÃ­cio for 0
        {                                       // inicio do laÃ§o de inÃ­cio
        if (RB2 == 1)                           // caso botÃ£o confirma for pressionado
        {                                       // inicio do laco do botao
            lcd_limpar();   
            lcd_cursor(1,2);
            lcd_envia_texto("Bem vindo ao simulador didatico");
            __delay_ms(800);
            lcd_cursor(3,2);
            lcd_envia_texto("Por favor,");
            __delay_ms(800);
            lcd_cursor(4,2);
            lcd_envia_texto("antes de utilizar leia o manual do usuario");
            __delay_ms(5000);
            inicio=1;                           // seta variÃ¡vel de inÃ­cio como 1
            lcd_limpar();

        }                                       // fim do laco do botao
        }                                       // fim do laco de inicio

        if (inicio==1 || menu ==0)
        {

            lcd_cursor(1,2);
            lcd_envia_texto("Escolha a partida:");
            lcd_cursor(3,2);
            lcd_envia_texto("Partida 1");
            lcd_cursor(4,2);
            lcd_envia_texto("Partida 2");
            cursor();
            
            if (RB0==1) // se botao cima for pressionado
            {    sobe();
                __delay_ms(100);
            }
            
            if (RB1==1) // se botao baixo for pressionado
            {     desce();
            __delay_ms(100);
            }
            
            if(posicao>5)   // caso a posicao do cursor atingir a borda do lcd
            {
                linha-- ;
                posicao=4;
            }

        }                                       // fim menu
        }                                       // fim da while


        }                                       // Fim da Main

      
