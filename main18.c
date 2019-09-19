/*
 * File:   main_testando_o_tcc.c
 * Author: Cesar
 *
 * Created on 15 de Agosto de 2019, 08:19
 */

#include <stdio.h>      //Inclusa a biblioteca C
#include <stdlib.h>     //Inclusa a biblioteca do windows
#include "config.h"     //Inclusa a configuraÃ?Â§Ã?Â£o do PIC
#include "lcd2.h"       //Incluso a biblioteca do LCD
#include "tempo2.h"     //Tempo modificado
#include "reles.h"      //Incluso biblioteca para acionamento de reles

#define cima RC0           // botÃ£o cima identificado como RB0
#define baixo RC1          // botÃ£o baixo identificado como RB1
#define confirma RC2       // botÃ£o confirma como RB2
#define volta RA4          // botÃ£o volta como RB3

/* 

        void's de comandos

*/

char posicao=3,trava;
void cursor()                                   // void que posiciona um traço para simbolizar onde o crusor esta
{
   

    lcd_cursor(posicao,1);
    lcd_envia_texto("-");
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
    TRISD = 0x00;                               // configuraçao para o lcd
    PORTD = 0x00;                               // configuraçao para o lcd
    TRISA = 0xF0;                               // configura saidas para os leds
    PORTA = 0xF0;                               // configura saidas para os leds
    TRISB = 0x00;                               // configura entrada para os botÃµes
    TRISE = 0x00;                               // config do lcd
    ADCON1= 0x0F;

    int                                  
            menu=0,                             // variavel para inicio do menu
            posicao,                            // variavel para os niveis do menu
            start=0,                            //variavel quando liga
            preset=0,                           // variavel de introdução
            flag,                               // variavel para botao sobe
            flag2,                              // variavel para botao desce
            trava=0,                            // variavel para entrar no submenu
            subm=1,                               // variavel de seleção para o sub menu
            erro=1;

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
        if (confirma==1 && start==1 && menu==0)
            preset++;
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
            tempo_seg(1);
            lcd_limpar();

            lcd_cursor(1,1);
            lcd_envia_texto(" Por favor, antes de");
            lcd_cursor(2,1);
            lcd_envia_texto("utilizar o painel");
            lcd_cursor(3,1);
            lcd_envia_texto("leia o manual");
            lcd_cursor(4,1);
            lcd_envia_texto("do usuario");
            tempo_seg(1);

            preset=2;
            menu=1;                      // seta variavel de inicio como 1
            posicao=4;
            lcd_limpar();

        }                                // fim do laco do botao
        /*

        inicio do menu selecao de partidas

        */
        if ( menu ==1)
        {
            if (cima==1 && trava==0) // se botao cima for pressionado
            {
                    if(flag==1)
                    posicao--;
                    lcd_limpar();
                    flag=0;
                    if (posicao<4)
                        posicao=4;
            }
            if(cima==0 )
                flag=1;

            if (baixo==1 && trava==0) // se botao baixo for pressionado
            {
                    if(flag2==1)
                    posicao++;
                    
                    lcd_limpar();
                    flag2=0;
                    if (posicao>=11)
                        posicao=10;
            }
            if(baixo==0)
                flag2=1;

            if(posicao==4)
            {
                if (trava==0)
                nivel_1();

                if(confirma==1 && trava==0)
                    {
                    lcd_limpar();
                    trava=1;
                    tempo_ms(200);
                    }

                if(trava==1)
                    {

                    if(cima==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=1;
                    }

                    if(baixo==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=2;
                    }

           if(subm==1)
                    {
                    lcd_cursor(1,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 1");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 2");
                    
                    
                    if(confirma)
                        
                        if(erro==0)
                        {
                        lcd_limpar();
                        erro1();
                        }
                      }
                    
           if(subm==2)
                    {
                    lcd_cursor(2,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 1");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 2");
                    
                  }

                if(volta==1)
               {
                        subm=1;
                        trava=0;
                        lcd_limpar();}
               

               }                       // fim do laco trava
               }                            // fim do laco posicao 4


            if(posicao==5)
            {
                if (trava==0)
                nivel_2();
                 if(confirma==1 && trava==0)
                {
                    lcd_limpar();
                    trava=1;
                }
                    if(trava==1)
                    {

                        if(cima==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=1;
                    }

                    if(baixo==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=2;
                    }

           if(subm==1)
                    {
                    lcd_cursor(1,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 3");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 4");

                    }
           if(subm==2)
                    {
                    lcd_cursor(2,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 3");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 4");

                  }

                if(volta==1)
               {
                        subm=1;
                        trava=0;
                        lcd_limpar();
                    }           // fim laço de volta
                    }           // fim laço de  trava
            }                   // fim laço de posicao

            if(posicao==6)
            {   if (trava==0)
                nivel_3();
      if(confirma==1 && trava==0)
                {
                    lcd_limpar();
                    trava=1;
                }
                    if(trava==1)
                    {

                        if(cima==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=1;
                    }

                    if(baixo==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=2;
                    }

           if(subm==1)
                    {
                    lcd_cursor(1,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 5");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 6");

                    }
           if(subm==2)
                    {
                    lcd_cursor(2,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 5");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 6");

                  }

                if(volta==1)
               {
                        subm=1;
                        trava=0;
                        lcd_limpar();

                    }           // fim laço de volta
                    }           // fim laço de  trava
            }                   // fim laço de posicao
            
            if(posicao==7)
            {   if (trava==0)
                nivel_4();


            if(confirma==1 && trava==0)
                {
                    lcd_limpar();
                    trava=1;
                }
                    if(trava==1)
                    {

                        if(cima==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=1;
                    }

                    if(baixo==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=2;
                    }

           if(subm==1)
                    {
                    lcd_cursor(1,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 7");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 8");

                    }
           if(subm==2)
                    {
                    lcd_cursor(2,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 7");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 8");

                  }

                if(volta==1)
               {
                        subm=1;
                        trava=0;
                        lcd_limpar();

                    }           // fim laço de volta
                    }           // fim laço de  trava
            }                   // fim laço de confirma
            
            if(posicao==8)
            {   if (trava==0)
                nivel_5();
            if(confirma==1 && trava==0)
                {
                    lcd_limpar();
                    trava=1;
                }
                    if(trava==1)
                    {

                        if(cima==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=1;
                    }

                    if(baixo==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=2;
                    }

           if(subm==1)
                    {
                    lcd_cursor(1,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 9");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 10");

                    }
           if(subm==2)
                    {
                    lcd_cursor(2,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 9");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 10");

                  }

                if(volta==1)
               {
                        subm=1;
                        trava=0;
                        lcd_limpar();
                    }           // fim laço de volta
                    }           // fim laço de  trava
            }                   // fim laço de posicao

            if(posicao==9)
            {   if (trava==0)
                nivel_6();
            if(confirma==1 && trava==0)
                {
                    lcd_limpar();
                    trava=1;
                }
                    if(trava==1)
                    {

                        if(cima==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=1;
                    }

                    if(baixo==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=2;
                    }

           if(subm==1)
                    {
                    lcd_cursor(1,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 11");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 12");

                    }
           if(subm==2)
                    {
                    lcd_cursor(2,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 11");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 12");

                  }

                if(volta==1)
               {
                        subm=1;
                        trava=0;
                        lcd_limpar();
                    }           // fim laço de volta
                    }           // fim laço de  trava
            }                   // fim laço de posicao
            if (posicao==10)
            {   if (trava==0)
                nivel_7();
            if(confirma==1 && trava==0)
                {
                    
                    lcd_limpar();
                    trava=1;
                }
                    if(trava==1)
                    {

                        if(cima==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=1;
                    }

                    if(baixo==1 && trava==1)
                    {
                    lcd_limpar();
                    subm=2;
                    }

           if(subm==1)
                    {
                    lcd_cursor(1,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 13");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 14");

                    }
           if(subm==2)
                    {
                    lcd_cursor(2,1);
                    lcd_envia_texto("-");
                    lcd_cursor(1,3);
                    lcd_envia_texto("Erro 13");
                    lcd_cursor(2,3);
                    lcd_envia_texto("Erro 14");

                   }

                if(volta==1)
                    {
                        subm=1;
                        trava=0;
                        lcd_limpar();
                    }                           // fim laço de volta
                    }                           // fim laço de  trava
            }                                   // fim laço de posicao







            }                                   // fim menu
        }                                       // fim da while
        }                                       // Fim da Main

