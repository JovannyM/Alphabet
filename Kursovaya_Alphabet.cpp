#include "stdafx.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <math.h>

bool triger=true;
int const size=16;
int  win = 0, ochered=1, hod=1, trigger = 1, tab_trigger = 0, R_tab_trigger = 0, cash_xPosition = 50, cash_yPosition = 50, cash_Point_abc = 0;
char alph[2], znach, buff;
char abc[size];
char abc_string_pc[16], abc_string_user[16];
char szCount[8];
int abc_set[16]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char RU_1[16]={'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ж', 'З', 'И', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р'};
char RU_2[16]={'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я'};
char EN_1[16]={'A', 'B', 'C', 'D', 'E', 'F', 'J', 'H', 'I', 'G', 'K', 'L', 'M', 'N', 'O', 'P'};
char EN_2[16]={'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
HWND hcon = GetConsoleWindow();
HDC hdc = GetDC(hcon);

void random_refiller(); //да есть она блин, есть!
void drawing_simbol(char simbol, int xPos, int yPos); // и эта есть, слепые вы блин!
void drawing_gradient(int start_x, int finish_x, int start_y, int finish_y); // и эта есть

void filler_abc(char *alph) //Заполняет массив abc[] выбранным алфавитом
{
	int simbol_indicator = 0, random_var = 0;
	//printf("Каким алфавитом заполнить поле? (RU/EN)\n");
	//fflush(stdin); gets(alph);
	random_var = rand()%100;
	if(!strcmp("RU", alph) || !strcmp("ru", alph) || !strcmp("КГ", alph)||!strcmp("кг", alph))
	{
		//if(v<50)
		if(random_var<50)
		{
			for (int i = 0; i < 16; i++)
			{
					abc[i]=RU_1[i];
			}
		}
		else
		{
			for (int i = 0; i < 16; i++)
			{
					abc[i]=RU_2[i];
			}
		}
	}
	if(!strcmp("EN", alph)||!strcmp("en", alph)||!strcmp("УТ", alph)||!strcmp("ут", alph))
	{
		if(random_var>50)
		{
			for (int i = 0; i < 16; i++)
			{
				abc[i] = EN_1[i];
			}
		}
		else
		{
			for (int i = 0; i < 16; i++)
			{
				abc[i] = EN_2[i];
			}
		}
	}
	random_refiller();
}

int checker(char a) //есть ли уже такое значение в массиве abc_string[][]?
{
	for (int i = 0; i < 16; i++)
	{
		if(znach==abc_string_pc[i]) return 0;
		else continue;
	}
	return 1;
}

void checker_wincondition(int who_is)
{
	if(who_is == 1)
	{
		for (int i = 0; i < 16; i++)
		{
			if(abc_string_user[i] == abc[i]) continue;
			else
			{
				win = 0;
				return;
			}
		}
		win = 1;
	}
	else
	{
		for (int i = 0; i < 16; i++)
		{
			if(abc_string_pc[i] == abc[i]) continue;
			else
			{
				win = 0;
				return;
			}
		}
		win = 2;
	}
}

void random_refiller() //рандомно заполняет abc_string_##[] из abc[][]
{
	int schet = 0;
	system("cls");
	for (int i = 0; i < 16; i++)
	{
		znach = abc[rand()%16];
		if(checker(znach))
		{
			abc_string_pc[schet] = znach;
			abc_string_user[schet] = znach;
			schet++;
		}
		else i--;
	}
}

void rotation_abc_string(int variant, int number) //поворот против часовой стрелки выбранного массива
{
	if(variant==1)
	{
		switch (number)
		{
			case 1:
			{
				buff = abc_string_pc[0];
				abc_string_pc[0]=abc_string_pc[1]; 
				abc_string_pc[1]=abc_string_pc[5];	
				abc_string_pc[5]=abc_string_pc[4]; 
				abc_string_pc[4]=buff;
				break;
			}
			case 2:
			{
				buff = abc_string_pc[1]; 
				abc_string_pc[1]=abc_string_pc[2]; 
				abc_string_pc[2]=abc_string_pc[6];	
				abc_string_pc[6]=abc_string_pc[5]; 
				abc_string_pc[5]=buff;
				break;
			}
			case 3:
			{
				buff = abc_string_pc[2]; 
				abc_string_pc[2]=abc_string_pc[3]; 
				abc_string_pc[3]=abc_string_pc[7];	
				abc_string_pc[7]=abc_string_pc[6]; 
				abc_string_pc[6]=buff;
				break;
			}
			case 4:
			{
				buff = abc_string_pc[4]; 
				abc_string_pc[4]=abc_string_pc[5]; 
				abc_string_pc[5]=abc_string_pc[9]; 
				abc_string_pc[9]=abc_string_pc[8]; 
				abc_string_pc[8]=buff;
				break;
			}
			case 5:
			{
				buff = abc_string_pc[5]; 
				abc_string_pc[5]=abc_string_pc[6]; 
				abc_string_pc[6]=abc_string_pc[10]; 
				abc_string_pc[10]=abc_string_pc[9]; 
				abc_string_pc[9]=buff;
				break;
			}
			case 6:
			{
				buff = abc_string_pc[6]; 
				abc_string_pc[6]=abc_string_pc[7]; 
				abc_string_pc[7]=abc_string_pc[11]; 
				abc_string_pc[11]=abc_string_pc[10]; 
				abc_string_pc[10]=buff;
				break;
			}
			case 7:
			{
				buff = abc_string_pc[8];
				abc_string_pc[8]=abc_string_pc[9]; 
				abc_string_pc[9]=abc_string_pc[13]; 
				abc_string_pc[13]=abc_string_pc[12]; 
				abc_string_pc[12]=buff;
				break;
			}
			case 8:
			{
				buff = abc_string_pc[9]; 
				abc_string_pc[9]=abc_string_pc[10]; 
				abc_string_pc[10]=abc_string_pc[14]; 
				abc_string_pc[14]=abc_string_pc[13]; 
				abc_string_pc[13]=buff;
				break;
			}
			case 9:
			{
				buff = abc_string_pc[10]; 
				abc_string_pc[10]=abc_string_pc[11]; 
				abc_string_pc[11]=abc_string_pc[15]; 
				abc_string_pc[15]=abc_string_pc[14]; 
				abc_string_pc[14]=buff;
				break;
			}
		}
	}
	else
	{
		switch (number)
		{
		case 1:
			{
				buff = abc_string_user[0]; 
				abc_string_user[0]=abc_string_user[1]; 
				abc_string_user[1]=abc_string_user[5]; 
				abc_string_user[5]=abc_string_user[4]; 
				abc_string_user[4]=buff;
				break;
			}
			case 2:
			{
				buff = abc_string_user[1]; 
				abc_string_user[1]=abc_string_user[2]; 
				abc_string_user[2]=abc_string_user[6]; 
				abc_string_user[6]=abc_string_user[5]; 
				abc_string_user[5]=buff;
				break;
			}
			case 3:
			{
				buff = abc_string_user[2]; 
				abc_string_user[2]=abc_string_user[3]; 
				abc_string_user[3]=abc_string_user[7]; 
				abc_string_user[7]=abc_string_user[6]; 
				abc_string_user[6]=buff;
				break;
			}
			case 4:
			{
				buff = abc_string_user[4]; 
				abc_string_user[4]=abc_string_user[5]; 
				abc_string_user[5]=abc_string_user[9]; 
				abc_string_user[9]=abc_string_user[8]; 
				abc_string_user[8]=buff;
				break;
			}
			case 5:
			{
				buff = abc_string_user[5]; 
				abc_string_user[5]=abc_string_user[6];
				abc_string_user[6]=abc_string_user[10]; 
				abc_string_user[10]=abc_string_user[9]; 
				abc_string_user[9]=buff;
				break;
			}
			case 6:
			{
				buff = abc_string_user[6]; 
				abc_string_user[6]=abc_string_user[7]; 
				abc_string_user[7]=abc_string_user[11]; 
				abc_string_user[11]=abc_string_user[10]; 
				abc_string_user[10]=buff;
				break;
			}
			case 7:
			{
				buff = abc_string_user[8]; 
				abc_string_user[8]=abc_string_user[9]; 
				abc_string_user[9]=abc_string_user[13]; 
				abc_string_user[13]=abc_string_user[12]; 
				abc_string_user[12]=buff;
				break;
			}
			case 8:
			{
				buff = abc_string_user[9]; 
				abc_string_user[9]=abc_string_user[10]; 
				abc_string_user[10]=abc_string_user[14]; 
				abc_string_user[14]=abc_string_user[13]; 
				abc_string_user[13]=buff;
				break;
			}
			case 9:
			{
				buff = abc_string_user[10]; 
				abc_string_user[10]=abc_string_user[11]; 
				abc_string_user[11]=abc_string_user[15]; 
				abc_string_user[15]=abc_string_user[14]; 
				abc_string_user[14]=buff;
				break;
			}
		}
	}
}

void player_game() //ходы игрока
{
	int Point_abc = cash_Point_abc, xPosition = cash_xPosition, yPosition = cash_yPosition;
	HWND hcon = GetConsoleWindow();
	HDC hdc = GetDC(hcon);
	//без цикла на старте нужно установить как бы указатель, поэтому отрисую только для енго часть поля	

	HPEN hPenYellow = CreatePen(BS_SOLID, 1, RGB(255, 229, 0)); //делаю желтую обводку для всего
	SelectObject(hdc, hPenYellow);

	HPEN hPenWhite = CreatePen(BS_SOLID, 1, RGB(255, 255, 255)); //делаю белую обводку для всего
	SelectObject(hdc, hPenWhite);

	HBRUSH hSimbolBrush = CreateSolidBrush(RGB(255,255,255)); //Блоки белые для букв
	SelectObject(hdc, hSimbolBrush);

	HBRUSH hBackBrush = CreateSolidBrush(RGB(255, 229, 0)); //цвет фона желтый
	SelectObject(hdc, hBackBrush);

	HBRUSH hCubeBrush = CreateSolidBrush(RGB(0, 0, 0)); //блоки для фона букв фиолетовые
	SelectObject(hdc, hCubeBrush);
	
	HBRUSH hSelectCubeBrush = CreateSolidBrush(RGB(255, 200, 155)); //цвет выделителя "блока"
	SelectObject(hdc, hSelectCubeBrush);

	HPEN hSelectPen = CreatePen(BS_SOLID, 1, RGB(0, 0, 0)); //делаю черную обводку
	SelectObject(hdc, hSelectPen);

	RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
	drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
	RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
	drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
	RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
	drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
	RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
	drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+135);

	hCubeBrush = CreateSolidBrush(RGB(100, 100, 100));
	SelectObject(hdc, hCubeBrush);
	RoundRect(hdc, 590, 318, 640, 368, 10, 10);
	hCubeBrush = CreateSolidBrush(RGB(50, 50, 50));
	SelectObject(hdc, hCubeBrush);
	Rectangle(hdc, 615, 328, 630, 358);
	hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hCubeBrush);
	RoundRect(hdc, 590, 258, 640, 308, 10, 10);
	SelectObject(hdc, hSelectCubeBrush);
	Rectangle(hdc, 600, 268, 630, 298);


	unsigned char ch;
	do 
	{
		ch = getch();
		if (ch == 224)
		{
			ch = getch();
			switch (ch)
			{
				case 80: //вниз
					if(yPosition < 320)
					{
						SelectObject(hdc, hPenWhite);
						SelectObject(hdc, hCubeBrush);
						RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
						RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);

						yPosition = yPosition + 135;
						Point_abc = Point_abc + 4;
						SelectObject(hdc, hSelectPen);
						SelectObject(hdc, hSelectCubeBrush);
						RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
						RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+135);
					}
					break;
				case 72: //вверх
					if(yPosition > 50)
					{						
						SelectObject(hdc, hPenWhite);
						SelectObject(hdc, hCubeBrush);
						RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
						RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+135);

						yPosition = yPosition - 135;
						Point_abc = Point_abc - 4;
						SelectObject(hdc, hSelectPen);
						SelectObject(hdc, hSelectCubeBrush);
						RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
						RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
					}
					break;
				case 77: //вправо
					if(xPosition < 320)
					{
						SelectObject(hdc, hPenWhite);
						SelectObject(hdc, hCubeBrush);
						RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
						RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);

						xPosition = xPosition + 135;
						Point_abc = Point_abc + 1;
						SelectObject(hdc, hSelectPen);
						SelectObject(hdc, hSelectCubeBrush);
						RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
						RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+135);
					}
					break;
				case 75: //влево
					if(xPosition > 50)
					{
						SelectObject(hdc, hPenWhite);
						SelectObject(hdc, hCubeBrush);
						RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
						RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+135);
						
						xPosition = xPosition - 135;
						Point_abc = Point_abc - 1;
						SelectObject(hdc, hSelectPen);
						SelectObject(hdc, hSelectCubeBrush);
						RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
						RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
						drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
					}
					break;
			}
		}
		else if(ch == 9 && tab_trigger == 0) // Идем на переключение
		{
			SelectObject(hdc, hPenWhite);
			hCubeBrush = CreateSolidBrush(RGB(100, 100, 100));
			SelectObject(hdc, hCubeBrush);
			RoundRect(hdc, 590, 258, 640, 308, 10, 10);
			hCubeBrush = CreateSolidBrush(RGB(50, 50, 50));
			SelectObject(hdc, hCubeBrush);
			Rectangle(hdc, 600, 268, 630, 298);
			hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hCubeBrush);
			RoundRect(hdc, 590, 318, 640, 368, 10, 10);
			SelectObject(hdc, hSelectCubeBrush);
			Rectangle(hdc, 615, 328, 630, 358);
			SelectObject(hdc, hCubeBrush);
			RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
			drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);	
			RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
			drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
			xPosition = xPosition + 135;
			Point_abc++;
			do
			{
				ch = getch();
				if (ch == 224 && R_tab_trigger == 0 || R_tab_trigger == 3)
				{
					ch = getch();
					switch (ch)
					{
						case 80: //вниз
							if(yPosition < 320)
							{

								SelectObject(hdc, hPenWhite);
								SelectObject(hdc, hCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);

								yPosition = yPosition + 135;
								Point_abc = Point_abc + 4;
								SelectObject(hdc, hSelectPen);
								SelectObject(hdc, hSelectCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
							}
							break;
						case 72: //вверх ЕСТЬ
							if(yPosition > 50)
							{						
								SelectObject(hdc, hPenWhite);
								SelectObject(hdc, hCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);

								yPosition = yPosition - 135;
								Point_abc = Point_abc - 4;
								SelectObject(hdc, hSelectPen);
								SelectObject(hdc, hSelectCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
								}
								break;
						case 77: //вправо Есть
							if(xPosition < 420)
							{
								SelectObject(hdc, hPenWhite);
								SelectObject(hdc, hCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);

								xPosition = xPosition + 135;
								Point_abc++;
								SelectObject(hdc, hSelectPen);
								SelectObject(hdc, hSelectCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
							}
							break;
						case 75: //влево ЕСТЬ!
							if(xPosition > 50)
							{
								SelectObject(hdc, hPenWhite);
								SelectObject(hdc, hCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
						
								xPosition = xPosition - 135;
								Point_abc = Point_abc - 1;
								SelectObject(hdc, hSelectPen);
								SelectObject(hdc, hSelectCubeBrush);
								RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
								RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
								drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
							}
							break;
					}
				}
				else if(ch == 114 && R_tab_trigger == 0 || R_tab_trigger == 1) // горизонтально двигаться
				{
					R_tab_trigger = 1;
					SelectObject(hdc, hPenWhite);
					SelectObject(hdc, hCubeBrush);
					hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
					SelectObject(hdc, hCubeBrush);
					RoundRect(hdc, 590, 318, 640, 368, 10, 10);
					SelectObject(hdc, hSelectCubeBrush);
					Rectangle(hdc, 600, 328, 630, 342);
					SelectObject(hdc, hCubeBrush);
					SelectObject(hdc, hPenWhite);
					RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
					drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
					RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
					drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
					xPosition = 50;
					yPosition = 50;
					Point_abc = 0;
					SelectObject(hdc, hSelectPen);
					SelectObject(hdc, hSelectCubeBrush);
					RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
					drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
					RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
					drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
					do
					{
						ch = getch();
						if (ch == 224)
						{
							ch = getch();
							switch (ch)
							{
								case 80: //вниз есть
									if(yPosition < 420)
									{
										SelectObject(hdc, hPenWhite);
										SelectObject(hdc, hCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);

										yPosition = yPosition + 135;
										Point_abc = Point_abc + 4;
										SelectObject(hdc, hSelectPen);
										SelectObject(hdc, hSelectCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
									}
									break;
								case 72: //вверх ЕСТЬ
									if(yPosition > 50)
									{						
										SelectObject(hdc, hPenWhite);
										SelectObject(hdc, hCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);

										yPosition = yPosition - 135;
										Point_abc = Point_abc - 4;
										SelectObject(hdc, hSelectPen);
										SelectObject(hdc, hSelectCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
										}
										break;
								case 77: //вправо Есть
									if(xPosition < 320)
									{
										SelectObject(hdc, hPenWhite);
										SelectObject(hdc, hCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);

										xPosition = xPosition + 135;
										Point_abc++;
										SelectObject(hdc, hSelectPen);
										SelectObject(hdc, hSelectCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
									}
									break;
								case 75: //влево ЕСТЬ!
									if(xPosition > 50)
									{
										SelectObject(hdc, hPenWhite);
										SelectObject(hdc, hCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
					
										xPosition = xPosition - 135;
										Point_abc = Point_abc - 1;
										SelectObject(hdc, hSelectPen);
										SelectObject(hdc, hSelectCubeBrush);
										RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
										RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
										drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
									}
									break;
							}
						
						}
					}while(ch != 13);
				}
			}while(ch != 13);
			if(R_tab_trigger == 0)
			{
				buff = abc_string_user[Point_abc];
				abc_string_user[Point_abc] = abc_string_user[Point_abc + 4];
				abc_string_user[Point_abc + 4] = buff;
				hCubeBrush = CreateSolidBrush(RGB(50, 255, 100));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
				RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
				Sleep(1000);
				checker_wincondition(1);	
				if(win == 1) return;
				SelectObject(hdc, hPenWhite);
				hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
				RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
				xPosition = 50;
				yPosition = 50;
				Point_abc = 0;
				SelectObject(hdc, hSelectPen);
				SelectObject(hdc, hSelectCubeBrush);
				RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
				RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc+1], xPosition+135, yPosition);
				RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc+4], xPosition, yPosition+135);
				RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+135);
				tab_trigger = 1;
				ch = 5;
				hCubeBrush = CreateSolidBrush(RGB(100, 100, 100));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, 590, 318, 640, 368, 10, 10);
				hCubeBrush = CreateSolidBrush(RGB(50, 50, 50));
				SelectObject(hdc, hCubeBrush);
				Rectangle(hdc, 615, 328, 630, 358);
				hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, 590, 258, 640, 308, 10, 10);
				SelectObject(hdc, hSelectCubeBrush);
				Rectangle(hdc, 600, 268, 630, 298);
			}
			else if(R_tab_trigger == 1)
			{
				buff = abc_string_user[Point_abc];
				abc_string_user[Point_abc] = abc_string_user[Point_abc + 1];
				abc_string_user[Point_abc + 1] = buff;
				hCubeBrush = CreateSolidBrush(RGB(50, 255, 100));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, xPosition, yPosition, xPosition + 125, yPosition + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
				RoundRect(hdc, xPosition + 135, yPosition, xPosition + 135 + 125, yPosition + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc + 1], xPosition + 135, yPosition);
				Sleep(1000);
				checker_wincondition(1);
				if (win == 1) return;
				SelectObject(hdc, hPenWhite);
				hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, xPosition, yPosition, xPosition + 125, yPosition + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
				RoundRect(hdc, xPosition + 135, yPosition, xPosition + 135 + 125, yPosition + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc + 1], xPosition + 135, yPosition);
				xPosition = 50;
				yPosition = 50;
				Point_abc = 0;
				SelectObject(hdc, hSelectPen);
				SelectObject(hdc, hSelectCubeBrush);
				RoundRect(hdc, xPosition, yPosition, xPosition + 125, yPosition + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition);
				RoundRect(hdc, xPosition + 135, yPosition, xPosition + 135 + 125, yPosition + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc + 1], xPosition + 135, yPosition);
				RoundRect(hdc, xPosition, yPosition + 135, xPosition + 125, yPosition + 135 + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc + 4], xPosition, yPosition + 135);
				RoundRect(hdc, xPosition + 135, yPosition + 135, xPosition + 135 + 125, yPosition + 135 + 125, 30, 30);
				drawing_simbol(abc_string_user[Point_abc + 5], xPosition + 135, yPosition + 135);
				tab_trigger = 1;
				ch = 5;
				hCubeBrush = CreateSolidBrush(RGB(100, 100, 100));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, 590, 318, 640, 368, 10, 10);
				hCubeBrush = CreateSolidBrush(RGB(50, 50, 50));
				SelectObject(hdc, hCubeBrush);
				Rectangle(hdc, 615, 328, 630, 358);
				hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hCubeBrush);
				RoundRect(hdc, 590, 258, 640, 308, 10, 10);
				SelectObject(hdc, hSelectCubeBrush);
				Rectangle(hdc, 600, 268, 630, 298);
			}
		}
	}while (ch != 13);
	SelectObject(hdc, hSelectPen);
	SelectObject(hdc, hSelectCubeBrush);
	RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
	RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
	RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
	RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
	drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition+45);	
	drawing_simbol(abc_string_user[Point_abc+1], xPosition+90, yPosition);		
	drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+90);
	drawing_simbol(abc_string_user[Point_abc+4], xPosition+45, yPosition+135);
	Sleep(80);
	drawing_gradient(xPosition, xPosition+135+126, yPosition, yPosition+135+126);
	SelectObject(hdc, hSelectPen);
	SelectObject(hdc, hSelectCubeBrush);
	RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
	RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
	RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
	RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
	drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition+90);	
	drawing_simbol(abc_string_user[Point_abc+1], xPosition+45, yPosition);		
	drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition+45);
	drawing_simbol(abc_string_user[Point_abc+4], xPosition+90, yPosition+135);
	Sleep(80);
	drawing_gradient(xPosition, xPosition+135+126, yPosition, yPosition+135+126);
	SelectObject(hdc, hSelectPen);
	SelectObject(hdc, hSelectCubeBrush);
	RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
	RoundRect(hdc, xPosition+135, yPosition, xPosition+135+125, yPosition+125, 30, 30);
	RoundRect(hdc, xPosition, yPosition+135, xPosition+125, yPosition+135+125, 30, 30);
	RoundRect(hdc, xPosition+135, yPosition+135, xPosition+135+125, yPosition+135+125, 30, 30);
	drawing_simbol(abc_string_user[Point_abc], xPosition, yPosition+135);	
	drawing_simbol(abc_string_user[Point_abc+1], xPosition, yPosition);		
	drawing_simbol(abc_string_user[Point_abc+5], xPosition+135, yPosition);
	drawing_simbol(abc_string_user[Point_abc+4], xPosition+135, yPosition+135);
	if(Point_abc == 0 || Point_abc == 1 || Point_abc == 2) rotation_abc_string(2, Point_abc+1);
	if(Point_abc == 4 || Point_abc == 5 || Point_abc == 6) rotation_abc_string(2, Point_abc);
	if(Point_abc == 8 || Point_abc == 9 || Point_abc == 10) rotation_abc_string(2, Point_abc-1);
	cash_xPosition = xPosition;
	cash_yPosition = yPosition;
	cash_Point_abc = Point_abc;
	ochered = 2;
	ReleaseDC (hcon, hdc);
	DeleteObject(hcon);
	DeleteObject(hdc);
	DeleteObject(hPenYellow);
	DeleteObject(hPenWhite);
	DeleteObject(hSimbolBrush);
	DeleteObject(hBackBrush);
	DeleteObject(hCubeBrush);
	DeleteObject(hSelectCubeBrush);
	DeleteObject(hSelectPen);
}

void drawing_PC()
{
	HWND hcon = GetConsoleWindow();
	HDC hdc = GetDC(hcon);
	HPEN hPenWhite = CreatePen(BS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hdc, hPenWhite);
	HBRUSH hCubeBrush = CreateSolidBrush(RGB(0, 0, 0));
	int xPosition = 725, yPosition = 50, stoped = 0, for_abc_string = 0;
	do //рисую для компьютера
	{
		SelectObject(hdc, hCubeBrush);
		RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
		drawing_simbol(abc_string_pc[for_abc_string], xPosition, yPosition);
		if(xPosition < 1130) xPosition = xPosition+135;
		else if(xPosition == 1130 && yPosition < 450)
		{
			xPosition = xPosition - 135*3;
			yPosition = yPosition + 135;
		}
		else stoped = 1;
		for_abc_string++;
	}while(stoped == 0);
	for_abc_string = 0;
	ReleaseDC (hcon, hdc);
	DeleteObject(hcon);
	DeleteObject(hdc);
	DeleteObject(hPenWhite);
	DeleteObject(hCubeBrush);
}

void pc_game() //ходы комплюхтера
{
	bool returned = true;
	do{
		if(abc_set[0]==0) //Может буква уже установлена была? ///////////////////////////поиск 0 (A) буквы
		{
			if(abc_string_pc[0] != abc[0]) 
			{
				int time=1;
				for (int i = 0; i < 11; i++)
				{
					if (i==3) {time--; continue;}
					if (i==7) {time--; continue;}
					if(abc_string_pc[i] == abc[0] || abc_string_pc[i+1] == abc[0] || abc_string_pc[i+5] == abc[0] || abc_string_pc[i+4] == abc[0])
					{
						rotation_abc_string(1, i+time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[0] = 1; //Если бука собрана, то перейдём сюда и установим "Буква установлена"
		}

		if(abc_set[3]==0) /////////////////////////поиск 3 (Г) буквы
		{
			if(abc_string_pc[3] != abc[3]) 
			{
				int time=0;
				for (int i = 3; i > 0; i--)
				{
					if(i==1) {i = 7; time++;}
					if(i==4) {i = 11; time++;}
					if(abc_string_pc[i] == abc[3] || abc_string_pc[i-1] == abc[3] || abc_string_pc[i+4] == abc[3] || abc_string_pc[i+3] == abc[3])
					{
						rotation_abc_string(1, i-time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[3] = 1;
		}
	
		if(abc_set[12]==0) //ВНИМАНИЕ, возможно задевание буквы Г, проверить и если что исправлять здесь!!!!!!!! поиск 12(Н) буквы
		{
			if(abc_string_pc[12] != abc[12]) 
			{
				int time=1;
				for (int i = 8; i < 12; i++)
				{
					if(i==11) {i = 4; time--;}
					if(i==7) {i = 1; time--;}
					if(abc_string_pc[i] == abc[12] || abc_string_pc[i+1] == abc[12] || abc_string_pc[i+5] == abc[12] || abc_string_pc[i+4] == abc[12])
					{
						rotation_abc_string(1, i-time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[12] = 1;
		}

		if(abc_set[15]==0) /////////////////////////поиск 15 (Р) буквы
		{
			if(abc_string_pc[15] != abc[15]) 
			{
				int time=1;
				for (int i = 10; i > 0; i--)
				{
					if(i==8) {i = 6; time--;}
					if(i==3) {i = 1; time--;}
					if(abc_string_pc[i] == abc[15] || abc_string_pc[i+1] == abc[15] || abc_string_pc[i+5] == abc[15] || abc_string_pc[i+4] == abc[15])
					{
						rotation_abc_string(1, i-time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[15] = 1;
		}

		if(abc_set[1]==0) /////////////////////////поиск 1 (Б) буквы
		{
			if(abc_string_pc[1] != abc[1]) 
			{
				int time=1;
				for (int i = 1; i < 11; i++)
				{
					if(i==2) {i = 4; time--;}
					if(i==7) {i = 9; time--;}
					if(abc_string_pc[i] == abc[1] || abc_string_pc[i+1] == abc[1] || abc_string_pc[i+5] == abc[1] || abc_string_pc[i+4] == abc[1])
					{
						rotation_abc_string(1, i+time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[1] = 1;
		}

		if(abc_set[2]==0) /////////////////////////поиск 2ой (В) буквы
		{
			if(abc_string_pc[2] != abc[2]) 
			{
				for (int i = 4; i < 11; i++)
				{
					if(i==5) i = 6;
					if(i==7) i = 9;
					if(abc_string_pc[i] == abc[2] || abc_string_pc[i+1] == abc[2] || abc_string_pc[i+5] == abc[2] || abc_string_pc[i+4] == abc[2])
					{
						if(i==4 && abc_string_pc[i+1] == abc[2]) 
						{
							trigger = 1;
							rotation_abc_string(1, 5);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 5);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 5);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							returned = false; break;
						}
						else if(i==4) // безконтрольный прыжок? Вносить внутрь наверх
						{
							rotation_abc_string(1, 4);
							returned = false; break;
						}
						if(i==6 && abc_string_pc[i] == abc[2]) // || trigger==2))
						{
							trigger = 2;
							rotation_abc_string(1, 6);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 6);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 6);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 6);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 2);
							drawing_PC();
							returned = false; break;
						}
						else if(i == 6)
						{
							rotation_abc_string(1, 6);
							returned = false; break;
						}
						if(i == 9)
						{
							rotation_abc_string(1, 8);
							returned = false; break;
						}
					
					}
				}
				returned = false; break;
			}
			else abc_set[2] = 1;
		}
	
		if(abc_set[4]==0) /////////////////////////поиск 4ой (Д) буквы
		{
			if(abc_string_pc[4] != abc[4]) 
			{
				int time=0;
				for (int i = 4; i < 11; i++)
				{
					if(i==7) {i = 9; time++;}
					if(abc_string_pc[i] == abc[4] || abc_string_pc[i+1] == abc[4] || abc_string_pc[i+5] == abc[4] || abc_string_pc[i+4] == abc[4])
					{
						rotation_abc_string(1, i-time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[4] = 1;
		}

		if(abc_set[8]==0) /////////////////////////поиск 8ой (И) буквы
		{
			if(abc_string_pc[8] != abc[8])
			{
				int time=0;
				for (int i = 5; i < 11; i++)
				{
					if(i==7) {i = 9; time++;}
					if(abc_string_pc[i] == abc[8] || abc_string_pc[i+1] == abc[8] || abc_string_pc[i+5] == abc[8] || abc_string_pc[i+4] == abc[8])
					{
						if(abc_string_pc[6] == abc[8])
						{
							rotation_abc_string(1, 4);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 5);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 5);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 4);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 4);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 4);
							drawing_PC();
							break;
						}
						else 
						{
							rotation_abc_string(1, i-time);
							break;
						}
					}
				}
				returned = false; break;
			}
			else abc_set[8] = 1;
		}

		if(abc_set[7]==0) /////////////////////////поиск 7ой (З) буквы
		{
			if(abc_string_pc[7] != abc[7]) 
			{
				int time=0;
				for (int i = 6; i < 11; i--)
				{
					if(i==4) {i = 9; time++;}
					if(abc_string_pc[i] == abc[7] || abc_string_pc[i+1] == abc[7] || abc_string_pc[i+5] == abc[7] || abc_string_pc[i+4] == abc[7])
					{
						rotation_abc_string(1, i-time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[7] = 1;
		}

		if(abc_set[11]==0) /////////////////////////поиск 11ой (М) буквы
		{
			if(abc_string_pc[11] != abc[11])
			{
				int time=0;
				for (int i = 5; i < 11; i+4)
				{
					if(i==9) time++;
					if(abc_string_pc[i] == abc[11] || abc_string_pc[i+1] == abc[11] || abc_string_pc[i+5] == abc[11] || abc_string_pc[i+4] == abc[11])
					{
						if(abc_string_pc[9] == abc[11])
						{
							rotation_abc_string(1, 6);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 6);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 6);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 5);
							drawing_PC();
							player_game();
							rotation_abc_string(1, 6);
							drawing_PC();
							break;
						}
						else 
						{
							rotation_abc_string(1, i-time);
							break;
						}
					}
				}
				returned = false; break;
			}
			else abc_set[11] = 1;
		}

		if(abc_set[13]==0) /////////////////////////поиск 13ой (О) буквы
		{
			if(abc_string_pc[13] != abc[13]) 
			{
				int time=1;
				for (int i = 9; i < 11; i-4)
				{
					if(i==4) time--;
					if(abc_string_pc[i] == abc[13] || abc_string_pc[i+1] == abc[13] || abc_string_pc[i+5] == abc[13] || abc_string_pc[i+4] == abc[13])
					{
						rotation_abc_string(1, i-time);
						break;
					}
				}
				returned = false; break;
			}
			else abc_set[13] = 1;
		}

		if(abc_set[14]==0) /////////////////////////поиск 14ой (П) буквы
		{
			if(abc_string_pc[14] != abc[14])
			{
				if(abc_string_pc[5] == abc[14])
				{
					rotation_abc_string(1, 8);
					drawing_PC();
					player_game();
					rotation_abc_string(1, 5);
					drawing_PC();
					player_game();
					rotation_abc_string(1, 5);
					drawing_PC();
					player_game();
					rotation_abc_string(1, 8);
					drawing_PC();
					player_game();
					rotation_abc_string(1, 8);
					drawing_PC();
					player_game();
					rotation_abc_string(1, 8);
					drawing_PC();
					break;
				}
				else 
				{
					rotation_abc_string(1, 5);
					break;
				}
				returned = false; break;
			}
			else abc_set[14] = 1;
		}

		if(abc_set[5]==0) /////////////////////////GJCKTLYBQ DLJ{ YF{EQ!
		{
			if(abc_string_pc[5] == abc[5] && abc_string_pc[6] == abc[6] && abc_string_pc[9] == abc[9] && abc_string_pc[10] == abc[10])
			{
				ochered = 1;
				win = true;
				drawing_PC();
				returned = false; break;
			}
			else if(abc_string_pc[5] == abc[5] && abc_string_pc[6] == abc[6])
			{
				buff = abc_string_pc[9]; abc_string_pc[9]=abc_string_pc[10]; abc_string_pc[10]=buff;
			}
			else if(abc_string_pc[9] == abc[9] && abc_string_pc[10] == abc[10])
			{
				buff = abc_string_pc[5]; abc_string_pc[5]=abc_string_pc[6]; abc_string_pc[6]=buff;
			}
			else if(abc_string_pc[5] == abc[5] && abc_string_pc[9] == abc[9])
			{
				buff = abc_string_pc[6]; abc_string_pc[6]=abc_string_pc[10]; abc_string_pc[10]=buff;
			}
			else if(abc_string_pc[6] == abc[6] && abc_string_pc[10] == abc[10])
			{
				buff = abc_string_pc[5]; abc_string_pc[5]=abc_string_pc[9]; abc_string_pc[9]=buff;
			}
			else
			{
				rotation_abc_string(1, 5);
				drawing_PC();
				returned = false; break;
			}
			abc_set[5] = 1;
			abc_set[6] = 1;
			abc_set[9] = 1;
			abc_set[10] = 1;
			ochered = 1;
			win = true;
			drawing_PC();
			returned = false; 
			break;
		}
	}while (returned);	
	ochered = 1;
	drawing_PC();
	checker_wincondition(2);
}
void play_one() //навероне надо убрать, но это поочереди играть с комплюхтером
{
	do
	{
		if (ochered == 1) player_game();
		else if (ochered == 2) pc_game();
	}while(win == 0);
	if(win == 1) printf("Ты выйграв!");
	else printf("Ты проиграв!");
}

void drawing_simbol(char simbol, int xPos, int yPos) //отрисует выбранную букву по координатам
{
	xPos = xPos + 12;
	yPos = yPos + 12;
	HWND hcon = GetConsoleWindow();
	HDC hdc = GetDC(hcon);
	HPEN hPenWhite = CreatePen(BS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hdc, hPenWhite);
	HBRUSH hSimbolBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hSimbolBrush);

	switch (simbol)
	{
		case 'А':
			Rectangle(hdc, xPos+10, yPos+80, xPos+30, yPos+100);
			Rectangle(hdc, xPos+15, yPos+60, xPos+85, yPos+80);
			Rectangle(hdc, xPos+20, yPos+40, xPos+40, yPos+60);
			Rectangle(hdc, xPos+25, yPos+20, xPos+45, yPos+40);
			Rectangle(hdc, xPos+30, yPos, xPos+70, yPos+20);
			Rectangle(hdc, xPos+55, yPos+20, xPos+75, yPos+40);
			Rectangle(hdc, xPos+60, yPos+40, xPos+80, yPos+60);
			Rectangle(hdc, xPos+70, yPos+80, xPos+90, yPos+100);
			break;
		case 'Б':			
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos, xPos+90, yPos+20);
			Rectangle(hdc, xPos+30, yPos+40, xPos+90, yPos+60);
			Rectangle(hdc, xPos+70, yPos+60, xPos+90, yPos+100);
			Rectangle(hdc, xPos+30, yPos+80, xPos+70, yPos+100);
			break;
		case 'В':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos, xPos+70, yPos+20);
			Rectangle(hdc, xPos+70, yPos+20, xPos+90, yPos+40);
			Rectangle(hdc, xPos+30, yPos+40, xPos+70, yPos+60);
			Rectangle(hdc, xPos+70, yPos+60, xPos+90, yPos+80);
			Rectangle(hdc, xPos+30, yPos+80, xPos+70, yPos+100);
			break;
		case 'Г':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos, xPos+90, yPos+20);
			break;
		case 'Д':
			Rectangle(hdc, xPos+10, yPos+80, xPos+30, yPos+100);
			Rectangle(hdc, xPos+10, yPos+60, xPos+90, yPos+80);
			Rectangle(hdc, xPos+70, yPos+80, xPos+90, yPos+100);
			Rectangle(hdc, xPos+20, yPos, xPos+40, yPos+60);
			Rectangle(hdc, xPos+40, yPos, xPos+60, yPos+20);
			Rectangle(hdc, xPos+60, yPos, xPos+80, yPos+60);
			break;
		case 'Е':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos, xPos+90, yPos+20);
			Rectangle(hdc, xPos+30, yPos+40, xPos+70, yPos+60);
			Rectangle(hdc, xPos+30, yPos+80, xPos+90, yPos+100);
			break;
		case 'Ж':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+40, yPos, xPos+60, yPos+100);
			Rectangle(hdc, xPos+70, yPos, xPos+90, yPos+100);
			Rectangle(hdc, xPos+30, yPos+40, xPos+70, yPos+60);
			break;
		case 'З':
			Rectangle(hdc, xPos+10, yPos+20, xPos+30, yPos+40);
			Rectangle(hdc, xPos+30, yPos, xPos+70, yPos+20);
			Rectangle(hdc, xPos+70, yPos+20, xPos+90, yPos+40);
			Rectangle(hdc, xPos+50, yPos+40, xPos+70, yPos+60);
			Rectangle(hdc, xPos+70, yPos+60, xPos+90, yPos+80);
			Rectangle(hdc, xPos+30, yPos+80, xPos+70, yPos+100);
			Rectangle(hdc, xPos+10, yPos+60, xPos+30, yPos+80);
			break;
		case 'И':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos+80, xPos+40, yPos+100);
			Rectangle(hdc, xPos+40, yPos+60, xPos+50, yPos+80);
			Rectangle(hdc, xPos+50, yPos+40, xPos+60, yPos+60);
			Rectangle(hdc, xPos+60, yPos+20, xPos+70, yPos+40);
			Rectangle(hdc, xPos+70, yPos, xPos+90, yPos+100);
			break;
		case 'К':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos+40, xPos+70, yPos+60);
			Rectangle(hdc, xPos+70, yPos, xPos+90, yPos+20);
			Rectangle(hdc, xPos+60, yPos+20, xPos+80, yPos+40);
			Rectangle(hdc, xPos+60, yPos+60, xPos+80, yPos+80);
			Rectangle(hdc, xPos+70, yPos+80, xPos+90, yPos+100);
			break;
		case 'Л':
			Rectangle(hdc, xPos+10, yPos+80, xPos+20, yPos+100);
			Rectangle(hdc, xPos+20, yPos, xPos+40, yPos+100);
			Rectangle(hdc, xPos+40, yPos, xPos+70, yPos+20);
			Rectangle(hdc, xPos+70, yPos, xPos+90, yPos+100);
			break;
		case 'М':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos+20, xPos+40, yPos+40);
			Rectangle(hdc, xPos+40, yPos+40, xPos+60, yPos+60);
			Rectangle(hdc, xPos+60, yPos+20, xPos+70, yPos+40);
			Rectangle(hdc, xPos+70, yPos, xPos+90, yPos+100);
			break;
		case 'Н':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos+40, xPos+70, yPos+60);
			Rectangle(hdc, xPos+70, yPos, xPos+90, yPos+100);
			break;
		case 'О':
			Rectangle(hdc, xPos+10, yPos, xPos+90, yPos+20);
			Rectangle(hdc, xPos+10, yPos+20, xPos+30, yPos+80);
			Rectangle(hdc, xPos+70, yPos+20, xPos+90, yPos+80);
			Rectangle(hdc, xPos+10, yPos+80, xPos+90, yPos+100);
			break;
		case 'П':
			Rectangle(hdc, xPos+10, yPos, xPos+90, yPos+20);
			Rectangle(hdc, xPos+10, yPos+20, xPos+30, yPos+100);
			Rectangle(hdc, xPos+70, yPos+20, xPos+90, yPos+100);
			break;
		case 'Р':
			Rectangle(hdc, xPos+10, yPos, xPos+30, yPos+100);
			Rectangle(hdc, xPos+30, yPos, xPos+70, yPos+20);
			Rectangle(hdc, xPos+70, yPos+20, xPos+90, yPos+40);
			Rectangle(hdc, xPos+30, yPos+40, xPos+70, yPos+60);
			break;
		case 'С':
			Rectangle(hdc, xPos+10, yPos+20, xPos+30, yPos+80);
			Rectangle(hdc, xPos+30, yPos, xPos+70, yPos+20);
			Rectangle(hdc, xPos+70, yPos+20, xPos+90, yPos+40);
			Rectangle(hdc, xPos+30, yPos+80, xPos+70, yPos+100);
			Rectangle(hdc, xPos+70, yPos+60, xPos+90, yPos+80);
			break;
		case 'Т':
			Rectangle(hdc, xPos+10, yPos, xPos+90, yPos+20);
			Rectangle(hdc, xPos+40, yPos+20, xPos+60, yPos+100);
			break;
		case 'Ф':
			Rectangle(hdc, xPos+10, yPos+20, xPos+20, yPos+80);
			Rectangle(hdc, xPos+20, yPos+20, xPos+80, yPos+40);
			Rectangle(hdc, xPos+20, yPos+60, xPos+80, yPos+80);
			Rectangle(hdc, xPos+40, yPos, xPos+60, yPos+100);
			Rectangle(hdc, xPos+80, yPos+20, xPos+90, yPos+80);
			break;
	}
	ReleaseDC (hcon, hdc);
	DeleteObject(hcon);
	DeleteObject(hdc);
	DeleteObject(hPenWhite);
	DeleteObject(hSimbolBrush);
}

void drawing_gradient(int start_x, int finish_x, int start_y, int finish_y)
{
	HWND hcon = GetConsoleWindow();
	HDC hdc = GetDC(hcon);
	HPEN hPenGradient = CreatePen(BS_SOLID, 1, RGB(255, 255, 255)); //делаю кисть для градиента
	SelectObject(hdc, hPenGradient);
	HBRUSH hBackGradient = CreateSolidBrush(RGB(255, 229, 0)); //браш для градиента
	SelectObject(hdc, hBackGradient);
	int R, G, B;
	double r = 255, g = 200, b = 155;
	r = r - 0.1086*(start_x-40);
	g = g - 0.0327*(start_x-40);
	b = b + 0.0792*(start_x-40);
	for (int x = start_x; x <= finish_x; x++)
	{
		R = ceil(r);
		G = ceil(g);
		B = ceil(b);
		hPenGradient = CreatePen(BS_SOLID, 1, RGB(R, G, B));
		SelectObject(hdc, hPenGradient);
		hBackGradient = CreateSolidBrush(RGB(R, G, B)); 
		SelectObject(hdc, hBackGradient);
		Rectangle(hdc, x, start_y, x+1, finish_y); 
		DeleteObject(hPenGradient);
		DeleteObject(hBackGradient);
		r = r - 0.1086;
		g = g - 0.0327;
		b = b + 0.0792;
	}
	ReleaseDC (hcon, hdc);
	DeleteObject(hcon);
	DeleteObject(hdc);
}

int _tmain(int argc, _TCHAR* argv[])
{
	fflush(stdin);
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	HWND hcon = GetConsoleWindow();
    COORD crd = {2000, 1000}; // принудительно размер консоли
    SMALL_RECT src = {0, 0, 160, 40};
    SetConsoleWindowInfo (hConsole, true, &src);
    SetConsoleScreenBufferSize (hConsole, crd);	
	HDC hdc = GetDC(hcon);
	HWND hwnd;

	LOGFONT font;
	font.lfHeight =  45 ;// Устанавливает высоту шрифта или символа
    font.lfWidth =  20;// Устанавливает среднюю ширину символов в шрифте
    font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
    font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
    font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
    font.lfItalic = 0;// Устанавливает курсивный шрифт
    font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
    font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
    font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
    font.lfOutPrecision = 0;// Устанавливает точность вывода
    font.lfClipPrecision = 0;// Устанавливает точность отсечения
    font.lfQuality = 0;// Устанавливает качество вывода
    font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	HFONT hfont;
	hfont = CreateFontIndirect(&font);
	SelectObject(hdc, hfont);
	
	HPEN hPenWhite = CreatePen(BS_SOLID, 1, RGB(255, 255, 255)); //делаю белую обводку для букв
	SelectObject(hdc, hPenWhite);

	HBRUSH hSimbolBrush = CreateSolidBrush(RGB(255,255,255)); //Блоки белые для букв
	SelectObject(hdc, hSimbolBrush);

	HBRUSH hCubeBrush = CreateSolidBrush(RGB(255, 255, 255)); //блоки для фона букв фиолетовые
	SelectObject(hdc, hCubeBrush);
		
	int xPosition = 50, yPosition = 50, stoped = 0, for_abc_string = 0, title_posotion = 250;
	
	drawing_gradient(55, 1260, 55, 585);
	
	drawing_simbol('А', title_posotion, 60);
	title_posotion = title_posotion + 110;
	drawing_simbol('Л', title_posotion, 60);
	title_posotion = title_posotion + 110;
	drawing_simbol('Ф', title_posotion, 60);
	title_posotion = title_posotion + 110;
	drawing_simbol('А', title_posotion, 60);
	title_posotion = title_posotion + 110;
	drawing_simbol('В', title_posotion, 60);
	title_posotion = title_posotion + 110;
	drawing_simbol('И', title_posotion, 60);
	title_posotion = title_posotion + 110;
	drawing_simbol('Т', title_posotion, 60);

	SetBkColor(hdc, (RGB(255, 255, 255)));
	SetTextColor(hdc, (RGB(0, 0, 0)));		
	TextOutA(hdc, 290, 300, "Каким алфавитом будем играть?", 29);
	SetBkColor(hdc, (RGB(150, 150, 150)));
	TextOutA(hdc, 500, 350, "Русский", 7);
	SetBkColor(hdc, (RGB(255, 255, 255)));
	TextOutA(hdc, 510, 400, "English", 7);

	drawing_gradient(55, 50, 55, 590);

	
	int pos = 1;
	unsigned char ch;
	do 
	{
		ch = getch();
		if (ch == 224)
		{
			ch = getch();
			drawing_gradient(55, 50, 55, 590);
			switch (ch)
			{
				case 80:
					for (int i=0; i<6; i++)
					{
						SetBkColor(hdc, (RGB(150, 150, 150)));
						TextOutA(hdc, 510, 400, "English", 7);
						SetBkColor(hdc, (RGB(255, 255, 255)));
						TextOutA(hdc, 500, 350, "Русский", 7);
					}
					pos = 2;
					break;
				case 72:
					for (int i=0; i<6; i++)
					{
						SetBkColor(hdc, (RGB(255, 255, 255)));
						TextOutA(hdc, 510, 400, "English", 7);
						SetBkColor(hdc, (RGB(150, 150, 150)));
						TextOutA(hdc, 500, 350, "Русский", 7);
					}
					pos = 1;
					break;
			}
		}
	} while (ch != 13);

	if (pos == 1)
		filler_abc("ru");
	else 
		filler_abc("en");

	drawing_gradient(40, 1265, 40, 590);
	do //ресую для игрока
	{
		SelectObject(hdc, hPenWhite);
		SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
		RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
		drawing_simbol(abc_string_user[for_abc_string], xPosition, yPosition);
		if(xPosition < 455) xPosition = xPosition+135;
		else if(xPosition == 455 && yPosition < 455)
		{
			xPosition = xPosition - 135*3;
			yPosition = yPosition + 135;
		}
		else stoped = 1;
		for_abc_string++;
	}while(stoped == 0);

	xPosition = 725;//рисую для компьютера
	yPosition = 50;
	stoped = 0;
	for_abc_string = 0;
	do 
	{
		SelectObject(hdc, hPenWhite);
		SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
		RoundRect(hdc, xPosition, yPosition, xPosition+125, yPosition+125, 30, 30);
		drawing_simbol(abc_string_pc[for_abc_string], xPosition, yPosition);
		if(xPosition < 1130) xPosition = xPosition+135;
		else if(xPosition == 1130 && yPosition < 450)
		{
			xPosition = xPosition - 135*3;
			yPosition = yPosition + 135;
		}
		else stoped = 1;
		for_abc_string++;
	}while(stoped == 0);
	ReleaseDC (hcon, hdc);
	DeleteObject(hcon);
	DeleteObject(hdc);
	DeleteObject(hPenWhite);
	DeleteObject(hSimbolBrush);
	DeleteObject(hCubeBrush);

	play_one(); //теперь начианем играть
	system("pause");
	return 0;
}
