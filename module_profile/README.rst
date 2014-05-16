Profile Module
=======================

:scope: General Use
:description: This module provides Motion profile generation and Profile control functions for position/velocity/torque control. 
:keywords: SOMANET, motor control, motion control, motion profile


The profile generator provides functions to define the acceleration, deceleration, 
slopes in some cases, velocity; and generates a profile to match these requirements.
Once initialized with these parameters the profile can be generated using respective
profile_generate function. Also profile generation for quick stop actions are provided.
Note: the profiles generated are limited by parameters like max acceleration, max 
profile velocity or max/min allowed target value for the profile.

The Profile control functions makes use of the profile generators to create motion 
profiles and communicates the profile with the respective control Server. 
