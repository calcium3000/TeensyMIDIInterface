/*
 * https://www.pjrc.com/teensy/td_libs_MIDI.html
 */

#include <MIDI.h>

#define INACTIVE_MS     10000


MIDI_CREATE_INSTANCE( HardwareSerial, Serial1, MIDI );
unsigned long t = 0;


void setup()
{
  MIDI.begin( MIDI_CHANNEL_OMNI );
  Serial.begin( 57600 );
  Serial.println( "MIDI Input Test" );
}


void loop()
{
  int note, velocity, channel, d1, d2;
  
  if( MIDI.read() )
  {
    byte type = MIDI.getType();
    
    switch( type )
    {
      case midi::NoteOn:
        note = MIDI.getData1();
        velocity = MIDI.getData2();
        channel = MIDI.getChannel();
        if( velocity > 0 )
        {
          Serial.println( String( "Note On:  ch=" ) + channel + ", note=" + note + ", velocity=" + velocity );
        }
        else
        {
          Serial.println( String( "Note Off: ch=" ) + channel + ", note=" + note );
        }
        break;
        
      case midi::NoteOff:
        note = MIDI.getData1();
        velocity = MIDI.getData2();
        channel = MIDI.getChannel();
        Serial.println( String( "Note Off: ch=") + channel + ", note=" + note + ", velocity=" + velocity );
        break;
        
      default:
        d1 = MIDI.getData1();
        d2 = MIDI.getData2();
        Serial.println( String( "Message, type=") + type + ", data = " + d1 + " " + d2 );
    }
    
    t = millis();
  }
  
  if ( millis() - t > INACTIVE_MS )
  {
    t += INACTIVE_MS;
    Serial.println( "(inactivity)" );
  }

  delay( 10 );
}
