PROJECT( urDiary )

cmake_minimum_required(VERSION 2.6)

find_package( Qt4 REQUIRED )

include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

set( QT_USE_QTSQL TRUE )

set( urDiary_SRC aboutwindow.cpp main.cpp mainwindow.cpp searchdialog.cpp )
set( urDiary_HEAD aboutwindow.h mainwindow.h searchdialog.h )
set( urDiary_FORMS aboutwindow.ui mainwindow.ui searchdialog.ui )
set( urDiary_RESOURCES img.qrc )

qt4_wrap_cpp( urDiary_HEADER_MOC ${urDiary_HEAD} )
qt4_wrap_ui( urDiary_FORMS_HEADERS ${urDiary_FORMS} )
qt4_add_resources( urDiary_RESOURCES_RCC ${urDiary_RESOURCES} )

include( ${QT_USE_FILE} )
add_definitions( ${QT_DEFINITIONS} )

add_executable( urDiary ${urDiary_SRC} ${urDiary_HEADER_MOC} 
   ${urDiary_FORMS_HEADERS} ${urDiary_RESOURCES_RCC} )

target_link_libraries( urDiary ${QT_LIBRARIES} )
