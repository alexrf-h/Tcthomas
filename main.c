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

/*

        void's de comandos

*/



void cursor()                                   // void que posiciona um traço para simbolizar onde o crusor esta
{
    char posicao ;
    
    lcd_cursor(posicao,1);
    lcd_envia_texto("-");
}

void sobe ()                                   // void que possibilita a navegacao pelo menu
{
    char posicao ;
    posicao--;
    if(posicao<1)                              //limita o cursor de ir além das possibilidades do menu
        posicao=1;
}

void desce()    
{
    char posicao ;   
        posicao++;
    if(posicao>9)                              //limita o cursor de ir além das possibilidades do menu
        posicao=9;
    }

/*

        void's de niveis do menu de selecao

*/
        void nivel_1()
        {
            lcd_limpar();
            lcd_cursor(1,2);
            lcd_envia_texto("Escolha a partida:");
            lcd_cursor(3,2);
            lcd_envia_texto("Partida 1");
            lcd_cursor(4,2);
            lcd_envia_texto("Partida 2");
            cursor();
        
        }

        void nivel_2()
        {
            lcd_limpar();
            lcd_cursor(2,2);
            lcd_envia_texto("Partida 1");
            lcd_cursor(3,2);
            lcd_envia_texto("Partida 2");
            lcd_cursor(4,2);
            lcd_envia_texto("Partida 3");
            
        }

        void nivel_3()
        {
            lcd_limpar();
            lcd_cursor(1,2);
            lcd_envia_texto("Partida 1");
            lcd_cursor(2,2);
            lcd_envia_texto("Partida 2");
            lcd_cursor(3,2);
            lcd_envia_texto("Partida 3");
            lcd_cursor(4,2);
            lcd_envia_texto("Partida 4");
        }

        void nivel_4()
        {
           lcd_limpar();
            lcd_cursor(1,2);
            lcd_envia_texto("Partida 2");
            lcd_cursor(2,2);
            lcd_envia_texto("Partida 3");
            lcd_cursor(3,2);
            lcd_envia_texto("Partida 4");
            lcd_cursor(4,2);
            lcd_envia_texto("Partida 5"); 

        }

        void nivel_5()
        {
           lcd_limpar();
            lcd_cursor(1,2);
            lcd_envia_texto("Partida 3");
            lcd_cursor(2,2);
            lcd_envia_texto("Partida 4");
            lcd_cursor(3,2);
            lcd_envia_texto("Partida 5");
            lcd_cursor(4,2);
            lcd_envia_texto("Partida 6"); 

        }

        void nivel_6()
        {
           lcd_limpar();
            lcd_cursor(1,2);
            lcd_envia_texto("Partida 4");
            lcd_cursor(2,2);
            lcd_envia_texto("Partida 5");
            lcd_cursor(3,2);
            lcd_envia_texto("Partida 6");
            lcd_cursor(4,2);
            lcd_envia_texto("Partida 7"); 

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
    {                                           // inicio da laco de repeticao
        lcd_cursor (2,7);                   
        lcd_envia_texto("Aperte");
        lcd_cursor (3,7);
        lcd_envia_texto("confirma");
            
        if (inicio == 0);                       // caso variÃ¡vel de inicio for 0
        {                                       // inicio do laÃ§o de inicio
        if (RB2 == 1)                           // caso botao confirma for pressionado
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
            inicio=1;                           // seta variavel de inicio como 1
            lcd_limpar();

        }                                       // fim do laco do botao
        }                                       // fim do laco de inicio

        /*
        
        inicio do menu selecao de partidas
        
        */
        
        if (inicio==1 || menu ==0)
        {
            if (RB0==1) // se botao cima for pressionado
            {    sobe();
                 cursor();   
             __delay_ms(50);
             
            }
            
            if (RB1==1) // se botao baixo for pressionado
            {     desce();
             cursor();
            __delay_ms(50);
            }
            
            
            if (posicao<5)
            {
                        nivel_1();
                        cursor();
            }
                
            if(posicao==5)         
                {
                        nivel_2();
                        cursor();
            }
            if(posicao==6)               
              {
                        nivel_3();
                        cursor();
            }
            if(posicao==7)              
                {
                        nivel_4();
                        cursor();
            }
            if(posicao==8)               
{
                        nivel_5();
                        cursor();
            }
            if(posicao==9)           
               {
                        nivel_6();
                        cursor();
            }           
        }                                       // fim menu
        }                                       // fim da while


        }                                       // Fim da Main

      
