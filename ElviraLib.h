#include <cmath>
#include "TXLib.h"

void DrawSun      (int x, int y, double size);
void DrawElka     (int x, int y, int crown1, int crown2, int crown3, int widthTrunk);
void DrawHaus     (int x, int y, double sizeX, double sizeY,
                   int shiftKrisha, int heightKrisha, int widthWindow, int heightWindow,
                   COLORREF wallColor, COLORREF krishaColor, COLORREF windowColor);
void DrawCat      (int x, int y, double size, int lengthTail, int heightTail,
                   int pawsL, int pawsR, COLORREF catColor);
void DrawChick    (int x, int y, int moveWing, int lengthStep);
void DrawAirplan  (int x, int y, double size);
void DrawCloud    (int x, int y, double sizeCloud);
void DrawAirport  (int x, int y, double sizeAirport);
void DrawBus      (int x, int y, double sizeBus, int RLBus, COLORREF BusColor);
void DrawGirl     (int x, int y, double sizeGirl, int legs, int eyeR, int crazy, int face,
                   int moveHandR, int moveHandL, int smile, COLORREF BodyColor);
void DrawHausCity (int x, int y, double sizeHaus, COLORREF HausColor);
void DrawRoad     (int y);
void DrawMonument (int x, int y, double sizeMonument);

//=============================================================================

void DrawSun (int x, int y, double size)
    {
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (x, y, 50*size);
    txLine (x,           y - 50*size, x,           y + 80*size);
    txLine (x - 80*size, y,           x + 80*size, y);
    txLine (x - 50*size, y - 40*size, x + 50*size, y + 60*size);
    txLine (x - 50*size, y + 60*size, x + 50*size, y - 40*size);
    }

//-----------------------------------------------------------------------------

void DrawElka (int x, int y, int crown1, int crown2, int crown3, int widthTrunk)
    {
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    POINT Treug1[3] = {{x - 17 - crown1/2, y + 36}, {x, y},      {x + 17 + crown1/2, y + 36}};
    txPolygon (Treug1, 3);
    POINT Treug2[3] = {{x - 25 - crown2/2, y + 60}, {x, y + 36}, {x + 25 + crown2/2, y + 60}};
    txPolygon (Treug2, 3);
    POINT Treug3[3] = {{x - 30 - crown3/2, y + 90}, {x, y + 60}, {x + 30 + crown3/2, y + 90}};
    txPolygon (Treug3, 3);
    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle (x - widthTrunk/2, y + 90, x + widthTrunk/2, y + 115);
    }

//{=============================================================================
//! Рисует Домик
//!
//! Рисует милый деревенский Домик с одним окошком
//!
//! @param x            x - координата конька Домика (самая верхушка)
//! @param y            y - координата конька Домика (самая верхушка)
//! @param sizeX        Размер ширины Домика
//! @param sizeY        Размер высоты Домика
//! @param shiftKrisha  Сдвиг крыши Домика. Делает крышу асимметричной
//! @param heightKrisha Увеличение или уменьшение высоты крыши Домика
//! @param widthWindow  Ширина окна Домика
//! @param heightWindow Высота окна Домика
//!
//! @par                Пример использования:
//! @code
//!                     DrawHaus (100, 100, 1, 1, 20, 0, 50, 50, TX_YELLOW, TX_RED, TX_BLUE);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawHaus (int x, int y, double sizeX, double sizeY,
               int shiftKrisha, int heightKrisha, int widthWindow, int heightWindow,
               COLORREF wallColor, COLORREF krishaColor, COLORREF windowColor)
    {
    txSetColor (TX_BLACK);
    txSetFillColor (krishaColor);
    POINT Krisha[3] = {{ROUND(x - 80*sizeX),    ROUND(y + 100*sizeY)},
                       {ROUND(x + shiftKrisha), ROUND(y - heightKrisha)},
                       {ROUND(x + 80*sizeX),    ROUND(y + 100*sizeY)}};
    txPolygon (Krisha, 3);
    txSetFillColor (wallColor);
    txRectangle (ROUND(x - 80*sizeX), ROUND(y + 100*sizeY), ROUND(x + 80*sizeX), ROUND(y + 250*sizeY));
    txSetFillColor (windowColor);
    txRectangle (ROUND(x - 38*sizeX - widthWindow/2), ROUND(y + 139*sizeY - heightWindow/2),
                 ROUND(x + 40*sizeX + widthWindow/2), ROUND(y + 208*sizeY + heightWindow/2));
    txLine (ROUND(x - 38*sizeX - widthWindow/2), ROUND(y + 174*sizeY - heightWindow/2),
            ROUND(x + 40*sizeX + widthWindow/2), ROUND(y + 174*sizeY - heightWindow/2));
    txLine (ROUND(x + sizeX),                    ROUND(y + 174*sizeY - heightWindow/2),
            ROUND(x + sizeX),                    ROUND(y + 208*sizeY + heightWindow/2));
    }

//{=============================================================================
//! Рисует Девочку
//!
//! Рисует Девочку с бантиком
//!
//! @param x         x - координата шеи Девочки
//! @param y         y - координата шеи Девочки
//! @param sizeGirl  Размер Девочки. Девочки могут быть маленькими и большими
//! @param legs      Подъем ноги Девочки
//! @param eyeR      Радиус глаз Девочки
//! @param crazy     У Девочки могут быть разные по величине глаза
//! @param face      Девочка может повернуться спиной (т.е. без лица)
//! @param moveHandR Движение правой руки Девочки
//! @param moveHandL Движение левой руки Девочки
//! @param smile     Улыбка Девочки
//!
//! @par             Пример использования:
//! @code
//!                  DrawGirl (500, 100, 0.9, 2, 3, 1, 1, 40, 0, 8, TX_GREEN);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawGirl (int x, int y, double sizeGirl, int legs, int eyeR, int crazy, int face,
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
    txCircle (ROUND (x - 1 * sizeGirl), ROUND (y - 21 * sizeGirl), ROUND ( 2 * sizeGirl) * face);

    txSetColor (TX_BLACK,2);
    txCircle (ROUND (x - 6 * sizeGirl), ROUND (y - 30 * sizeGirl), ROUND (eyeR * sizeGirl - crazy * sizeGirl) * face);
    txCircle (ROUND (x + 7 * sizeGirl), ROUND (y - 30 * sizeGirl), ROUND (eyeR * sizeGirl + crazy * sizeGirl) * face);

    txSetColor (TX_RED,1);
    txLine (ROUND (x - 10 * sizeGirl) * face, ROUND (y - 9 * sizeGirl) * face,
            ROUND (x +  1 * sizeGirl) * face, ROUND (y - 9 * sizeGirl + smile * sizeGirl) * face);
    txLine (ROUND (x + 10 * sizeGirl) * face, ROUND (y - 9 * sizeGirl) * face,
            ROUND (x +  1 * sizeGirl) * face, ROUND (y - 9 * sizeGirl + smile * sizeGirl) * face);

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

//{=============================================================================
//! Рисует Кота
//!
//! Рисует милого Котика
//!
//! @param x          x - координата центра головы Кота
//! @param y          y - координата центра головы Кота
//! @param lengthTail Длина хвостика Кота (ведь хвосты бывают разные)
//! @param heightTail Высота подъема хвостика Кота (0 - горизонтально)
//! @param pawsL      Шаг задних лап Кота
//! @param pawsR      Шаг передних лап Кота
//!
//! @par              Пример использования:
//! @code
//!                   DrawCat (500, 100, 1.5, 30, 10, 10, 20, TX_WHITE);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawCat (int x, int y, double size, int lengthTail, int heightTail,
              int pawsL, int pawsR, COLORREF catColor)
    {
    txSetColor (TX_LIGHTGRAY);
    txSetFillColor (catColor);
    txRectangle (ROUND ((x - 105) * size), ROUND ((y + 16) * size),
                 ROUND ((x -  10) * size), ROUND ((y + 56) * size));

    txCircle (ROUND (x * size), ROUND (y * size), ROUND (23 * size));

    POINT Ear1[3] = {{ROUND ((x - 13) * size), ROUND ((y - 22) * size)},
                     {ROUND ((x -  4) * size), ROUND ((y - 38) * size)},
                     {ROUND ((x +  5) * size), ROUND ((y - 22) * size)}};
    txPolygon (Ear1, 3);
    POINT Ear2[3] = {{ROUND ((x +  5) * size), ROUND ((y - 20) * size)},
                     {ROUND ((x + 10) * size), ROUND ((y - 35) * size)},
                     {ROUND ((x + 15) * size), ROUND ((y - 20) * size)}};
    txPolygon (Ear2, 3);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txCircle (ROUND ((x +  9) * size), ROUND ((y - 5) * size), ROUND (2 * size));
    txCircle (ROUND ((x + 23) * size), ROUND ((y + 1) * size), ROUND (2 * size));

    txSetColor (TX_BLACK, 3);
    txLine (ROUND ((x - 153 - lengthTail) * size), ROUND ((y + 16 - heightTail) * size),
            ROUND ((x - 105) * size),              ROUND ((y + 16) * size));

    txLine (ROUND ((x - 86 - pawsL/2) * size), ROUND ((y + 88) * size), ROUND ((x - 86) * size), ROUND ((y + 55) * size));
    txLine (ROUND ((x - 86 + pawsL/2) * size), ROUND ((y + 86) * size), ROUND ((x - 86) * size), ROUND ((y + 55) * size));
    txLine (ROUND ((x - 30 - pawsR/2) * size), ROUND ((y + 87) * size), ROUND ((x - 30) * size), ROUND ((y + 55) * size));
    txLine (ROUND ((x - 30 + pawsR/2) * size), ROUND ((y + 86) * size), ROUND ((x - 30) * size), ROUND ((y + 55) * size));
    }

//=============================================================================

void DrawChick (int x, int y, int moveWing, int lengthStep)
    {
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (x, y, 25);
    txCircle (x - 23, y - 21, 15);
    txCircle (x + 19, y -  5, 10);
    txSetColor (TX_BLACK);
    txLine (x - 46, y - 15, x - 37,                y - 20);
    txLine (x - 46, y - 15, x - 37,                y - 15);
    txLine (x -  7, y -  7, x + 11,                y + moveWing);
    txLine (x + 14, y -  7, x + 11,                y + moveWing);
    txLine (x + 14, y -  7, x -  7,                y -  7);
    txLine (x -  3, y + 26, x -  3 - lengthStep/2, y + 40);
    txLine (x +  2, y + 26, x +  2 + lengthStep/2, y + 40);
    txSetFillColor (TX_BLACK);
    txCircle (x - 31, y - 20, 2);
    }

//-----------------------------------------------------------------------------

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
    int kWindow = 0;
    while (kWindow <= 4)
        {
        txCircle (ROUND ((x + 75 + 20 * kWindow) * size), ROUND ((y + 45) * size), ROUND (5 * size));
        kWindow += 1;
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
    txTextOut (x - 22 * sizeAirport, y - 14 * sizeAirport, "УФА аэропорт");
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

void DrawBus (int x, int y, double sizeBus, int RLBus, COLORREF BusColor)
    {
    txSetColor (TX_ORANGE);
    txSetFillColor (BusColor);
    txRectangle (x - 10 * sizeBus, y,               x + 10 * sizeBus, y + 10 * sizeBus);
    txSetFillColor (TX_ORANGE);
    txCircle (x + 9 * sizeBus * RLBus, y + 7 * sizeBus, 1 * sizeBus);
    txSetColor (TX_LIGHTGRAY);
    txSetFillColor (TX_LIGHTGRAY);
    txRectangle (x -  9 * sizeBus * RLBus, y + 2 * sizeBus, x + 10 * sizeBus * RLBus, y +  6 * sizeBus);
    txSetColor (RGB (128, 128, 128), 3);
    txLine (x - 9 * sizeBus * RLBus, y +  2 * sizeBus, x -  9 * sizeBus * RLBus, y +  6 * sizeBus);
    txLine (x - 6 * sizeBus * RLBus, y +  2 * sizeBus, x -  6 * sizeBus * RLBus, y +  6 * sizeBus);
    txLine (x - 2 * sizeBus * RLBus, y +  2 * sizeBus, x -  2 * sizeBus * RLBus, y + 10 * sizeBus);
    txLine (x + 2 * sizeBus * RLBus, y +  2 * sizeBus, x +  2 * sizeBus * RLBus, y + 10 * sizeBus);
    txLine (x + 6 * sizeBus * RLBus, y +  2 * sizeBus, x +  6 * sizeBus * RLBus, y +  6 * sizeBus);
    txLine (x - 9 * sizeBus * RLBus, y +  2 * sizeBus, x + 10 * sizeBus * RLBus, y +  2 * sizeBus);
    txLine (x - 9 * sizeBus * RLBus, y +  6 * sizeBus, x + 10 * sizeBus * RLBus, y +  6 * sizeBus);
    txLine (x - 2 * sizeBus * RLBus, y + 10 * sizeBus, x +  2 * sizeBus * RLBus, y + 10 * sizeBus);
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txCircle (x - 6 * sizeBus * RLBus, y + 10 * sizeBus, 2 * sizeBus);
    txCircle (x + 6 * sizeBus * RLBus, y + 10 * sizeBus, 2 * sizeBus);
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
    txTextOut ((x - 10) * sizeMonument, (y + 32) * sizeMonument, "Monument of friendship");
    }

//-----------------------------------------------------------------------------

void DrawHausCity (int x, int y, double sizeHaus, COLORREF HausColor)
    {
    txSetColor (HausColor);
    txSetFillColor (HausColor);
    txRectangle ((x + 1) * sizeHaus, (y +  1) * sizeHaus, (x + 15) * sizeHaus, (y + 19) * sizeHaus);
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    int iWin = 1;
    while (iWin <= 7)
        {
        int jWin = 1;
        while (jWin <= 5)
            {
            txRectangle ((x + 1 + 2*jWin) * sizeHaus, (y + 1 + 2*iWin) * sizeHaus,
                         (x + 3 + 2*jWin) * sizeHaus, (y + 3 + 2*iWin) * sizeHaus);
            jWin += 2;
            }
        iWin += 2;
        }
    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle ((x + 7) * sizeHaus, (y + 15) * sizeHaus, (x +  9) * sizeHaus, (y + 19) * sizeHaus);
    }
