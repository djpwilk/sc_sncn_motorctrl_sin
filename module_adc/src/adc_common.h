/*
 * \file adc_common.h
 *
 * The copyrights, all other intellectual and industrial 
 * property rights are retained by XMOS and/or its licensors. 
 * Terms and conditions covering the use of this code can
 * be found in the Xmos End User License Agreement.
 *
 * Copyright XMOS Ltd 2010
 *
 * In the case where this code is a modification of existing code
 * under a separate license, the separate license terms are shown
 * below. The modifications to the code are still covered by the 
 * copyright notice above.
 *
 **/                                   
#ifndef __ADC_COMMON_H__
#define __ADC_COMMON_H__

#ifdef __dsc_config_h_exists__
#include <dsc_config.h>
#endif

#ifndef NUMBER_OF_MOTORS
#define NUMBER_OF_MOTORS 1
#endif

// The number of trigger channels coming from PWM units
#define ADC_NUMBER_OF_TRIGGERS NUMBER_OF_MOTORS

// Count of the number of elements in the ADC filter array
#define ADC_FILT_SAMPLE_COUNT 31

typedef struct calibration {
	int Ia_calib;
	int Ib_calib;
	int Ic_calib;
} calib_data;

#endif /* __ADC_COMMON_H__ */
