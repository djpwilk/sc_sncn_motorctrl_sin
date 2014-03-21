#include <xs1.h>
#include <internal_config.h>
#include <platform.h>

/**
 * 	\fn config_gpio(chanend c_gpio, int port_number, int switch_type)
 *  \brief Client enables configuration of digital I/Os as inputs or outputs,
 *  	   to read input ports and write to output ports.
 *  	   By default all IO ports act as outputs if not configured as inputs.
 *
 *  \param c_gpio channel used to configure any digital ports /and send commands  to read/write to port specified
 *  \param port_number selects a port to be configured: 0 - EXT_D0, 1 - EXT_D1, 2 - EXT_D2, 3 - EXT_D3, 4 - all EXT_D0, EXT_D1, EXT_D2, EXT_D3
 *  \param switch_type specifies type: Active High/Active Low when switch is closed
 *
 *  \return 1 - success
 *
 */
int config_gpio_digital_input(chanend c_gpio, int port_number, int input_type, int switch_type);

/**
 * 	\fn end_config_gpio(chanend c_gpio)
 *  \brief Disables further configuration of digital I/Os as inputs or outputs.
 *
 *  \param c_gpio channel used to configure any digital ports
 *  \return 1 - success
 *
 */
int end_config_gpio(chanend c_gpio);

/**
 * 	\fn read_gpio_digital_input(chanend c_gpio, int port_number)
 *  \brief Read digital input ports
 *
 *  \param c_gpio channel used to read ports
 *  \param port_number selects a port to be read  0 - EXT_D0, 1 - EXT_D1, 2 - EXT_D2, 3 - EXT_D3, 4 - all EXT_D0, EXT_D1, EXT_D2, EXT_D3
 *
 *  \return port value
 *
 */
int read_gpio_digital_input(chanend c_gpio, int port_number);

/**
 * 	\fn write_gpio_digital_output(chanend c_gpio, int port_number, int port_value)
 *  \brief Write to digital ports
 *
 *  \param c_gpio channel used to write ports
 *  \param port_number selects a port to write: 0 - EXT_D0, 1 - EXT_D1, 2 - EXT_D2, 3 - EXT_D3, 4 - all EXT_D0, EXT_D1, EXT_D2, EXT_D3
 *	\param port_value specify a value: 1/0 to drive port
 *
 */
void write_gpio_digital_output(chanend c_gpio, int port_number, int port_value);

