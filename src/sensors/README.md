# Virtual Motor Controller Sensor Fusion Module

## Using LCG (Linear Congruential Generator) for Noise file

Forumal LCG follows:

$seed_{n+1} = (a \cdot seed_n + c) \bmod m $

Where:

$a$ -> multiplier

$c$ -> increment

$m$ -> modulus

## Constants 

Reason for using 214013 and 2531011 initially:

These numbers come from Microsoft Vigual C++ runtime's rand() implementation. LCG pairs. 

For 32767: This is the maximum value of 15 bit integer. Allows LCG to extract 15 bits of randomness from the seed. Dividing with this number also normalizes random value into range : 0.0 -> 1.0

## Improvements for later...
- Use Gaussian Nosie
- Bias dift
- Axis misalignment

