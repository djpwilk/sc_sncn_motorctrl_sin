SOMANET Motor Commutation Controller
====================================

:scope: General Use
:description: This module provides driver for the BLDC Motor connected to the interface module (IFM).
:keywords: SOMANET, motor control, sinusoidal commutation
 
The module consists of commutation which internally makes use of the predriver to 
drive fets and configurations under pwm. The module provides Commutation server thread 
which acquires position information from the Hall server and commutates the motor 
in a while loop; and provides client functions to optimize motor commutation with 
commutation offsets, motor winding types, nominal motor speed and number of pole pairs; 
set input voltage for the motor, get fet_state from the Commutation Server.
