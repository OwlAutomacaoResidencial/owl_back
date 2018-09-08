##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=HomeOn_Central
ConfigurationName      :=Debug
WorkspacePath          :=/home/homeon/HomeOn
ProjectPath            :=/home/homeon/HomeOn/HomeOn_Central
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=homeon
Date                   :=11/20/17
CodeLitePath           :=/home/homeon/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="HomeOn_Central.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lboost_system -pthread -lboost_thread -lmysqlcppconn
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/home/homeon/HomeOn/HomeOn_Central/include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/root/boost_1_55_0/stage/lib/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
!CodeLiteDir:=/usr/share/codelite
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_source_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_networking_Server.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_networking_Client.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_logging_Logger.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_database_datasheet.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_source_main.cpp$(ObjectSuffix): src/source/main.cpp $(IntermediateDirectory)/src_source_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_main.cpp$(DependSuffix): src/source/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_main.cpp$(DependSuffix) -MM src/source/main.cpp

$(IntermediateDirectory)/src_source_main.cpp$(PreprocessSuffix): src/source/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_main.cpp$(PreprocessSuffix) src/source/main.cpp

$(IntermediateDirectory)/src_source_networking_Server.cpp$(ObjectSuffix): src/source/networking/Server.cpp $(IntermediateDirectory)/src_source_networking_Server.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/networking/Server.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_networking_Server.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_networking_Server.cpp$(DependSuffix): src/source/networking/Server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_networking_Server.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_networking_Server.cpp$(DependSuffix) -MM src/source/networking/Server.cpp

$(IntermediateDirectory)/src_source_networking_Server.cpp$(PreprocessSuffix): src/source/networking/Server.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_networking_Server.cpp$(PreprocessSuffix) src/source/networking/Server.cpp

$(IntermediateDirectory)/src_source_networking_Client.cpp$(ObjectSuffix): src/source/networking/Client.cpp $(IntermediateDirectory)/src_source_networking_Client.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/networking/Client.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_networking_Client.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_networking_Client.cpp$(DependSuffix): src/source/networking/Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_networking_Client.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_networking_Client.cpp$(DependSuffix) -MM src/source/networking/Client.cpp

$(IntermediateDirectory)/src_source_networking_Client.cpp$(PreprocessSuffix): src/source/networking/Client.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_networking_Client.cpp$(PreprocessSuffix) src/source/networking/Client.cpp

$(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(ObjectSuffix): src/source/networking/ClientManager.cpp $(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/networking/ClientManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(DependSuffix): src/source/networking/ClientManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(DependSuffix) -MM src/source/networking/ClientManager.cpp

$(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(PreprocessSuffix): src/source/networking/ClientManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_networking_ClientManager.cpp$(PreprocessSuffix) src/source/networking/ClientManager.cpp

$(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(ObjectSuffix): src/source/networking/SensorManager.cpp $(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/networking/SensorManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(DependSuffix): src/source/networking/SensorManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(DependSuffix) -MM src/source/networking/SensorManager.cpp

$(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(PreprocessSuffix): src/source/networking/SensorManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_networking_SensorManager.cpp$(PreprocessSuffix) src/source/networking/SensorManager.cpp

$(IntermediateDirectory)/src_source_logging_Logger.cpp$(ObjectSuffix): src/source/logging/Logger.cpp $(IntermediateDirectory)/src_source_logging_Logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/logging/Logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_logging_Logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_logging_Logger.cpp$(DependSuffix): src/source/logging/Logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_logging_Logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_logging_Logger.cpp$(DependSuffix) -MM src/source/logging/Logger.cpp

$(IntermediateDirectory)/src_source_logging_Logger.cpp$(PreprocessSuffix): src/source/logging/Logger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_logging_Logger.cpp$(PreprocessSuffix) src/source/logging/Logger.cpp

$(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(ObjectSuffix): src/source/database/mysql_manager.cpp $(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/database/mysql_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(DependSuffix): src/source/database/mysql_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(DependSuffix) -MM src/source/database/mysql_manager.cpp

$(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(PreprocessSuffix): src/source/database/mysql_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_database_mysql_manager.cpp$(PreprocessSuffix) src/source/database/mysql_manager.cpp

$(IntermediateDirectory)/src_source_database_datasheet.cpp$(ObjectSuffix): src/source/database/datasheet.cpp $(IntermediateDirectory)/src_source_database_datasheet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/database/datasheet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_database_datasheet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_database_datasheet.cpp$(DependSuffix): src/source/database/datasheet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_database_datasheet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_database_datasheet.cpp$(DependSuffix) -MM src/source/database/datasheet.cpp

$(IntermediateDirectory)/src_source_database_datasheet.cpp$(PreprocessSuffix): src/source/database/datasheet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_database_datasheet.cpp$(PreprocessSuffix) src/source/database/datasheet.cpp

$(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(ObjectSuffix): src/source/mweb/WebRouter.cpp $(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/mweb/WebRouter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(DependSuffix): src/source/mweb/WebRouter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(DependSuffix) -MM src/source/mweb/WebRouter.cpp

$(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(PreprocessSuffix): src/source/mweb/WebRouter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_mweb_WebRouter.cpp$(PreprocessSuffix) src/source/mweb/WebRouter.cpp

$(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(ObjectSuffix): src/source/controls/SensorControl.cpp $(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/controls/SensorControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(DependSuffix): src/source/controls/SensorControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(DependSuffix) -MM src/source/controls/SensorControl.cpp

$(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(PreprocessSuffix): src/source/controls/SensorControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_controls_SensorControl.cpp$(PreprocessSuffix) src/source/controls/SensorControl.cpp

$(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(ObjectSuffix): src/source/controls/UsuarioControl.cpp $(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/controls/UsuarioControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(DependSuffix): src/source/controls/UsuarioControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(DependSuffix) -MM src/source/controls/UsuarioControl.cpp

$(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(PreprocessSuffix): src/source/controls/UsuarioControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_controls_UsuarioControl.cpp$(PreprocessSuffix) src/source/controls/UsuarioControl.cpp

$(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(ObjectSuffix): src/source/controls/ComodoControl.cpp $(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/controls/ComodoControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(DependSuffix): src/source/controls/ComodoControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(DependSuffix) -MM src/source/controls/ComodoControl.cpp

$(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(PreprocessSuffix): src/source/controls/ComodoControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_controls_ComodoControl.cpp$(PreprocessSuffix) src/source/controls/ComodoControl.cpp

$(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(ObjectSuffix): src/source/database/dao/DAOSensores.cpp $(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/database/dao/DAOSensores.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(DependSuffix): src/source/database/dao/DAOSensores.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(DependSuffix) -MM src/source/database/dao/DAOSensores.cpp

$(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(PreprocessSuffix): src/source/database/dao/DAOSensores.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_database_dao_DAOSensores.cpp$(PreprocessSuffix) src/source/database/dao/DAOSensores.cpp

$(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(ObjectSuffix): src/source/database/dao/DAOUsuarios.cpp $(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/database/dao/DAOUsuarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(DependSuffix): src/source/database/dao/DAOUsuarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(DependSuffix) -MM src/source/database/dao/DAOUsuarios.cpp

$(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(PreprocessSuffix): src/source/database/dao/DAOUsuarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_database_dao_DAOUsuarios.cpp$(PreprocessSuffix) src/source/database/dao/DAOUsuarios.cpp

$(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(ObjectSuffix): src/source/database/dao/DAOComodos.cpp $(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/database/dao/DAOComodos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(DependSuffix): src/source/database/dao/DAOComodos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(DependSuffix) -MM src/source/database/dao/DAOComodos.cpp

$(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(PreprocessSuffix): src/source/database/dao/DAOComodos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_database_dao_DAOComodos.cpp$(PreprocessSuffix) src/source/database/dao/DAOComodos.cpp

$(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix): src/source/json/serializer/ComodoSerializer.cpp $(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/json/serializer/ComodoSerializer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(DependSuffix): src/source/json/serializer/ComodoSerializer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(DependSuffix) -MM src/source/json/serializer/ComodoSerializer.cpp

$(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(PreprocessSuffix): src/source/json/serializer/ComodoSerializer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_json_serializer_ComodoSerializer.cpp$(PreprocessSuffix) src/source/json/serializer/ComodoSerializer.cpp

$(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(ObjectSuffix): src/source/json/serializer/SensorSerializer.cpp $(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/json/serializer/SensorSerializer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(DependSuffix): src/source/json/serializer/SensorSerializer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(DependSuffix) -MM src/source/json/serializer/SensorSerializer.cpp

$(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(PreprocessSuffix): src/source/json/serializer/SensorSerializer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_json_serializer_SensorSerializer.cpp$(PreprocessSuffix) src/source/json/serializer/SensorSerializer.cpp

$(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix): src/source/json/serializer/UsuarioSerializer.cpp $(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/homeon/HomeOn/HomeOn_Central/src/source/json/serializer/UsuarioSerializer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(DependSuffix): src/source/json/serializer/UsuarioSerializer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(DependSuffix) -MM src/source/json/serializer/UsuarioSerializer.cpp

$(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(PreprocessSuffix): src/source/json/serializer/UsuarioSerializer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_source_json_serializer_UsuarioSerializer.cpp$(PreprocessSuffix) src/source/json/serializer/UsuarioSerializer.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


