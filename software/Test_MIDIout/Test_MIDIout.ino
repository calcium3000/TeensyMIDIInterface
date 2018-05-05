/*
 * Test_MIDIout.ino
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
