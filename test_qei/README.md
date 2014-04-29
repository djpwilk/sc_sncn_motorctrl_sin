test_qei.xc illustrates the usage of \ref module_qei to get position and calculate velocity information.

<table class="core_usage" align="center" cellpadding="5" width="20%">
<tr>
    <th colspan="2">CORE use</th>
</tr>
<tr>
    <td>Parallel \b THREADS</td>
    <td width="30px" align="center"> 2 </td>
</tr>
<tr>
    <td>\b TILES used</td>
    <td width="30px" align="center"> 2 </td>
 </tr>
</table>

<table  class="hw_comp" align="center" cellpadding="2" width="50%">
<tr align="center">
    <th colspan="3">HW compatibility</th>
  <tr align="center">
    <th>COM</th>
    <th>CORE</th>
    <th>IFM</th>
  </tr>
  <tr align="center">
    <td>*</td>
    <td>C21-DX</td>
   <td>Drive DC 100</td>
 </tr>
  <tr align="center">
    <td></td>
    <td>C22</td>
    <td>Drive DC 300</td>
  </tr>
</table>

<br/>
<br/>
<br/>
<br/>
<br/>
<br/>

- \b THREADS: QEI Server, QEI Client.
- \b TILES:

	#define TILE_ONE 0
	#define IFM_TILE 3

\b TILE_ONE: It takes care of the client side function. Since these functions do not require any port access, any free TILE could run them.

	on stdcore[TILE_ONE]:

- \b Thread: QEI Client

	qei_test(c_qei_p1);

The client reads position fron QEI Server and calculates velocity from the position info. Read more at \ref module_qei.

\b IFM_TILE (3 by default): It executes the server side functions, controlling the interfaces. These functions need access to the Interface Module (IFM), so just the tile that provides access to the \b IFM ports can run these functions.  

	on stdcore[IFM_TILE]:

- \b Thread: QEI Server

	qei_par qei_params;
	init_qei_param(qei_params);
	run_qei(c_qei_p1, c_qei_p2, c_qei_p3, c_qei_p4, 
		c_qei_p5, c_qei_p6, p_ifm_encoder, qei_params); // channel priority 1,2..6

QEI Server that captures the signals on the sensor. Read more at \ref module_qei.

\b Please, do not forget to set properly your node and motor configuration when using this application.

- <a href="">Configure your node</a> 
- \ref how_configure_motors

More information about QEI Server/ Client can be found at \ref module_qei.

Other dependancies: sc_somanet-base/module_nodeconfig, \ref module_blocks, \ref module_common

\b See \b also:

- <a href="http://doc.synapticon.com/wiki/index.php/Category:Getting_Started_with_SOMANET">Getting started with SOMANET</a>  