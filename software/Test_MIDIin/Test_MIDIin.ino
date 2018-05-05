/*
 * Test_MIDIin.ino
 * 
 * Copyright 2018  Calvin A. Cherry (calvincherry@gmail.com)
 *                 calcium3000.wordpress.com
 * 
 * Adopted from PRJC's MIDI Library page
 * https://www.pjrc.com/teensy/td_libs_MIDI.html
 * 
 * For use with the Teensy MIDI Interface board
 * https://github.com/calcium3000/TeensyMIDIInterface
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
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
