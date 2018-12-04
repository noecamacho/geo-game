#include <allegro.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct NODO{
	int num;
	char name[5];
	struct NODO *sgte;
};

NODO *lista = NULL;

FILE *score_txt;

struct usuario
{
	int score;
	char name[5];
} user;


void init();
void deinit();
void result(bool dato, int x, int y);
int menu(BITMAP *buffer, SAMPLE *effect);
int check(int random, SAMPLE *blocks);
void iniciar(BITMAP* buffer, SAMPLE *blocks);
void ayuda(BITMAP* buffer, SAMPLE *effect);
void score(BITMAP* buffer, SAMPLE *effect);
void insertar_lista(int score, char name[5]);
void imprimir_lista();
void asignacion_inicial();

int main() 
{
	
	// INICIO DE PERIFERICOS Y ELEMENTOS AUDIOVISUALES
	if ((score_txt = fopen("score.txt", "a+b")) == NULL)
	{
		exit(1);
	}
	init();
	BITMAP *buffer = create_bitmap(960, 720);
	// Efectos de sonido del juego
	SAMPLE *sample = load_wav("song.wav");
	SAMPLE *effect = load_wav("hit.wav"); 
	SAMPLE *blocks = load_wav("blocks.wav");
	show_mouse(screen);
	play_sample(sample, 255, 0, 1000, 1);


	bool corriendo = true;
	while (corriendo) 
	{
    	draw_sprite(screen, buffer, 0, 0);
    	clear(buffer);
		int temp = menu(buffer, effect);
		switch(temp) 
		{
			case 1:
			{
				iniciar(buffer, effect);
				break;
			}
			case 2:
			{
				ayuda(buffer, effect);
				break;
			}
			case 3:
			{
				score(buffer, effect);
				break;
			}
			default:
			{
				corriendo = false;
				break;
			}
		}
		
	}
	
	// LIBERACION DE MEMORIA DE PUNTEROS Y DRIVERS
	stop_sample(sample);
	destroy_sample(sample);
	destroy_sample(effect);
	destroy_sample(blocks);
	deinit();
	return 0;
}
END_OF_MAIN()


int menu(BITMAP* buffer, SAMPLE* effect)
{
	//DECLARACION DE VARIABLES BOOLEANAS e INT's
	bool menu_ciclo = true;
	int count = 0;
	
	//DECLARACION DE BITMAPS
	BITMAP *img1 = load_bitmap("menu1.BMP", NULL);
	BITMAP *img2 = load_bitmap("menu2.BMP", NULL);
	BITMAP *img3 = load_bitmap("menu3.BMP", NULL);
	BITMAP *img4 = load_bitmap("menu4.BMP", NULL);
	BITMAP *img5 = load_bitmap("menu5.BMP", NULL);
	
	//CICLO DEL MENU
	while (menu_ciclo || !key[KEY_ESC])
	{
	    clear(buffer);
		
		if (mouse_x < 530 && mouse_x > 408 && mouse_y < 401  && mouse_y > 350) //OPCIÓN::INICIAR
		{
			if(count != 1)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			count = 1;
			blit(img2, screen, 0, 0, 0, 0, 960, 720);
			if (mouse_b & 1)
			{
				return 1;
			}
		}
		else if (mouse_x < 530 && mouse_x > 408 && mouse_y < 478  && mouse_y > 401) //OPCIÓN::AYUDA
		{
			if(count != 2)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			count = 2;
			blit(img3, screen, 0, 0, 0, 0, 960, 720);
			if (mouse_b & 1) 
			{
				return 2;
			}
		}
		else if (mouse_x < 530 && mouse_x > 408 && mouse_y < 548  && mouse_y > 478)	//OPCIÓN::SCORE	
		{
			if(count != 3)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			count = 3;
			blit(img4, screen, 0, 0, 0, 0, 960, 720);
			if (mouse_b & 1) 
			{
				return 3;
			}
		}
		else if (mouse_x < 530 && mouse_x > 408 && mouse_y < 604  && mouse_y > 548) //OPCIÓN::SALIR
		{
			if(count != 4)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			count = 4;
			blit(img5, screen, 0, 0, 0, 0, 960, 720);
			if (mouse_b & 1) 
			{
				return 4;
			}
		}
		else //PANTALLA POR DEFAULT DEL MENU
		{
			count = 5;
			blit(img1, screen, 0, 0, 0, 0, 960, 720);
		}
	}
	
	//DESTRUYE PUNTEROS DE BITMAPS
	destroy_bitmap(img1);
	destroy_bitmap(img2);
	destroy_bitmap(img3);
	destroy_bitmap(img4);
	destroy_bitmap(img5);
}

void iniciar(BITMAP* buffer, SAMPLE *blocks)
{
	srand(time(NULL));
	FONT *letras = load_font("letra.pcx", NULL, NULL);
	BITMAP *img1 = load_bitmap("iniciar1.BMP", NULL);
	BITMAP *perdedor = load_bitmap("perdedor.BMP", NULL);
	BITMAP *corrector = load_bitmap("black.BMP", NULL);
	BITMAP *life = load_bitmap("life.BMP", NULL);
	BITMAP *fig1 = load_bitmap("fig1.BMP", NULL);
	BITMAP *fig2 = load_bitmap("fig2.BMP", NULL);
	BITMAP *fig3 = load_bitmap("fig3.BMP", NULL);
	BITMAP *fig4 = load_bitmap("fig4.BMP", NULL);
	BITMAP *fig5 = load_bitmap("fig5.BMP", NULL);
	BITMAP *fig6 = load_bitmap("fig6.BMP", NULL);
	BITMAP *fig7 = load_bitmap("fig7.BMP", NULL);
	BITMAP *fig8 = load_bitmap("fig8.BMP", NULL);
	BITMAP *fig9 = load_bitmap("fig9.BMP", NULL);
	BITMAP *fig10 = load_bitmap("fig10.BMP", NULL);
	BITMAP *fig11 = load_bitmap("fig11.BMP", NULL);
	BITMAP *fig12 = load_bitmap("fig12.BMP", NULL);
	BITMAP *fig13 = load_bitmap("fig13.BMP", NULL);
	BITMAP *fig14 = load_bitmap("fig14.BMP", NULL);
	BITMAP *fig15 = load_bitmap("fig15.BMP", NULL);
	BITMAP *fig16 = load_bitmap("fig16.BMP", NULL);
	BITMAP *fig17 = load_bitmap("fig17.BMP", NULL);
	BITMAP *registro = load_bitmap("score_register.BMP",NULL);
	
	int array[17] = {0}, array_counter = 0, count = 0, count_game = 0, random, counter = 0, pos = 0,
						sonido = 20, bloque = 0, score = 0, score2 = 500, vida = 4, count_temp = 0, key, name_pos_x = 300;
	char name[5]; 
	bool corriendo = true, repetido = true, bloques = true, resultado, ciclo_temp = true, name_register = false;
	
	
	while (corriendo) 
	{	
		blit(img1, screen, 0, 0, 0, 0, 960, 720);
		
		// Se terminaron las vidas
		if (vida == 0 && count_game != 17) 
		{
			blit(perdedor, screen, 0, 0, 0, 0, 960, 720);
			while (ciclo_temp)
			{
				if ((mouse_x < 573 && mouse_x > 398 && mouse_y < 671  && mouse_y > 613))
				{
					if (count_temp != 1) { play_sample(blocks, 255, 0, 1000, 0); }
					count_temp = 1;
					if (mouse_b & 1) 
					{ 
						corriendo = false;
						random = 0;
						clear(buffer);
						clear(screen);
						break;
					}
				}
				else
				{
					count_temp = 0;
				}
			}
			corriendo = false;
		} 
		if (count_game == 17)  // Las 17 figuras han sido acertadas
		{
			blit(registro, screen, 0, 0, 0, 0, 960, 720);
			textprintf_ex(screen, letras, 380, 150, makecol(255, 255, 255), -1, "%d", score); // IMPRIME SCORE
			while (ciclo_temp)
			{
				if (!name_register)
				{
					do
					{
						key = readkey();
						name[pos] = key;
						if(name[pos] == 8 && name_pos_x >= 380) // Si el usuario desea eliminar el caracter
						{
							name_pos_x -= 80;
							blit(corrector, screen, 0, 0, name_pos_x-6, 314, corrector->w, corrector->h);
							pos--;
							name[pos] == 0;
						}
						else if ((name[pos] == 13 && pos != 0)) // Guarda si click enter y hay caracteres ingresados
						{
							name[pos] = '\0';
							insertar_lista(score, name);
							textout_ex(screen, letras, "GUARDADO!", 280, 400, makecol(0, 255, 0), -1);
							name_register = true;
							break;
							
						}
						else if (name[pos] == 13 && pos == 0) // Verifica que no se guarde sin caracteres
						{
							name[pos] == 0;
						}
						else if (pos < 5)
						{
							textprintf_ex(screen, letras, name_pos_x, 300, makecol(255, 255, 255), -1, "%c", name[pos]);
//							textprintf_ex(screen, letras, name_pos_x, 500, makecol(255, 255, 255), -1, "%d", name[pos]);
							name_pos_x += 80;
							pos++;	
						}
					} while (pos < 5);
				}
				if ((mouse_x < 597 && mouse_x > 362 && mouse_y < 592  && mouse_y > 495))
				{
					if (count_temp != 1) { play_sample(blocks, 255, 0, 1000, 0); }
					count_temp = 1;
					if (mouse_b & 1 && name_register )
					{ 
						corriendo = false;
						random = 0;
						vida = 0;
						clear(buffer);
						clear(screen);
						ciclo_temp = false;
						break;
					}
					else if (mouse_b & 1 && !name_register)
					{
						textout_ex(screen, font, "REGISTRA TU NOMBRE", 700, 300, makecol(255, 0, 0), -1);
					}
				}
				else
				{
					count_temp = 0;
				}
			}
		} 
	
		if (vida != 0) // Si las vidas no se han acabado...
		{
			random = rand() % (17 - 1 + 1) + 1;
			repetido = true;
			while (repetido)  //genera numero random sin repetirse
			{
				counter = 0;
				for (int x=0; x<17; x++)
				{
					if (random == array[x])
					{
						counter++;
						break;
					}
				}
				if (counter == 0)
				{
					array[array_counter] = random;
					array_counter++;
					repetido = false;
				}
				else
				{
					random = rand() % (17 - 1 + 1) + 1;
				}
			}
			
			textprintf_ex(screen, letras, 120, 0, makecol(255, 255, 255), -1, "%d", score); // IMPRIME SCORE
			
			switch(vida)
			{
				case 1:
				{
					masked_blit(life, screen, 0, 0, 500, 30, fig1->w, fig1->h);	
					break;	
				}
				case 2:
				{
					masked_blit(life, screen, 0, 0, 500, 30, fig1->w, fig1->h);
					masked_blit(life, screen, 0, 0, 570, 30, fig1->w, fig1->h);
					break;
				}
				case 3:
				{
					masked_blit(life, screen, 0, 0, 500, 30, fig1->w, fig1->h);
					masked_blit(life, screen, 0, 0, 570, 30, fig1->w, fig1->h);
					masked_blit(life, screen, 0, 0, 640, 30, fig1->w, fig1->h);
					break;
				}
				case 4:
				{
					masked_blit(life, screen, 0, 0, 500, 30, fig1->w, fig1->h);
					masked_blit(life, screen, 0, 0, 570, 30, fig1->w, fig1->h);
					masked_blit(life, screen, 0, 0, 640, 30, fig1->w, fig1->h);
					masked_blit(life, screen, 0, 0, 720, 30, fig1->w, fig1->h);
					break;
				}
				default:
					break;
			}
			
			switch (random)
			{
				case 1:
				{
					masked_blit(fig1, screen, 0, 0, 316, 89, fig1->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 2:
				{
					masked_blit(fig2, screen, 0, 0, 316, 89, fig2->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 3:
				{
					masked_blit(fig3, screen, 0, 0, 316, 89, fig3->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;				
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 4:
				{
					masked_blit(fig4, screen, 0, 0, 316, 89, fig4->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 5:
				{                          
					masked_blit(fig5, screen, 0, 0, 316, 89, fig5->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 6:
				{                          
					masked_blit(fig6, screen, 0, 0, 316, 89, fig6->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 7:
				{                         
					masked_blit(fig7, screen, 0, 0, 316, 89, fig7->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 8:
				{                          
					masked_blit(fig8, screen, 0, 0, 316, 89, fig8->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 9:
				{                          
					masked_blit(fig9, screen, 0, 0, 316, 89, fig9->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{ 
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 10:
				{                          
					masked_blit(fig10, screen, 0, 0, 316, 89, fig10->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 11:
				{                          
					masked_blit(fig11, screen, 0, 0, 316, 89, fig11->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 12:
				{                          
					masked_blit(fig12, screen, 0, 0, 316, 89, fig12->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 13:
				{                          
					masked_blit(fig13, screen, 0, 0, 316, 89, fig13->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 14:
				{                          
					masked_blit(fig14, screen, 0, 0, 316, 89, fig14->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 15:
				{                          
					masked_blit(fig15, screen, 0, 0, 316, 89, fig15->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 16:
				{                          
					masked_blit(fig16, screen, 0, 0, 316, 89, fig16->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				case 17:
				{                          
					masked_blit(fig17, screen, 0, 0, 316, 89, fig17->w, fig1->h);
					if (check(random, blocks) == 1)
					{
						score2+=250;
						score += score2;
						count_game++;					
					}
					else
					{
						score2 = 500;
						score -= 200;
						vida--;
						array[array_counter] = 0;
						array_counter--;
					}
					clear(buffer);
					clear(screen);
					break;
				}
				default:
					break;                    
			}
		}
//		textprintf_ex(screen, letras, 120, 0, makecol(255, 255, 255), -1, "%d", score);
	}
	
	NODO *x = lista;
	score_txt = fopen("score.txt", "w+");
	while (x != NULL) 
	{
		user.score = x->num;
		strcpy(user.name, x->name);
		fwrite(&user, sizeof(usuario), 1, score_txt);
		x = x -> sgte;
	}
	fclose(score_txt);
	
	destroy_font(letras);
	destroy_bitmap(corrector);
	destroy_bitmap(registro);
	destroy_bitmap(perdedor);
	destroy_bitmap(img1);
	destroy_bitmap(life);
	destroy_bitmap(fig1);
	destroy_bitmap(fig2);
	destroy_bitmap(fig3);
	destroy_bitmap(fig4);
	destroy_bitmap(fig5);
	destroy_bitmap(fig6);
	destroy_bitmap(fig7);
	destroy_bitmap(fig8);
	destroy_bitmap(fig9);
	destroy_bitmap(fig10);
	destroy_bitmap(fig11);        
	destroy_bitmap(fig12);
	destroy_bitmap(fig13);
	destroy_bitmap(fig14);
	destroy_bitmap(fig15);
	destroy_bitmap(fig16);
	destroy_bitmap(fig17);
}

int check(int random, SAMPLE *blocks)
{
	bool bloques, dato = true;
	int sonido = 20, bloque = 0;
	bloques = true;
	while (bloques)
	{
		if ((mouse_x < 215 && mouse_x > 55 && mouse_y < 531  && mouse_y > 489)) // Fig1. Dodecaedro
		{
//			masked_blit(block1, screen, 0, 0, 55, 489, block1->w, block1->h);
			
			if (sonido != 1) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 1;
			
			if (mouse_b & 1) 
			{
				bloque = 1;
				if (bloque == random)
				{
					dato = true;
					result(dato, 135, 510);
					return 1;
				}
				else
				{
					dato = false;
					result(dato, 135, 510);
					return 0;
				}
			}
		}
		else if ((mouse_x < 215 && mouse_x > 55 && mouse_y < 575  && mouse_y > 531)) // Fig2. Icosaedro
		{
			if(sonido != 2) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 2;
			if (mouse_b & 1) 
			{
				bloque = 2;
				if (bloque == random)
				{
					result(true, 214, 574);
					return 1;
				}
				else
				{
					result(false, 214, 574);
					return 0;
				}
			}			
		}
		else if ((mouse_x < 215 && mouse_x > 55 && mouse_y < 617  && mouse_y > 575)) // Fig3. Hexaedro
		{
			if(sonido != 3) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 3;
			if (mouse_b & 1) 
			{
				bloque = 3;
				if (bloque == random)
				{
					result(true, 214, 616);
					return 1;
				}
				else
				{
					result(false, 214, 616);
					return 0;
				}
			}
		}
		else if ((mouse_x < 215 && mouse_x > 55 && mouse_y < 660  && mouse_y > 617)) // Fig4. Octaedro
		{
			if(sonido != 4) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 4;
			if (mouse_b & 1) 
			{
				bloque = 4;
				if (bloque == random)
				{
					result(true, 214, 659);
					return 1;
				}
				else
				{
					result(false, 214, 659);
					return 0;
				}
			}
		}
		else if ((mouse_x < 215 && mouse_x > 55 && mouse_y < 707  && mouse_y > 660)) // Fig5. Tetraedro
		{
			if(sonido != 5) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 5;
			if (mouse_b & 1) 
			{
				bloque = 5;
				if (bloque == random)
				{
					result(true, 214, 706);
					return 1;
				}
				else
				{
					result(false, 214, 706);
					return 0;
				}
			}
		}
		else if ((mouse_x < 475 && mouse_x > 300 && mouse_y < 573  && mouse_y > 530)) // Fig6. Prisma Cuadrangular
		{
			if(sonido != 6) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 6;
			if (mouse_b & 1) 
			{
				bloque = 6;
				if (bloque == random)
				{
					result(true, 474, 572);
					return 1;
				}
				else
				{
					result(false, 474, 572);
					return 0;
				}
			}
		}
		else if ((mouse_x < 475 && mouse_x > 300 && mouse_y < 615  && mouse_y > 573)) // Fig7. Prisma Hexagonal
		{
			if(sonido != 7) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 7;
			if (mouse_b & 1) 
			{
				bloque = 7;
				if (bloque == random)
				{
					result(true, 474, 614);
					return 1;
				}
				else
				{
					result(false, 474, 614);
					return 0;
				}
			}
		}
		else if ((mouse_x < 475 && mouse_x > 300 && mouse_y < 659  && mouse_y > 615)) // Fig8. Prisma Triangular
		{
			if(sonido != 8) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 8;
			if (mouse_b & 1) 
			{
				bloque = 8;
				if (bloque == random)
				{
					result(true, 474, 658);
					return 1;
				}
				else
				{
					result(false, 474, 658);
					return 0;
				}
			}
		}
		else if ((mouse_x < 475 && mouse_x > 300 && mouse_y < 699  && mouse_y > 659)) // Fig9. Prisma Pentagonal
		{
			if(sonido != 9) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 9;
			if (mouse_b & 1) 
			{
				bloque = 9;
				if (bloque == random)
				{
					result(true, 474, 698);
					return 1;
				}
				else
				{
					result(false, 474, 698);
					return 0;
				}
			}
		}
		else if ((mouse_x < 666 && mouse_x > 492 && mouse_y < 573  && mouse_y > 530)) // Fig10. Pirámide Cuadrangular
		{
			if(sonido != 10) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 10;
			if (mouse_b & 1) 
			{
				bloque = 10;
				if (bloque == random)
				{
					result(true, 665, 572);
					return 1;
				}
				else
				{
					result(false, 665, 572);
					return 0;
				}
			}
		}
		else if ((mouse_x < 666 && mouse_x > 492 && mouse_y < 615  && mouse_y > 573)) // Fig11. Pirámide Hexagonal
		{
			if(sonido != 11) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 11;
			if (mouse_b & 1) 
			{
				bloque = 11;
				if (bloque == random)
				{
					result(true, 665, 614);
					return 1;
				}
				else
				{
					result(false, 665, 614);
					return 0;
				}
			}
		}
		else if ((mouse_x < 666 && mouse_x > 492 && mouse_y < 659  && mouse_y > 615)) // Fig12. Pirámide Triangular
		{
			if(sonido != 12) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 12;
			if (mouse_b & 1) 
			{
				bloque = 12;
				if (bloque == random)
				{
					result(true, 665, 658);
					return 1;
				}
				else
				{
					result(false, 665, 658);
					return 0;
				}
			}
		}
		else if ((mouse_x < 666 && mouse_x > 492 && mouse_y < 699  && mouse_y > 659)) // Fig13. Pirámide Pentagonal
		{
			if(sonido != 13) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 13;
			if (mouse_b & 1) 
			{
				bloque = 13;
				if (bloque == random)
				{
					result(true, 665, 698);
					return 1;
				}
				else
				{
					result(false, 665, 698);
					return 0;
				}
			}
		}
		else if ((mouse_x < 925 && mouse_x > 749 && mouse_y < 532  && mouse_y > 490)) // Fig14. Cono
		{
			if(sonido != 14) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 14;
			if (mouse_b & 1) 
			{
				bloque = 14;
				if (bloque == random)
				{
					result(true, 924, 531);
					return 1;
				}
				else
				{
					result(false, 924, 531);
					return 0;
				}
			}
		}
		else if ((mouse_x < 925 && mouse_x > 749 && mouse_y < 577  && mouse_y > 532)) // Fig15. Cilindro
		{
			if(sonido != 15) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 15;
			if (mouse_b & 1) 
			{
				bloque = 15;
				if (bloque == random)
				{
					result(true, 924, 576);
					return 1;
				}
				else
				{
					result(false, 924, 576);
					return 0;
				}
			}
		}
		else if ((mouse_x < 925 && mouse_x > 749 && mouse_y < 619 && mouse_y > 577)) // Fig16. Esfera
		{
			if(sonido != 16) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 16;
			if (mouse_b & 1) 
			{
				bloque = 16;
				if (bloque == random)
				{
					result(true, 924, 618);
					return 1;
				}
				else
				{
					result(false, 924, 618);
					return 0;
				}
			}
		}
		else if ((mouse_x < 925 && mouse_x > 749 && mouse_y < 663  && mouse_y > 619)) // Fig17. Toro
		{
			if(sonido != 17) {play_sample(blocks, 255, 0, 1000, 0);}
			sonido = 17;
			if (mouse_b & 1) 
			{
				bloque = 17;
				if (bloque == random)
				{
					result(true, 924, 662);
					return 1;
				}
				else
				{
					result(false, 924, 662);
					return 0;
				}
			}
		}
	}
}

void ayuda(BITMAP* buffer, SAMPLE *effect)
{
	bool corriendo = true;
	int count = 0, opcion = 0;
	
	BITMAP *img1 = load_bitmap("ayuda1.BMP", NULL);
	BITMAP *img1_2 = load_bitmap("ayuda1_2.BMP", NULL);
	BITMAP *img2 = load_bitmap("ayuda2.BMP", NULL);
	BITMAP *img3 = load_bitmap("ayuda3.BMP", NULL);
	BITMAP *img4 = load_bitmap("ayuda4.BMP", NULL);
	BITMAP *img5 = load_bitmap("ayuda5.BMP", NULL);
	
	while (corriendo)
	{
		clear(buffer);
		if ((mouse_x < 490 && mouse_x > 441 && mouse_y < 702  && mouse_y > 653) || (key[KEY_ESC])) // volver al menú
		{
			if(opcion != 1)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			opcion = 1;
			if (mouse_b & 1)
			{
				corriendo = false; 				
			}
		}
		if (count == 0)
		{
			blit(img1, screen, 0, 0, 0, 0, 960, 720);
		}
		else if (count == 1)
		{
			blit(img2, screen, 0, 0, 0, 0, 960, 720);
		}
		else if (count == 2)
		{
			blit(img3, screen, 0, 0, 0, 0, 960, 720);
		}
		else if (count == 3)
		{
			blit(img4, screen, 0, 0, 0, 0, 960, 720);
		}
		else if (count == 4)
		{
			blit(img5, screen, 0, 0, 0, 0, 960, 720);
		}

		if (mouse_x < 548 && mouse_x > 507 && mouse_y < 699  && mouse_y > 649) // Ir a pagina siguiente
		{
			if(opcion != 2)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			opcion = 2;
			if (count == 0)
			{
				blit(img1_2, screen, 0, 0, 0, 0, 960, 720);
				if (mouse_b & 1)
				{
					count = 1;
					for(int x=0; x<100000000; x++) x++;
				}
			}
			else if (count == 1)
			{
				if (mouse_b & 1)
				{
					count = 2;
					for(int x=0; x<100000000; x++) x++;				
				}
			}
			else if (count == 2)
			{
				if (mouse_b & 1)
				{
					count = 3;
					for(int x=0; x<100000000; x++) x++;
				}
			}
			else if (count == 3)
			{
				if (mouse_b & 1)
				{
					count = 4;
					for(int x=0; x<100000000; x++) x++;
				}
			}
		}
		if (mouse_x < 425 && mouse_x > 378 && mouse_y < 702  && mouse_y > 652) // Ir a pagina anterior
		{
			if(opcion != 3)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			opcion = 3;
			if (count == 4)
			{
				if (mouse_b & 1)
				{
					count = 3;
					for(int x=0; x<100000000; x++) x++;
				}
			}
			else if (count == 3)
			{
				if (mouse_b & 1)
				{
					count = 2;
					for(int x=0; x<100000000; x++) x++;
				}
			}
			else if (count == 2)
			{
				if (mouse_b & 1)
				{
					count = 1;
					for(int x=0; x<100000000; x++) x++;
				}
			}
			else if (count == 1)
			{
				if (mouse_b & 1)
				{
					count = 0;
					for(int x=0; x<100000000; x++) x++;
				}
			}
		}
	}
	destroy_bitmap(img1);
	destroy_bitmap(img1_2);
	destroy_bitmap(img2);
	destroy_bitmap(img3);
	destroy_bitmap(img4);
	destroy_bitmap(img5);
}

void score(BITMAP* buffer, SAMPLE *effect)
{
	BITMAP *img1 = load_bitmap("score.BMP", NULL);
	bool corriendo = true;
	int opcion;
	
	blit(img1, screen, 0, 0, 0, 0, 960, 720);
	imprimir_lista();
	while (corriendo)
	{
		if ((mouse_x < 490 && mouse_x > 441 && mouse_y < 702  && mouse_y > 653) || (key[KEY_ESC])) // volver al menú
		{
			if(opcion != 1)
			{
				play_sample(effect, 255, 0, 1000, 0);	
			}
			opcion = 1;
			if (mouse_b & 1)
			{
				corriendo = false; 				
			}
		}
		else
		{
			opcion = 0;
		}
	}
	destroy_bitmap(img1);
}

void result(bool dato, int x, int y)
{
	BITMAP *redbar = load_bitmap("redbar.BMP", NULL);
	BITMAP *greenbar = load_bitmap("greenbar.BMP", NULL);
	int i = 0, j = 390;
	if (dato)
	{
		for(i=0; i<962; i+=10)
		{
			position_mouse(x, y);
			blit(greenbar, screen, 0, 0, i, j, 960, 720);	
		}
	}
	else
	{
		for(i=0; i<962; i+=10)
		{
			position_mouse(x, y);
			blit(redbar, screen, 0, 0, i, j, 960, 720);	
		}
	}
	destroy_bitmap(redbar);
	destroy_bitmap(greenbar);	
}
	
void init() 
{
	allegro_init();
	asignacion_inicial();
	int depth, res;
	depth = desktop_color_depth();
	if (depth == 0) 
	{
		depth = 32;
	}
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 960, 720, 0, 0);
	
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	/* add other initializations here */

}

void deinit() 
{
	clear_keybuf();
	/* add other deinitializations here */
}

void insertar_lista(int score, char name[5]) 
{
	
	NODO *aux1 = lista;
	NODO *aux2 = NULL;
	NODO *temp = (NODO*)malloc(sizeof(NODO));
	
	temp->num = score;
	strcpy(temp->name, name);
	temp->sgte = NULL;
	
	while(aux1 != NULL && aux1->num > temp->num) 
	{
		aux2 = aux1;
		aux1 = aux1->sgte;
	} 
	if(lista == aux1) 
	{
		lista = temp;
	} 
	else 
	{
		aux2->sgte = temp;
	}
	temp->sgte = aux1;
}

void imprimir_lista()
{
	FONT *letras = load_font("letra.pcx", NULL, NULL);
	NODO *x = lista;
	int pos_y = 200, count = 0;
	
	while (x != NULL) 
	{
		if (count == 5)
		{
			break;
		}
		//printf("%s", x->name);
//		printf("%d", x->num);
		textprintf_ex(screen, letras, 200, pos_y, makecol(255, 255, 255), -1, "%s", x->name);
		textprintf_ex(screen, letras, 500, pos_y, makecol(255, 255, 255), -1, "%d", x->num);
		pos_y += 100;
		count++;
		x = x -> sgte;
	}
	destroy_font(letras);
}

void asignacion_inicial()
{
//	user.score = 200;
//	strcpy(user.name, "PEPE");
//	fwrite(&user, sizeof(usuario), 1, score_txt);
//	insertar_lista(user.score, user.name);

//	user.score = 67890;
//	strcpy(user.name, "MAURI");
//	fwrite(&user, sizeof(usuario), 1, score_txt);
//	insertar_lista(user.score, user.name);

	// FILE score_txt;
	int NumRegistros;
	score_txt = fopen("score.txt", "r");
	if(score_txt != NULL)
	{
		NumRegistros = fread(&user, sizeof(struct usuario), 1, score_txt);
		while(NumRegistros == 1)
		{
			fflush(stdin);
			fflush(stdout);
			insertar_lista(user.score, user.name);
			NumRegistros = fread(&user, sizeof(struct usuario), 1, score_txt);
		}
		fclose(score_txt);
	}
	else
		puts("Error, no se ha podido abrir el archivo");
	
	//if (score_txt != NULL) // Lee el registro de scores.txt
//	{
//		printf("ESTOY EN SCORE_TXT != NULL");
//		fread(&user, sizeof(usuario), 1, score_txt);
//		
//		user.score = 67890;
//		strcpy(user.name, "MAURI");
//		
//		while (score_txt == 1)
//		for(int x=0; x<5; x++)
//		{
//			insertar_lista(user.score, user.name);
//			fread(&user, sizeof(usuario), 1, score_txt);
//		}
//		fclose(score_txt);
//	}
//	else
//	{
//		printf("SOY NULL");
//	}
//	printf("\t ya sali del null");

}
