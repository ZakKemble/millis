/*
 * Project: Lightweight millisecond tracking library
 * Author: Zak Kemble, contact@zakkemble.net
 * Copyright: (C) 2018 by Zak Kemble
 * License: GNU GPL v3 (see License_GPL-3.0.txt) or MIT (see License_MIT.txt)
 * Web: http://blog.zakkemble.net/millisecond-tracking-library-for-avr/
 */

// Blink 2 LEDs, one every 500ms and the other every 700ms

#include <millis.h>

#define LED1_PIN 2
#define LED2_PIN 3

void setup()
{
	// Initialize library
	millis_init();

	// Config outputs
	pinMode(LED1_PIN, OUTPUT);
	pinMode(LED2_PIN, OUTPUT);
}

void loop()
{
	// Variables for keeping time LEDs last changed
	static millis_t lastChangeLed1 = 0;
	static millis_t lastChangeLed2 = 0;
	static bool stateLed1 = LOW;
	static bool stateLed2 = LOW;

	// Time now
	millis_t now = millis_get();

	// Has it been 500ms since last change for LED1?
	if(now - lastChangeLed1 >= 500)
	{
		// Toggle LED
		stateLed1 = !stateLed1;
		digitalWrite(LED1_PIN, stateLed1);
		
		// Store time
		lastChangeLed1 = now;
	}

	// Has it been 700ms since last change for LED2?
	if(now - lastChangeLed2 >= 700)
	{
		// Toggle LED
		stateLed2 = !stateLed2;
		digitalWrite(LED2_PIN, stateLed2);
		
		// Store time
		lastChangeLed2 = now;
	}
}