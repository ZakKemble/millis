/*
 * Project: Lightweight millisecond tracking library
 * Author: Zak Kemble, me@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/millisecond-tracking-library-for-avr/
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>
#include "millis.h"

#ifndef F_CPU
	#error "F_CPU not defined!"
#endif

// If you use a different timer it may have different prescaler settings

// Decide what what prescaler to use and how many ticks there should be
#if F_CPU > 16320000 // 16.32MHz - 32.64MHz
	#define CLOCKSEL ((1<<CS22)|(1<<CS20))
	#define PRESCALER 128
#elif F_CPU > 8160000 // 8.16MHz - 16.32MHz
	#define CLOCKSEL (1<<CS22)
	#define PRESCALER 64
#elif F_CPU > 2040000 // 2.04MHz - 8.16MHz
	#define CLOCKSEL ((1<<CS21)|(1<<CS20))
	#define PRESCALER 32
#elif F_CPU > 255 // 256Hz - 2.04MHz
	#define CLOCKSEL (1<<CS21)
	#define PRESCALER 8
#else
	#error "Bad F_CPU setting (<256 or >=32640000)"
#endif
#define TICKS ((F_CPU / PRESCALER) / 1000)

static volatile millis_t milliseconds = 0;

// Initialize library
void millis_init()
{
	// Timer 2 settings for millisecond tracking
	TCCR2A = (1<<WGM21);
	TCCR2B = CLOCKSEL;
	TIMSK2 = (1<<OCIE2A);
	OCR2A = TICKS;
}

// Get current milliseconds
millis_t millis_get()
{
	millis_t ms;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		ms = milliseconds;
	}
	return ms;
}

// Turn on timer and resume time keeping
void millis_resume()
{
	power_timer2_enable();
	TIMSK2 |= (1<<OCIE2A);
}

// Pause time keeping and turn off timer to save power
void millis_pause()
{
	TIMSK2 &= ~(1<<OCIE2A);
	power_timer2_disable();
}

// Reset milliseconds count to 0
void millis_reset()
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		milliseconds = 0;
	}
}

// Add time
void millis_add(millis_t ms)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		milliseconds += ms;
	}
}

// Subtract time
void millis_subtract(millis_t ms)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		milliseconds -= ms;
	}
}

ISR(TIMER2_COMPA_vect)
{
	++milliseconds;
}
