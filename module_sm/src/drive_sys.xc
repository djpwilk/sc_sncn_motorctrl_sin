/**
 * drive_sys.xc
 *
 *  Created on: Jul 12, 2013
 *      Author: pkanajar
 */

#include <drive_config.h>
#include <internal_config.h>
#include <print.h>
//#define print_slave
int read_controlword_switch_on(int control_word) {
	return (control_word & SWITCH_ON_CONTROL);
}

int read_controlword_quick_stop(int control_word) {
	return (~((control_word & QUICK_STOP_CONTROL) >> 2) & 0x1);
}

int read_controlword_enable_op(int control_word) {
	return (control_word & ENABLE_OPERATION_CONTROL) >> 3;
}

int read_controlword_fault_reset(int control_word) {
	return (control_word & FAULT_RESET_CONTROL) >> 7;
}

bool __check_commutation_init(chanend c_signal)
{
	bool init_state;
	c_signal <: CHECK_BUSY;
	c_signal :> init_state;
	return init_state;
}

bool __check_hall_init(chanend c_hall)
{
	bool init_state;
	c_hall <: CHECK_BUSY;
	c_hall :> init_state;
	return init_state;
}

bool __check_qei_init(chanend c_qei)
{
	bool init_state;
	c_qei <: CHECK_BUSY;
	c_qei :> init_state;
	return init_state;
}

bool __check_adc_init()
{
	return 0;
}

bool __check_torque_init(chanend c_torque_ctrl)
{
	bool init_state;
	c_torque_ctrl <: CHECK_BUSY;
	c_torque_ctrl :> init_state;
	return init_state;
}
bool __check_velocity_init(chanend c_velocity_ctrl)
{
	bool init_state;
	c_velocity_ctrl <: CHECK_BUSY;
	c_velocity_ctrl :> init_state;
	return init_state;
}
bool __check_position_init(chanend c_position_ctrl)
{
	bool init_state;
	c_position_ctrl <: CHECK_BUSY;
	c_position_ctrl :> init_state;
	return init_state;
}

check_list init_checklist(void)
{
	check_list check_list_param;
	check_list_param._adc_init = INIT_BUSY;
	check_list_param._commutation_init = INIT_BUSY;
	check_list_param._hall_init = INIT_BUSY;
	check_list_param._position_init = INIT_BUSY;
	check_list_param._qei_init = INIT_BUSY;
	check_list_param._torque_init = INIT_BUSY;
	check_list_param._velocity_init = INIT_BUSY;

	check_list_param.mode_op = false;
	check_list_param.fault = false;
	check_list_param.operation_enable = false;
	check_list_param.ready = false;
	check_list_param.switch_on = false;
	return check_list_param;
}

void update_checklist(check_list &check_list_param, int mode, chanend c_commutation, chanend c_hall, chanend c_qei,
		chanend c_adc, chanend c_torque_ctrl, chanend c_velocity_ctrl, chanend c_position_ctrl)
{
	bool check;
	bool skip = true;
	check =  check_list_param._commutation_init // & check_list_param._fault check_list_param._adc_init &
			& check_list_param._hall_init & check_list_param._qei_init;
	switch(check)
	{
		case INIT_BUSY:
			if(~check_list_param._commutation_init)
			{
				check_list_param._commutation_init = __check_commutation_init(c_commutation);
				if(check_list_param._commutation_init)
					skip = false;
			}
			if(~skip && ~check_list_param._adc_init)
			{
				check_list_param._adc_init = __check_adc_init();
			}
			if(~skip && ~check_list_param._hall_init)
			{
				check_list_param._hall_init = __check_hall_init(c_hall);
			}
			if(~skip &&  ~check_list_param._qei_init)
			{
				check_list_param._qei_init = __check_qei_init(c_qei);
			}
			break;
		case INIT:
			if(~check_list_param._torque_init && mode == 1)
			{
				check_list_param._torque_init = __check_torque_init(c_torque_ctrl);
			}
			if(~check_list_param._velocity_init && mode == 2)
			{
				check_list_param._velocity_init = __check_velocity_init(c_velocity_ctrl);
			}
			if(~check_list_param._position_init && mode == 3)
			{
				check_list_param._position_init = __check_position_init(c_position_ctrl);
			}
			break;
	}
	if(check_list_param._commutation_init && ~check_list_param.fault)
	{
		check_list_param.ready = true;
	}
	if(check_list_param.ready && check_list_param._hall_init && check_list_param._qei_init && ~check_list_param.fault)
	{
		check_list_param.switch_on = true;
		check_list_param.mode_op = true;
		check_list_param.operation_enable = true;
	}
}

int init_state(void) {
	return 1;
}

/**
 *
 */
int update_statusword(int current_status, int state_reached, int ack, int q_active, int shutdown_ack) {
	int status_word;

	switch (state_reached) {
	case 1:
		status_word = current_status & ~READY_TO_SWITCH_ON_STATE
				& ~SWITCHED_ON_STATE & ~OPERATION_ENABLED_STATE
				& ~VOLTAGE_ENABLED_STATE;
		break;

	case 7:
		status_word = (current_status & ~OPERATION_ENABLED_STATE
				& ~SWITCHED_ON_STATE & ~VOLTAGE_ENABLED_STATE
				& ~SWITCH_ON_DISABLED_STATE) | READY_TO_SWITCH_ON_STATE;
		break;

	case 2:
		status_word = (current_status & READY_TO_SWITCH_ON_STATE
				& ~OPERATION_ENABLED_STATE & ~SWITCHED_ON_STATE
				& ~VOLTAGE_ENABLED_STATE) | SWITCH_ON_DISABLED_STATE;
		break;

	case 3:
		status_word = (current_status & ~SWITCH_ON_DISABLED_STATE
				& ~OPERATION_ENABLED_STATE) | SWITCHED_ON_STATE
				| VOLTAGE_ENABLED_STATE;
		break;

	case 4:
		status_word = current_status | OPERATION_ENABLED_STATE;
		break;

	case 5:
		status_word = current_status | FAULT_STATE;
		break;

	case 6:
		status_word = current_status | QUICK_STOP_STATE;
		break;

	}
	if(q_active == 1)
		return status_word & (~QUICK_STOP_STATE);
	if(shutdown_ack == 1)
		return status_word & (~VOLTAGE_ENABLED_STATE);
	if(ack == 1)
		return status_word|TARGET_REACHED;
	else if(ack == 0)
		return status_word & (~TARGET_REACHED);
	return status_word;
}

int get_next_state(int in_state, check_list &checklist, int controlword) {
	int out_state;
	int ctrl_input;

	switch (in_state) {
	case 1:

		if (checklist.fault == true)
			out_state = 5;
		else if (checklist.ready == false)
			out_state = 2;
		else if (checklist.ready == true)
			out_state = 7;
#ifdef print_slave
		printstr("updated state ");
		printhexln(in_state);
#endif
		break;

	case 2:
		if (checklist.fault == true)
			out_state = 5;
		else if (checklist.ready == false)
			out_state = 1;
		else if (checklist.ready == true)
			out_state = 7;
#ifdef print_slave
		printstr("updated state ");
		printhexln(in_state);
#endif
		break;

	case 7:
		ctrl_input = read_controlword_switch_on(controlword);
		if (checklist.fault == true)
			out_state = 5;
		else if (checklist.switch_on == false)
			out_state = 7;
		else if (checklist.switch_on == true)
			if (ctrl_input == false)
				out_state = 7;
			else if (ctrl_input == true)
				out_state = 3;
#ifdef print_slave
		printstr("updated state ");
		printhexln(in_state);
#endif
		break;

	case 3:
		ctrl_input = read_controlword_enable_op(controlword);
		if (checklist.fault == true)
			out_state = 5;
		else if (checklist.switch_on == false)
			out_state = 3;
		else if (checklist.switch_on == true)
			if (ctrl_input == false)
				out_state = 3;
			else if (ctrl_input == true)
				out_state = 4;
#ifdef print_slave
		printstr("updated state ");
		printhexln(in_state);
#endif
		break;

	case 4:
		ctrl_input = read_controlword_quick_stop(controlword); //quick stop
		if (checklist.fault == true)
			out_state = 5;
		else if (ctrl_input == false)
			out_state = 4;
		else if (ctrl_input == true) /*quick stop*/
			out_state = 6;
#ifdef print_slave
		printstr("updated state ");
		printhexln(in_state);
#endif
		break;

	case 5:
		ctrl_input = read_controlword_fault_reset(controlword);
		if (ctrl_input == false)
			out_state = 5;
		else if (ctrl_input == true)
			out_state = 2;
#ifdef print_slave
		printstr("updated state ");
		printhexln(in_state);
#endif
		break;

	case 6:
		if (checklist.fault == true)
			out_state = 5;
		//else
		//	out_state = 2;
#ifdef print_slave
		printstr("updated state ");
		printhexln(in_state);
#endif
		break;

	default:
		if (checklist.fault == true)
			out_state = 5;
		break;
	}
	return out_state;
}


