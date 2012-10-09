DEFINES = SYSTEM_PC PRJ_USE_AUTOGEN_CONFIG=config_2_10_RemoteWriteSetpointSimpleSetpointIso.h
INCLUDEPATH = ../../../xgpl_src
INCLUDEPATH += ../../../IsoAgLib_Examples/tutorial/2_ProcessData/2_10_RemoteWriteSetpointSimpleSetpointIso
TEMPLATE = app
CONFIG = warn_on debug console stl
CONFIG -= qt
CONFIG -= x11
INCPATH -= -I/usr/include

OBJECTS_DIR = objects

QMAKE_CFLAGS_DEBUG += -fno-builtin -Wall -Wpointer-arith -Wstrict-prototypes

QMAKE_CXXFLAGS_DEBUG += -fno-builtin -Wall -Wpointer-arith -Wstrict-prototypes
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/monitoritem_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/baseitem_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/systemmgmt_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/istate_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/identitem_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isoname_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isoitem_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isomonitor_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isosystempkg_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Scheduler/impl/scheduler_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/util/impl/canpkgext_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/util/impl/util_funcs.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/util/impl/canpkg_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/util/impl/cancustomer_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/util/liberr_c.cpp
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/monitoritem_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/identitem_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/baseitem_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/istate_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/impl/systemmgmt_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isoitem_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isomonitor_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isoname_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/impl/isosystempkg_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/iisoitem_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/iisomonitor_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/ISO11783/iisoname_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/istate_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/imonitoritem_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/isystemmgmt_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/SystemMgmt/iidentitem_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Scheduler/impl/scheduler_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Scheduler/ischeduler_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/icanpkgext_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/cancustomer_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/singleton_container.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/elementbase_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/singleton_container_decl.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/getypos_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/util_funcs.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/canpkgext_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/singleton.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/impl/canpkg_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/liberr_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/config.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/icancustomer_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/icanpkg_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/compiler_adoption.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/igetypos_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/util/iutil_funcs.h
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/impl/procdatabase_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/impl/processpkg_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/impl/processelementbase_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/impl/procident_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/impl/process_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/impl/procdataremotebase_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/SimpleSetpointElements/impl/simplemanagesetpointremote_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/StdMeasureElements/impl/measureprogremote_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/SimpleSetpoint/impl/procdataremotesimplesetpoint_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/StdMeasureElements/impl/measureprogbase_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/StdMeasureElements/impl/measuresubprog_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Process/processdatachangehandler_c.cpp
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/impl/processelementbase_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/impl/procident_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/impl/process_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/impl/procdatabase_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/impl/processpkg_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/impl/proc_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/impl/procdataremotebase_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/SimpleSetpointElements/impl/simplemanagesetpointremote_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/SimpleSetpointElements/isimplemanagesetpointremote_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/StdMeasureElements/impl/measureprogremote_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/StdMeasureElements/imeasureprogremote_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/SimpleSetpoint/impl/procdataremotesimplesetpoint_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/Remote/SimpleSetpoint/iprocdataremotesimplesetpoint_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/StdMeasureElements/impl/measuresubprog_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/StdMeasureElements/impl/measureprogbase_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/processdatachangehandler_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/proc_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Process/iprocess_c.h
HEADERS += ../../../xgpl_src/Application_Config/isoaglib_config.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/typedef.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/config.h
HEADERS += ../../../xgpl_src/IsoAgLib/typedef.h
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/can/hal_can_interface.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/can/target_extension_can_rte.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/system/system_target_extensions.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/ident_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/msgobj_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/filterbox_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/canio_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/system/impl/system_c.cpp
SOURCES += ../../../xgpl_src/supplementary_driver/hal/pc/rs232/target_extension_rs232_rte.cpp
SOURCES += ../../../xgpl_src/supplementary_driver/driver/rs232/impl/rs232io_c.cpp
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/can.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/can_typedef.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/hal_can_interface.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/can_target_extensions.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/config.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/system/system_target_extensions.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/system/system.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/errcodes.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/can.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/system.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/filterbox_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/msgobj_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/ident_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/canio_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/iident_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/icanio_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/system/impl/system_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/system/isystem_c.h
HEADERS += ../../../xgpl_src/supplementary_driver/hal/rs232.h
HEADERS += ../../../xgpl_src/supplementary_driver/driver/rs232/impl/rs232io_c.h
HEADERS += ../../../xgpl_src/supplementary_driver/driver/rs232/irs232io_c.h
SOURCES += ../../../IsoAgLib_Examples/tutorial/2_ProcessData/2_10_RemoteWriteSetpointSimpleSetpointIso/2_10_RemoteWriteSetpointSimpleSetpointIso.cpp
QMAKE_LIBS += ../../../commercial_BIOS/bios_pc.testserver/lib/librte_client.a
INCLUDEPATH += ../../../commercial_BIOS/bios_pc.testserver/rte_client_lib
INCLUDEPATH += ../../../commercial_BIOS/bios_pc.testserver/include
INCLUDEPATH += ../../../commercial_BIOS/bios_pc.testserver/sw
