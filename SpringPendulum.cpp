#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<graphics.h>

int main() {
	initgraph(500, 500);
	setbkcolor(LIGHTGRAY);
	cleardevice();
	int n = 1500000, i = 0, j = 0;
	double F = 0.0, L0 = 1.0, m = 1.0, k = 40.0, dt = 0.00001, g = 10.0;
	double vx = 0.0, vy = 0.0, x = L0, y = 0.0, r = 1.0, d = r - L0, Fx = 0.0, Fy = 0.0;
	long double;
	char name[4] = { "1.0" };
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	setlinestyle(PS_DASH);
	rectangle(50, 50, 450, 450);
	fillrectangle(50, 50, 450, 450);
	setlinestyle(PS_DASH);
	setlinecolor(LIGHTGRAY);
	for (i = 1; i < 4; i++)
		line(100 * i + 50, 50, 100 * i + 50, 450);
	for (i = 1; i < 4; i++)
		line(50, 50 + 100 * i, 450, 50 + 100 * i);
	setlinestyle(PS_SOLID);
	setlinecolor(BLACK);
	settextstyle(15, 5, _T("ËÎÌו"));
	settextcolor(BLACK);
	line(250, 50, 250, 450);
	line(50, 250, 450, 250);
	outtextxy(252, 452, _T("-2.0"));
	setbkcolor(WHITE);
	outtextxy(52, 252, _T("-2.0"));
	outtextxy(252, 352, _T("-1.0"));
	outtextxy(152, 252, _T("-1.0"));
	outtextxy(252, 252, _T("0.0"));
	for (i = 1; i <= 2; i++) {
		outtextxy(252, 252 - 100 * i, name);
		if (i == 2)
		{
			setbkcolor(LIGHTGRAY);
			outtextxy(252 + 100 * i, 252, name);
		}
		name[0]++;
	}
	setfillcolor(GREEN);
	setlinecolor(GREEN);
	for (i = 0; i <= n; i++) {
		x = x - 0.5 * k * d * x / r / m * dt * dt + vx * dt;
		y = y + 0.5 * (g - k * d * y / r / m) * dt * dt + vy * dt;
		r = sqrt(pow(x, 2) + pow(y, 2));
		d = r - L0;
		vx = vx - k * d * x / r / m * dt;
		vy = vy + (g - k * d * y / r / m) * dt;
		circle(250 + x * 100, 250 + y * 100, 0.1);
		fillcircle(250 + x * 100, 250 + y * 100, 0.1);
	}
	system("Pause");
}