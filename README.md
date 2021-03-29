# Qt-charts

Simple charts based on QGraphicsView and QGraphicsItems.
No need to use QCharts library.

Data for graphics loaded from web page:
https://www.finam.ru/profile/akcii-usa-bats/american-express/export/
https://www.finam.ru/profile/akcii-usa-bats/3m-co/export/

If you wish to load another paper, then follow this view while loading from www.finam.ru
<TICKER>	<PER>	<DATE>	<TIME>	<OPEN>	<HIGH>	<LOW>	<CLOSE>	<VOL>
3M	1	03/01/17	17:31:00	179.1900000	179.2900000	179.1500000	179.2900000	3240
3M	1	03/01/17	17:32:00	179.2400000	179.6500000	179.2400000	179.6300000	700
3M	1	03/01/17	17:33:00	179.6499000	180.0000000	179.6499000	179.9300000	9249
3M	1	03/01/17	17:34:00	179.9700000	179.9700000	179.8800000	179.8800000	700
3M	1	03/01/17	17:35:00	179.8700000	179.9100000	179.7900000	179.9100000	1599
3M	1	03/01/17	17:36:00	179.9100000	179.9700000	179.5300000	179.5300000	2000

There are 3 view of interval graphic:
Candlenar:
![gif](/doc/candlebar-chart.gif)
Rabgenar and Line chart:
![gif](/doc/stickbar-chart.gif)

Also available volume chart:
![gif](/doc/volume.gif)

Cross cursor and Fibbonacci lines:
![gif](/doc/cursor-fibbonacci.gif)

And average true range line:
![gif](/doc/atr-line.gif)
