ERCOAP_DIR  := $(TOP)/PLAT/middleware/thirdparty/er-coap-13

CFLAGS_INC  +=  -I $(TOP)/PLAT/middleware/thirdparty/er-coap-13

ERCOAP_SRC_DIRS += $(ERCOAP_DIR)
ERCOAP_EXCLUDE_FILES :=
ERCOAP_CSRC = $(foreach dir, $(ERCOAP_SRC_DIRS), $(wildcard $(dir)/*.c))
ERCOAP_CFILES = $(filter-out $(ERCOAP_EXCLUDE_FILES), $(ERCOAP_CSRC))
ERCOAP_COBJSTEMP := $(patsubst %.c, %.o, $(ERCOAP_CFILES))
ERCOAP_COBJSTEMP :=$(subst $(ERCOAP_DIR),PLAT/middleware/thirdparty/er-coap-13,$(ERCOAP_COBJSTEMP))
ERCOAP_COBJS := $(addprefix $(BUILDDIR)/, $(ERCOAP_COBJSTEMP))

-include $(ERCOAP_COBJS:.o=.d)


ifeq ($(TOOLCHAIN),GCC)

lib-y += libercoap.a

$(BUILDDIR)/lib/libercoap.a: $(ERCOAP_COBJS)
	@mkdir -p $(dir $@)
	$(ECHO) AR $@
	$(Q)$(AR) -cr $@ $^

endif

ifeq ($(TOOLCHAIN),ARMCC)
ifeq ($(BUILD_USE_PREBUILD_LIB),n)
lib-y += libercoap.lib
endif
$(BUILDDIR)/lib/libercoap.lib: $(ERCOAP_COBJS)
	@mkdir -p $(dir $@)
	$(ECHO) AR $@
	$(Q)$(AR) $(ARFLAGS) $@ $^

endif
