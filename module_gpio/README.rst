SOMANET General Purpose I/O 
===========================

:scope: General Use
:description: This module provides driver for the GPIO digital ports on the interface module (IFM) 
:keywords: SOMANET, motor control, quadrature encoder


The server acquires analog input data in a loop:

   * configures the GPIO ports; 
   * read/write GPIO  digital ports in a while loop
   * provides client functions to configure ports and read/write ports. 
