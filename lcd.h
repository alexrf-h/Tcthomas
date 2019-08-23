#define EN RE1
#define RS RE2
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

void lcd_port(const unsigned char x)//envia os 4 bits para o LCD de uma das duas funções abaixo
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

void lcd_envia_cmd(const unsigned x)//envia um comando para o LCD
{
	RS = 0x00;
	lcd_port(x);
	EN = 0x01;
	__delay_ms(0x04);
	EN = 0x00;
}

void lcd_envia_dado(const unsigned char x)//envia um dado para o LCD (caracter, letra ou numero)
{
	unsigned char z = x>>0x04;
	unsigned char y = x&0x0F;
	
	RS = 0x01;

	lcd_port(z);
	EN = 0x01;
	__delay_us(40);
	EN = 0x00;

	lcd_port(y);
	EN = 0x01;
	__delay_us(0x28);
	EN = 0x00;	
}

void lcd_envia_texto(const unsigned char *x)//com o auxílio da função acima envia palavra ou texto para o LCD
{
	int i;
    for(i = 0; x[i]!='\0'; i++)
	lcd_envia_dado(x[i]);
}

void lcd_iniciar()//Inicia o LCD no modo 4 bits, cursor desligado e formato 5X7
{
	lcd_envia_cmd(0x02);

	lcd_envia_cmd(0x02);

	lcd_envia_cmd(0x08);

	lcd_envia_cmd(0x00);

	lcd_envia_cmd(0x0C);

	lcd_envia_cmd(0x00);

	lcd_envia_cmd(0x06);
}

void lcd_limpar()//limpa informações do LCD
{

	lcd_envia_cmd(0x00);

	lcd_envia_cmd(0x01);	
}

void lcd_cursor(const unsigned l, const unsigned c)//posiciona o cursor (linha e coluna)
{
	unsigned char posicao, z, y;
	
	if(l == 0x01)
	{
		posicao = 0x80 + c - 1;
		z = posicao>>0x04;
		y = posicao&0x0F;
		lcd_envia_cmd(z);
		lcd_envia_cmd(y);
	}

	else if(l == 0x02)
	{
		posicao = 0xC0 + c - 1;
		z = posicao>>0x04;
		y = posicao&0x0F;
		lcd_envia_cmd(z);
		lcd_envia_cmd(y);
	}
        else if(l == 0x03)
	{
		posicao = 0x94 + c - 1;
		z = posicao>>0x04;
		y = posicao&0x0F;
		lcd_envia_cmd(z);
		lcd_envia_cmd(y);
	}
        else if(l == 0x04)
	{
		posicao = 0xD4 + c - 1;
		z = posicao>>0x04;
		y = posicao&0x0F;
		lcd_envia_cmd(z);
		lcd_envia_cmd(y);
	}
}

void lcd_shift_left()//desloca o texto para a esquerda
{

	lcd_envia_cmd(0x01);

	lcd_envia_cmd(0x08);	
}

void lcd_shift_right()//desloca o texto para a direita
{

	lcd_envia_cmd(0x01);

	lcd_envia_cmd(0x0C);
}

