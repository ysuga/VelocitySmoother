// -*- C++ -*-
/*!
 * @file  VelocitySmoother.cpp
 * @brief Velocity Smoother RTC
 * @date $Date$
 *
 * $Id$
 */

#include "VelocitySmoother.h"

// Module specification
// <rtc-template block="module_spec">
static const char* velocitysmoother_spec[] =
  {
    "implementation_id", "VelocitySmoother",
    "type_name",         "VelocitySmoother",
    "description",       "Velocity Smoother RTC",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Filte",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    // "conf.default.gain", "0.1",
	"conf.default.ax", "0.1",
	"conf.default.ay", "0.1",
	"conf.default.aa", "0.1",
    // Widget
    "conf.__widget__.gain", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
VelocitySmoother::VelocitySmoother(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
VelocitySmoother::~VelocitySmoother()
{
}



RTC::ReturnCode_t VelocitySmoother::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  //m_inIn.addConnectorDataListener(ON_BUFFER_WRITE,
	//			  new DataListener(this));
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  // bindParameter("gain", m_gain, "0.1");

  bindParameter("ax", m_ax, "0.1");
  bindParameter("ay", m_ay, "0.1");
  bindParameter("aa", m_aa, "0.1");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t VelocitySmoother::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocitySmoother::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocitySmoother::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t VelocitySmoother::onActivated(RTC::UniqueId ec_id)
{
	m_out.data.vx = m_out.data.vy = m_out.data.va = 0;
	m_outOut.write();

	m_in.data.vx = m_in.data.vy = m_in.data.va = 0;
	return RTC::RTC_OK;
}


RTC::ReturnCode_t VelocitySmoother::onDeactivated(RTC::UniqueId ec_id)
{
	m_out.data.vx = m_out.data.vy = m_out.data.va = 0;
	m_outOut.write();

	
  return RTC::RTC_OK;
}


RTC::ReturnCode_t VelocitySmoother::onExecute(RTC::UniqueId ec_id)
{
	if (m_inIn.isNew()) {
		m_inIn.read();
	}

	double dx = m_in.data.vx - m_out.data.vx;
	double dy = m_in.data.vy - m_out.data.vy;
	double da = m_in.data.va - m_out.data.va;

	if (dx > m_ax) m_out.data.vx += m_ax;
	else if (dx < -m_ax) m_out.data.vx -= m_ax;
	else m_out.data.vx = m_in.data.vx;

	if (dy > m_ay) m_out.data.vy += m_ay;
	else if (dy < -m_ay) m_out.data.vy -= m_ay;
	else m_out.data.vy = m_in.data.vy;

	if (da > m_aa) m_out.data.va += m_aa;
	else if (dx < -m_aa) m_out.data.va -= m_aa;
	else m_out.data.va = m_in.data.va;

	setTimestamp(m_out);
	m_outOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t VelocitySmoother::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocitySmoother::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocitySmoother::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocitySmoother::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VelocitySmoother::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void VelocitySmootherInit(RTC::Manager* manager)
  {
    coil::Properties profile(velocitysmoother_spec);
    manager->registerFactory(profile,
                             RTC::Create<VelocitySmoother>,
                             RTC::Delete<VelocitySmoother>);
  }
  
};


