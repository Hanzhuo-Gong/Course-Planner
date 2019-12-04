# Makefile for SQLAPI++
# Solaris Studio version

# Replace with any own source objects
ifndef OBJS
OBJS = sqltest.obj
endif

CPPDEFS =
CPPFLAGS = +w
INCLUDES = -I../include
LDFLAGS = -L../lib

.SUFFIXES:
.SUFFIXES: .cpp .obj

ifndef SQLAPI_OS
SQLAPI_OS=SQLAPI_LINUX
#SQLAPI_OS=SQLAPI_AIX
#SQLAPI_OS=SQLAPI_HPUX
#SQLAPI_OS=SQLAPI_OSX
endif

# 64-bit version
ifdef SA_64BIT
CPPDEFS += -DSA_64BIT=1
CPPFLAGS += -m64
LDFLAGS += -m64
else
ifdef SA_32BIT
CPPFLAGS += -m32
LDFLAGS += -m32
endif
endif

ifndef CFG
CFG=release
$(warning SQLAPI: Build "release" configuration)
endif

ifndef CFG_LINK
CFG_LINK=dynamic
$(warning SQLAPI: Use "dynamic" configuration)
endif

ifeq "$(CFG)" "release"
CPPFLAGS += -O2
#-fno-strict-aliasing
CPPDEFS += -DNDEBUG
SQLAPI_DEBUG_SUFFIX=
LDFLAGS += -s
else
CPPFLAGS += -g
CPPDEFS += -D_DEBUG
SQLAPI_DEBUG_SUFFIX=d
endif

LIBS=
ifdef SA_USE_PTHREAD
CPPFLAGS += -mt
LIBS += -lpthread
endif

ifdef SA_UNICODE
CPPDEFS += -DUNICODE -D_UNICODE -DSA_UNICODE
SQLAPI_UNICODE_SUFFIX=u
else
SQLAPI_UNICODE_SUFFIX=
endif

LIBS += -lc -lm -ldl

ifeq "$(CFG_LINK)" "dynamic"
LIBS += -lsqlapi$(SQLAPI_UNICODE_SUFFIX)$(SQLAPI_DEBUG_SUFFIX)
SQLAPI_LINK_SUFFIX=
else
LIBS += ../lib/libsqlapi$(SQLAPI_UNICODE_SUFFIX)$(SQLAPI_DEBUG_SUFFIX).a
SQLAPI_LINK_SUFFIX=s
endif

CPP = CC

SA_TARGET_NAME=sqltest$(SQLAPI_UNICODE_SUFFIX)$(SQLAPI_LINK_SUFFIX)$(SQLAPI_DEBUG_SUFFIX)
SA_TARGET=$(SA_TARGET_NAME)

.cpp.obj:
	@$(CPP) -c $(CPPFLAGS) $(CPPDEFS) $(INCLUDES) -o $@ $<
	
$(SA_TARGET): $(OBJS)
	@$(CPP) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)

include build/Makefile.UTILS_UNIX
