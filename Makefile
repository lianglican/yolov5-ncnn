#############################################################
# 根据不同的平台传入不同的编译选项，直接make表示编译X86平台
# 如需要编译海思平台：make PLATFORM=HI_V300A7 即可
# 调试需传入DEBUG=DEBUG_GDB
#############编译平台##########
# ifeq ($(PLATFORM), HI_V300A7)
#     COMPILER_PREFIX:=arm-hisiv300-linux-
#     LIB_DIR:=lib_hiv300a7
#     USERCPPFLAGS :=-mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations -DARCH_ARM_V7 -DCHIP_PLATFORM_3521A
#     SDK_LIBS:=../libs/sdk_lib/Hi3521A
# else ifeq ($(PLATFORM), HI_X200)
    # COMPILER_PREFIX:=arm-himix200-linux-
    # LIB_DIR:=lib_hix200
    # USERCPPFLAGS :=-mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -fno-aggressive-loop-optimizations -DARCH_ARM_V7 -DCHIP_PLATFORM_3516C
    # SDK_LIBS:=../libs/sdk_lib/Hi3516CV500
#else #x86
    COMPILER_PREFIX:=
    LIB_DIR:=lib_x86
    USERCPPFLAGS := -ffunction-sections -fdata-sections -DARCH_X86_64
# endif

###########目标文件的名称##########
RELEASE_DIR:=release
OBJ_DIR :=.objects/
EXEC_FILE:=$(RELEASE_DIR)/pig_detect

#############编译平台##########
CC  := $(COMPILER_PREFIX)gcc
CXX := $(COMPILER_PREFIX)g++
AR  := $(COMPILER_PREFIX)ar
LD  := $(COMPILER_PREFIX)ld

######指定源文件所在目录
SRC_DIR := ./ \
           ./modules/comm \
           ./modules/mainthread \
           ./modules/parameter \
           ./modules/network/bgserver \
           ./modules/network/oss \
           ./modules/network/curldownloader \
           ./modules/network/socket \
           ./modules/network/rtspserver \
           ./modules/streambuffer \
           ./modules/easylogger \
           ./modules/yolov5 \
           ./modules/json \

######指定头文件,静态库头文件所在目录
INCLUDE_DIR := $(SRC_DIR) \
                ./libs/private/stdlib/include \
                ./libs/third/curl/include \
                ./libs/third/openssl/include \
                ./libs/third/jsoncpp/include \
                ./libs/third/hwobs/include \
                ./libs/third/iconv/include \
                ./libs/third/log4cpp/include \
                ./libs/third/pcre/include \
                ./libs/third/xml/include \
                ./libs/third/zlib/include \
                ./libs/third/ncnn/include \

#####指定所依赖的静态库文件
STATIC_LIBS := ./libs/third/ncnn/$(LIB_DIR)/libncnn.a
            #    ../libs/private/stdlib/$(LIB_DIR)/libqcstd.a 
            #    ../libs/third/jsoncpp/$(LIB_DIR)/libjsoncpp.a 
            #    ../libs/third/log4cpp/$(LIB_DIR)/liblog4cpp.a 
            #    ../libs/third/xml/$(LIB_DIR)/libxml2.a 
            #    ../libs/third/curl/$(LIB_DIR)/libcurl.a 
            #    ../libs/third/openssl/$(LIB_DIR)/libssl.a  
            #    ../libs/third/openssl/$(LIB_DIR)/libcrypto.a 
            #    ../libs/third/pcre/$(LIB_DIR)/libpcre.a  
            #    ../libs/third/pcre/$(LIB_DIR)/libpcrecpp.a  
            #    ../libs/third/pcre/$(LIB_DIR)/libpcreposix.a 
            #    ../libs/third/iconv/$(LIB_DIR)/libiconv.a  
            #    ../libs/third/iconv/$(LIB_DIR)/libcharset.a  
            #    ../libs/third/zlib/$(LIB_DIR)/libz.a
            #    ../libs/third/hwobs/$(LIB_DIR)/libeSDKOBS.a
            #    ../libs/third/hwobs/$(LIB_DIR)/libeSDKLogAPI.a
            #    ../libs/third/hwobs/$(LIB_DIR)/libsecurec.a 


#####指定所依赖的动态库文件如：libtest.so, -L后面带依赖库的路径
# LDFLAGS+=-leSDKOBS -lsecurec -leSDKLogAPI    -L../libs/third/hwobs/$(LIB_DIR) 
#                 -lpcre -lpcrecpp -lpcreposix -L../libs/third/pcre/$(LIB_DIR) 
#                 -lcurl 			-L../libs/third/curl/$(LIB_DIR) 
#                 -lcrypto -lssl 	-L../libs/third/openssl/$(LIB_DIR) 
#                 -liconv 		-L../libs/third/iconv/$(LIB_DIR) 
#                 -llog4cpp 		-L../libs/third/log4cpp/$(LIB_DIR) 
#                 -lxml2 			-L../libs/third/xml/$(LIB_DIR) 
#                 -lz 			-L../libs/third/zlib/$(LIB_DIR) 
#                 -lFEC -lhwpusdk -ljson-c -lSEC -L$(SDK_LIBS)/lib 
LDFLAGS+=-lopencv_highgui -lopencv_videoio -lgomp -lopencv_imgcodecs -lopencv_imgproc -lopencv_core -L/usr/local/lib

#####指定编译选项
ifeq ($(DEBUG), DEBUG_GDB)
USERCPPFLAGS += -g -D$(DEBUG) 
$(warning $(shell echo -e "\033[31m debug open, please be check \033[0m"))
endif

VPATH := $(SRC_DIR)

CSrcs := $(foreach CurDir,$(SRC_DIR),$(wildcard $(CurDir)/*.c))
CppSrcs := $(foreach CurDir,$(SRC_DIR),$(wildcard $(CurDir)/*.cpp))

Objects := $(addprefix $(OBJ_DIR), $(addsuffix .o,$(notdir $(basename $(CSrcs) $(CppSrcs)))))

CDeps:= $(addsuffix .cdep, $(addprefix $(OBJ_DIR), $(basename $(notdir $(CSrcs)))))
CppDeps := $(addsuffix .cppdep, $(addprefix $(OBJ_DIR), $(basename $(notdir $(CppSrcs)))))

CPPFLAGS := -W $(USERCPPFLAGS) -std=c++11
CPPFLAGS += $(addprefix -I,$(INCLUDE_DIR))
LDFLAGS +=  -lpthread -ldl -lrt -lm

$(EXEC_FILE): $(Objects) $(STATIC_LIBS)
	$(CXX) $^ -o $@ $(LDFLAGS)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),cleandep)
-include $(CDeps)
-include $(CppDeps)
endif
endif

$(OBJ_DIR)%.cdep: %.c
	$(create_dep_file)

$(OBJ_DIR)%.cppdep: %.cpp
	$(create_dep_file)

$(OBJ_DIR)%.o:%.c
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(OBJ_DIR)%.o:%.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

define create_dep_file
	@if [ ! -e "$(RELEASE_DIR)" ];then mkdir "$(RELEASE_DIR)";fi
	@if [ ! -e "$(OBJ_DIR)" ];then mkdir "$(OBJ_DIR)"; fi
	@echo Updating dependance ====\> $@;\
	rm -f $@; \
	$(CC) $(CPPFLAGS) -MM $< | sed 's,$(*F).o:,$(OBJ_DIR)$*.o $@:,g' > $@;
endef


.PHONY: clean
clean:
	-rm $(OBJ_DIR) $(EXEC_FILE) -rf
	# -rm $(RELEASE_DIR)/* -rf

