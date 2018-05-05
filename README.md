# Teensy MIDI Interface
MIDI interface for the Teensy 3.2 development board

## Hardware
This board provides standard MIDI IN, OUT, and THRU ports that connect to the [PJRC Teensy 3.2](https://www.pjrc.com/teensy/) development board.  Connections follow the MIDI standard -- i.e. optoisolation on the IN port, standard 5mA signals, etc.  For more information, see the [MIDI 1.0 Specification](https://www.midi.org/specifications/item/the-midi-1-0-specification).

In addition, all pins on the perimeter of the Teensy are broken out for easier access and prototyping.  Footprints for a 5V, 1A regulator and associated components are provided for stand-alone operation.

**Warning:** Disconnect external power source when connected to USB.

### Connections
`MIDI_IN` is connected to `D0/RX1` for use with the `Serial1` library.

`MIDI_OUT` is connected to `D1/TX1`, ditto with `Serial1`.

### License
All source files are released under the [TAPR Open Hardware License](http://tapr.org/ohl).  See `LICENSE.txt` for a copy of the license.

## Software
Provided are two test programs for MIDI input and MIDI output configurations.  Both are adopted from [ PRJC's MIDI Library](https://www.pjrc.com/teensy/td_libs_MIDI.html) page.  More specific examples to come!

### License
All source files are released under the [GNU General Public License](https://www.gnu.org/licenses/gpl.html).  See `LICENSE.txt` for a copy of the license.