/*

 *      Comandos para cada partida de reles

 */


#define r8    RB7
#define r7    RB6
#define r6    RB5
#define r5    RB4
#define r4    RB3
#define r3    RB2
#define r2    RB1
#define r1    RB0
#define r9    RD7
#define r10   RD6
#define r11   RD5
#define r12   RD4
#define r13   RC5
#define r14   RC6
#define r15   RC4
#define r16   RA5
#define r17   RC6

#define volta RA4

    char
    load=0,
    erro=1,
    back=0;

/*

   Erros da partida Direta

 */
void erro1()        
{
    erro=1;
    while (erro==1)
    {
        r1=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 1");
        tempo_seg(1);
    
        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 1");
        ast(4);
        r8=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r8=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

void erro2()
{
    erro=2;
    while (erro==2)
    {
        r1=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 1");
        tempo_seg(3);

        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 2");
        ast(4);
        r9=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r9=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

void erro3()
{
    erro=3;
    while (erro==3)
    {
        r1=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 1");
        tempo_seg(3);

        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 3");
        ast(4);
        r15=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r15=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

void erro4()
{
    erro=3;
    while (erro==3)
    {
        r1=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 1");
        tempo_seg(3);

        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 3");
        ast(4);
        r8=1;
        r9=1;
        r15=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r8=0;
        r9=0;
        r15=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

/*

   Erros da partida Reversa

 */

void erro5()
{
    erro=5;
    while (erro==5)
    {
        r1=1;
        r2=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 2");
        tempo_seg(3);

        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 2");
        ast(4);
        r8=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r2=0;
        r8=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

void erro6()
{
    erro=6;
    while (erro==6)
    {
        r1=1;
        r2=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 5");
        tempo_seg(3);

        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 5");
        ast(4);
        r9=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r2=0;
        r9=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

void erro7()
{
    erro=7;
    while (erro==7)
    {
        r1=1;
        r2=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 6");
        tempo_seg(3);

        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 6");
        ast(4);
        r15=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r2=0;
        r15=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

void erro8()
{
    erro=8;
    while (erro==8)
    {
        r1=1;
        r2=1;
        if(load<20){
        lcd_cursor(1,2);
        lcd_envia_texto("Por favor,");
        lcd_cursor(2,1);
        lcd_envia_texto("acione a partida 6");
        tempo_seg(3);

        lcd_cursor(3,6);
        lcd_envia_texto("Carregando");
        lcd_cursor(4,1);
        for(load=0;load<21;load++)
        {
            lcd_envia_texto("*");
            tempo_ms(150);
        }
    }

    if(back==0)
    {
        lcd_limpar();
        ast(1);
        lcd_cursor(2,5);
        lcd_envia_texto("Executando");
        lcd_cursor(3,6);
        lcd_envia_texto("Erro 6");
        ast(4);
        r8=1;
        r9=1;
        r15=1;
        back=1;
    }

    if (volta==1)
    {
        while(volta){};
        back=2;
    }

    if (back==2)
    {
        r1=0;
        r2=0;
        r8=0;
        r9=0;
        r15=0;
        lcd_limpar();
        ast (1);
        lcd_cursor(2,6);
        lcd_envia_texto("Voltando ao");
        lcd_cursor(3,5);
        lcd_envia_texto("Menu de Erros");
        ast (4);
        tempo_seg(4);
        back=0;
        load=0;
        erro=0;
    }
    }
}

/*

    Erros da partida Estrela Triangulo

 */

void erro9()
{
    erro=9;
    while (erro==9)
    {
        r3=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 1");
            ast(4);
            r8=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r8=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}

void erro10()
{
    erro=10;
    while (erro==10)
    {
        r3=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 1");
            ast(4);
            r12=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r12=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}

void erro11()
{
    erro=11;
    while (erro==11)
    {
        r3=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 1");
            ast(4);
            r15=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r15=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}

void erro12()
{
    erro=12;
    while (erro==12)
    {
        r3=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 6");
            ast(4);
            r8=1;
            r12=1;
            r15=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r8=0;
            r12=0;
            r15=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}

/*

    Erros da partida Estrela Triangulo

 */

void erro13()
{
    erro=13;
    while (erro==13)
    {
        r3=1;
        r4=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 1");
            ast(4);
            r9=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r4=0;
            r9=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}

void erro14()
{
    erro=14;
    while (erro==14)
    {
        r3=1;
        r4=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 1");
            ast(4);
            r11=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r4=0;
            r11=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}

void erro15()
{
    erro=15;
    while (erro==15)
    {
        r3=1;
        r4=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 1");
            ast(4);
            r16=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r4=0;
            r16=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}

void erro16()
{
    erro=12;
    while (erro==12)
    {
        r3=1;
        if(load<20)
        {
            lcd_cursor(1,2);
            lcd_envia_texto("Por favor,");
            lcd_cursor(2,1);
            lcd_envia_texto("acione a partida 3");
            tempo_seg(3);

            lcd_cursor(3,6);
            lcd_envia_texto("Carregando");
            lcd_cursor(4,1);
            for(load=0;load<21;load++)
            {
                lcd_envia_texto("*");
                tempo_ms(150);
            }
        }

        if(back==0)
        {
            lcd_limpar();
            ast(1);
            lcd_cursor(2,5);
            lcd_envia_texto("Executando");
            lcd_cursor(3,6);
            lcd_envia_texto("Erro 6");
            ast(4);
            r8=1;
            r12=1;
            r15=1;
            back=1;
        }

        if (volta==1)
        {
            while(volta){};
            back=2;
        }

        if (back==2)
        {
            r3=0;
            r8=0;
            r12=0;
            r15=0;
            lcd_limpar();
            ast (1);
            lcd_cursor(2,6);
            lcd_envia_texto("Voltando ao");
            lcd_cursor(3,5);
            lcd_envia_texto("Menu de Erros");
            ast (4);
            tempo_seg(4);
            back=0;
            load=0;
            erro=0;
        }
    }
}
