# KPK-Multik
### Мультфильм "Долгожданная встреча"
Мультфильмы близки каждому человеку с детства. Они учат детей простым и понятным языком анимации серьёзным вещам. Что если самому создать мультик и при этом же научиться программированию?
Вашему вниманию проект мультфильма «Долгожданная встреча».
![](https://github.com/Nielra/KPK-Multik/blob/main/Название.gif?raw=true)
Данный проект состоит из трех частей: 

 * сцена прилета ![](https://github.com/Nielra/KPK-Multik/blob/main/Arrival.gif?raw=true)
 * город ![](https://github.com/Nielra/KPK-Multik/blob/main/City.gif?raw=true)
 * встреча ![](https://github.com/Nielra/KPK-Multik/blob/main/Meet.gif?raw=true)

Основные объекты проекта - девочки, самолет, автобус; фоновые - здания, мост, памятник, дорога и другие.
В работе используется библиотека TXLib, которая достаточно легко воспринимается на начальном этапе освоения прорграммирования. 
Чтобы создать подобный мультфильм, предварительно нужно установить Code Blocks и библиотеку TXLib с сайта http://ded32.net.ru. Затем написать сценарий, придумать персонажей. Объекты рисуются на координатной плоскости линиями, прямоугольниками, окружностями и другими фигурами. Учтите, что начало координат в левом верхнем углу. «Оживление» персонажа происходит путем его перерисовки с небольшими изменениями. Наверняка, каждый пробовал рисовать человечка в небольшом блокноте, потом быстро перелистывал, заставляя человечка бежать. Удобно, когда объект задается функцией с параметрами, изменение которых приведет к движению. И тут не лишним будет вспомнить прямолинейное движение из курса физики. 
Например, функция рисования облака: 
`void DrawCloud (int x, int y, double sizeCloud)
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txEllipse (ROUND( x           * sizeCloud), ROUND((y + 20) * sizeCloud), ROUND((x + 40) * sizeCloud),
                     ROUND((y + 40) * sizeCloud));
    txEllipse (ROUND((x + 20) * sizeCloud), ROUND( y           * sizeCloud), ROUND((x + 80) * sizeCloud),
                     ROUND((y + 40) * sizeCloud));
    txEllipse (ROUND((x + 20) * sizeCloud), ROUND((y + 30) * sizeCloud), ROUND((x + 60) * sizeCloud),
                     ROUND((y + 50) * sizeCloud));
    }`
Вызываем ее в цикле:
`DrawCloud (190 - t/9 * 10, 10, 0.8);` 
И облако поплывет.
В мультфильм можно добавлять тест, звук. 
Дерзайте и у вас всё получится!
