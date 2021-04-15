//{=============================================================================
// Ìóëüòôèëüì "Äîëãîæäàííàÿ âñòðå÷à"
// Çà÷åòíàÿ ðàáîòà
// ÊÏÊ ó÷èòåëåé èíôîðìàòèêè
// Íàôèêîâà Ýëüâèðà Ðàôèñîâíà
// ã. Óôà
// 2021
//}=============================================================================

#include <cmath>
#include "TXLib.h"

//=============================================================================

void DrawAirplan  (int x, int y, double size);
void DrawCloud    (int x, int y, double sizeCloud);
void DrawAirport  (int x, int y, double sizeAirport);
void DrawBus      (int x, int y, double sizeBus);
void DrawGirl     (int x, int y, double sizeGirl, int legs, int eyeR, int crazy, int Face,
                   int moveHandR, int moveHandL, int smile, COLORREF BodyColor);
void DrawHaus     (int x, int y, double sizeHaus, COLORREF HausColor);
void DrawRoad     (int y);
void DrawMonument (int x, int y, double sizeMonument);

void DrawMostFront();
void DrawMostRear();
void BackgroundTitryBegin();
void BackgroundArrived();
void BackgroundPassengerInBus();
void BackgroundGoBus();
void BackgroundMost();
void BackgroundStop();
void BackgroundOutBas();
void BackgroundMeet();
void BackgroundTitryEnd();

//=============================================================================

int main()
    {
    txCreateWindow (1300, 650);

    BackgroundTitryBegin();

    BackgroundArrived();

    BackgroundPassengerInBus();

    BackgroundGoBus();

    BackgroundMost();

    BackgroundStop();

    BackgroundOutBas();

    BackgroundMeet();

    BackgroundTitryEnd();

    return 0;
    }

//=============================================================================

void BackgroundArrived()
    {
    txClear();

    int t = 0;
    while (t <= 100)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 100, 1300, 650);
        txSetFillColor (TX_CYAN);
        txRectangle (0,   0, 1300, 100);

        DrawAirport (500, 250, 10);

        DrawBus (1000, 200, 10);

        DrawAirplan (t * 2, t, t * 0.025);

        DrawCloud (1000 - t/9 * 10, 30, 1  );
        DrawCloud ( 300 - t/9 * 10, 10, 0.8);
        DrawCloud (     - t/9 * 10,  5, 1.5);

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//-----------------------------------------------------------------------------

void BackgroundPassengerInBus()
    {
    txClear();

    int t = 1;
    while (t <= 100)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 100, 1300, 650);
        txSetFillColor (TX_CYAN);
        txRectangle (0,   0, 1300, 100);

        DrawAirport (500, 250, 10);

        DrawBus (1000, 200, 10);

        DrawGirl (900 + t, 330 - t, (10 - t/20) * 0.09 , pow (-1, (t/5) % 2),
                  0, 0, 0, 0, 1, 1, TX_PINK);
        DrawGirl (850 + t, 330 - t, (10 - t/20) * 0.09 , pow (-1, (t/5) % 2),
                  0, 0, 0, 0, 1, 1, TX_YELLOW);

        DrawAirplan (200, 100, 2.5);

        DrawCloud (890 - t/9 * 10, 30, 1  );
        DrawCloud (190 - t/9 * 10, 10, 0.8);
        DrawCloud (900 - t/9 * 10,  5, 1.5);

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//-----------------------------------------------------------------------------

void BackgroundGoBus()
    {
    txClear();

    int t = 1;
    while (t <= 100)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 100, 1300, 650);
        txSetFillColor (TX_CYAN);
        txRectangle (0,   0, 1300, 100);

        DrawAirport (500, 250, 10);

        DrawBus (1000 + t * 5, 200, 10);

        DrawAirplan (200, 100, 2.5);

        DrawCloud (780 - t/9 * 10, 30, 1  );
        DrawCloud ( 80 - t/9 * 10, 10, 0.8);
        DrawCloud (790 - t/9 * 10,  5, 1.5);

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//-----------------------------------------------------------------------------

void BackgroundMost()
    {
    txClear();

    int t = 1;
    while (t <= 100)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 100, 1300, 650);
        txSetFillColor (TX_CYAN);
        txRectangle (0,   0, 1300, 100);
        txSetColor (TX_BLUE);
        txSetFillColor (TX_BLUE);
        txLine (150, 100, 170, 650);
        txLine (150, 100, 300, 100);
        txLine (170, 650, 450, 650);
        txLine (300, 100, 450, 650);
        txFloodFill (200, 105);
        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txSelectFont ("Arial", 20, 0, FW_BOLD);
        txTextOut (300, 600, "ð. Àãèäåëü");

        DrawMostRear();

        DrawRoad (400);

        DrawCloud (780 - t/9 * 10, 30, 1  );
        DrawCloud ( 80 - t/9 * 10, 10, 0.8);
        DrawCloud (790 - t/9 * 10,  5, 1.5);

        DrawMonument (80, 1, 8);

        DrawHaus (230, 10, 5, RGB ( 47, 79,  79));
        DrawHaus (100, 10, 10, TX_ORANGE);
        DrawHaus (120,  5, 7, RGB (128,  0, 128));
        DrawHaus (130, 10, 9, RGB (128,  0, 128));

        DrawBus (100 + t * 15, 250, 20);

        DrawMostFront();

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//-----------------------------------------------------------------------------

void BackgroundStop()
    {
    txClear();

    int t = 1;
    while (t <= 30)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 100, 1300, 650);
        txSetFillColor (TX_CYAN);
        txRectangle (0,   0, 1300, 100);

        DrawRoad (300);

        DrawCloud (780 - t/9 * 10, 30, 1  );
        DrawCloud ( 80 - t/9 * 10, 10, 0.8);
        DrawCloud (790 - t/9 * 10,  5, 1.5);

        DrawHaus (230, 10,  5, RGB ( 47, 79,  79));
        DrawHaus (210, 10,  5, RGB ( 47, 79,  79));
        DrawHaus ( 50, 13,  6, RGB ( 47, 79,  79));
        DrawHaus (120,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 10,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 70,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 30, 11,  6, TX_ORANGE);

        DrawBus (100 + t * 15, 250, 10);

        DrawHaus (130, 30,  9, RGB (128,  0, 128));
        DrawHaus ( 20, 35, 10, RGB ( 47, 79,  79));
        DrawHaus ( 70, 30, 12, TX_ORANGE);

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//-----------------------------------------------------------------------------

void BackgroundOutBas()
    {
    txClear();

    int t = 1;
    while (t <= 20)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 100, 1300, 650);
        txSetFillColor (TX_CYAN);
        txRectangle (0,   0, 1300, 100);

        DrawRoad (300);

        DrawCloud (750 - t/9 * 10, 30, 1  );
        DrawCloud ( 50 - t/9 * 10, 10, 0.8);
        DrawCloud (760 - t/9 * 10,  5, 1.5);

        DrawHaus (230, 10,  5, RGB ( 47, 79,  79));
        DrawHaus (210, 10,  5, RGB ( 47, 79,  79));
        DrawHaus ( 50, 13,  6, RGB ( 47, 79,  79));
        DrawHaus (120,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 10,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 70,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 30, 11,  6, TX_ORANGE);

        DrawBus (550, 250, 10);

        DrawGirl (570, 330, 0.7, 0, 2, 0, 1, 0,   1,               2, TX_PINK);
        DrawGirl (500, 330, 0.8, 0, 2, 0, 1, 0,   1,               3, TX_YELLOW);
        DrawGirl (800, 450, 1,   0, 0, 0, 0, 0, -50 * ((t/2) % 2), 0, RGB (0, 255, 255));

        DrawHaus (130, 30,  9, RGB (128,  0, 128));
        DrawHaus ( 20, 35, 10, RGB ( 47, 79,  79));
        DrawHaus ( 70, 30, 13, TX_ORANGE);

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//-----------------------------------------------------------------------------

void BackgroundMeet()
    {
    txClear();

    int t = 1;
    while (t <= 100)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 100, 1300, 650);
        txSetFillColor (TX_CYAN);
        txRectangle (0,   0, 1300, 100);

        DrawRoad (300);

        DrawCloud (730 - t/9 * 10, 30, 1  );
        DrawCloud ( 30 - t/9 * 10, 10, 0.8);
        DrawCloud (740 - t/9 * 10,  5, 1.5);

        DrawHaus (230, 10,  5, RGB ( 47, 79,  79));
        DrawHaus (210, 10,  5, RGB ( 47, 79,  79));
        DrawHaus ( 50, 13,  6, RGB ( 47, 79,  79));
        DrawHaus (120,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 10,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 70,  5,  7, RGB (128,  0, 128));
        DrawHaus ( 30, 11,  6, TX_ORANGE);

        DrawBus (550 + t * 15, 250, 10);

        DrawGirl (570 + t, 330 + t, (10 + t/20) * 0.07 , pow (-1, (t/5) % 2),
                  2, 0, 1, 0, 1, 2, TX_PINK);
        DrawGirl (500 + t, 330 + t, (10 + t/20) * 0.08 , pow (-1, (t/5) % 2),
                  2, 0, 1, 0, 1, 3, TX_YELLOW);
        DrawGirl (800,     450,     1,                   0,
                  0, 0, 0, 0, 0, 0, RGB (0, 255, 255));

        DrawHaus (130, 30,  9, RGB (128,  0, 128));
        DrawHaus ( 20, 35, 10, RGB ( 47, 79,  79));
        DrawHaus ( 70, 30, 13, TX_ORANGE);

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//=============================================================================

void DrawAirplan (int x, int y, double size)
    {
    txSetColor (TX_BLUE);
    txSetFillColor (TX_LIGHTBLUE);
    POINT Airplan[14] = {{ROUND ( x        * size), ROUND ( y        * size)}, {ROUND ((x +  30) * size), ROUND ( y        * size)},
                         {ROUND ((x +  50) * size), ROUND ((y +  30) * size)}, {ROUND ((x +  75) * size), ROUND ((y +  30) * size)},
                         {ROUND ((x +  60) * size), ROUND ((y -  10) * size)}, {ROUND ((x +  90) * size), ROUND ((y -  10) * size)},
                         {ROUND ((x + 115) * size), ROUND ((y +  30) * size)}, {ROUND ((x + 160) * size), ROUND ((y +  30) * size)},
                         {ROUND ((x + 210) * size), ROUND ((y +  70) * size)}, {ROUND ((x + 115) * size), ROUND ((y +  70) * size)},
                         {ROUND ((x +  90) * size), ROUND ((y + 110) * size)}, {ROUND ((x +  60) * size), ROUND ((y + 110) * size)},
                         {ROUND ((x +  75) * size), ROUND ((y +  70) * size)}, {ROUND ((x +  20) * size), ROUND ((y +  70) * size)}};
          txPolygon (Airplan, 14);
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    int KWindow = 0;
    while (KWindow <= 4)
        {
        txCircle (ROUND ((x + 75 + 20 * KWindow) * size), ROUND ((y + 45) * size), ROUND (5 * size));
        KWindow += 1;
        }
    }

//-----------------------------------------------------------------------------

void DrawCloud (int x, int y, double sizeCloud)
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);

    txEllipse (ROUND( x       * sizeCloud), ROUND((y + 20) * sizeCloud), ROUND((x + 40) * sizeCloud), ROUND((y + 40) * sizeCloud));
    txEllipse (ROUND((x + 20) * sizeCloud), ROUND( y       * sizeCloud), ROUND((x + 80) * sizeCloud), ROUND((y + 40) * sizeCloud));
    txEllipse (ROUND((x + 20) * sizeCloud), ROUND((y + 30) * sizeCloud), ROUND((x + 60) * sizeCloud), ROUND((y + 50) * sizeCloud));
    }

//-----------------------------------------------------------------------------

void DrawAirport (int x, int y, double sizeAirport)
    {
    txSetColor (RGB (105, 105, 105));
    txSetFillColor (RGB (105, 105, 105));
    txRectangle (x +  20 * sizeAirport, y +  3 * sizeAirport,
                 x + 100 * sizeAirport, y + 10 * sizeAirport);
    txSetColor (TX_WHITE, 3);
    txLine ( 750, y + 6 * sizeAirport,  850, y + 6 * sizeAirport);
    txLine ( 900, y + 6 * sizeAirport, 1000, y + 6 * sizeAirport);
    txLine (1050, y + 6 * sizeAirport, 1150, y + 6 * sizeAirport);
    txLine (1200, y + 6 * sizeAirport, 1300, y + 6 * sizeAirport);
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    txRectangle (x - 24 * sizeAirport, y - 12 * sizeAirport,
                 x + 24 * sizeAirport, y + 12 * sizeAirport);
    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    txRectangle (x - 20 * sizeAirport, y - 10 * sizeAirport,
                 x + 20 * sizeAirport, y + 10 * sizeAirport);
    txSetColor (TX_GRAY, 3);
    txLine (x - 20 * sizeAirport, y - 6 * sizeAirport,
            x + 20 * sizeAirport, y - 6 * sizeAirport);
    txLine (x - 20 * sizeAirport, y,
            x + 20 * sizeAirport, y                  );
    txLine (x - 20 * sizeAirport, y + 6 * sizeAirport,
            x + 20 * sizeAirport, y + 6 * sizeAirport);
    txLine (x - 10 * sizeAirport, y - 10 * sizeAirport,
            x - 10 * sizeAirport, y + 10 * sizeAirport);
    txLine (x,                    y - 10 * sizeAirport,
            x,                    y + 10 * sizeAirport);
    txLine (x + 10 * sizeAirport, y - 10 * sizeAirport,
            x + 10 * sizeAirport, y + 10 * sizeAirport);
    txSetColor (TX_WHITE, 3);
    txSetFillColor (TX_NULL);
    txCircle (x,                   y - 14 * sizeAirport, 2 * sizeAirport);
    txLine (x - 2 * sizeAirport, y - 14 * sizeAirport, x + 2 * sizeAirport, y - 14 * sizeAirport);
    txSetColor (TX_BLUE, 3);
    txCircle (x - 5 * sizeAirport, y - 14 * sizeAirport, 2 * sizeAirport);
    txLine (x - 5 * sizeAirport, y - 16 * sizeAirport, x - 5 * sizeAirport, y - 12 * sizeAirport);
    txSetColor (RGB (0, 100, 0), 3);
    txCircle (x + 5 * sizeAirport, y - 14 * sizeAirport, 2 * sizeAirport);
    txLine (x + 5 * sizeAirport, y - 16 * sizeAirport, x + 5 * sizeAirport, y - 12 * sizeAirport);
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txSelectFont ("Arial", 20, 0, FW_BOLD);
    txTextOut (x - 22 * sizeAirport, y - 14 * sizeAirport, "ÓÔÀ àýðîïîðò");
    txTextOut (x + 12 * sizeAirport, y - 14 * sizeAirport, "airport UFA" );
    txSetColor (RGB (105, 105, 105));
    txSetFillColor (RGB (105, 105, 105));
    txRectangle (0, y + 12 * sizeAirport, 1300, y + 24 * sizeAirport);
    txSetColor (TX_WHITE, 4);
    txLine (   0, y + 18 * sizeAirport,  100, y + 18 * sizeAirport);
    txLine ( 150, y + 18 * sizeAirport,  250, y + 18 * sizeAirport);
    txLine ( 300, y + 18 * sizeAirport,  400, y + 18 * sizeAirport);
    txLine ( 450, y + 18 * sizeAirport,  550, y + 18 * sizeAirport);
    txLine ( 600, y + 18 * sizeAirport,  700, y + 18 * sizeAirport);
    txLine ( 750, y + 18 * sizeAirport,  850, y + 18 * sizeAirport);
    txLine ( 900, y + 18 * sizeAirport, 1000, y + 18 * sizeAirport);
    txLine (1050, y + 18 * sizeAirport, 1150, y + 18 * sizeAirport);
    txLine (1200, y + 18 * sizeAirport, 1300, y + 18 * sizeAirport);
    }

//-----------------------------------------------------------------------------

void DrawBus (int x, int y, double sizeBus)
    {
    txSetColor (TX_ORANGE);
    txSetFillColor (TX_YELLOW);
    txRectangle (x - 10 * sizeBus, y,               x + 10 * sizeBus, y + 10 * sizeBus);
    txSetFillColor (TX_ORANGE);
    txCircle (x + 9 * sizeBus, y + 7 * sizeBus, 1 * sizeBus);
    txSetColor (TX_LIGHTGRAY);
    txSetFillColor (TX_LIGHTGRAY);
    txRectangle (x -  9 * sizeBus, y + 2 * sizeBus, x + 10 * sizeBus, y +  6 * sizeBus);
    txSetColor (RGB (128, 128, 128), 3);
    txLine (x - 9 * sizeBus, y +  2 * sizeBus, x -  9 * sizeBus, y +  6 * sizeBus);
    txLine (x - 6 * sizeBus, y +  2 * sizeBus, x -  6 * sizeBus, y +  6 * sizeBus);
    txLine (x - 2 * sizeBus, y +  2 * sizeBus, x -  2 * sizeBus, y + 10 * sizeBus);
    txLine (x + 2 * sizeBus, y +  2 * sizeBus, x +  2 * sizeBus, y + 10 * sizeBus);
    txLine (x + 6 * sizeBus, y +  2 * sizeBus, x +  6 * sizeBus, y +  6 * sizeBus);
    txLine (x - 9 * sizeBus, y +  2 * sizeBus, x + 10 * sizeBus, y +  2 * sizeBus);
    txLine (x - 9 * sizeBus, y +  6 * sizeBus, x + 10 * sizeBus, y +  6 * sizeBus);
    txLine (x - 2 * sizeBus, y + 10 * sizeBus, x +  2 * sizeBus, y + 10 * sizeBus);
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txCircle (x - 6 * sizeBus, y + 10 * sizeBus, 2 * sizeBus);
    txCircle (x + 6 * sizeBus, y + 10 * sizeBus, 2 * sizeBus);
    }

//-----------------------------------------------------------------------------

void DrawGirl (int x, int y, double sizeGirl, int legs, int eyeR, int crazy, int Face,
               int moveHandR, int moveHandL, int smile, COLORREF BodyColor)
    {
    txSetFillColor (BodyColor);
    txSetColor (TX_BLACK);
    POINT Girl[3] = {{ROUND (x - 35 * sizeGirl), ROUND (y + 130 * sizeGirl)},
                     {ROUND (x -  1 * sizeGirl), ROUND (y -   1 * sizeGirl)},
                     {ROUND (x + 35 * sizeGirl), ROUND (y + 130 * sizeGirl)}};
          txPolygon (Girl, 3);
    txSetFillColor (TX_RED);
    POINT Bant1[3] = {{ROUND (x - 24 * sizeGirl), ROUND (y - 36 * sizeGirl)},
                      {ROUND (x - 24 * sizeGirl), ROUND (y - 68 * sizeGirl)},
                      {ROUND (x +  1 * sizeGirl), ROUND (y - 51 * sizeGirl)}};
          txPolygon (Bant1, 3);
    POINT Bant2[3] = {{ROUND (x + 26 * sizeGirl), ROUND (y - 36 * sizeGirl)},
                      {ROUND (x + 26 * sizeGirl), ROUND (y - 68 * sizeGirl)},
                      {ROUND (x +  1 * sizeGirl), ROUND (y - 51 * sizeGirl)}};
          txPolygon (Bant2, 3);
    txSetFillColor (TX_WHITE);
    txCircle (ROUND (x - 1 * sizeGirl), ROUND (y - 25 * sizeGirl), ROUND (25 * sizeGirl));
    txCircle (ROUND (x - 1 * sizeGirl), ROUND (y - 21 * sizeGirl), ROUND ( 2 * sizeGirl) * Face);
    txSetColor (TX_BLACK,2);
    txCircle (ROUND (x - 6 * sizeGirl), ROUND (y - 30 * sizeGirl), ROUND (eyeR * sizeGirl - crazy * sizeGirl));
    txCircle (ROUND (x + 7 * sizeGirl), ROUND (y - 30 * sizeGirl), ROUND (eyeR * sizeGirl + crazy * sizeGirl));
    txSetColor (TX_RED,1);
    txLine (ROUND (x - 10 * sizeGirl) * Face, ROUND (y - 9 * sizeGirl) * Face,
            ROUND (x +  1 * sizeGirl) * Face, ROUND (y - 9 * sizeGirl + smile * sizeGirl) * Face);
    txLine (ROUND (x + 10 * sizeGirl) * Face, ROUND (y - 9 * sizeGirl) * Face,
            ROUND (x +  1 * sizeGirl) * Face, ROUND (y - 9 * sizeGirl + smile * sizeGirl) * Face);
    txSetColor (TX_BLACK, 3);
    txLine (ROUND (x -  9 * sizeGirl), ROUND (y + 35 * sizeGirl),
            ROUND (x - 56 * sizeGirl), ROUND (y + 57 * sizeGirl + moveHandR * sizeGirl));
    txLine (ROUND (x + 11 * sizeGirl), ROUND (y + 36 * sizeGirl),
            ROUND (x + 56 * sizeGirl), ROUND (y + 59 * sizeGirl + moveHandL * sizeGirl));
    txSetColor (TX_RED, 3);
    txLine (ROUND (x - 2 * sizeGirl), ROUND (y + 130 * sizeGirl),
            ROUND (x - 4 * sizeGirl), ROUND (y + 174 * sizeGirl + 5 * legs * sizeGirl));
    txLine (ROUND (x + 2 * sizeGirl), ROUND (y + 130 * sizeGirl),
            ROUND (x + 4 * sizeGirl), ROUND (y + 174 * sizeGirl - 5 * legs * sizeGirl));
    }

//-----------------------------------------------------------------------------

void DrawRoad (int y)
    {
    txSetColor (RGB (105, 105, 105));
    txSetFillColor (RGB (105, 105, 105));
    txRectangle (0, y - 100, 1300, y + 100);
    txSetColor (TX_WHITE, 4);
    txLine (   0, y,  100, y);
    txLine ( 150, y,  250, y);
    txLine ( 300, y,  400, y);
    txLine ( 450, y,  550, y);
    txLine ( 600, y,  700, y);
    txLine ( 750, y,  850, y);
    txLine ( 900, y, 1000, y);
    txLine (1050, y, 1150, y);
    txLine (1200, y, 1300, y);
    }

//-----------------------------------------------------------------------------

void DrawMonument (int x, int y, double sizeMonument)
    {
    txSetColor (TX_RED);
    txSetFillColor (TX_RED);
    POINT Monument[5] = {{ROUND ((x + 1) * sizeMonument), ROUND ((y +  1) * sizeMonument)}, {ROUND ((x + 3) * sizeMonument), ROUND ((y +  2) * sizeMonument)},
                         {ROUND ((x + 5) * sizeMonument), ROUND ((y + 24) * sizeMonument)}, {ROUND ((x - 3) * sizeMonument), ROUND ((y + 24) * sizeMonument)},
                         {ROUND ((x - 1) * sizeMonument), ROUND ((y +  2) * sizeMonument)}};
          txPolygon (Monument, 5);
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    POINT OsnovanieCentr[4] = {{ROUND ((x -  5) * sizeMonument), ROUND ((y + 24) * sizeMonument)}, {ROUND ((x +  7) * sizeMonument), ROUND ((y + 24) * sizeMonument)},
                               {ROUND ((x +  9) * sizeMonument), ROUND ((y + 32) * sizeMonument)}, {ROUND ((x -  7) * sizeMonument), ROUND ((y + 32) * sizeMonument)}};
          txPolygon (OsnovanieCentr, 4);
    POINT OsnovanieLeft[4]  = {{ROUND ((x -  7) * sizeMonument), ROUND ((y + 26) * sizeMonument)}, {ROUND ((x -  7) * sizeMonument), ROUND ((y + 32) * sizeMonument)},
                               {ROUND ((x - 11) * sizeMonument), ROUND ((y + 32) * sizeMonument)}, {ROUND ((x - 11) * sizeMonument), ROUND ((y + 26) * sizeMonument)}};
          txPolygon (OsnovanieLeft, 4);
    POINT OsnovanieRight[4] = {{ROUND ((x +  9) * sizeMonument), ROUND ((y + 26) * sizeMonument)}, {ROUND ((x +  9) * sizeMonument), ROUND ((y + 32) * sizeMonument)},
                               {ROUND ((x + 13) * sizeMonument), ROUND ((y + 32) * sizeMonument)}, {ROUND ((x + 13) * sizeMonument), ROUND ((y + 26) * sizeMonument)}};
          txPolygon (OsnovanieRight, 4);
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txSelectFont ("Arial", 20, 0, FW_BOLD);
    txTextOut ((x - 9) * sizeMonument, (y + 32) * sizeMonument, "Ìîíóìåíò Äðóæáû");
    }

//-----------------------------------------------------------------------------

void DrawMostFront()
    {
    txSetColor (RGB (220, 220, 220), 6);
    txSetFillColor (RGB (220, 220, 220));
    txArc (100, 365, 460, 1115, 60, 60);
    txRectangle (130, 460, 420, 503);
    }

//-----------------------------------------------------------------------------

void DrawMostRear()
    {
    txSetColor (RGB (220, 220, 220), 6);
    txSetFillColor (RGB (220, 220, 220));
    txArc (100, 200, 400, 915, 70, 50);
    txRectangle (140, 265, 360, 303);
    }

//-----------------------------------------------------------------------------

void DrawHaus (int x, int y, double sizeHaus, COLORREF HausColor)
    {
    txSetColor (HausColor);
    txSetFillColor (HausColor);
    txRectangle ((x + 1) * sizeHaus, (y +  1) * sizeHaus, (x + 15) * sizeHaus, (y + 19) * sizeHaus);
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    int i = 1;
    while (i <= 7)
        {
        int j = 1;
        while (j <= 5)
            {
            txRectangle ((x + 1 + 2*j) * sizeHaus, (y + 1 + 2*i) * sizeHaus,
                         (x + 3 + 2*j) * sizeHaus, (y + 3 + 2*i) * sizeHaus);
            j += 2;
            }
        i += 2;
        }
    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle ((x + 7) * sizeHaus, (y + 15) * sizeHaus, (x + 9) * sizeHaus, (y + 19) * sizeHaus);
    }

//=============================================================================

void BackgroundTitryBegin()
    {
    txClear();

    int t = 0;
    while (t <= 50)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (RGB (255, 228, 225));
        txRectangle (0, 0, 1300, 650);

        txSetColor (TX_GRAY);
        txSetFillColor (TX_GRAY);
        txSelectFont ("Arial", 100, 0, FW_BOLD);
        txTextOut (500 - t * 10, 300, "Äîëãîæäàííàÿ âñòðå÷à");

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }

//-----------------------------------------------------------------------------

void BackgroundTitryEnd()
    {
    txClear();

    int t = 0;
    while (t <= 75)
        {
        txBegin();

        txSetColor (TX_GREEN);
        txSetFillColor (TX_GREEN);
        txRectangle (0, 0, 1300, 650);

        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txSelectFont ("Arial", 50, 0, FW_BOLD);
        txTextOut (400, 300 - t * 10, "Äîáðî ïîæàëîâàòü â Óôó!");
        txTextOut (200, 500 - t * 10, "Ïðîåêò âûïîëíèëà");
        txTextOut (200, 550 - t * 10, "Íàôèêîâà Ýëüâèðà Ðàôèñîâíà");
        txTextOut (500, 650 - t * 10, "ã.Óôà, 2021");

        t ++ ;

        txSleep (50);

        txEnd();
        }
    }
