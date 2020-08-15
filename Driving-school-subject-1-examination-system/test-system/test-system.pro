#工程文件的配置:
QT       += core gui  #当前QT支持核心应用扩展库,支持组建
RC_ICONS += H1A.ico  #将当前应用程序的小图片设置;文件名:H1A.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  #版本号4:同上^ //超过4就要加入支持的扩展

#TARGET = test-system //改名的地方
#TEMPLATE = app //模板

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS  #如果使用过时的api就会警告

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#所有源文件
SOURCES += \
    main.cpp \
    logindialog.cpp \
    thetestwindow.cpp

HEADERS += \
    logindialog.h \
    thetestwindow.h

FORMS += \
    logindialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgang.qrc
