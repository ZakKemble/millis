/*
 * Project: Lightweight millisecond tracking library
 * Author: Zak Kemble, me@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/millisecond-tracking-library-for-avr/
 */

// Set data type
// Data type			- Max time span			- Memory used
// unsigned char		- 255 milliseconds		- 1 byte
// unsigned int			- 65.54 seconds			- 2 bytes
// unsigned long		- 49.71 days			- 4 bytes
// unsigned long long	- 584.9 million years	- 8 bytes
typedef unsigned long millis_t;

// Don't use alias if library is being used with Arduino, since millis() is already used
#ifndef ARDUINO
	#define millis() millis_get()
#endif

// Initialize library
void millis_init();

// Get current milliseconds
millis_t millis_get();

// Turn on timer and resume time keeping
void millis_resume();

// Pause time keeping and turn off timer to save power
void millis_pause();

// Reset milliseconds count to 0
void millis_reset();

// Add time
void millis_add(millis_t);

// Subtract time
void millis_subtract(millis_t);
