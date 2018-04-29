/*
 * https://www.pjrc.com/teensy/td_libs_MIDI.html
 */

#include <MIDI.h>


MIDI_CREATE_INSTANCE( HardwareSerial, Serial1, MIDI );
const byte channel = 1;


void setup()
{
  MIDI.begin();
}

void loop()
{
  byte note;
  for( note = 10; note <= 127; note++ )
  {
    MIDI.sendNoteOn( note, 100, channel );
    delay( 50 );
    MIDI.sendNoteOff( note, 100, channel );
  }
  
  delay( 2000 );
}
