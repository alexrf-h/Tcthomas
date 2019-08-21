#define EN RE1
#define RS RE2
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

void Lcd_Port(const unsigned char x)//envia os 4 bits para o LCD de uma das duas funções abaixo
{
	if(x&0x01)
	D4 = 0x01;
	else
	D4 = 0x00;
	
	
	if(x&0x02)
	D5 = 0x01;
	else
	D5 = 0x00;
	
	
	if(x&0x04)
	D6 = 0x01;
	else
	D6 = 0x00;

	
	if(x&0x08)
	D7 = 0x01;
	else
	D7 = 0x00;
}

void Lcd_Envia_Cmd(const unsigned x)//envia um comando para o LCD
{
	RS = 0x00;
	Lcd_Port(x);
	EN = 0x01;
	__delay_ms(0x04);
	EN = 0x00;
}

void Lcd_Envia_Dado(const unsigned char x)//envia um dado para o LCD (caracter, letra ou numero)
{
	unsigned char z = x>>0x04;
	unsigned char y = x&0x0F;
	
	RS = 0x01;

	Lcd_Port(z);
	EN = 0x01;
	__delay_us(40);
	EN = 0x00;

	Lcd_Port(y);
	EN = 0x01;
	__delay_us(0x28);
	EN = 0x00;	
}

void Lcd_Envia_Texto(const unsigned char *x)//com o auxílio da função acima envia palavra ou texto para o LCD
{
	int i;
    for(i = 0; x[i]!='\0'; i++)
	Lcd_Envia_Dado(x[i]);
}

void Lcd_Iniciar()//Inicia o LCD no modo 4 bits, cursor desligado e formato 5X7
{
	Lcd_Envia_Cmd(0x02);

	Lcd_Envia_Cmd(0x02);

	Lcd_Envia_Cmd(0x08);

	Lcd_Envia_Cmd(0x00);

	Lcd_Envia_Cmd(0x0C);

	Lcd_Envia_Cmd(0x00);

	Lcd_Envia_Cmd(0x06);
}

void Lcd_Limpar()//limpa informações do LCD
{

	Lcd_Envia_Cmd(0x00);

	Lcd_Envia_Cmd(0x01);	
}

void Lcd_Cursor(const unsigned l, const unsigned c)//posiciona o cursor (linha e coluna)
{
	unsigned char posicao, z, y;
	
	if(l == 0x01)
	{
		posicao = 0x80 + c - 1;
		z = posicao>>0x04;
		y = posicao&0x0F;
		Lcd_Envia_Cmd(z);
		Lcd_Envia_Cmd(y);
	}

	else if(l == 0x02)
	{
		posicao = 0xC0 + c - 1;
		z = posicao>>0x04;
		y = posicao&0x0F;
		Lcd_Envia_Cmd(z);
		Lcd_Envia_Cmd(y);
	}	
}

void Lcd_Shift_Left()//desloca o texto para a esquerda
{

	Lcd_Envia_Cmd(0x01);

	Lcd_Envia_Cmd(0x08);	
}

void Lcd_Shift_Right()//desloca o texto para a direita
{

	Lcd_Envia_Cmd(0x01);

	Lcd_Envia_Cmd(0x0C);
}
