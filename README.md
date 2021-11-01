### Background

A few years ago I made a [machine to mix cocktails](https://github.com/Lumorti/drink-182), but after testing it at a party it didn't work as well as I expected, due to various issues with leakage and the touch screen not working well. So here I present the revised version: Sir Mix-a-Lot (no relation). This time it uses just an Arduino for simplicity, only uses four liquids for cost reasons, uses dials to choose the ratios rather than a touchscreen, and the pumps are peristalic meaning they don't need to be gravity fed. All of this housed inside a simple cardboard box (to avoid having to saw wood like last time).

### Photo taken just before the debut Halloween party

![Photo of the machine](photo.jpg)

### Usage

- use the dials to choose the amounts of each of the four liquids (between 0 and 180 ml)
- use the go button to pour it 
- use the stop button if you want only a partial pour

### Diagram

![Circuit diagram for this project](plan.png)

### Parts Required

- standard Arduino
- power supply (12 V, 3 A)
- optocoupler with at least 4 channels
- 2 buttons
- 4 potentiometers
- 4 peristaltic pumps (12 V)
- silicon tubing of the same dimension of the pump (I used 3 mm * 5 mm)
- resistors and jumper cables for general wiring

