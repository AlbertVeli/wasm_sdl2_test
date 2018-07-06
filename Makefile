########################################################
#   ~~=) All Rights Reversed - No Rights Reserved (=~~
#
# Sweetmorn, the 40th day of Confusion in the YOLD 3184
#
# Albert Veli
########################################################

# Source files
SRCS = ball.c init.c audio.c

OBJS = $(SRCS:%.c=%.o)

CC = emcc
WFLAGS := -W -Wall -O3
CFLAGS := $(WFLAGS) -s WASM=1 -s USE_SDL=2
# For background music
CFLAGS += -s USE_OGG=1 -s USE_VORBIS=1
# Uncomment line below if assets are large
#CFLAGS += -s ALLOW_MEMORY_GROWTH=1
CFLAGS += --preload-file assets

# Check if emcc is in PATH
EMCC_EXISTS := $(shell $(CC) --version 2> /dev/null)

# Colors for warning message
ccred := \033[0;31m
ccend := \033[0m

# Check EMCC_EXISTS then build index.js (and index.wasm)
all: check index.js

# Also builds index.wasm
index.js: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@
	@echo -e "Done. Try it out with $(ccred)python -m SimpleHTTPServer 8080$(ccend)"


.PHONY: check clean

# Check if EMCC_EXISTS was set, else warn and exit
check:
ifndef EMCC_EXISTS
	@echo -e "$(CC) not in PATH. Please source $(ccred)memsdk/emsdk_env.sh$(ccend) and try again."
	@false
endif

clean:
	rm -f index.js index.wasm index.data $(OBJS)
