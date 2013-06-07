/*
 * File:    qei_server.h
 *
 * The copyrights, all other intellectual and industrial 
 * property rights are retained by XMOS and/or its licensors. 
 * Terms and conditions covering the use of this code can
 * be found in the Xmos End User License Agreement.
 *
 * Copyright XMOS Ltd 2013
 *
 * In the case where this code is a modification of existing code
 * under a separate license, the separate license terms are shown
 * below. The modifications to the code are still covered by the 
 * copyright notice above.
 *
 */


#ifndef __QEI_SERVER_H__
#define __QEI_SERVER_H__
#include <xs1.h>

/**
 * \brief Implementation of the QEI server thread
 *
 * \param c_qei The control channel used by the client
 * \param p_qei The hardware port where the quadrature encoder is located
 *
 *
 */
void run_qei (  chanend c_qei, port in p_qei );

#endif /*__QEI_SERVER_H__ */
