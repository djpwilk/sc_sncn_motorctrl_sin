SOMANET Sinusoidal Motor Control Components
===========================================

Implementation of Sinusoidal Motor Control for BLDC drives on SOMANET devices.

* [How to?](https://github.com/synapticon/sc_sncn_motorctrl/tree/master/howto)

Key Features
------------

   * Sinusoidal Commutation
   * Profile Position Control 
   * Profile Velocity Control
   * Profile Torque Control
   * Homing feature
   * Ethercat Operating Modes
   * Support QEI sensor with Index/ no Index
   * Support Hall sensor
   * Support Analog sensor 
   * Support GPIO Digital
   * Precise position control based on position sensor ticks

Content
-------

| Module        				| Demo          						|
| :-------------: 				|:-------------							|
| [module_adc][module_adc]      		| [test_adc_external_input][test_adc_external_input] 		|
| [module_blocks][module_blocks] 		|       							|
| [module_comm][module_comm]	 		|     								|
| [module_common][module_common]		|     								|
| [module_commutation][module_commutation]	|								|
| [module_ctrl_loops][module_ctrl_loops]	| [test_position-ctrl][test_position-ctrl] [test_velocity-ctrl][test_velocity-ctrl] [test_torque-ctrl][test_torque-ctrl]	|
| [module_ecat_drive][module_ecat_drive]	| [test_ethercat-motorctrl-mode][test_ethercat-motorctrl-mode]	|
| [module_gpio][module_gpio]			| [test_gpio_digital][test_gpio_digital] [test_homing][test_homing] 	|
| [module_hall][module_hall]			| [test_hall][test_hall]					|
| [module_profile][module_profile]		|								|
| [module_qei][module_qei]			| [test_qei][test_qei]						|
| [module_sm][module_sm]			|								|


Required software (dependencies)
---------
  * [sc_somanet-base](https://github.com/synapticon/sc_somanet-base) 
  * [sc_pwm](https://github.com/synapticon/sc_pwm)
  * [sc_sncn_ethercat](https://github.com/synapticon/sc_sncn_ethercat) (only if using Ethercat Operating Modes)


