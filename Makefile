%.asm: %.src
	k2pp <$< >$@

%.obj: %.asm
	k2asm -o $@ -x $(@:%.obj=%.hdr) -c $(@:%.obj=%.dnc) $<

%.obj: %.bas
	petcat -w2 <$< >$@
