/*
 * Project: Lightweight millisecond tracking library
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/millisecond-tracking-library-for-avr/
 */

// Blink 2 LEDs, one every 500ms and the other every 700ms

#include <avr/io.h>
#include <avr/interrupt.h>
#include "millis.h"

int main()
{
	// Initialize library
	millis_init();

	// Port D 2 and 3 as outputs
	DDRD |= _BV(DDD2)|_BV(DDD3);

	// Enable interrupts
	sei();

	// Variables for keeping time LEDs last changed
	millis_t lastChangeLed1 = 0;
	millis_t lastChangeLed2 = 0;

	while(1)
	{
		// Time now
		millis_t now = millis();

		// Has it been 500ms since last change for LED1?
		if(now - lastChangeLed1 >= 500)
		{
			// Toggle LED
			PORTD ^= _BV(PORTD2);
			
			// Store time
			lastChangeLed1 = now;
		}

		// Has it been 700ms since last change for LED2?
		if(now - lastChangeLed2 >= 700)
		{
			// Toggle LED
			PORTD ^= _BV(PORTD3);
			
			// Store time
			lastChangeLed2 = now;
		}
	}
}