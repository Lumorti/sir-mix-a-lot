### History

A few years ago I made a [machine to mix cocktails](https://github.com/Lumorti/drink-182), but after testing it at a party I discovered a few things:

 - plumbing is hard, it leaked a lot
 - the cheap Raspberry Pi touchscreen was quite hard to press
 - flow rates for thin tubes aren't as high as you might think
 - it being gravity fed meant that the timings/pressures weren't constant at all
 - giving drunk people a long list of cocktails is too much pressure
 - making things out of wood is a lot of physical effort

So here I present the revised version: Sir Mix-a-Lot (no relation). This time it uses just an Arduino for simplicity, only uses four liquids for cost reasons, uses dials to choose the ratios rather than a touchscreen, and the pumps are peristalic meaning they don't need to be gravity fed. All of this housed inside a nice premade box.

### Usage

- use the dials to choose the amounts of each of the four liquids
- then use the button to pour it (stop button in case the glass starts overfilling)

### Photo

![Photo of the fixed machine](photo.jpg)

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



### FUn Combinations Of Four (FUCOFs)

- gin, tonic, lemonade, orange juice
- vodka, whiskey, lemonade, cola
