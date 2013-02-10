A lightweight millisecond time keeping library for AVR
======================================================

A lightweight library for keeping track of time to millisecond accuracy, supports use of 'unsigned long long'
to keep track of time for 584.9 million years, any clock frequency up to 20MHz can be used, some frequencies
may have a small amount of error.

Even though Arduino has its own millis() time keeping, this library may be handy if running at clock frequencies
at or below 8MHz or for running longer than 50 days.

    http://blog.zakkemble.co.uk/millisecond-tracking-library-for-avr/

--------

Zak Kemble
me@zakkemble.co.uk