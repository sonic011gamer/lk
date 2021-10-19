LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LK_TOP_DIR)/platform/msm_shared/include
INCLUDES += -I$(LOCAL_DIR)/include

OBJS += \
	$(LOCAL_DIR)/main.o \
	$(LOCAL_DIR)/fb.o \
	$(LOCAL_DIR)/game.o \
	$(LOCAL_DIR)/stone.o \
	$(LOCAL_DIR)/font.o \
	$(LOCAL_DIR)/states/ingame.o \
	$(LOCAL_DIR)/states/menu.o \
	$(LOCAL_DIR)/states/gameover.o \
	$(LOCAL_DIR)/../aboot/fastboot.o \
	$(LOCAL_DIR)/../aboot/splash.o

