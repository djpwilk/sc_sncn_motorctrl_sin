SOMANET Quadtraure Encoder Interface
====================================

:scope: General Use
:description: Interface and processing for Quadrature encoders used with SOMANET 
:keywords: SOMANET, motor control, quadrature encoder

This module provides driver for the Incremental Encoders connected to the interface 
module (IFM). The module provides QEI server thread which acquires position 
information from the Incremental encoder in quadrature mode in a while loop; and 
provides client functions to configure QEI Server with encoder resolution, encoder 
type, polarity and max ticks; get position from QEI Server and to calculate velocity 
from the QEI position.
