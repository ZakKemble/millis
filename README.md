A Lightweight Millisecond Time Keeping Library for AVR
======================================================

A lightweight library for keeping track of time with millisecond resolution. Mainly for use with an ATmega48/88/168/328, but should work with other AVRs with minor changes. Supports use of the 'unsigned long long' datatype for keeping track of time for 584.9 million years. Any clock frequency up to 20MHz can be used. Some frequencies may have a small amount of error, see the blog post linked below.

Even though Arduino has its own millis() time keeping, this library may be handy if running at clock frequencies at or below 8MHz or for timing for longer than 50 days.

http://blog.zakkemble.net/millisecond-tracking-library-for-avr/

Documentation
-------------

[Doxygen pages](http://zkemble.github.io/millis/)

---

Zak Kemble

contact@zakkemble.net
