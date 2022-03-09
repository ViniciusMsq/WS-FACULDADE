#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <math.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int raio, y1, y2, i, nivel;
	
	int width, height;
	
	width = 1366;
	height = 768;
	
	initwindow(1366, 768, "PRIMEIRO PROGRAMA Gráfico");
	setcolor(WHITE);
	
	int no_x[3], no_info[3];
	
	no_info[0] = 15;
	no_info[1] = 20;
	no_info[2] = 10;
	
	// As coordenadas X e Y de um nó devem ser em função do seu nivel da arvore
	
	// Preenchendo as coordenadas X dos nós
	no_x[0] = width/2; // nó raiz
	
	nivel =1; // Nós filhos da raiz
	
	no_x[1] = no_x[0] + (width/2) / pow(2, nivel);
	no_x[2] = no_x[0] - (width/2) / pow(2, nivel);
	
	raio = 15;
	
	y1 = raio + 20; // y no nivel 0(raiz)
	y2 = nivel * 70 + raio + 20;   // y no nivel 1 (filhos da raiz)
	
	// Desenhando os nós
	fillellipse(no_x[0], y1, raio, raio);
	fillellipse(no_x[1], y2, raio, raio);
	fillellipse(no_x[2], y2, raio, raio);	
	
	// Fazendo as ligações
	line(no_x[0], y1, no_x[1], y2);
	line(no_x[0], y1, no_x[2], y2);
	
	// Imprimindo os textos
	
	char buffrstr[20];
	
	outtextxy(no_x[0]-raio/2, y1-raio/2, itoa(no_info[0], buffrstr, 10)); // itoa = Int To Array (char*)
	outtextxy(no_x[1]-raio/2, y2-raio/2, itoa(no_info[1], buffrstr, 10));
	outtextxy(no_x[2]-raio/2, y2-raio/2, itoa(no_info[2], buffrstr, 10));
	
	getch();
	
	closegraph();
	
	
	return 0;
}
