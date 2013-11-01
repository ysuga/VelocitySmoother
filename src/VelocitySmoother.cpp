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
    "conf.default.gain", "1.0",
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
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("gain", m_gain, "1.0");
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
  return RTC::RTC_OK;
}


RTC::ReturnCode_t VelocitySmoother::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t VelocitySmoother::onExecute(RTC::UniqueId ec_id)
{
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


