DEFINES = SYSTEM_PC PRJ_USE_AUTOGEN_CONFIG=config_imi_iso_sim.h
INCLUDEPATH = ../../../xgpl_src
INCLUDEPATH += ../../../IsoAgLib_Examples
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
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/isoterminalpkg_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectarchedbargraph_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectlinearbargraph_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectlineattributes_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputstring_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectalarmmask_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectsoftkeymask_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectoutputnumber_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectobjectpointer_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectellipse_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectcontainer_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectmacro_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectworkingset_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectbutton_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectoutputstring_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputlist_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectpicturegraphic_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputboolean_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinput_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectfillattributes_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectstringvariable_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectstring_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectauxiliaryfunction_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectmeter_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectfontattributes_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobject_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectline_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputattributes_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputnumber_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectkey_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectauxiliaryinput_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectrectangle_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectnumbervariable_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectdatamask_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/isoterminal_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectpolygon_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobject_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Multipacket/impl/multisendpkg_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/comm/Multipacket/impl/multisend_c.cpp
HEADERS += ../../../xgpl_src/Application_Config/isoaglib_config.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/typedef.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/config.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectbutton_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectsoftkeymask_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectstringvariable_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinput_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectcontainer_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectstring_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/isoterminal_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectlineattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectellipse_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectbutton_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputlist_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectpolygon_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vttypes.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectpicturegraphic_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectauxiliaryinput_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectline_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectkey_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectmeter_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/isoterminalpkg_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectdatamask_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectfillattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobject_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectoutputstring_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectnumbervariable_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectoutputnumber_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectauxiliaryfunction_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectrectangle_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectlinearbargraph_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectarchedbargraph_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectmacro_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputboolean_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectalarmmask_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputstring_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectinputnumber_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectobjectpointer_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectworkingset_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/impl/vtobjectfontattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectauxiliaryfunction_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobject_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectobjectpointer_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectrectangle_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectmask_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectstringvariable_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectmeter_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectalarmmask_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectworkingset_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectlineattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtincludes.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectpicturegraphic_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectdatamask_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectauxiliaryinput_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectmacro_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectfillattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/iisoterminalobjectpool_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectnumbervariable_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectline_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectcontainer_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectlinearbargraph_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectinputstring_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectarchedbargraph_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectoutputstring_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectinputnumber_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectinputattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/iisoterminal_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectoutputnumber_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectinputlist_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectkey_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectstring_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivttypes.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectsoftkeymask_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectinputboolean_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectfontattributes_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectellipse_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectinput_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/ISO_Terminal/ivtobjectpolygon_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Multipacket/impl/multisend_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Multipacket/impl/multisendstreamer_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Multipacket/impl/multisendpkg_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/comm/Multipacket/imultisend_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/typedef.h
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/can/hal_can_interface.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/can/target_extension_can_rte.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/eeprom/pc_eeditor_rs232.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/eeprom/pc_eeditor_can.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/eeprom/eeprom_target_extensions.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/hal/pc/system/system_target_extensions.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/ident_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/msgobj_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/filterbox_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/can/impl/canio_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/eeprom/impl/eepromio_c.cpp
SOURCES += ../../../xgpl_src/IsoAgLib/driver/system/impl/system_c.cpp
SOURCES += ../../../xgpl_src/supplementary_driver/hal/pc/rs232/target_extension_rs232_rte.cpp
SOURCES += ../../../xgpl_src/supplementary_driver/driver/rs232/impl/rs232io_c.cpp
HEADERS += ../../../xgpl_src/Application_Config/eeprom_adr.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/can.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/can_typedef.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/hal_can_interface.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/can/can_target_extensions.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/eeprom/eeprom.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/eeprom/eeprom_target_extensions.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/eeprom/pc_eeditor_can.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/eeprom/pc_eeditor_rs232.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/config.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/system/system_target_extensions.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/system/system.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/pc/errcodes.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/can.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/eeprom.h
HEADERS += ../../../xgpl_src/IsoAgLib/hal/system.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/filterbox_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/msgobj_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/ident_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/impl/canio_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/iident_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/can/icanio_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/eeprom/impl/eepromio_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/eeprom/ieepromio_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/system/impl/system_c.h
HEADERS += ../../../xgpl_src/IsoAgLib/driver/system/isystem_c.h
HEADERS += ../../../xgpl_src/supplementary_driver/hal/rs232.h
HEADERS += ../../../xgpl_src/supplementary_driver/driver/rs232/impl/rs232io_c.h
HEADERS += ../../../xgpl_src/supplementary_driver/driver/rs232/irs232io_c.h
QMAKE_LIBS += ../../../commercial_BIOS/bios_pc.testserver/lib/librte_client.a
INCLUDEPATH += ../../../commercial_BIOS/bios_pc.testserver/rte_client_lib
INCLUDEPATH += ../../../commercial_BIOS/bios_pc.testserver/include
INCLUDEPATH += ../../../commercial_BIOS/bios_pc.testserver/sw
