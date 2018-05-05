/*
 * https://www.pjrc.com/teensy/td_libs_MIDI.html
 */

#include <MIDI.h>

#define TEST_CHANNEL      1
#define TEST_VELOCITY     100

#define NOTE_MIN          1
#define NOTE_MAX          127

#define NOTE_DURATION     1000
#define PAUSE_DURATION    2000


MIDI_CREATE_INSTANCE( HardwareSerial, Serial1, MIDI );


void setup()
{
  MIDI.begin();
}


void loop()
{
  byte note;
  for( note = NOTE_MIN; note <= NOTE_MAX; note++ )
  {
    MIDI.sendNoteOn( note, TEST_VELOCITY, TEST_CHANNEL );
    delay( NOTE_DURATION );
    MIDI.sendNoteOff( note, TEST_VELOCITY, TEST_CHANNEL );
  }
  
  delay( PAUSE_DURATION );
}
