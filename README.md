#A lightweight millisecond time keeping library for AVR

A lightweight library for keeping track of time with millisecond resolution. Supports use of 'unsigned long long'
for keeping track of time for 584.9 million years. Any clock frequency up to 20MHz can be used. Some frequencies
may have a small amount of error.

Even though Arduino has its own millis() time keeping, this library may be handy if running at clock frequencies
at or below 8MHz or for timing for longer than 50 days.

##Documentation
<a href="http://zkemble.github.io/millis/">Doxygen pages</a>

--------

    http://blog.zakkemble.co.uk/millisecond-tracking-library-for-avr/

--------

Zak Kemble

contact@zakkemble.co.uk