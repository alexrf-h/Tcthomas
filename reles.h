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

#define volta RA4

char load=0,f,erro=1;



void erro1()
{
    while (erro==1)
    {
    r1=1;
    if(load<20){
    lcd_cursor(1,1);
    lcd_envia_texto("Por favor,");
    lcd_cursor(2,1);
    lcd_envia_texto("acione a partida 1");
    tempo_seg(3);
    lcd_limpar();
    lcd_cursor(3,6);
    lcd_envia_texto("Carregando");
    lcd_cursor(4,1);
    for(load=0;load<21;load++)
    {
        lcd_envia_texto("*");
        tempo_ms(200);
    }
    erro=0;
    }
    if(erro==0)
    {
    lcd_limpar();
    lcd_cursor(1,1);
    ast();
    lcd_cursor(2,5);
    lcd_envia_texto("Executando");
    lcd_cursor(3,5);
    lcd_envia_texto("Erro 1");
    lcd_cursor(4,1);
    ast();
    r8=1;

    if (volta)
    {
        if(f==1)
        {
            load++;
            f=0;
        }
    }
    if (!volta)
        f=1;

    if (load==22)
    {
        r1=0;
        r8=0;
        lcd_cursor(2,1);
        lcd_envia_texto("é tem que ver isso ai HEHE");
        tempo_seg(5);
        
    }
    }
    }

}




void erro2()
{

}

void erro3()
{

}
void erro4()
{

}
void erro5()
{

}
void erro6()
{

}
void erro7()
{

}
void erro8()
{

}void erro9()
{

}void erro10()
{

}void erro11()
{

}
void erro12()
{

}void erro13()
{

}
void erro14()
{

}












