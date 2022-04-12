CC=g++
ODIR=obj

_OBJ = main.o Simulador.o CamadaFisica.o CamadaEnlace.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp | $(ODIR)
	$(CC) -c -o $@ $<

linkcodesim: $(OBJ)
	$(CC) -o $@ $^

$(ODIR):
	mkdir $(ODIR)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o