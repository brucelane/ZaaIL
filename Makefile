T:
	@echo "-------- ZaaIL SWC --------"

	@echo && echo "Now compile ZaaIL SWC"
	"$(FLASCC)/usr/bin/g++" $(BASE_CFLAGS) -O4 as3api.cpp main.cpp -emit-swc=Zaa.IL -o ZaaIL.swc

clean:
	rm -f *.swf *.swc *.bc *.exe
