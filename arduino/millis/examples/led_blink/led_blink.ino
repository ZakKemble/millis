/*
 * Project: Lightweight millisecond tracking library
 * Author: Zak Kemble, me@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/millisecond-tracking-library-for-avr/
 */

// Blink 2 LEDs, one every 500ms and the other every 700ms

#include <millis.h>

void setup()
{
	// Initialize library
	millis_init();

	// Config outputs
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
}

void loop()
{
	// Variables for keeping time LEDs last changed
	static millis_t lastChangeLed1 = 0;
	static millis_t lastChangeLed2 = 0;
	static bool stateLed1 = LOW;
	static bool stateLed2 = LOW;

	// Time now
	millis_t now = millis();

	// Has it been 500ms since last change for LED1?
	if(now - lastChangeLed1 > 500)
	{
		// Toggle LED
		stateLed1 = !stateLed1;
		digitalWrite(2, stateLed1);
		
		// Store time
		lastChangeLed1 = now;
	}

	// Has it been 700ms since last change for LED2?
	if(now - lastChangeLed2 > 700)
	{
		// Toggle LED
		stateLed2 = !stateLed2;
		digitalWrite(3, stateLed2);
		
		// Store time
		lastChangeLed2 = now;
	}
}