/*
 * File:   main_testando_o_tcc.c
 * Author: Cesar
 *
 * Created on 15 de Agosto de 2019, 08:19
 */

#include <stdio.h>      //Inclusa a biblioteca C
#include <stdlib.h>     //Inclusa a biblioteca do windows
#include "config.h"      //Inclusa a configuraÃ?Â§Ã?Â£o do PIC
#include "lcd2.h"        //Incluso a biblioteca do LCD
#include "tempo2.h"

#define cima RB0           // botÃ£o cima identificado como RB0
#define baixo RB1          // botÃ£o baixo identificado como RB1
#define confirma RB2       // botÃ£o confirma como RB2
#define volta RB3          // botÃ£o volta como RB3

#define led1 RA0           // define saidas do portA como led's
#define led2 RA1
#define led3 RA2
#define led4 RA3
#define led5 RA5

/* a

        void's de comandos

*/

char posicao=3;


void cursor()                                   // void que posiciona um traço para simbolizar onde o crusor esta
{
   

    lcd_cursor(posicao,1);
    lcd_envia_texto("-");
}

void sobe ()                                   // void que possibilita a navegacao pelo menu
{
    
    posicao--;
    if(posicao==2)                              //limita o cursor de ir além das possibilidades do menu
        posicao=3;
}

void desce()
{
    
        posicao++;
    if(posicao==10)                              //limita o cursor de ir além das possibilidades do menu
        posicao=9;
    }

/*.

        void's de niveis do menu de selecao

*/
        void nivel_1()
        {
            
            lcd_cursor(1,2);
            lcd_envia_texto(" Escolha a partida:");
            lcd_cursor(2,1);
            lcd_envia_texto("********************");
            lcd_cursor(3,3);
            lcd_envia_texto("Partida 1");
            lcd_cursor(4,3);
            lcd_envia_texto("Partida 2");
            cursor();

        }

        void nivel_2()
        {
            lcd_cursor(1,1);
            lcd_envia_texto("********************");
            lcd_cursor(2,3);
            lcd_envia_texto("Partida 1");
            lcd_cursor(3,3);
            lcd_envia_texto("Partida 2");
            lcd_cursor(4,3);
            lcd_envia_texto("Partida 3");
                 cursor();



        }

        void nivel_3()
        {
            
            lcd_cursor(1,3);
            lcd_envia_texto("Partida 1");
            lcd_cursor(2,3);
            lcd_envia_texto("Partida 2");
            lcd_cursor(3,3);
            lcd_envia_texto("Partida 3");
            lcd_cursor(4,3);
            lcd_envia_texto("Partida 4");
            cursor();
        }

        void nivel_4()
        {
           
            lcd_cursor(1,3);
            lcd_envia_texto("Partida 2");
            lcd_cursor(2,3);
            lcd_envia_texto("Partida 3");
            lcd_cursor(3,3);
            lcd_envia_texto("Partida 4");
            lcd_cursor(4,3);
            lcd_envia_texto("Partida 5");
            cursor();

        }

        void nivel_5()
        {
           
            lcd_cursor(1,3);
            lcd_envia_texto("Partida 3");
            lcd_cursor(2,3);
            lcd_envia_texto("Partida 4");
            lcd_cursor(3,3);
            lcd_envia_texto("Partida 5");
            lcd_cursor(4,3);
            lcd_envia_texto("Partida 6");
            cursor();

        }

        void nivel_6()
        {
           
            lcd_cursor(1,3);
            lcd_envia_texto("Partida 4");
            lcd_cursor(2,3);
            lcd_envia_texto("Partida 5");
            lcd_cursor(3,3);
            lcd_envia_texto("Partida 6");
            lcd_cursor(4,3);
            lcd_envia_texto("Partida 7");
            cursor();

        }
                void nivel_7()
        {


            lcd_cursor(1,3);
            lcd_envia_texto("Partida 5");
            lcd_cursor(2,3);
            lcd_envia_texto("Partida 6");
            lcd_cursor(3,3);
            lcd_envia_texto("Partida 7");
            cursor();
            lcd_cursor(4,1);
            lcd_envia_texto("********************");


        }

void main ()
{                                               //Inicio da main
    TRISD = 0x0F;                               // configuraçao para o lcd
    PORTD = 0x00;                               // configuraçao para o lcd
    TRISA = 0x00;                               // configura saidas para os leds
    PORTA = 0x00;                               // configura saidas para os leds
    TRISB = 0x0F;                               // configura entrada para os botÃµes
    TRISE = 0x00;                               // config do lcd
    ADCON1= 0x0F;

    int     inicio=0,                             // variavel para iniciar o lcd
            menu=0,                             // variavel para inicio do menu
            posicao, 
            start=0,
            preset=0,
            flag,
            flag2;

    lcd_iniciar ();                             //inicia o lcd
    lcd_limpar ();                              // limpa o lcd

    while (1)
    {                                           // inicio da laco de repeticao

        if (start==0)
        {
        lcd_limpar ();
        lcd_cursor(1,1);
        lcd_envia_texto("********************");
        lcd_cursor(4,1);
        lcd_envia_texto("********************");
        lcd_cursor (2,7);
        lcd_envia_texto("Aperte");
        lcd_cursor (3,7);
        lcd_envia_texto("confirma");
        start=1;
        }

                            // caso variÃ¡vel de inicio for 0
                                               // inicio do laÃ§o de inicio
        if (confirma==1 && start==1)
        {
            preset++;
        
        }
        if (preset==1)                           // caso botao confirma for pressionado
        {                                              
            lcd_limpar();
            lcd_cursor(1,6);
            lcd_envia_texto("Bem vindo ao");
            lcd_cursor(2,3);
            lcd_envia_texto("Simulador Didatico");
            lcd_cursor(3,10);
            lcd_envia_texto("de");
            lcd_cursor(4,9);
            lcd_envia_texto("Erros");
            tempo_seg(5);
            
            lcd_limpar();

            lcd_cursor(1,1);
            lcd_envia_texto(" Por favor, antes de");
            lcd_cursor(2,1);
            lcd_envia_texto("utilizar o painel");
            lcd_cursor(3,1);
            lcd_envia_texto("leia o manual");
            lcd_cursor(4,1);
            lcd_envia_texto("do usuario");
            tempo_seg(6);

            preset=2;
            inicio=1;                           // seta variavel de inicio como 1
            menu=1;
            posicao=4;
            lcd_limpar();

        }                                // fim do laco do botao
                                               // fim do laco de inicio

        /*

        inicio do menu selecao de partidas

        */

        if (inicio==1 && menu ==1)
        {
            if (RB0==1) // se botao cima for pressionado
            {
                if(flag==1)
                    posicao--;
                    lcd_limpar();
                    flag=0;
                    if (posicao<4)
                        posicao=4;

            }
            if(RB0==0)
               
                flag=1;

            if (RB1==1) // se botao baixo for pressionado
            {
                    if(flag2==1)
                    posicao++;
                    
                    lcd_limpar();
                    flag2=0;
                    if (posicao>=11)
                        posicao=10;
            }

            if(RB1==0)
                flag2=1;

            if(posicao<5)
                nivel_1();         
            if(posicao==5)
               nivel_2(); 
            if(posicao==6)
                nivel_3();
            if(posicao==7)
                nivel_4();
            if(posicao==8)
                nivel_5();     
            if(posicao==9)
                nivel_6();
            if (posicao==10)
                nivel_7();
                
            
            }                                       // fim menu
        }                                       // fim da while
        }                                       // Fim da Main
