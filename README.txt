--------------------------------

      Agenda_UI 说明文档

--------------------------------
开发环境：QT 5.7.0

功能说明：基于 QT Widget Application 模式开发的Agenda GUI

帮助文档：

在工程目录下，

README.txt :           说明文档

Agenda_UI.pro :        QT_project

./bin :                Agenda.exe 
			(由于5M上传限制没有用 windeployqt 发布，
				不可直接打开除非设置系统环境变量)
./build :              xx.o, moc_xx.o 
./data :               xx.csv

./include/service_ :   xx.hpp  逻辑层和数据层
./include/ui_ :        xx.h    交互层

./rc :                 .rc,    icon资源

./src/service_ :       xx.cpp  逻辑层和数据层
./src/ui_ :            xx.cpp  交互层
  
./ui :                 xx.ui    UI文件
