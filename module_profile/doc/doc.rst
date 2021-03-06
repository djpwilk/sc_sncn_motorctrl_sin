Profile Module
=======================
<a href="https://github.com/synapticon/sc_sncn_motorctrl_sin/blob/master/SYNAPTICON.md">
<img align="left" src="https://s3-eu-west-1.amazonaws.com/synapticon-resources/images/logos/synapticon_fullname_blackoverwhite_280x48.png"/>
</a>
<br/>
<br/>

This module provides Motion profile generation and Profile control functions for 
position/velocity/torque control. 

The profile generator provides functions to define the acceleration, deceleration, 
slopes in some cases, velocity; and generates a profile to match these requirements.
Once initialized with these parameters the profile can be generated using respective
profile_generate function. Also profile generation for quick stop actions are provided.
Note: the profiles generated are limited by parameters like max acceleration, max 
profile velocity or max/min allowed target value for the profile.

The Profile control functions makes use of the profile generators to create motion 
profiles and communicates the profile with the respective control Server. 

To include this module add module_profile to USED_MODULES in the application/test
makefile, and include header files: profile.h and profile_control.h

