.SUFFIXES:

BUILD_DIR:=build

MAKETARGET=$(MAKE) --no-print-directory -C $@ -f $(CURDIR)/Makefile \
	ROOT_DIR=$(CURDIR) $(MAKECMDGOALS)

.PHONY: $(BUILD_DIR) clean

$(BUILD_DIR):
	+@[ -d $@ ] || mkdir -p $@
	+@$(MAKETARGET)

Makefile : ;
%.mk :: ;

% :: $(BUILD_DIR) ; :

clean:
	rm -rf $(BUILD_DIR)
