#include<stdio.h>
#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_audio.h>
#include<allegro5\allegro_acodec.h>

int main()
{
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_BITMAP *player1 = al_load_bitmap("player1.png");
	ALLEGRO_BITMAP *player2 = al_load_bitmap("player2.png");
	ALLEGRO_BITMAP *arm11 = al_load_bitmap("kol.png");
	ALLEGRO_BITMAP *arm12 = al_load_bitmap("kol.png");
	ALLEGRO_BITMAP *arm21 = al_load_bitmap("kol.png");
	ALLEGRO_BITMAP *arm22 = al_load_bitmap("kol.png");
	ALLEGRO_BITMAP *arm2 = al_load_bitmap("kol.png");
	ALLEGRO_BITMAP *arka = al_load_bitmap("saha.png");
	ALLEGRO_BITMAP *pota = al_load_bitmap("basket.png");
	ALLEGRO_BITMAP *pota2 = al_load_bitmap("basket2.png");
	ALLEGRO_BITMAP *ball = al_load_bitmap("top.png");
	ALLEGRO_BITMAP *scoreboard = al_load_bitmap("scoreboard.png");
	ALLEGRO_BITMAP *sýfýr = al_load_bitmap("0.png");
	ALLEGRO_BITMAP *bir = al_load_bitmap("1.png");
	ALLEGRO_BITMAP *iki = al_load_bitmap("2.png");
	ALLEGRO_BITMAP *üç = al_load_bitmap("3.png");
	ALLEGRO_BITMAP *k1 = al_load_bitmap("kazanma1.png");
	ALLEGRO_BITMAP *k2 = al_load_bitmap("kazanma2.png");
	ALLEGRO_SAMPLE *music = al_load_sample("music.wav");

	ALLEGRO_DISPLAY *display = al_create_display(1785, 720);
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

	al_install_keyboard();
	al_reserve_samples(1);

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	
	ALLEGRO_EVENT ev1;
	ALLEGRO_EVENT ev2;

	int score1 = 2, score2 = 0;
	int p1x = 500, p1y = 500, p1r = 20;
	int p2x = 600, p2y = 500, p2r = 20;
	int hx = 223, hy = 415, hr = 20;
	int h2x =550, h2y = 415, h2r = 20;
	int tx = 850, ty = 250, tr = 20;
	int rotation = 0;
	int rotation2 = 0;
	int a11x = 360, a11y = 250;
	int a12x = 360, a12y = 260;
	int a21x = 1000, a21y = 250;
	int a22x = 1000, a22y = 260;
	
	while (score1!=3 && score2!=3) {

		al_draw_bitmap(arka, 0, 0, NULL);
		al_draw_bitmap(pota, -10, 60, NULL);
		al_draw_bitmap(pota2, 1420, 60, NULL);
		al_draw_bitmap(scoreboard, 770, 0, NULL);
		al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, 0);

		if (tx == 290 && ty == 220) {
			score2++;
			al_draw_bitmap(arm11, a11x=360, a11y=250, NULL);
			al_draw_bitmap(arm21, a21x=1000, a21y=250, NULL);
			al_draw_bitmap(player1, p1x=500, p1y=500, NULL);
			al_draw_bitmap(player2, p2x=600, p2y=500, NULL);
			al_draw_bitmap(ball, tx=850, ty=250, NULL);
			al_draw_bitmap(arm12, a12x=360, a12y=260, NULL);
			al_draw_bitmap(arm22, a22x=1000, a22y=260, NULL);
		}
		if (tx == 1450 && ty == 220) {
			score1++;
			al_draw_bitmap(arm11, a11x=360, a11y=250, NULL);
			al_draw_bitmap(arm21, a21x=1000, a21y=250, NULL);
			al_draw_bitmap(player1, p1x = 500, p1y = 500, NULL);
			al_draw_bitmap(player2, p2x = 600, p2y = 500, NULL);
			al_draw_bitmap(ball, tx = 850, ty = 250, NULL);
			al_draw_bitmap(arm12, a12x=360, a12y=260, NULL);
			al_draw_bitmap(arm22, a22x=1000, a22y=260, NULL);
		}
		if (score1 == 0) {
			al_draw_bitmap(sýfýr, 780, 10, NULL);
		}
		if (score1 == 1) {
			al_draw_bitmap(bir, 780, 10, NULL);
		}
		if (score1 == 2) {
			al_draw_bitmap(iki, 780, 10, NULL);
		}
		if (score1 == 3) {
			al_draw_bitmap(üç, 780, 10, NULL);
		}
		if (score2 == 0) {
			al_draw_bitmap(sýfýr, 910, 10, NULL);
		}
		if (score2 == 1) {
			al_draw_bitmap(bir, 910, 10, NULL);
		}
		if (score2 == 2) {
			al_draw_bitmap(iki, 910, 10, NULL);
		}
		if (score2 == 3) {
			al_draw_bitmap(üç, 910, 10, NULL);
		}
		al_draw_bitmap(arm11, a11x, a11y, NULL);
		al_draw_bitmap(arm21, a21x, a21y, NULL);
		al_draw_bitmap(player1, p1x, p1y, NULL);
		al_draw_bitmap(player2, p2x, p2y, NULL);
		al_draw_bitmap(ball, tx, ty, NULL);
		al_draw_bitmap(arm12, a12x, a12y, NULL);
		al_draw_bitmap(arm22, a22x, a22y, NULL);
        
		al_flip_display();

		al_wait_for_event(queue, &ev1);
		al_wait_for_event(queue, &ev2);

		if (ev1.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			rotation2 = 1;
		}
		else if (ev1.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			rotation2 = 2;
		}
		else if (ev1.keyboard.keycode == ALLEGRO_KEY_UP) {
			rotation2 = 3;
		}
		else if (ev1.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			rotation2 = 4;
		}
       if (ev2.keyboard.keycode == ALLEGRO_KEY_D) {
			rotation = 1;
		}
	   else if (ev2.keyboard.keycode == ALLEGRO_KEY_A) {
		   rotation = 2;
	   }
	   else if (ev2.keyboard.keycode == ALLEGRO_KEY_W) {
		   rotation = 3;
	   }
	   else if (ev2.keyboard.keycode == ALLEGRO_KEY_S) {
		   rotation = 4;
	   }
	   if (rotation == 1) {
				
				if (tx-70 == p1x && ty-40 == p1y) {
					al_draw_bitmap(arm11, a11x=a11x+10, a11y, NULL);
					al_draw_bitmap(player1, p1x = p1x + 10, p1y, NULL);
					al_draw_bitmap(ball, tx = tx + 10, ty, NULL);
					al_draw_bitmap(arm12, a12x = a12x + 10, a12y, NULL);
					al_flip_display();
				}
				else {
					al_draw_bitmap(arm11, a11x=a11x+10, a11y, NULL);
					al_draw_bitmap(player1, p1x = p1x + 10, p1y, NULL);
					al_draw_bitmap(arm12, a12x = a12x + 10, a12y, NULL);
					al_flip_display();
				}
			    al_flip_display();
				rotation = 0;
	   }
	   else if (rotation == 2) {

				if (tx-70 == p1x && ty-40 == p1y) {
					al_draw_bitmap(arm11, a11x=a11x-10, a11y, NULL);
				    al_draw_bitmap(player1, p1x = p1x - 10, p1y, NULL);
					al_draw_bitmap(ball, tx = tx - 10, ty, NULL);
					al_draw_bitmap(arm12, a12x = a12x - 10, a12y, NULL);
					al_flip_display();
				}
				else {
					al_draw_bitmap(arm11, a11x=a11x-10, a11y, NULL);
					al_draw_bitmap(player1, p1x = p1x - 10, p1y, NULL);
					al_draw_bitmap(arm12, a12x = a12x - 10, a12y, NULL);
					al_flip_display();
				}
				al_flip_display();
				rotation = 0;
	   }
	   else if (rotation == 3) {

			if (tx-70 == p1x && ty-40 == p1y) {
				al_draw_bitmap(arm11, a11x, a11y=a11y-10, NULL);
				al_draw_bitmap(player1, p1x, p1y=p1y-10, NULL);
				al_draw_bitmap(ball, tx, ty=ty-10, NULL);
				al_draw_bitmap(arm12, a12x, a12y = a12y - 10, NULL);
				al_flip_display();
			}
			else {
				al_draw_bitmap(arm11, a11x, a11y=a11y-10, NULL);
				al_draw_bitmap(player1, p1x, p1y=p1y-10, NULL);
				al_draw_bitmap(arm12, a12x, a12y = a12y - 10, NULL);
				al_flip_display();
			}
			al_flip_display();
			rotation = 0;
	   }
	   else if (rotation == 4) {

			if (tx-70 == p1x && ty-40 == p1y) {
				al_draw_bitmap(arm11, a11x, a11y = a11y + 10, NULL);
				al_draw_bitmap(player1, p1x, p1y = p1y + 10, NULL);
				al_draw_bitmap(ball, tx, ty = ty + 10, NULL);
				al_draw_bitmap(arm12, a12x, a12y = a12y + 10, NULL);
				al_flip_display();
			}
			else {
				al_draw_bitmap(arm11, a11x, a11y = a11y + 10, NULL);
				al_draw_bitmap(player1, p1x, p1y = p1y + 10, NULL);
				al_draw_bitmap(arm12, a12x, a12y = a12y + 10, NULL);
				al_flip_display();
			}
			al_flip_display();
			rotation = 0;
	   }
	   if (rotation2 == 1) {

				if (tx-550 == p2x && ty-40 == p2y) {
					al_draw_bitmap(arm21, a21x=a21x+10, a21y, NULL);
					al_draw_bitmap(player2, p2x = p2x + 10, p2y, NULL);
					al_draw_bitmap(ball, tx = tx + 10, ty, NULL);
					al_draw_bitmap(arm22, a22x=a22x+10, a22y, NULL);
					al_flip_display();
				}
				else {
					al_draw_bitmap(arm21, a21x=a21x+10, a21y, NULL);
					al_draw_bitmap(player2, p2x = p2x + 10, p2y, NULL);
					al_draw_bitmap(arm22, a22x = a22x + 10, a22y, NULL);
					al_flip_display();
				}
				al_flip_display();
				rotation2 = 0;
	   }
	   else if (rotation2 == 2) {

			if (tx - 550 == p2x && ty-40 == p2y) {
				al_draw_bitmap(arm21, a21x = a21x - 10, a21y, NULL);
				al_draw_bitmap(player2, p2x = p2x - 10, p2y, NULL);
				al_draw_bitmap(ball, tx = tx - 10, ty, NULL);
				al_draw_bitmap(arm22, a22x = a22x - 10, a22y, NULL);
				al_flip_display();
			}
			else {
				al_draw_bitmap(arm21, a21x = a21x - 10, a21y, NULL);
				al_draw_bitmap(player2, p2x = p2x - 10, p2y, NULL);
				al_draw_bitmap(arm22, a22x = a22x - 10, a22y, NULL);
				al_flip_display();
			}
			al_flip_display();
			rotation2 = 0;
	   }
	   else if (rotation2 == 3) {

			if (tx - 550 == p2x && ty-40 == p2y) {
				al_draw_bitmap(arm21, a21x, a21y=a21y-10, NULL);
				al_draw_bitmap(player2, p2x, p2y=p2y-10, NULL);
				al_draw_bitmap(ball, tx, ty=ty-10, NULL);
				al_draw_bitmap(arm22, a22x, a22y=a22y-10, NULL);
				al_flip_display();
			}
			else {
				al_draw_bitmap(arm21, a21x, a21y = a21y - 10, NULL);
				al_draw_bitmap(player2, p2x, p2y=p2y-10, NULL);
				al_draw_bitmap(arm22, a22x, a22y = a22y - 10, NULL);
				al_flip_display();
			}
			al_flip_display();
			rotation2 = 0;
	   }
	   else if (rotation2 == 4) {

			if (tx - 550 == p2x && ty-40 == p2y) {
				al_draw_bitmap(arm21, a21x, a21y = a21y + 10, NULL);
				al_draw_bitmap(player2, p2x, p2y = p2y + 10, NULL);
				al_draw_bitmap(ball, tx, ty = ty + 10, NULL);
				al_draw_bitmap(arm22, a22x, a22y = a22y + 10, NULL);
				al_flip_display();
			}
			else {
				al_draw_bitmap(arm21, a21x, a21y = a21y + 10, NULL);
				al_draw_bitmap(player2, p2x, p2y = p2y + 10, NULL);
				al_draw_bitmap(arm22, a22x, a22y = a22y + 10, NULL);
				al_flip_display();
			}
			al_flip_display();
			rotation2 = 0;
	   }	
	   al_flip_display();
	}
	if (score1 == 3) {
		al_draw_bitmap(k1, 550, 600, NULL);
	}
	if (score2 == 3) {
		al_draw_bitmap(k2, 550, 600, NULL);
	}



	al_flip_display();

	al_rest(2);

	al_destroy_display(display);
	al_destroy_bitmap(player1);
	al_destroy_bitmap(arm11);
	al_destroy_bitmap(arm12);
	al_destroy_bitmap(arm21);
	al_destroy_bitmap(arm22);
	al_destroy_bitmap(arka);
	al_destroy_bitmap(pota);
	al_destroy_bitmap(k1);
	al_destroy_bitmap(k2);
	al_destroy_sample(music);
	
	return 0;
}