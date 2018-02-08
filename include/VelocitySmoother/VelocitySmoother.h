// -*- C++ -*-
/*!
 * @file  VelocitySmoother.h
 * @brief Velocity Smoother RTC
 * @date  $Date$
 *
 * $Id$
 */

#ifndef VELOCITYSMOOTHER_H
#define VELOCITYSMOOTHER_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>
#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/ConnectorListener.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

using namespace RTC;




 
/*!
 * @class VelocitySmoother
 * @brief Velocity Smoother RTC
 *
 */
class VelocitySmoother
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  VelocitySmoother(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~VelocitySmoother();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  gain
   * - DefaultValue: 1.0
   */
  float m_gain;

  float m_ax;
  float m_ay;
  float m_aa;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedVelocity2D m_in;
  /*!
   */
  InPort<RTC::TimedVelocity2D> m_inIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedVelocity2D m_out;
  /*!
   */
  OutPort<RTC::TimedVelocity2D> m_outOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>
public:
  void writeVelocity(double vx, double vy, double vz) {
    m_out.data.vx = vx;
    m_out.data.vy = vy;
    m_out.data.va = vz;
    m_outOut.write();
  }

  double getGain() {
    return m_gain;
  }

};


class DataListener
  : public ConnectorDataListenerT<RTC::TimedVelocity2D>
{
public:
  DataListener(VelocitySmoother* rtc) : m_parent(rtc), vx(0), vy(0), vz(0) {}
  virtual ~DataListener()
  {
    //std::cout << "dtor of " << m_name << std::endl;
  }

  virtual void operator()(const ConnectorInfo& info,
                          const RTC::TimedVelocity2D& data)
  {
    static int stdout_counter;
    double gain = m_parent->getGain();
    double dvx = data.data.vx - vx;
    if (dvx < 0 && dvx < -gain) { dvx = -gain; }
    else if (dvx > 0 && dvx > gain) { dvx = gain; }
    vx += dvx;


    double dvz = data.data.va - vz;
    if (dvz < 0 && dvz < -gain) { dvz = -gain; }
    else if (dvz > 0 && dvz > gain) { dvz = gain; }
    vz += dvz;

    stdout_counter++;
    if (stdout_counter % 10 == 0) {
      std::cout << "[RTC:VelocitySmoother] vx / target = " << vx  << " / " << data.data.vx << " / " << dvx << std::endl;
      std::cout << "[RTC:VelocitySmoother] vz / target = " << vz  << " / " << data.data.va << " / " << dvz << std::endl;
    }

    m_parent->writeVelocity(vx, vy, vz);
  };
  

  VelocitySmoother *m_parent;
  double vx, vy, vz;
};



extern "C"
{
  DLL_EXPORT void VelocitySmootherInit(RTC::Manager* manager);
};

#endif // VELOCITYSMOOTHER_H
