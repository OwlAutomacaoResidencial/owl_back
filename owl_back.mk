##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=owl_back
ConfigurationName      :=Debug
WorkspacePath          :=/home/lucas/Documents/owl
ProjectPath            :=/home/lucas/Documents/owl/owl_back
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lucas Leite
Date                   :=09/08/18
CodeLitePath           :=/home/lucas/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="owl_back.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            := -lboost_system -pthread -lboost_thread -lmysqlcppconn 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch)lib/boost/ $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_controls_ComodoControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_database_mysql_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_mweb_WebRouter.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_logging_Logger.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/source_networking_ClientManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_networking_Client.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_controls_SensorControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_database_datasheet.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_networking_Server.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_networking_SensorManager.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(ObjectSuffix): source/database/dao/DAOSensores.cpp $(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/database/dao/DAOSensores.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(DependSuffix): source/database/dao/DAOSensores.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(DependSuffix) -MM source/database/dao/DAOSensores.cpp

$(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(PreprocessSuffix): source/database/dao/DAOSensores.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_database_dao_DAOSensores.cpp$(PreprocessSuffix) source/database/dao/DAOSensores.cpp

$(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(ObjectSuffix): source/json/serializer/SensorSerializer.cpp $(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/json/serializer/SensorSerializer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(DependSuffix): source/json/serializer/SensorSerializer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(DependSuffix) -MM source/json/serializer/SensorSerializer.cpp

$(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(PreprocessSuffix): source/json/serializer/SensorSerializer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_json_serializer_SensorSerializer.cpp$(PreprocessSuffix) source/json/serializer/SensorSerializer.cpp

$(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix): source/json/serializer/UsuarioSerializer.cpp $(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/json/serializer/UsuarioSerializer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(DependSuffix): source/json/serializer/UsuarioSerializer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(DependSuffix) -MM source/json/serializer/UsuarioSerializer.cpp

$(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(PreprocessSuffix): source/json/serializer/UsuarioSerializer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_json_serializer_UsuarioSerializer.cpp$(PreprocessSuffix) source/json/serializer/UsuarioSerializer.cpp

$(IntermediateDirectory)/source_controls_ComodoControl.cpp$(ObjectSuffix): source/controls/ComodoControl.cpp $(IntermediateDirectory)/source_controls_ComodoControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/controls/ComodoControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_controls_ComodoControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_controls_ComodoControl.cpp$(DependSuffix): source/controls/ComodoControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_controls_ComodoControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_controls_ComodoControl.cpp$(DependSuffix) -MM source/controls/ComodoControl.cpp

$(IntermediateDirectory)/source_controls_ComodoControl.cpp$(PreprocessSuffix): source/controls/ComodoControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_controls_ComodoControl.cpp$(PreprocessSuffix) source/controls/ComodoControl.cpp

$(IntermediateDirectory)/source_database_mysql_manager.cpp$(ObjectSuffix): source/database/mysql_manager.cpp $(IntermediateDirectory)/source_database_mysql_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/database/mysql_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_database_mysql_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_database_mysql_manager.cpp$(DependSuffix): source/database/mysql_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_database_mysql_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_database_mysql_manager.cpp$(DependSuffix) -MM source/database/mysql_manager.cpp

$(IntermediateDirectory)/source_database_mysql_manager.cpp$(PreprocessSuffix): source/database/mysql_manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_database_mysql_manager.cpp$(PreprocessSuffix) source/database/mysql_manager.cpp

$(IntermediateDirectory)/source_mweb_WebRouter.cpp$(ObjectSuffix): source/mweb/WebRouter.cpp $(IntermediateDirectory)/source_mweb_WebRouter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/mweb/WebRouter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_mweb_WebRouter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_mweb_WebRouter.cpp$(DependSuffix): source/mweb/WebRouter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_mweb_WebRouter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_mweb_WebRouter.cpp$(DependSuffix) -MM source/mweb/WebRouter.cpp

$(IntermediateDirectory)/source_mweb_WebRouter.cpp$(PreprocessSuffix): source/mweb/WebRouter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_mweb_WebRouter.cpp$(PreprocessSuffix) source/mweb/WebRouter.cpp

$(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix): source/json/serializer/ComodoSerializer.cpp $(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/json/serializer/ComodoSerializer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(DependSuffix): source/json/serializer/ComodoSerializer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(DependSuffix) -MM source/json/serializer/ComodoSerializer.cpp

$(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(PreprocessSuffix): source/json/serializer/ComodoSerializer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_json_serializer_ComodoSerializer.cpp$(PreprocessSuffix) source/json/serializer/ComodoSerializer.cpp

$(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(ObjectSuffix): source/database/dao/DAOUsuarios.cpp $(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/database/dao/DAOUsuarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(DependSuffix): source/database/dao/DAOUsuarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(DependSuffix) -MM source/database/dao/DAOUsuarios.cpp

$(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(PreprocessSuffix): source/database/dao/DAOUsuarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_database_dao_DAOUsuarios.cpp$(PreprocessSuffix) source/database/dao/DAOUsuarios.cpp

$(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(ObjectSuffix): source/controls/UsuarioControl.cpp $(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/controls/UsuarioControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(DependSuffix): source/controls/UsuarioControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(DependSuffix) -MM source/controls/UsuarioControl.cpp

$(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(PreprocessSuffix): source/controls/UsuarioControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_controls_UsuarioControl.cpp$(PreprocessSuffix) source/controls/UsuarioControl.cpp

$(IntermediateDirectory)/source_logging_Logger.cpp$(ObjectSuffix): source/logging/Logger.cpp $(IntermediateDirectory)/source_logging_Logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/logging/Logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_logging_Logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_logging_Logger.cpp$(DependSuffix): source/logging/Logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_logging_Logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_logging_Logger.cpp$(DependSuffix) -MM source/logging/Logger.cpp

$(IntermediateDirectory)/source_logging_Logger.cpp$(PreprocessSuffix): source/logging/Logger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_logging_Logger.cpp$(PreprocessSuffix) source/logging/Logger.cpp

$(IntermediateDirectory)/source_networking_ClientManager.cpp$(ObjectSuffix): source/networking/ClientManager.cpp $(IntermediateDirectory)/source_networking_ClientManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/networking/ClientManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_networking_ClientManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_networking_ClientManager.cpp$(DependSuffix): source/networking/ClientManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_networking_ClientManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_networking_ClientManager.cpp$(DependSuffix) -MM source/networking/ClientManager.cpp

$(IntermediateDirectory)/source_networking_ClientManager.cpp$(PreprocessSuffix): source/networking/ClientManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_networking_ClientManager.cpp$(PreprocessSuffix) source/networking/ClientManager.cpp

$(IntermediateDirectory)/source_main.cpp$(ObjectSuffix): source/main.cpp $(IntermediateDirectory)/source_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_main.cpp$(DependSuffix): source/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_main.cpp$(DependSuffix) -MM source/main.cpp

$(IntermediateDirectory)/source_main.cpp$(PreprocessSuffix): source/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_main.cpp$(PreprocessSuffix) source/main.cpp

$(IntermediateDirectory)/source_networking_Client.cpp$(ObjectSuffix): source/networking/Client.cpp $(IntermediateDirectory)/source_networking_Client.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/networking/Client.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_networking_Client.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_networking_Client.cpp$(DependSuffix): source/networking/Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_networking_Client.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_networking_Client.cpp$(DependSuffix) -MM source/networking/Client.cpp

$(IntermediateDirectory)/source_networking_Client.cpp$(PreprocessSuffix): source/networking/Client.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_networking_Client.cpp$(PreprocessSuffix) source/networking/Client.cpp

$(IntermediateDirectory)/source_controls_SensorControl.cpp$(ObjectSuffix): source/controls/SensorControl.cpp $(IntermediateDirectory)/source_controls_SensorControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/controls/SensorControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_controls_SensorControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_controls_SensorControl.cpp$(DependSuffix): source/controls/SensorControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_controls_SensorControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_controls_SensorControl.cpp$(DependSuffix) -MM source/controls/SensorControl.cpp

$(IntermediateDirectory)/source_controls_SensorControl.cpp$(PreprocessSuffix): source/controls/SensorControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_controls_SensorControl.cpp$(PreprocessSuffix) source/controls/SensorControl.cpp

$(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(ObjectSuffix): source/database/dao/DAOComodos.cpp $(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/database/dao/DAOComodos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(DependSuffix): source/database/dao/DAOComodos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(DependSuffix) -MM source/database/dao/DAOComodos.cpp

$(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(PreprocessSuffix): source/database/dao/DAOComodos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_database_dao_DAOComodos.cpp$(PreprocessSuffix) source/database/dao/DAOComodos.cpp

$(IntermediateDirectory)/source_database_datasheet.cpp$(ObjectSuffix): source/database/datasheet.cpp $(IntermediateDirectory)/source_database_datasheet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/database/datasheet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_database_datasheet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_database_datasheet.cpp$(DependSuffix): source/database/datasheet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_database_datasheet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_database_datasheet.cpp$(DependSuffix) -MM source/database/datasheet.cpp

$(IntermediateDirectory)/source_database_datasheet.cpp$(PreprocessSuffix): source/database/datasheet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_database_datasheet.cpp$(PreprocessSuffix) source/database/datasheet.cpp

$(IntermediateDirectory)/source_networking_Server.cpp$(ObjectSuffix): source/networking/Server.cpp $(IntermediateDirectory)/source_networking_Server.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/networking/Server.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_networking_Server.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_networking_Server.cpp$(DependSuffix): source/networking/Server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_networking_Server.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_networking_Server.cpp$(DependSuffix) -MM source/networking/Server.cpp

$(IntermediateDirectory)/source_networking_Server.cpp$(PreprocessSuffix): source/networking/Server.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_networking_Server.cpp$(PreprocessSuffix) source/networking/Server.cpp

$(IntermediateDirectory)/source_networking_SensorManager.cpp$(ObjectSuffix): source/networking/SensorManager.cpp $(IntermediateDirectory)/source_networking_SensorManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lucas/Documents/owl/owl_back/source/networking/SensorManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_networking_SensorManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_networking_SensorManager.cpp$(DependSuffix): source/networking/SensorManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_networking_SensorManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_networking_SensorManager.cpp$(DependSuffix) -MM source/networking/SensorManager.cpp

$(IntermediateDirectory)/source_networking_SensorManager.cpp$(PreprocessSuffix): source/networking/SensorManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_networking_SensorManager.cpp$(PreprocessSuffix) source/networking/SensorManager.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


